#include "Inmobiliaria.h"
#include "AdministraPropiedad.h"  
Inmobiliaria::Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email,
                           std::string direccion, std::string url, std::string telefono): Usuario(nickname, contrasena, nombre, email), direccion(direccion), url(url), telefono(telefono) {}


void Inmobiliaria::agregarRepresentado(Propietario* p) {
    representados.insert(p);
}
Inmobiliaria::~Inmobiliaria() {
    for (AdministraPropiedad* ap : administraciones) {
        delete ap;
    }
    administraciones.clear();
}



void Inmobiliaria::agregarAdministracion(AdministraPropiedad* ap) {
    administraciones.insert(ap);
}

std::set<Propietario*> Inmobiliaria::getRepresentados() const {
    return representados;
}

std::set<AdministraPropiedad*> Inmobiliaria::getAdministraciones() const {
    return administraciones;
}

bool Inmobiliaria::tieneAdministracionCon(Inmueble* in) const {
    for (AdministraPropiedad* ap : administraciones) {
        if (ap->getInmueble() == in) {
            return true;
        }
    }
    return false;
}

AdministraPropiedad* Inmobiliaria::getAdministracionCon(Inmueble* in) {
    for (AdministraPropiedad* ap : administraciones) {
        if (ap->getInmueble() == in) {
            return ap;
        }
    }
    return nullptr;
}
