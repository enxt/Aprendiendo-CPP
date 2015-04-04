#include <iostream>
#include "cimpresora.h"

using namespace std;

CImpresora::CImpresora(int unidades, double precio, string tipo_conexion) : CArticulo(unidades, precio) {
    this->tipo_conexion = tipo_conexion;
}

void CImpresora::VisualizarFicha() {
    cout << "Unidades: " << unidades << endl;
    cout << "Precio: " << precio << endl;
    cout << "Tipo de conexión: " << tipo_conexion << endl;
    cout << "Nombre: " << nombre() << endl;
}

string CImpresora::nombre() {
    return "Impresora";
}