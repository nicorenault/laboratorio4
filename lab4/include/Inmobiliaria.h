#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H
#include "Usuario.h"
#include <string>
#include <set>
#include "Propietario.h"


class Inmobiliaria : public Usuario {
    private:
        std::string direccion;
        std::string url;
        std::string telefono;
        std::set<Propietario*> representados;
    

    public:
        Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono);
        void agregarRepresentado(Propietario* p);
    
        ~Inmobiliaria();
};

#endif
