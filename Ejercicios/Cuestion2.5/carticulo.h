#ifndef _CARTICULO_H_
#define _CARTICULO_H_

#include <string>

class CArticulo {

    protected:
        int unidades;
        double precio;

    public:
        CArticulo(int unidades, double precio);
        ~CArticulo();
        virtual void VisualizarFicha();
        virtual std::string nombre() = 0;
        static int num;

};

#endif //_CARTICULO_H_
