#include <iostream>
#include "cordenador.h"

using namespace std;

COrdenador::COrdenador(int unidades, double precio, string cpu) : CArticulo(unidades, precio) {
    this->cpu = cpu;
}

void COrdenador::VisualizarFicha() {
    cout << "Unidades: " << unidades << endl;
    cout << "Precio: " << precio << endl;
    cout << "CPU" << cpu << endl;
}