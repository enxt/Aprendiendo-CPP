#ifndef _CIMPRESORA_H_
#define _CIMPRESORA_H_

#include <string>
#include "carticulo.h"

class CImpresora : public CArticulo {
protected:
    std::string tipo_conexion;

public:
    CImpresora(int unidades, double precio, std::string tipo_conexion);
    void VisualizarFicha();
    std::string nombre();
};

#endif //_CIMPRESORA_H_
