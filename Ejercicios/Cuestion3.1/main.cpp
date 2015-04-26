#include <iostream>
#include "ExceptionFueraDeRango.h"
#include "ExceptionDeDivisionEntreCero.h"

using namespace std;

int leeNumeroEnRango();
float leeNumerosDivision();

int main(int argc, char * argv[]) {
    int nrango;
    float ndivision;

    while(true) {
        try {
            nrango = leeNumeroEnRango();
            ndivision = leeNumerosDivision();
            break;
        }
        catch(ExceptionFueraDeRango& e) {
            cout << e.what() << endl;
        }
        catch(ExceptionDeDivisionEntreCero& e) {
            cout << e.what() << endl;
        }
    }

    cout << endl << "Los datos son correctos." << endl;
    cout << "El número: " << nrango << " está dentro del rango -100...100" << endl;
    cout << "El resultado de la división es: " << ndivision << endl;

    return 0;
}


int leeNumeroEnRango() {
    int numero;
    char p;

    cout << "Introduzca un número: ";
    cin >> numero;
    cin.get(p);

    if(numero < -100 || numero > 100)
        throw ExceptionFueraDeRango();

    return numero;
}

float leeNumerosDivision() {
    int dividendo, divisor;
    char p;

    cout << "Introduzca el dividendo: ";
    cin >> dividendo;
    cin.get(p);

    cout << "Introduzca el divisor: ";
    cin >> divisor;
    cin.get(p);

    if(divisor == 0)
        throw ExceptionDeDivisionEntreCero();

    return (float)dividendo/(float)divisor;
}

