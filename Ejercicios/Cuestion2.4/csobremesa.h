#ifndef _CSOBREMESA_H_
#define _CSOBREMESA_H_

#include <string>
#include "cordenador.h"

class CSobremesa : public COrdenador {
protected:
    std::string pantalla;

public:
    CSobremesa(int unidades, double precio, std::string cpu, std::string pantalla);
    void VisualizarFicha();
    std::string nombre();
};

#endif //_CSOBREMESA_H_
