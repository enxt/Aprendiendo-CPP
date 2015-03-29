#include <iostream>
#include <cstring>
#include "funciones.h"

using namespace std;

/**
 * Se encarga de capturar la variable con el nombre y la etiqueta indicada de la entrada estandard
 * var          puntero de la variable a recoger
 * varPrompt    el texto a mostrar para pedir el dato
 * exitOnEmpty  indica si hay que salir del programa cuando el usuario deje este dato en blanco (Nombre)
 * maxLength    longitud máxima del dato a pedir
 * isNumber     si hay que comprobar que se trata de un número
 */
void getVariable(string *var, const string &varPrompt, bool exitOnEmpty, int maxLength, bool isNumber) {
	char _var[maxLength];
	bool get = true;
	do {
		cout << varPrompt << ": ";      // Pido el dato
		cin.getline(_var, maxLength);   // Recojo la entrada estandard en _var
		
		// Si es un campo con el que se sale cuando está vacío y la cadena es de longitud 0
		if(exitOnEmpty && (!cin || strlen(_var) == 0)) {
			*var = string(); // Asigno a var una cadena vacía
			get = false; // Para salir del bucle
		}
		else if(strlen(_var) > 0) {
			*var = string(_var); // Paso el array a cadena asignadoselo a var
			if((isNumber && isNumeric(var)) || (!isNumber && isNameWord(var))) {
			    get = false; // Para salir del bucle
			}
		}
	}
	while(get);
	
	cin.clear();
}


/**
 * Comprueba que el puntero *cadena contenga única y exclusivamente digitos
 */
bool isNumeric(string *cadena) {
    size_t posicion = (*cadena).find_first_not_of("0123456789");
    return (posicion == string::npos); // string::npos nos indica que no hay coincidencias
}

/**
 * Comprueba que el puntero *cadena contenga caracteres que puedan ir incluidos en un nombre o apellido
 */
bool isNameWord(string * cadena) {
    size_t posicion = (*cadena).find_first_not_of("abcdefghijklmnñopqrstuvwxyzABCDEFGHIJKLMNÑOPQRSTUVWXYZºªáéíóúàèìòùäëïöüçÇ");
    return (posicion == string::npos); // string::npos nos indica que no hay coincidencias
}