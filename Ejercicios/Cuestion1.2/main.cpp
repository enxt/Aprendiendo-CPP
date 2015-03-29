#include <iostream>
#include <string>
#include "funciones.h"

using namespace std;

//char muestraMenu(int* numero, string resultado);
//void getNumero(int* numero);

int main(int argc, char* argv[]) {
    
    char opcion;
    int numero;
    string resultado("");
    
    while(true) {
        opcion = muestraMenu(&numero, resultado);
        resultado = "";
        switch(opcion) {
            case 's':
                return 0; // Salimos del switch y del while
                break;
            case 'n':
                getNumero(&numero);
                break;
            case 'p':
                if(par_impar(&numero)) resultado = "El número es par";
                else resultado = "El número es impar";
                break;
            case 'g':
                if(grande(&numero)) resultado = "El número es grande";
                else resultado = "El número NO número es grande";
                break;
            case 'o':
                if(positivo(&numero)) resultado = "El número es positivo";
                else resultado = "El número es negativo";
                break;
            case 'd':
                if(divisible5(&numero)) resultado = "Es divisible por 5";
                else resultado = "El número NO es divisible por 5";
                break;
            default:
                break;
        }
    }

    return 0;
}



