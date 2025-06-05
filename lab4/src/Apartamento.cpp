#include "Apartamento.h"

Apartamento::Apartamento(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion,int piso, bool tieneAscensor, float gastosComunes)
: Inmueble(direccion, numeroPuerta, superficie, anoConstruccion),piso(piso),tieneAscensor(tieneAscensor),gastosComunes(gastosComunes) {        
}
