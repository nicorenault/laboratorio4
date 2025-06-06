#include "Controlador.h"
#include "Cliente.h"
#include "Casa.h"
#include "TipoTecho.h"
#include "Apartamento.h"


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

set<DTInmuebleListado> ControladorSistema::listarInmueblesNoAdministradosInmobiliaria(string nickname) {
    return {};
}

void ControladorSistema::altaAdministraPropiedad(string nickname, int codigo) {}

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
    inmuebles[nuevo->getCodigo()] = nuevo;
    nuevo->setPropietario(propietarios[propietario]);
}

void ControladorSistema::altaApartamento(string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes, string propietario) {
    Inmueble* nuevo = new class Apartamento(direccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes);
    inmuebles[nuevo->getCodigo()] = nuevo;
    nuevo->setPropietario(propietarios[propietario]);
    
}

bool ControladorSistema::altaPublicacion(string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipo, string texto, float precio) {
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

    Publicacion* publicacion = new Publicacion(tipo, texto, precio);
    inmueble->setPublicacion(publicacion);

    return true;
}

//FAlTA IMPLEMENTAR

void ControladorSistema::finalizarAltaUsuario() {}


set<DTInmuebleListado> ControladorSistema::listarInmueblesAdministrados(string nicknameInmobiliaria) {
    return {};
}


set<DTPublicacion> ControladorSistema::listarPublicacion(TipoPublicacion tipo, float precioMin, float precioMax, TipoInmueble tipoInmueble) {
    return {};
}

//DTInmueble detalleInmueblePublicacion(codigoPublicacion): DTInmueble

// DTInmueble detalleInmueble(codigoInmueble)

void ControladorSistema::eliminarInmueble(int codigoInmueble) {}

//Coleccion de DTInmuebleListado listarInmueblesNoAdministradosInmobiliaria(nicknameInmobiliaria);

//altaAdministraPropiedad(nicknameInmobiliaria, codigoInmueble);

//funciones para notificaciones



