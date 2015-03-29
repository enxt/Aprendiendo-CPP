#include <iostream>
#include "rectangulo.h"

using namespace std;

int main(int argc, char * argv[]) {

    int alto;
    int ancho;
    char a;
    
    cout << "Introduzca el alto de rect1: ";
    cin >> alto;
    cin.get(a);
    
    cout << "Introduzca el ancho de rect1: ";
    cin >> ancho;
    cin.get(a);
    
    Rectangulo rect1(alto, ancho);
    
    cout << endl;
    
    cout << "Introduzca el alto de rect2: ";
    cin >> alto;
    cin.get(a);
    
    cout << "Introduzca el ancho de rect2: ";
    cin >> ancho;
    cin.get(a);
    
    Rectangulo *rect2 = new Rectangulo(ancho, alto);
    
    rect1.printInformacion("rect1");
    rect2->printInformacion("rect2");
    
    delete rect2;
    
    return 0;
}