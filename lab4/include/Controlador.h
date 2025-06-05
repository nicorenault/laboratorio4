#ifndef CONTROLADORSISTEMA_H
#define CONTROLADORSISTEMA_H

#include "IControladorSistema.h"
#include "Inmobiliaria.h"
#include "Inmueble.h"
#include "Propietario.h"
#include "Cliente.h"
#include "AdministraPropiedad.h"
#include "ControladorFechaActual.h"
#include "Publicacion.h"
#include <map>
#include <set>
#include <string>
#include "DTUsuario.h"
#include "DTInmuebleListado.h"
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "Cliente.h"
#include "Casa.h"
#include "TipoTecho.h"
#include "Apartamento.h"


class ControladorSistema : public IControladorSistema {
private:
    static ControladorSistema* instancia;

    map<string, Usuario*> usuarios;
    map<int, Inmueble*> inmuebles;
    set<AdministraPropiedad*> administraciones;
    set<Publicacion*> publicaciones;
    map<string, Inmobiliaria*> inmobiliarias;
    map<string, Propietario*> propietarios;
    map<string, Cliente*> clientes;

    Inmobiliaria* inmobiliariaSeleccionada = nullptr;

    ControladorSistema();

public:
    static ControladorSistema* getInstance();

    bool altaCliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento) override;
    
    bool altaPropietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono) override;
    
    bool altaInmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono) override;

    set<DTUsuario> listarInmobiliarias() override;
    
    set<DTInmuebleListado> listarInmueblesAdministrados(string nicknameInmobiliaria) override;
    
    set<DTPublicacion> listarPublicacion(TipoPublicacion tipo, float precioMin, float precioMax, TipoInmueble tipoInmueble) override;
    
    void eliminarInmueble(int codigoInmueble) override;
    
    bool altaPublicacion(string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipo, string texto, float precio) override;

    set<DTInmuebleListado> listarInmueblesNoAdministradosInmobiliaria(string nickname) override;
    void altaAdministraPropiedad(string nickname, int codigo) override;
    
    set<DTUsuario> listarPropietarios() override;
    
    void representarPropietario(string nicknamePropietario) override;
    
    void altaCasa(string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo) override;
    
    void altaApartamento(string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso,bool tieneAscensor, float gastosComunes) override;

    
    void finalizarAltaUsuario() override;
    
};

#endif
