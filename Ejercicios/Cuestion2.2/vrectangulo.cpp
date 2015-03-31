#include <iostream>
#include "vrectangulo.h"

using namespace std;

VecRect::VecRect(int valor) {

    if(valor > 20) {
        std::cerr << "No se pudo crear los rectángulos.\nSaliendo." << endl;
        total = 0;
    }
    else {
        array_rect = new Rectangulo*[valor];
        for(int i = 0; i < valor; i++) {
            array_rect[i] = new Rectangulo();
        }
        
        total = valor;
    }
}

VecRect::~VecRect() {
    for(int i = 0; i < total; i++)
        delete array_rect[i];
    delete [] array_rect;
}

void VecRect::presentaDatos(int i) {
    cout << endl << "Información para la posición: " << i << endl;
    array_rect[i]->printInformacion("");
}

void VecRect::asignaDatos(int i, float Vlargo, float Vancho) {
    array_rect[i] = new Rectangulo(Vlargo, Vancho);
}