#include "Controlador.h"
#include "Cliente.h"
#include "Casa.h"
#include "TipoTecho.h"
#include "Apartamento.h"
#include "Apartamento.h"
#include "DTCasa.h"
#include "DTApartamento.h"


int ControladorSistema::ultimaPublicacion = 0;

ControladorSistema* ControladorSistema::instancia = nullptr;

ControladorSistema::ControladorSistema() {}

ControladorSistema* ControladorSistema::getInstance() {
    if (instancia == nullptr)
        instancia = new ControladorSistema();
    return instancia;
}

bool ControladorSistema::altaCliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento) {
    if (usuarios.count(nickname) || contrasena.length() < 6) {
        return false;
    }
    Cliente* nuevo = new Cliente(nickname, contrasena, nombre, email, apellido, documento);
    clientes[nickname] = nuevo;
    return true;
}

bool ControladorSistema::altaPropietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono) {
    if (usuarios.count(nickname)|| contrasena.length() < 6) return false;

    Propietario* nuevo = new Propietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
    propietarios[nickname] = nuevo;
    return true;

}

bool ControladorSistema::altaInmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono) {
    if (usuarios.count(nickname)|| contrasena.length() < 6) return false;

    Inmobiliaria* nueva = new Inmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
    inmobiliarias[nickname] = nueva;
    return true;
}

set<DTUsuario> ControladorSistema::listarInmobiliarias() {
    set<DTUsuario> resultado;
    map<string, Inmobiliaria*>::iterator it;

    for (it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it) {
        string nickname = it->first;
        Inmobiliaria* p = it->second;
        resultado.insert(DTUsuario(nickname, p->getNombre()));
    }

    return resultado;
    
}


set<DTInmuebleListado> ControladorSistema::listarInmuebles(){
    set<DTInmuebleListado> resultado;

    map<int, Inmueble*>::iterator it;
    for (it = inmuebles.begin(); it != inmuebles.end(); ++it) {
        Inmueble* in = it->second;

        int codigo = in->getCodigo();
        string direccion = in->getDireccion();
        string nicknamePropietario = in->getPropietario()->getNickname();
        DTInmuebleListado dato = DTInmuebleListado(codigo, direccion, nicknamePropietario);
        resultado.insert(dato);
    }

    return resultado;
}



void ControladorSistema::altaAdministraPropiedad(string nickname, int codigo) {
    Inmobiliaria* inmobiliaria = inmobiliarias[nickname];
    Inmueble* inmueble = inmuebles[codigo];

    time_t now = time(0);
    tm* ltm = localtime(&now);
    DTFecha* fecha = new DTFecha(ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year);

    AdministraPropiedad* ap = new AdministraPropiedad(fecha);
    ap->setInmueble(inmueble);
    ap->setInmobiliaria(inmobiliaria);

    inmobiliaria->agregarAdministracion(ap);
    inmueble->setAdministraPropiedad(ap);

    
}

set<DTUsuario> ControladorSistema::listarPropietarios() {
    set<DTUsuario> resultado;
    map<string, Propietario*>::iterator it;

    for (it = propietarios.begin(); it != propietarios.end(); ++it) {
        string nickname = it->first;
        Propietario* p = it->second;
        resultado.insert(DTUsuario(nickname, p->getNombre()));
    }

    return resultado;
}

void ControladorSistema::representarPropietario(string nicknamePropietario, string nickname) {
    if (inmobiliarias.count(nickname) && propietarios.count(nicknamePropietario)) {
            Inmobiliaria* i = inmobiliarias[nickname];
            Propietario* p = propietarios[nicknamePropietario];
            i->agregarRepresentado(p);
    }
}



void ControladorSistema::altaCasa(string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo, string propietario) {
    Inmueble* nuevo = new class Casa(direccion, numeroPuerta, superficie, anoConstruccion, esPH, techo);
    nuevo->setPropietario(propietarios[propietario]);
    inmuebles[nuevo->getCodigo()] = nuevo;
    nuevo->setPropietario(propietarios[propietario]);
}

void ControladorSistema::altaApartamento(string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes, string propietario) {
    Inmueble* nuevo = new class Apartamento(direccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes);
    inmuebles[nuevo->getCodigo()] = nuevo;
    nuevo->setPropietario(propietarios[propietario]);
    nuevo->setPropietario(propietarios[propietario]);
    
}



