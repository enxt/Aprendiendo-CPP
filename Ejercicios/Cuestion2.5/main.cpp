#include <iostream>
#include "carticulo.h"
#include "cordenador.h"
#include "cportatil.h"
#include "csobremesa.h"
#include "cimpresora.h"

using namespace std;
int CArticulo::num = 0;

int main(int argc, char * argv[]) {

    CArticulo **articulos = new CArticulo*[100];

    articulos[0] = new COrdenador(5, 800, "Core i7");
    articulos[1] = new CPortatil(2, 1200, "Core i5", 2.2);
    articulos[2] = new CSobremesa(3, 500, "Core i7", "Sony 20''");
    articulos[3] = new CImpresora(4, 50, "USB");


    for(int i = 0; i < 100; i++) {
        if(articulos[i] != NULL) {
            (articulos[i])->VisualizarFicha();
            cout << endl;
        }
    }

    delete [] articulos;
    delete articulos;

    return 0;
}