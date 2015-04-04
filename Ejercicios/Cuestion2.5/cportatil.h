#ifndef _CPORTATIL_H_
#define _CPORTATIL_H_

#include <string>
#include "cordenador.h"

class CPortatil : public COrdenador {
    protected:
        float peso;

    public:
        CPortatil(int unidades, double precio, std::string cpu, float peso);
        void VisualizarFicha();
        std::string nombre();
};

#endif //_CPORTATIL_H_
