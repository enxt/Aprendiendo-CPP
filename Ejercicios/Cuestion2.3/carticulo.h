#ifndef _CARTICULO_H_
#define _CARTICULO_H_

class CArticulo {

    protected:
        int unidades;
        double precio;

    public:
        CArticulo(int unidades, double precio);
        void VisualizarFicha();

};

#endif //_CARTICULO_H_
