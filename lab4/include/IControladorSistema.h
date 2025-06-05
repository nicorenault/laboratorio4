

#ifndef ICONTROLADORSISTEMA_H
#define ICONTROLADORSISTEMA_H

#include <string>
#include <set>
#include "DTUsuario.h"
#include "DTInmuebleListado.h"
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "TipoTecho.h"
#include "Casa.h"
#include "Apartamento.h"


using namespace std;

class IControladorSistema {
public:
    virtual bool altaCliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento) = 0;
    
    virtual bool altaPropietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono) = 0;
    
    virtual bool altaInmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono) = 0;
    
    virtual set<DTUsuario> listarInmobiliarias() = 0;
    
    virtual set<DTInmuebleListado> listarInmueblesAdministrados(string nicknameInmobiliaria) = 0;
    
    virtual set<DTPublicacion> listarPublicacion(TipoPublicacion tipo, float precioMin, float precioMax, TipoInmueble tipoInmueble) = 0;
    
    virtual void eliminarInmueble(int codigoInmueble) = 0;
    
    virtual bool altaPublicacion(string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipo, string texto, float precio) = 0;

    // Nuevas del Lab 4
    virtual set<DTInmuebleListado> listarInmueblesNoAdministradosInmobiliaria(string nickname) = 0;
    virtual void altaAdministraPropiedad(string nickname, int codigo) = 0;
    
    virtual set<DTUsuario> listarPropietarios() = 0;
    
    virtual void representarPropietario(string nicknamePropietario) = 0;
    
    virtual void finalizarAltaUsuario() = 0;
    
    virtual void altaCasa(string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo) = 0;
    virtual void altaApartamento(string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso,bool tieneAscensor, float gastosComunes) = 0;

    virtual ~IControladorSistema() {}
};

#endif
