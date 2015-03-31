#include <iostream>
#include "carticulo.h"
#include "cordenador.h"
#include "cportatil.h"

using namespace std;

int main(int argc, char * argv[]) {

    //CArticulo * articulo = new CArticulo(2, 2.2);
    COrdenador * ordenador = new COrdenador(5, 800, "Core i7");
    CPortatil * portatil = new CPortatil(2, 1200, "Core i5", 2.2);


    //articulo->VisualizarFicha();
    //cout << endl;
    ordenador->VisualizarFicha();
    cout << endl;
    portatil->VisualizarFicha();

    //delete articulo;

    return 0;
}