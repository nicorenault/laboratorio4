#include "../include/Factory.h"
#include "../include/ControladorFechaActual.h"
#include <cstddef>
#include "IControladorSistema.h"
#include "Controlador.h"
Factory* Factory::instance = NULL;

Factory::Factory() {
}

Factory* Factory::getInstance() {
    if (instance == NULL) {
        instance = new Factory();
    }
    return instance;
}

IControladorFechaActual* Factory::getControladorFechaActual(){
    return ControladorFechaActual::getInstance();
}

IControladorSistema* Factory::getControladorSistema() {
    return ControladorSistema::getInstance();
}
