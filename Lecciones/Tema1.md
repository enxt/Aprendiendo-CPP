##Revisión de la programación básica en C++

#### Lenguaje de programación C++:

* Sucesor del lenguaje de propósito general C.
* Incorpora mecanismos de Programación Orientada a Objetos, lo que le permite construir programas:
  * claros,
  * extensibles
  * fáciles de mantener

**Estructura de los programas:**

La estructura del programa principal en C++ es la siguiente:

_directivas del preprocesador: comienzan por #_<br>
_declaración de importaciones (directivas #include)_<br>
_definición de constantes_<br>
_definición de tipos_


```cpp
int main(parámetros) // cabecera de la función principal
{
	 secuencia de instrucciones	
	 y declaraciones locales	
	 return 0; 	
}
```

**Ejemplo** de programa:

```cpp
#include <iostream>  // entrada/salida

using namespace std; // permite nombrar los elementos importados 
                     //sin cualificarlos std::	

int main(int argc, char* argv[])
{
	string S;	
	cout << "Hola mundo! \n" << "es el anio " << 2000 << "?" << endl;	
	cin >> S;	
	cout << S << endl;
}
```
