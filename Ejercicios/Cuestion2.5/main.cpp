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
    articulos[3] = new CPortatil(20, 520, "Core i3", 3.9);
    articulos[4] = new CImpresora(4, 150, "LPT");
    articulos[5] = new COrdenador(2, 250, "Core i3");
    articulos[6] = new COrdenador(4, 50, "Core i5");
    articulos[7] = new CPortatil(5, 1222, "Core i5", 1.2);
    articulos[8] = new COrdenador(20, 1110, "Core i 20");
    articulos[9] = new CImpresora(4, 50, "USB");
    articulos[3] = new CImpresora(4, 50, "USB");
    articulos[10] = new COrdenador(5, 800, "Core i7");
    articulos[11] = new CPortatil(2, 1200, "Core i5", 2.2);
    articulos[12] = new CSobremesa(3, 500, "Core i7", "Sony 20''");
    articulos[13] = new CImpresora(4, 50, "USB");
    articulos[14] = new CPortatil(77, 755, "Core i5", 2.2);
    articulos[15] = new CPortatil(1, 510, "AMD", 2.3);
    articulos[16] = new CSobremesa(5, 50, "Core i5", "Dell 22''");
    articulos[17] = new CImpresora(6, 150, "USB");
    articulos[18] = new CSobremesa(74, 50, "Core i5", "NEC 2132");
    articulos[19] = new CImpresora(7, 750, "USB");
    articulos[13] = new CPortatil(78, 650, "Core i5", 5.5);




   for(int i = 0; i < 100; i++) {
        if(articulos[i] != NULL) {
            (articulos[i])->VisualizarFicha();
            cout << endl;
        }
    }

    delete articulos;

    return 0;
}