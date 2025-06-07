#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "Usuario.h"
#include <string>
#include <set>

class Inmueble;

class Propietario : public Usuario {
    private:
        std::string cuentaBancaria;
        std::string telefono;
        std::set<Inmueble*> propiedades;

    public:
        Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono);
        void agregarPropiedad(Inmueble* in);
        std::set<Inmueble*> getPropiedades() const;
    
};

#endif
