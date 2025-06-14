#ifndef PUBLICACION_H
#define PUBLICACION_H
#include "DTFecha.h"
#include "TipoPublicacion.h"
#include <string>
class AdministraPropiedad;

class Publicacion {
private:
    int codigo;
    DTFecha* fecha;
    TipoPublicacion tipo;
    std::string texto;
    float precio;
    bool activa;
    AdministraPropiedad* administra;

public:
    Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, std::string texto, float precio, bool activa);
    int getCodigo() const;
    DTFecha* getFecha() const;
    TipoPublicacion getTipo() const;
    std::string getTexto() const;
    float getPrecio() const;
    bool getActiva() const;
    void setAdministraPropiedad(AdministraPropiedad* ap);
    AdministraPropiedad* getAdministraPropiedad() const;

    void setActiva(bool a);
    ~Publicacion();
};

#endif
