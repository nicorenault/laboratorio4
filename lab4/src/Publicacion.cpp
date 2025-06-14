#include "Publicacion.h"

Publicacion::Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, std::string texto, float precio, bool activa)
    : codigo(codigo), fecha(fecha), tipo(tipo), texto(texto), precio(precio), activa(activa) {
        fecha = new DTFecha(fecha);
    }

int Publicacion::getCodigo() const {
    return codigo;
}

DTFecha* Publicacion::getFecha() const {
    return fecha;
}

TipoPublicacion Publicacion::getTipo() const {
    return tipo;
}

std::string Publicacion::getTexto() const {
    return texto;
}

float Publicacion::getPrecio() const {
    return precio;
}

bool Publicacion::getActiva() const {
    return activa;
}

void Publicacion::setActiva(bool a) {
    activa = a;
}

void Publicacion::setAdministraPropiedad(AdministraPropiedad* ap) {
    administra = ap;
}

AdministraPropiedad* Publicacion::getAdministraPropiedad() const {
    return administra;
}

Publicacion::~Publicacion() {
    delete fecha;
}

