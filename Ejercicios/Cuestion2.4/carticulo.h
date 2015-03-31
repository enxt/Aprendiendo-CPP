#ifndef _CARTICULO_H_
#define _CARTICULO_H_

#include <string>

class CArticulo {

    protected:
        int unidades;
        double precio;

    public:
        CArticulo(int unidades, double precio);
        virtual void VisualizarFicha();
        virtual std::string nombre() = 0;

};

#endif //_CARTICULO_H_
