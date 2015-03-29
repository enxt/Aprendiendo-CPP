#include <iostream>
#include "vrectangulo.h"

using namespace std;

int main(int argc, char * argv[]) {

    int alto, ancho;
    int index;
    char c;
    
    VecRect *vr = new VecRect(10);
    
    if(vr->getTotal() == 0) return 1;
    
    cout << "Introduzca el indice del rectangulo que desee modificar: " << endl;
    cin >> index;
    cin.get(c);
    
    if(index < vr->getTotal()) {
        cout << "Introduzca el alto: ";
        cin >> alto;
        cin.get(c);
        
        cout << "Introduzca el ancho: ";
        cin >> ancho;
        cin.get(c);
        
        vr->asignaDatos(index, alto, ancho);
    }
    
    cout << "Tengo: " << vr->getTotal() << " rectangulos" << endl;
    for(int i = 0; i < vr->getTotal(); i++) {
        vr->presentaDatos(i);
    }
    
    return 0;
}