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
    if (usuarios.count(nickname)) {
        return false;
    }
    Cliente* nuevo = new Cliente(nickname, contrasena, nombre, email, apellido, documento);
    clientes[nickname] = nuevo;
    return true;
}

bool ControladorSistema::altaPropietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono) {
    if (usuarios.count(nickname)) return false;

    Propietario* nuevo = new Propietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
    propietarios[nickname] = nuevo;
    return true;

}

bool ControladorSistema::altaInmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono) {
    if (usuarios.count(nickname)) return false;

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
    
    return {};
}

set<DTInmuebleListado> ControladorSistema::listarInmueblesAdministrados(string nicknameInmobiliaria) {
    return {};
}

set<DTPublicacion> ControladorSistema::listarPublicacion(TipoPublicacion tipo, float precioMin, float precioMax, TipoInmueble tipoInmueble) {
    return {};
}

void ControladorSistema::eliminarInmueble(int codigoInmueble) {}

bool ControladorSistema::altaPublicacion(string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipo, string texto, float precio) {
    
    return true;
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

void ControladorSistema::representarPropietario(string nicknamePropietario) {
    if (inmobiliariaSeleccionada && propietarios.count(nicknamePropietario)) {
        Propietario* p = propietarios[nicknamePropietario];
        inmobiliariaSeleccionada->agregarRepresentado(p);
    }
}

void ControladorSistema::finalizarAltaUsuario() {
    inmobiliariaSeleccionada = nullptr;
}

void ControladorSistema::altaCasa(string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo) {
    Inmueble* nuevo = new class Casa(direccion, numeroPuerta, superficie, anoConstruccion, esPH, techo);
    inmuebles[nuevo->getCodigo()] = nuevo;
}

void ControladorSistema::altaApartamento(string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes) {
    Inmueble* nuevo = new class Apartamento(direccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes);
    inmuebles[nuevo->getCodigo()] = nuevo;
}
