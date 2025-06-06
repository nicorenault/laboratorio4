#ifndef INMUEBLE_H
#define INMUEBLE_H
#include <string>
#include "Propietario.h"

class Inmueble {
    private:
        int codigo;
        std::string direccion;
        int numeroPuerta;
        int superficie;
        int anoConstruccion;
        static int ultimoCodigo;
        Propietario* propietario;

    public:
        Inmueble(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion);
        void setPropietario(Propietario* p);
        Propietario* getPropietario();
        ~Inmueble();
        int getCodigo() const;
        std::string getDireccion() const;
        int getNumeroPuerta() const;
        int getSuperficie() const;
        int getAnioConstruccion() const;
};

#endif
