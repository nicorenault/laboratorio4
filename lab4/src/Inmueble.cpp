#include "Inmueble.h"

int Inmueble::ultimoCodigo = 1;


Inmueble::Inmueble(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion): direccion(direccion), numeroPuerta(numeroPuerta), superficie(superficie), anoConstruccion(anoConstruccion){
    codigo = ultimoCodigo++;
};

Inmueble::~Inmueble() {}

int Inmueble::getCodigo() const {
    return codigo;
}

std::string Inmueble::getDireccion() const {
    return direccion;
}

int Inmueble::getNumeroPuerta() const {
    return numeroPuerta;
}

int Inmueble::getSuperficie() const {
    return superficie;
}

int Inmueble::getAnioConstruccion() const {
    return anoConstruccion;
}
