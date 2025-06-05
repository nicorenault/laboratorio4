#ifndef INMUEBLE_H
#define INMUEBLE_H
#include <string>

class Inmueble {
    private:
        int codigo;
        std::string direccion;
        int numeroPuerta;
        int superficie;
        int anoConstruccion;
        static int ultimoCodigo;

    public:
        Inmueble(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion);
        ~Inmueble();
        int getCodigo() const;
        std::string getDireccion() const;
        int getNumeroPuerta() const;
        int getSuperficie() const;
        int getAnioConstruccion() const;
};

#endif
