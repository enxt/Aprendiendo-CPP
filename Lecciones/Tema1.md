##1.- Revisión de la programación básica en C++

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


##2.- Tipos elementales

#### Consideraciones Sintácticas Generales

**Comentarios:**

* Un fragmento de texto: /* ··· */
* Una sola línea de texto: //

**Separador de instrucciones:** ;

**Instrucciones compuestas:** { . . . }

 { Inst1; Inst2; ...}

**Nombres de los identificadores:**

Se distingue entre mayúsculas y minúsculas: ```Dato```  es distinto de ```dato```.

* Longitud: entre 1 y 32 caracteres.
* Primer carácter: una letra o un subrayado.
* Resto de los caracteres: letras, números o subrayados.

El tipo de los identificadores se escribe delante del nombre: ```int dato;``` 


#### Tipos básicos:

**char**: caracteres y cualquier cantidad de 8 bits.
**int**: cantidades enteras.
**float**: números reales.
**double**: números reales más grandes.
**bool : **booleano
**valores lógicos** (true / false).
**void**: nada (usada para indicar que una función no devuelve nada)

Según la máquina y el compilador que se utilice los tipos primitivos ocupan un determinado tamaño en memoria. La siguiente lista ilustra el número de bits que ocupan los distintos tipos primitivos en un PC de la familia 386 con gcc.

 char: 8 bits
 short: 16 bits
 int: 32 bits
 float: 32 bit
 double: 64 bits


**Modificadores de tipos:** unsigned, short y long

Los modificadores condicionan el rango de valores que puede tomar una variable
del tipo correspondiente. Para los tamaños especificados en la lista anterior tendríamos:
****
unsigned char: 0 a 255
unsigned int: 0 a 65535
short int:-32768 a 32767
long int:-2147483648 a 2147483647
unsigned long int: 0 a 4294967295
long double: 1.7E-308 a 1.7E+308

#### Declaración de Variables:

lista variables es uno o más identificadores separados por comas.
**Ejemplos:**
i_nt i, j, l;_
_unsigned int valor;_
_double variable1, variable2;_
**Variables Locales:**
Se declaran dentro del cuerpo de una función o de un bloque.
**void funcion()**
**{**

```cpp
	 int i;	
	 i = 0;	
	 ...	
	 if (i == 0) {	
		 char c;		
		 ...		
	 }	
```
**}**


#### Definición de Nuevos Tipos Simples

**Redefinición de tipos:** para dar nuevos nombres a un tipo
 typedef tipo nombre;

**Ejemplo**
_typedef char caracter;_
_caracter dato;_
**Tipos Enumerados**
enum nombre tipo { lista símbolos } lista variables;

**Ejemplo**
_enum colores { blanco, rojo, amarillo };_
_enum colores dato;_
_..._
_dato = rojo;_

#### Moldeadores de Tipo

Un dato almacenado en una variable de un cierto tipo puede necesitarse como un
dato de distinto tipo. Dos tipos son compatibles si es posible la conversión de uno
de otro:
 • Los tipos escalares son compatibles entre sí.
 • Los tipos reales son compatibles entre sí.
 • Los tipos reales no son compatibles con los escalares.
La operación de conversión se realiza con operadores de
moldeado: el nombre del tipo de dato al que se desea convertir,
entre paréntesis, colocado delante del dato a convertir.

#### Constantes e Literales

Se declaran con la palabra ```cpp const``` 
Se les asigna valor con el signo** =**
Los literales de tipo cadena se escriben entre **''**.
**Ejemplo**
_const int HorasDia = 24;_
_const int MinutosHora = 60;_
_const char Retorno = '\n';_
_int Minutos;_
_Minutos = HorasDia * MinutosHora;_
_const string Nombre = "pepe";_

#### Inicialización en la Declaración

Las variables pueden inicializarse cuando se declaran.
También pueden inicializarse arrays o estructuras.

**Ejemplo:**
_enum Meses {Ene, Feb, Mar, Abr, May, Jun, Jul,Ago, Sep, Oct, Nov, Dic};_
_const int DiasMes[] = {31, 29, 31, 30, 31, 30, 31,31,30, 31, 30, 31};_
_const int HorasDia = 24;_
_int HorasAbril = DiasMes[Abr] * HorasDia;_


#### Estructuras

struct nombre tipo {
 tipo nombre variable;
 tipo nombre variable;
 ...
} variables;

**Ejemplos**___struct tdireccion {_

```cpp
	 string calle;	
	 int numero;	
```
_};_
_tdireccion dir1;_
____**Acceso:**
_···_
_tdireccion nueva;_
_···_
_nueva.calle = "Castellana";_
_nueva.numero = 20;_
_···_#### Arrays
__tipo nombre[tamañoN]...[tamaño1];

__**Ejemplos:**_char nombre[20];_
