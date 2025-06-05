#ifndef FACTORY_H
#define FACTORY_H

#include "IControladorFechaActual.h"
#include "IControladorSistema.h"
#include "Controlador.h"

class Factory {
    private:
        static Factory* instance;
        Factory();

    public:
        static Factory* getInstance();
        IControladorFechaActual* getControladorFechaActual();
        IControladorSistema* getControladorSistema();
        //TODO: Get interfaces de controladores
        ~Factory();
};

#endif
