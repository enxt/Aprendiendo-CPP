#ifndef _CORDENADOR_H_
#define _CORDENADOR_H_

#include <string>
#include "carticulo.h"

class COrdenador: public CArticulo {
    protected:
        std::string cpu;

    public:
        COrdenador(int unidades, double precio, std::string cpu);
        void VisualizarFicha();
        std::string nombre();
};

#endif // _CORDENADOR_H_
