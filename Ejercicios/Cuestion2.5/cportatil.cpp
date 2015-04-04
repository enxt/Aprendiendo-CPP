#include <iostream>
#include "cportatil.h"

using namespace std;

CPortatil::CPortatil(int unidades, double precio, string cpu, float peso) : COrdenador(unidades, precio, cpu) {
    this->peso = peso;
}

void CPortatil::VisualizarFicha() {
    cout << "Unidades: " << unidades << endl;
    cout << "Precio: " << precio << endl;
    cout << "CPU: " << cpu << endl;
    cout << "Peso: " << peso << endl;
    cout << "Nombre: " << nombre() << endl;
}

string CPortatil::nombre() {
    return "Ordenador portatil";
}