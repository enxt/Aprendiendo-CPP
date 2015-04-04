#include <iostream>
#include "csobremesa.h"

using namespace std;

CSobremesa::CSobremesa(int unidades, double precio, string cpu, string pantalla) : COrdenador(unidades, precio, cpu) {
    this->pantalla = pantalla;
}

void CSobremesa::VisualizarFicha() {
    cout << "Unidades: " << unidades << endl;
    cout << "Precio: " << precio << endl;
    cout << "CPU: " << cpu << endl;
    cout << "Pantalla: " << pantalla << endl;
    cout << "Nombre: " << nombre() << endl;
}

string CSobremesa::nombre() {
    return "Ordenador sobremesa";
}