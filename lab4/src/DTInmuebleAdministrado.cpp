#include "../include/DTInmuebleAdministrado.h"

DTInmuebleAdministrado::DTInmuebleAdministrado(int codigo, std::string direccion, DTFecha* fechaComienzo) {
    this->codigo = codigo;
    this->direccion = direccion;
    this->fechaComienzo = new DTFecha(fechaComienzo);
}

int DTInmuebleAdministrado::getCodigo() const {
    return codigo;
}

std::string DTInmuebleAdministrado::getDireccion() const {
    return direccion;
}

DTFecha* DTInmuebleAdministrado::getFechaComienzo() {
    return fechaComienzo;
}

DTInmuebleAdministrado::~DTInmuebleAdministrado(){
    //delete fechaComienzo;
}

bool DTInmuebleAdministrado::operator<(const DTInmuebleAdministrado& otro) const {
    return this->codigo < otro.codigo;
}
