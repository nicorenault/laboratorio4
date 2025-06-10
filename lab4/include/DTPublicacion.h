#ifndef DTPUBLICACION_H
#define DTPUBLICACION_H
#include "DTFecha.h"
#include <string>

class DTPublicacion {
    private:
        int codigo;
        DTFecha* fecha;
        std::string texto;
        std::string precio;
        std::string inmobiliaria;

    public:
        DTPublicacion(int codigo, DTFecha* fecha, std::string texto, std::string precio, std::string inmobiliaria);
        int getCodigo() const;
        DTFecha* getFecha() const;
        std::string getTexto() const;
        std::string getPrecio() const;
        std::string getInmobiliaria() const;
    // Operador < para usar en std::set
        bool operator<(const DTPublicacion& other) const {
        return this->codigo < other.codigo;}
        ~DTPublicacion();
};

#endif
