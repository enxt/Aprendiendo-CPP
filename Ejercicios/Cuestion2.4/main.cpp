#include <iostream>
#include "cordenador.h"
#include "cportatil.h"
#include "csobremesa.h"
#include "cimpresora.h"

using namespace std;

int main(int argc, char * argv[]) {

    //CArticulo * articulo = new CArticulo(2, 2.2);
    COrdenador * ordenador = new COrdenador(5, 800, "Core i7");
    CPortatil * portatil = new CPortatil(2, 1200, "Core i5", 2.2);
    CSobremesa * sobremesa = new CSobremesa(3, 500, "Core i7", "Sony 20''");
    CImpresora * impresora = new CImpresora(4, 50, "USB");


    //articulo->VisualizarFicha();
    //cout << endl;
    ordenador->VisualizarFicha();
    cout << endl;
    portatil->VisualizarFicha();
    cout << endl;
    sobremesa->VisualizarFicha();
    cout << endl;
    impresora->VisualizarFicha();

    delete ordenador;
    delete portatil;
    delete sobremesa;
    delete impresora;

    return 0;
}