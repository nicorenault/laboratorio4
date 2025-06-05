#include "Casa.h"

Casa::Casa(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo)
    : Inmueble(direccion, numeroPuerta, superficie, anoConstruccion),esPH(esPH), techo(techo) {}

Casa::~Casa() {}

bool Casa::getEsPH() const {
    return esPH;
}

TipoTecho Casa::getTecho() const {
    return techo;
}
