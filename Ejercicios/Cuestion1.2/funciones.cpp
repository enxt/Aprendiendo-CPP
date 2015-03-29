#include <iostream>
#include "funciones.h"

/**
 * Comprueba si el número es par o impar, devuelve true si es par,
 * devuelve false is es impar
 */
bool par_impar(int* numero) {
    if(*numero%2 == 0) return true;
    
    return false;
}

/**
 * Comprueba que el número sea mayor a 1000 y devuelve true, si no, false
 */
bool grande(int* numero) {
    if(*numero > 1000) return true;
    
    return false;
}

/**
 * Comprueba si el número es positivo y en ese caso devuelve true, si no, false
 */
bool positivo(int* numero) {
    if(*numero >= 0) return true;
    
    return false;
}

/**
 * Si el numero es divisble por cinco, devuelve true, si no, devuelve false
 */
bool divisible5(int* numero) {
    if(*numero%5 == 0) return true;
    
    return false;
}

/**
 * Muestra el menú del programa.
 * número es un puntero al número sobre el que se realizarán las comprobaciones.
 * resultado es una cadena con el resultado de la comprobación realizada anteriormente
 */
char muestraMenu(int* numero, std::string resultado) {
    char opcion;
    char temp;
    std::cout << std::string(100 , '\n');
    
    if(resultado != "" && *numero)
        std::cout << "****\t" << resultado << "\t****" << std::endl;
        
    if(*numero)
        std::cout << "Número actual seleccionado: " << *numero << std::endl;
        
    std::cout << "Marque una opción:" << std::endl;
    std::cout << "\t'n' para introducir un nuevo numero" << std::endl;
    std::cout << "\t'p' para comprobar par o impar" << std::endl;
    std::cout << "\t'g' para comprobar si el numero es grande" << std::endl;
    std::cout << "\t'o' para comprobar si es positivo" << std::endl;
    std::cout << "\t'd' para comprobar si es divisible por 5" << std::endl;
    std::cout << "\t's' para salir" << std::endl << std::endl;

    std::cin >> opcion;
    std::cin.get(temp);
    return opcion;
}

/**
 * Asigna al puntero número el valor introducido por el usuario
 */
void getNumero(int* numero) {
    char temp;
    
    std::cout << "Introduzca el número: ";
    std::cin >> *numero;
    std::cin.get(temp);
}
