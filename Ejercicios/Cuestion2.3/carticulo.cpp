#include <iostream>
#include "carticulo.h"

using namespace std;

CArticulo::CArticulo(int unidades, double precio) {
    this->unidades = unidades;
    this->precio = precio;
}

void CArticulo::VisualizarFicha() {
    cout << "Unidades: " << unidades << endl;
    cout << "Precio: " << precio << endl;
}