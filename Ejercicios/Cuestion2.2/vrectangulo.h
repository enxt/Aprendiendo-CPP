#ifndef _VRECTANGULO_H_
#define _VRECTANGULO_H_

#include "rectangulo.h"

class VecRect {
    private:
        Rectangulo **array_rect; // Array de punteros a rectángulos
        int total;
    
    public:
        VecRect(int valor);
        ~VecRect();
        void asignaDatos(int i, float Vlargo, float Vancho);
        void presentaDatos(int i);
        
        int getTotal() {return total;}
};

#endif // _VRECTANGULO_H_