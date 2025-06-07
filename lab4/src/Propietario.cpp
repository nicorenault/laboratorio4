#include "Propietario.h"

Propietario::Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email,
                         std::string cuentaBancaria, std::string telefono): Usuario(nickname, contrasena, nombre, email),cuentaBancaria(cuentaBancaria), telefono(telefono) {}


void Propietario::agregarPropiedad(Inmueble* in) {
    propiedades.insert(in);
}

std::set<Inmueble*> Propietario::getPropiedades() const {
    return propiedades;
}
