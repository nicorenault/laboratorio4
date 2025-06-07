
#include "AdministraPropiedad.h"
#include "Inmueble.h"
#include "Inmobiliaria.h"

AdministraPropiedad::AdministraPropiedad(DTFecha* fecha)
    : fecha(fecha), inmueble(nullptr), inmobiliaria(nullptr) {}

AdministraPropiedad::~AdministraPropiedad() {
    delete fecha;
}

DTFecha* AdministraPropiedad::getFecha() const {
    return fecha;
}

Inmueble* AdministraPropiedad::getInmueble() const {
    return inmueble;
}

Inmobiliaria* AdministraPropiedad::getInmobiliaria() const {
    return inmobiliaria;
}


void AdministraPropiedad::setInmueble(Inmueble* in) {
    inmueble = in;
}

void AdministraPropiedad::setInmobiliaria(Inmobiliaria* i) {
    inmobiliaria = i;
}

void AdministraPropiedad::agregarPublicacion(Publicacion* p) {
    publicaciones.insert(p);
}

Publicacion* AdministraPropiedad::getPublicacionActivaDelTipo(TipoPublicacion tipo) const {
    for (Publicacion* p : publicaciones) {
        if (p->getTipo() == tipo && p->getActiva())
            return p;
    }
    return nullptr;
}

bool AdministraPropiedad::tienePublicacionActivaDelTipo(TipoPublicacion tipo) const {
    return getPublicacionActivaDelTipo(tipo) != nullptr;
}
