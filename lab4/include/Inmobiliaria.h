#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H
#include "Usuario.h"
#include <string>
#include <set>
#include "Propietario.h"
#include "Inmueble.h"

class AdministraPropiedad;

class Inmobiliaria : public Usuario {
    private:
        std::string direccion;
        std::string url;
        std::string telefono;
        std::set<Propietario*> representados;
        std::set<AdministraPropiedad*> administraciones;
    
    

    public:
        Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono);
        void agregarRepresentado(Propietario* p);
        // Inmueble* getInmueble(int codigo);
        void agregarAdministracion(AdministraPropiedad* ap);

        std::set<Propietario*> getRepresentados() const;
        std::set<AdministraPropiedad*> getAdministraciones() const;

        bool tieneAdministracionCon(Inmueble* in) const;
        AdministraPropiedad* getAdministracionCon(Inmueble* in);
    
        ~Inmobiliaria();
};

#endif
