#ifndef DTINMUEBLEADMINISTRADO_H
#define DTINMUEBLEADMINISTRADO_H
#include "DTFecha.h"
#include <string>

class DTInmuebleAdministrado {
    private:
        int codigo;
        std::string direccion;
        DTFecha* fechaComienzo;

    public:
        DTInmuebleAdministrado(int codigo, std::string direccion, DTFecha* fechaComienzo);
        int getCodigo() const;
        std::string getDireccion()const;
        DTFecha* getFechaComienzo();
        ~DTInmuebleAdministrado();
        bool operator<(const DTInmuebleAdministrado& otro) const;
};

#endif