bool ControladorSistema::altaPublicacion(string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipo, string texto, float precio) {
    
    Inmobiliaria* i = inmobiliarias[nicknameInmobiliaria];
    Inmueble* in = inmuebles[codigoInmueble];
    AdministraPropiedad* ap = i->getAdministracionCon(in);
    
    
    time_t now = time(0);
    tm* ltm = localtime(&now);
    DTFecha* fecha = new DTFecha(ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year);
    int codigo = ++ultimaPublicacion;

        Publicacion* nueva = new Publicacion(codigo, fecha, tipo, texto, precio, true);
        ap->agregarPublicacion(nueva);

        // Desactivar anterior publicación del mismo tipo, si la hay
        Publicacion* vieja = ap->getPublicacionActivaDelTipo(tipo);
        if (vieja != nullptr)
            vieja->setActiva(false);

        return true;

    
    /*
    // Buscar la inmobiliaria por nickname
    auto it = inmobiliarias.find(nicknameInmobiliaria);
    if (it == inmobiliarias.end()) {
        std::cerr << "Error: Inmobiliaria no encontrada." << std::endl;
        return false;
    }

    Inmobiliaria* inmobiliaria = it->second;

    // Buscar el inmueble que administra con ese código
    Inmueble* inmueble = inmobiliaria->getInmueble(codigoInmueble);
    if (inmueble == nullptr) {
        std::cerr << "Error: Inmueble no encontrado para esa inmobiliaria." << std::endl;
        return false;
    }

    // código para la publicación
    static int proximoCodigoPublicacion = 1;
    int codigo = proximoCodigoPublicacion++;

    // Crear la fecha actual
    time_t now = time(0);
    tm* ltm = localtime(&now);
    DTFecha fecha(
        ltm->tm_mday,
        1 + ltm->tm_mon,
        1900 + ltm->tm_year
    );

    Publicacion* publicacion = new Publicacion(codigo, fecha, tipo, texto, precio, true);
    inmueble->setPublicacion(publicacion);
*/
   // return true;
}

set<DTInmuebleAdministrado> ControladorSistema::listarInmueblesAdministrados(string nicknameInmobiliaria) {
        set<DTInmuebleAdministrado> resultado;
        
        Inmobiliaria* i = inmobiliarias[nicknameInmobiliaria];
        set<AdministraPropiedad*> admins = i->getAdministraciones();

        for (AdministraPropiedad* ap : admins) {
            Inmueble* in = ap->getInmueble();
            DTFecha* fecha = ap->getFecha();

            DTInmuebleAdministrado dto(
                in->getCodigo(),
                in->getDireccion(),
                fecha
            );

            resultado.insert(dto);
        }

        return resultado;
    }
    

set<DTInmuebleListado> ControladorSistema::listarInmueblesNoAdministradosInmobiliaria(string nickname) {
    set<DTInmuebleListado> resultado;

    Inmobiliaria* inmobiliaria = inmobiliarias[nickname];
    set<AdministraPropiedad*> administradas = inmobiliaria->getAdministraciones();

    set<int> codigosAdministrados;
    for (set<AdministraPropiedad*>::iterator it = administradas.begin(); it != administradas.end(); ++it) {
        codigosAdministrados.insert((*it)->getInmueble()->getCodigo());
    }

    for (map<int, Inmueble*>::iterator it = inmuebles.begin(); it != inmuebles.end(); ++it) {
        int codigo = it->first;
        if (codigosAdministrados.find(codigo) == codigosAdministrados.end()) {
            Inmueble* in = it->second;
            Propietario* p = in->getPropietario();
            DTInmuebleListado dt(codigo, in->getDireccion(), p->getNombre());
            resultado.insert(dt);
        }
    }

    return resultado;
}


//FAlTA IMPLEMENTAR

void ControladorSistema::finalizarAltaUsuario() {}


set<DTPublicacion> ControladorSistema::listarPublicacion(TipoPublicacion tipo, float precioMin, float precioMax, TipoInmueble tipoInmueble) {
    return {};
}

DTInmueble* ControladorSistema::detalleInmueble(int codigoInmueble){
    return{};
}


//DTInmueble detalleInmueblePublicacion(codigoPublicacion): DTInmueble
DTInmueble* ControladorSistema::detalleInmueblePublicacion(int codigoPublicacion){
    return nullptr;
}


void ControladorSistema::eliminarInmueble(int codigoInmueble) {}



//funciones para notificaciones



