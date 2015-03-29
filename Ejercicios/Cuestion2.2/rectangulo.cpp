#include <iostream>
#include "rectangulo.h"

using namespace std;

Rectangulo::Rectangulo() {
    this->alto = 1;
    this->ancho = 1;
}

Rectangulo::Rectangulo(int alto, int ancho) {
    this->alto = alto;
    this->ancho = ancho;
}

int Rectangulo::leer_alto() {
    return alto;
}

int Rectangulo::leer_ancho() {
    return ancho;
}

int Rectangulo::area() {
    return alto *ancho;
}

// En el enunciado del ejercicio no se especifica que esta función
// devuelva el valor que calcula, de modo que el valor calculado lo
// asigno a la variable perim.
void Rectangulo::perimetro() {
    this->perim = 2*(alto + ancho);
}

bool Rectangulo::cuadrado() {
    return (alto==ancho);
}

void Rectangulo::printInformacion(const string &rectname) {
    perimetro();
    //cout << endl << "************** " << rectname << " **************" << endl;
    cout << "Perímetro: " << perim << endl;
    cout << "Área: " << area() << endl;
    
    cout << "Es un cuadrado: " << (cuadrado()?"Sí":"No") << endl;
    //cout << "************** " << rectname << " **************" << endl;
}