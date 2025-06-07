#ifndef INMUEBLE_H
#define INMUEBLE_H
#include <string>
#include "Propietario.h"
class AdministraPropiedad;
class Inmueble {
    private:
        int codigo;
        std::string direccion;
        int numeroPuerta;
        int superficie;
        int anoConstruccion;
        static int ultimoCodigo;
        Propietario* propietario;
        AdministraPropiedad* adminPropiedad;
    

    public:
        Inmueble(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion);
        void setPropietario(Propietario* p);
        //void setPublicacion(Publicacion*);
        Propietario* getPropietario();
        ~Inmueble();
        int getCodigo() const;
        std::string getDireccion() const;
        int getNumeroPuerta() const;
        int getSuperficie() const;
        int getAnioConstruccion() const;
        void setAdministraPropiedad(AdministraPropiedad* ap);
        AdministraPropiedad* getAdministraPropiedad() const;
        
};

#endif
