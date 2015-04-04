##1.-Revisión de la programación básica en C++.

####1.1-Lenguaje de programación C++:

* Sucesor del lenguaje de propósito general C.
* Incorpora mecanismos de Programación Orientada a Objetos, lo que le permite construir programas:
	* claros,
	* extensibles
	* fáciles de mantener

**Estructura de los programas:**

La estructura del programa principal en C++ es la siguiente:

_directivas del preprocesador: comienzan por # _
_declaración de importaciones (directivas #include)_
_definición de constantes _
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
#include <iostream> // entrada/salida
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



##2.-Tipos elementales.

####2.1.-Consideraciones Sintácticas Generales

**Comentarios:**

* Un fragmento de texto: /* ··· */
* Una sola línea de texto: //

**Separador de instrucciones:** ;

**Instrucciones compuestas:** { . . . }

 { Inst1; Inst2; ...}

**Nombres de los identificadores:**

Se distingue entre mayúsculas y minúsculas: ```Dato``` es distinto de ```dato```.

* Longitud: entre 1 y 32 caracteres.
* Primer carácter: una letra o un subrayado.
* Resto de los caracteres: letras, números o subrayados.
* El tipo de los identificadores se escribe delante del nombre: ``` int dato;```


####2.2.-Tipos básicos:

* **char**: caracteres y cualquier cantidad de 8 bits.
* **int**: cantidades enteras.
* **float**: números reales.
* **double**: números reales más grandes.
* **bool**: booleano
* **valores lógicos** (true / false).
* **void**: nada (usada para indicar que una función no devuelve nada)

Según la máquina y el compilador que se utilice los tipos primitivos ocupan un determinado tamaño en memoria. La siguiente lista ilustra el número de bits que ocupan los distintos tipos primitivos en un PC de la familia 386 con gcc.

 * char: 8 bits
 * short: 16 bits
 * int: 32 bits
 * float: 32 bit
 * double: 64 bits


**Modificadores de tipos:** unsigned, short y long

Los modificadores condicionan el rango de valores que puede tomar una variable del tipo correspondiente. Para los tamaños especificados en la lista anterior tendríamos:

* unsigned char: 0 a 255
* unsigned int: 0 a 65535
* short int:-32768 a 32767
* long int:-2147483648 a 2147483647
* unsigned long int: 0 a 4294967295
* long double: 1.7E-308 a 1.7E+308

####2.3.-Declaración de Variables:

**_[modificadores]_ tipo lista variables;**

lista variables es uno o más identificadores separados por comas.

**Ejemplos:**
```cpp
int i, j, l;
unsigned int valor;
double variable1, variable2;
```
**Variables Locales:**

Se declaran dentro del cuerpo de una función o de un bloque.
```cpp
void funcion()
{
	 int i;	
	 i = 0;	
	 ...	
	 if (i == 0) {	
		 char c;		
		 ...		
	 }	
}
```


####2.4.-Definición de Nuevos Tipos Simples

**Redefinición de tipos:** para dar nuevos nombres a un tipo
``` typedef tipo nombre;```

**Ejemplo**
```cpp
typedef char caracter;
caracter dato;
```

**Tipos Enumerados**

```enum nombre tipo { lista símbolos } lista variables;```

**Ejemplo**
```cpp
enum colores { blanco, rojo, amarillo };
enum colores dato;
...
dato = rojo;
```

####2.5.-Moldeadores de Tipo

Un dato almacenado en una variable de un cierto tipo puede necesitarse como un dato de distinto tipo. Dos tipos son compatibles si es posible la conversión de uno de otro:

* Los tipos escalares son compatibles entre sí.
* Los tipos reales son compatibles entre sí.
* Los tipos reales no son compatibles con los escalares.

La operación de conversión se realiza con operadores de moldeado: el nombre del tipo de dato al que se desea convertir, entre paréntesis, colocado delante del dato a convertir.

####2.6.-Constantes e Literales

Se declaran con la palabra ```const```
Se les asigna valor con el signo **=**
Los literales de tipo cadena se escriben entre **''**.

**Ejemplo**
```cpp
const int HorasDia = 24;
const int MinutosHora = 60;
const char Retorno = '\n';
int Minutos;
Minutos = HorasDia * MinutosHora;
const string Nombre = "pepe";
```

####2.7.-Inicialización en la Declaración

Las variables pueden inicializarse cuando se declaran.
También pueden inicializarse arrays o estructuras.

**Ejemplo:**
```cpp
enum Meses {Ene, Feb, Mar, Abr, May, Jun, Jul,Ago, Sep, Oct, Nov, Dic};
const int DiasMes[] = {31, 29, 31, 30, 31, 30, 31,31,30, 31, 30, 31};
const int HorasDia = 24;
int HorasAbril = DiasMes[Abr] * HorasDia;
```


####2.8.- Tipos de Datos Estructurados: Estructuras

```cpp
struct nombre tipo {
 tipo nombre variable;
 tipo nombre variable;
 ...
} variables;
```

**Ejemplos**
```cpp
struct tdireccion {
	 string calle;
	 int numero;
};

tdireccion dir1;
```
**Acceso:**
```cpp
···
tdireccion nueva;
···
nueva.calle = "Castellana";
nueva.numero = 20;
...
```
####2.9.-Arrays
_tipo nombre[tamañoN]...[tamaño1];

**Ejemplos:**
```cpp
char nombre[20];
...
nombre[3] = 'a';
int matriz[4][2] = {1, 1 , 2, 4, 3, 9, 4, 16};
// matriz[0][0] = 1
// matriz[0][1] = 1
// matriz[1][0] = 2
// matriz[1][1] = 4
// ...
```


##3.-Construcciones elementales.

####3.1.-Funciones

**Estructura de una función:**
```cpp
tipo nombre ( lista de parámetros )
{
	(secuencia de instrucciones)
	return valor devuelto;
}
```

**Parámetros de entrada:** Se declaran a continuación del identificativo de la función, entre paréntesis, con el mismo formato que cualquier variable:

```cpp
void espera (int segundos)
```

**Parámetros por valor y por referencia: ** en los parámetros por referencia se antepone & en la declaración:
```cpp
void Cuadrado (int Factor, int &Resultado)
{
	Resultado = Factor * Factor;

}
···
int N;
Cuadrado(8,N); // Modifica N
```

**Parámetros de salida: ** valor devuelto por la función, que determina su tipo. Se especifica con **return**.
```cpp
int Cuadrado (int Factor)
{
	return Factor * Factor;
}
···
int N;
N = Cuadrado(8);
```

**Prototipos:** cabecera de la función seguida de ;


####3.2.-Instrucciones:

**Asignación**

```variable = expresión;```

**Operadores Aritméticos**

* \+ - * /% (función módulo)
* \++ operador incremento ```i++;``` equivale a ```i = i + 1;```
* \-- operador decremento

**Operadores Relacionales**

* \> >= < <=
* \== (igual)
* \!= (distinto)

**Operadores Lógicos**

* && (Y lógica)
* || (O lógica)
* ! (negación)


####3.3.-Instrucción condicional if

_if (expresion) instrucción;_

_if (expresion) instrucción;_
_else instrucción;_

_if (expresion) {_
	 secuencia de instrucciones
_}_
_else {_
	_secuencia de instrucciones_
_}_

**Ejemplo:**
```cpp
bool EsPar(int valor) {
	 if (valor% 2 == 0)	
		return true;	
	 else
		return false;	
}
```

####3.4.-Instrucción condicional switch

_switch ( variable ) {
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;case constante1:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;secuencia de instrucciones
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;break;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;case constante2:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;secuencia de instrucciones
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;break;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;default:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;secuencia de instrucciones
}_

**Ejemplo:**
```cpp
switch ( mes ) {
	 case 4:	
	 case 6:	
	 case 9:	
	 case 11:	
		 num_dias = 30;
		 break;		
	 case 2:	
		 num_dias = 28;		
		 break;
	 default:	
		 num_dias = 31;		
}
```
####3.5.-Instrucción iterativa while

_while (condición) instrucción;_

**Ejemplo:**

```cpp
while ((c != a[i]) && (i < 20)) {
	 i++;

}
```

#### Instrucción iterativa do/while

_do {
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;secuencia de instrucciones;
} while (condicion);_

**Ejemplo:**
```cpp
do {
	 presentar_datos(a[i]);
	 i++;
} while (i < 100);
```

##4.-Uso de punteros.

####4.1.- Uso de punteros
Una estructura de datos en C++, como puede ser una matriz o un registro (struct), puede tener cualquier tamaño, con la única limitación de la memoria libre en el sistema. Sin embargo, en ocasiones, la asignación estática de memoria que hemos utilizado hasta ahora, no es la más adecuada, por ejemplo, cuando no se conoce la cantidad de espacio que se necesita. En estos casos podemos usar asignación dinámica de memoria, que manejamos mediante punteros.


* Un puntero es una variable que contiene una dirección de memoria, la	dirección de un valor de un cierto tipo denominado tipo base.
* Como cualquier otra variable se declara, se le asignan valores, se usa en expresiones, etc. La diferencia fundamental entre un puntero y cualquier otra variable consiste en que aquél no almacena un valor de un cierto tipo, como puede ser un número o una cadena, sino que	 contiene una dirección de memoria en la que se almacena una cierta	información.
* Los punteros pueden ser de cualquiera de los tipos que hemos visto. Por ejemplo, si en un puntero queremos almacenar la dirección de memoria donde se almacena un entero, el puntero será de tipo int.

####4.2.-Declaración de un puntero

* La declaración de un puntero es prácticamente idéntica a la declaración de una variable del tipo al que va a apuntar el puntero, con la única diferencia de que detrás del tipo colocaremos el operador \** indicará al compilador que lo que estamos declarando no es una variable de ese tipo sino un puntero. Detrás del tipo se coloca el operador \**

**Ejemplo**
```cpp
int * PNumero // puntero a valor de tipo int
```

* Al declarar un puntero, éste toma un valor inicial representado por la constante **NULL**, indicando que el puntero no tiene actualmente dirección alguna, o lo que es lo mismo, que no apunta a ningún objeto. Este valor es asignado a todo puntero que no se declara de forma local, por ejemplo, en el interior de una función, en cuyo caso puede tomar cualquier valor arbitrario.
* Para indicar que un puntero no contiene ninguna dirección se le asigna la constante NULL, compatible con todos los tipos.
* Antes de usar un puntero para manipular el valor al que se supone que está apuntando, es necesario comprobar si realmente el puntero contiene alguna dirección, o si está sin inicializar porque es igual a NULL, ya que en este caso se generaría un error de ejecución.
* C++ nos permite realizar ciertas conversiones entre tipos, operación que se usa habitualmente con punteros. Si deseamos declarar un puntero que en principio no va a apuntar a ningún tipo definido, usaremos como tipo la palabra reservada **void**.

####4.3.- Direcciones de Memoria

La memoria del computador está dividida en celdillas de un byte a cada una de las cuales le corresponde una dirección. Cuando declaramos una variable en nuestro programa, especificando un identificador y un tipo, estamos reservando para este programa un conjunto de celdillas de memoria. El número de celdillas vendrá determinado por la ocupación del tipo que hayamos elegido, mientras que el acceso al contenido de dichas celdillas se realizará mediante el identificador, que puede verse como el nombre que le ponemos a ese conjunto de celdillas de memoria.
* Toda dato del programa tiene asignada una o más direcciones de memoria.
*  La declaración de una variable estática reserva automáticamente una serie de direcciones de memoria, en las que se almacenará.
* Podemos conocer la dirección de una variable anteponiendo el operador **&** al nombre de la variables.
```cpp
int Numero = 10;
int* PNumero = &Numero;
```

####4.4.- Referencia al valor de un puntero

La finalidad principal de un puntero es, obviamente, permitirnos manipular la información almacenada en la dirección a la que apunta.
* Para acceder a los datos contenidos en la dirección de memoria apuntado por un puntero se antepone el operador * (operador de indirección) al identificador del puntero.

**Ejemplo:**
```cpp
	int Numero = 10;	
	int* PNumero = &Numero;	
	// Mostramos el valor apuntado por PNumero	
	cout << "*PNumero=" << *PNumero << endl;	
	// Usamos el puntero para modificar el valor	
	*PNumero = 5; // Numero tambien vale 5	
	cout << "Numero=" << Numero << endl;	
```

* Si usamos el operador de indirección con un puntero que no contiene una dirección, sino NULL, se producirá una excepción (error) que causará la parada del programa.
* Podemos acceder a los miembros de una estructura apuntada por un puntero mediante el operador −>

**Ejemplo**
```cpp
struct tdireccion {
	string calle;
	int numero;
};
tdireccion dir1;
tdireccion* pdir1;
dir1.calle = "Castellana";
pdir1 = &dir1;
pdir1−>calle = "Castellana";
//es equivalente a (*pdir).calle
```

####4.5.- Asignación Dinámica

Todas las variables que declaramos en un programa se asignan estáticamente, es decir, en el momento en que se ejecuta el programa todas las variables se crean, y en el momento en que el programa termina se destruyen automáticamente, liberándose la memoria que ocupaban.
* Aunque los punteros pueden usarse para acceder a direcciones de variables estáticas, su principal utilidad es la asignación dinámica de memoria.
* La declaración de un puntero no lo asocia con ninguna dirección de memoria. Para poder usarlo tendremos que asignar un bloque de memoria y obtener su dirección.
* Es posible solicitar memoria al sistema en tiempo de ejecución. El espacio para asignación dinámica se extiende a lo largo de toda la memoria de que disponga el computador durante la ejecución del programa y éste puede solicitar, en cualquier momento, bloques de ese espacio de memoria de forma dinámica, es decir, cuando lo necesite.
* La memoria asignada dinámicamente se debe liberar cuando ya no es
precisa para que pueda ser reutilizada.

**Los operadores **

El operador **new** reserva en ejecución un espacio de memoria cuyo tamaño viene determinado por el tipo del puntero con que se invoca. A diferencia de lo que ocurre con el espacio de memoria estático, la memoria asignada por **new** está libre al comienzo del programa y sólo se reserva cuando se realiza la llamada a este operador. Esto nos permite ocupar en cada momento, sólo la porción de memoria necesaria, por lo que se denomina asignación dinámica.	
	
La liberación de la memoria reservada dinámicamente, tampoco se libera automáticamente. Para llevar a cabo esta operación utilizaremos el operador 	delete, al que pasaremos como parámetro el puntero que contiene la dirección de memoria del bloque a liberar y que es, habitualmente, el mismo que se usó en la asignación con el operador **new**. 

```cpp
int * PNumero;	
PNumero = new int;	
// Mostramos el valor apuntado por PNumero	
cout << "*PNumero=" << *PNumero << endl;	
//Lo modificamos y lo volvemos a mostrar	
*PNumero = 5;	
cout << "*PNumero=" << *PNumero << endl;	
delete PNumero;	
```	
Al asignar memoria con el operador **new** es posible especificar un valor inicial facilitándolo entre paréntesis detrás del tipo. De esta forma, la instrucción ```PNumero = new int(5)``` además de asignar memoria para un entero, inicializa ese bloque con el valor dado.	

* A veces el bloque de memoria que deseemos asignar no constará de un solo elemento sino de una serie de ellos. Por ejemplo, podemos desear reservar memoria para 10000 enteros o para un cierto número de enteros que se calcule a lo largo de la ejecución. Para estos casos disponemos de los mismos operadores anteriores, new y delete, pero acompañados de corchetes que indican el tamaño a reservar.

**Los operadores new[] y delete[]**

* El operador **new[]** permite especificar (entre corchetes, a continuación del tipo), el número de elementos del tipo base que se desean crear.
* El acceso a las posiciones reservadas se realiza como si se tratase de una matriz.
* El operador **delete[]** permite indicar que lo que se libera es una matriz, colocando unos corchetes vac´ıos a continuación del operador.

```cpp
int * PNumero;
PNumero = new int[5000];
// Inicializamos y Mostrados dos elementos
PNumero[1] = 5;
PNumero[7] = 10;
cout << "PNumero[1]=" << PNumero[1] << "\nPNumero[7]=" << PNumero[7] << endl;
delete [] PNumero;
```
####4.6.- Precauciones con la asignación dinámica

Al igual que ocurre con cualquier puntero, antes de hacer uso de un bloque de memoria asignado dinámicamente hay que estar seguros de que dicho bloque existe. No debemos hacer referencia al contenido antes de asignar el bloque o después de haberlo liberado, ya que en estos casos se producirá una excepción que detendrá la ejecución del programa.

Supongamos por ejemplo, que hemos reservado un área de memoria a la que podemos acceder mediante dos punteros. Si liberamos el bloque con un puntero distinto del que se usó para la asignación o bien no se liberará toda la memoria que se reservó o se corre el riesgo aún mayor de liberar zonas de memoria ajenas a nuestro código, lo que normalmente terminará en una interrupción del programa o incluso en un bloqueo del sistema.

```cpp
main()
{
	int * PNumero; // Puntero a int	
	char * PCaracter; // Puntero a char	
	PNumero = new int; // Asignamos memoria para un int	
	*PNumero = 30000; // Asignamos un valor al int	
	PCaracter = (char *) PNumero; // PCaracter apunta al mismo valor	
	// Mostramos el contenido de los punteros	
	cout << "*PNumero="<< *PNumero <<	"\nPCaracter=" << *PCaracter << endl;	
	delete PNumero; // Liberamos la memoria asignada	
	// !!! PCaracter apunta a una zona de memoria liberada	
	*PCaracter = 'x';	
	return 0;	
}
```

####4.7.- Conversiones y Punteros

Los punteros son variables que almacenan direcciones de memoria. Desde
este punto de vista todos los punteros son iguales. Sin embargo, un puntero contiene la dirección de memoria de un dato de un cierto tipo y el puntero almacena información sobre dicho tipo.
La conversión de un puntero de un tipo a otro distinto es algo muy usado,
ya que nos permite acceder a la información con una estructura diferente.
```cpp
#include <iostream.h>
struct TFecha { // Estructura TFecha
	int Dia, Mes, Anio;	
};
typedef TFecha* PFecha; // PFecha es un nuevo tipo, puntero a TFecha
main()
{
	TFecha Hoy; // Hoy es de tipo TFecha	
	void * PHoy; // PHoy es un puntero genérico	
	PHoy = &Hoy; // Asignamos a PHoy la dirección de Hoy
	// El moldeado (PFecha )Hoy nos permite acceder a
	// los miembros de la estructura mediante el puntero	
	((PFecha )PHoy)->Dia = 4; // El operador de selección	
	((PFecha )PHoy)->Mes = 2; // no es un punto, sino los
	((PFecha )PHoy)->Anio = 1999; // caracteres ->	
	cout << Hoy.Dia << "/" << 	Hoy.Mes + "/" <<	 Hoy.Anio << endl; 	return 0;	
}
```


##5.- Módulos.

El código de un programa puede repartirse en más de un archivo o modulo, con objeto de

* Mantener el nivel de complejidad adecuado.
* Reutilizar código.

Un módulo es una unidad de compilación independiente. Algunos usos:

* **Módulos de tipos de datos:**
Un módulo puede encapsular las declaraciones de tipo junto con sus operaciones (creación, acceso, modificación).

* **Módulos funcionales:**
Un módulo puede enriquecer el repertorio de operaciones sobre tipos de datos ya definidos.
La descomposición modular debe guiarse por la facilidad de mantenimiento y la de reusabilidad.

En C++ se distinguen módulos de código (extensión cpp) y módulos de cabecera (extensión h), para especificar que elementos podrán ser usados por otros programas o módulos (interface del módulo).
El módulo cabecera tiene el mismo nombre que el de código (distinta extensión) y contiene las declaraciones de tipo, constantes y variables públicas, y un prototipo (cabecera terminada en ;) de las funciones públicas.
Este papel del módulo cabecera no lo impone el compilador, sino que es una convención. El módulo de código contiene la implementación de las funciones especificadas en el módulo cabecera, así como declaraciones y funciones privadas.

El módulo de código comienza incluyendo su módulo cabecera(directiva #include).
El proceso de compilación construye archivos binarios intermedios con extensión OBJ a partir de las cabeceras (H o HPP) y los módulos fuente (CPP).
A partir de los archivos OBJ el linkador resuelve las referencias cruzadas y genera el ejecutable (EXE) .


##6.- El preprocesador de C++.

####6.1.- El Papel del Preprocesador

El preprocesdor se ejecuta implícitamente cuando compilamos. El símbolo **#** actúa como una señal que indica al preprocesador que lo que sigue es una directiva (comando de lectura) del preprocesador. 

**Ejemplo:**
```cpp
#include <iostream.h >
```
le dice al preprocesador que incluya el texto contenido en el fichero iostream.h.
Los paréntesis angulares indican que el fichero está en el directorio definido por el camino del sistema.

Un segundo uso de la directiva o comando include consiste en escribir el nombre del fichero entre comillas, indicando que debe buscarse en el directorio en curso.

**Ejemplo:**
```cpp
#include "mimodulo.h"
```
A continuación del reemplazamiento de texto realizado por el preprocesador, viene la compilación. El proceso de compilación construye ficheros intermedios con extensión .obj a partir de las cabeceras (.h o .hpp) y los modulos fuente (.cpp). 
Se crea un fichero objeto por cada fichero fuente (.cpp) definido en nuestro 
programa. Otros se incluyen al incluir funcionalidades preexistentes. Una vez que estos ficheros binarios intermedios (no ejecutables) se han creado, se invoca al enlazador (linkador) para resolver las referencias como las llamadas a funciones y los resultados de programas ejecutables. 

####6.2.- El Preprocesador en la Construcción de Aplicaciones
El preprocesador mantiene algunos de sus usos históricos, como la inclusión de los ficheros cabecera (.h). Los ficheros cabeceras suelen utilizarse para especificar el interface a clases o funciones a las que hacen referencia las declaraciones.
C++ es un lenguaje fuertemente tipado, lo que significa que la declaración
de clases y funciones, así como la de datos debe aparecer anter de usarlas.
Las declaraciones también actuan como un interface que filtra los tipos de
datos que utilizará la aplicación. Puesto que las cabeceras pueden incluirse,
y las declaraciones deben aparecer antes de las definiciones, a las cabeceras
se les asigna este papel. Este papel no lo impone el compilador, sino que
es una convención que los programadores deben aprender a emplear con la experiencia.

####6.3.- Otras Directivas del preprocesador

Existen varias directivas que el preprocesador reconoce, unas más intuitivas que otras.

**Uso de #define y #undef**

La directiva **#define** se usa para indicar al preprocesador que una palabra es reconocible o tiene un valor. Una vez definida puede usarse en comprobaciones simples.

**Ejemplo:**
```cpp
#define DEBUG
```
crea la palabra reconocible DEBUG qeu el preprocesador puede usar en
test condicionales. La directiva **#undef** tiene el efecto contrario. Mientras los test condicionales sobre DEBUG se evaluan a cierto si se ha usando **#define**,
con **#undef ** se evaluan a falso.

**Uso de #ifdef, #else y #endif**

Las directivas **#ifdef, #else, #endif** se usan conjuntamente. Siempre hay
que usar #endif para terminar una directiva **#ifdef**, pero el uso de **#else** es opcional.
Cuando se declara un fichero cabecera el objetivo es declara las funciones,
clases y otros elementos que pueda necesitarse incluir en más de un módulo.
Si el código se incluyera en varios ficheros de código de programa, cuando se ejecuta el compilador colocaría todos los elementos en la tabla de símbolos.

Esto podría producir conflictos de nombres, ya que viene del mismo fichero
cabecera. Una técnica para evitar esto consiste en envolver el código del fichero cabecera en una directiva del preprocesador que actua como filtro. 

**Ejemplo:**
```cpp
// PARMSWAP.H_
#ifndef _PARMSWAP_H_
#define _PARMSWAP_H_
#define SWAP(T)
inline void Swap( T& a, T& b)
{T t = a; a = b; b = t}
#endif
```


##7.- Ejemplo de programa en C++:operadores de entrada-salida y otros.

Vamos a considerar un sencillo ejemplo de programa completo en C++, que nos va a permitir introducir los opradores de entrada-salida, muy cómodo de utilizar en C++, y otros conceptos como los espacios de nombres:

```cpp
#include <iostream>

using namespace std;
int main()
{
	string nombre;
	char apellidos[80];
	char c;

	cout << "Introduce tu nombre" << endl;
	cin >> nombre;
	cin.get(c);
	cout << "Tu nombre tiene " << nombre.length() << " caracteres" << endl;
	cout << "Introduce tus apellidos:" << endl;
	cin.getline(apellidos, 80);
	cout << "te llamas " << nombre << " " << apellidos << endl;
}
```

* **#include <iostream>**
Esta directiva hace que el preprocesador añada los contenidos del archivo iostream al programa. Contiene las declaraciones de los identificadores **cout** y **cin** y de los operadores **<<** y **>>**.

* **using namespace std;**
Todo identificador C++ tiene un ámbito que determina el espacio en que es reconocido por el compilador. Mediante los ámbitos con nombre o **namespaces**, podemos crear ámbitos en los cuales es posible definir tipos, declarar variables, etc., sin que ese ámbito sea el de una clase o el de una función. Los identificadores de ese ámbito pueden ser usados desde cualquier punto de la aplicación siempre que se cualifiquen de forma apropiada, indicando el nombre del ámbito. Los **namespaces** son especialmente útiles cuando una aplicación está compuesta de diversos módulos en cuya codificación han intervenido varias personas, pudiendo darse el caso de que en algunos de ellos existan identificadores globales con nombres coincidentes, lo que causaría los errores correspondientes durante la compilación.

Para usar los identificadores definidos en el ámbito de un namespace se usa la directiva **using namespace**, como en el ejemplo.
En este caso, std es el espacio de nombres donde está definida la libreria de clases estándar ANSI C++.

* **string nombre;**
Declara una variable de tipo cadena (**string**). Estas variables almacenan secuencias de caracteres que se procesan conjuntamente. Este tipo string, que en realidad es una clase predefinida, permite utilizar una serie de operaciones sobre cadenas, como consultar su longitud (**length**), etc.

* **cout << "Introduce tu nombre << endl;**
Es una instrucción de salida que hace que se muestre por pantalla la cadena que está entre comillas. El identificador **cout** es un objeto predeterminado que representa el flujo de salida estándar en C++, que es la pantalla. El operador **<<** se conoce como operador de salida y envía al objeto especificada a su izquierda ( en el ejemplo **cout** ) el contenido de la variable especificada a su derecha. Se pueden encadenar una serie de operadores de este tipo, como en la instrucción:
**cout << "Tu nombre tiene " << nombre.length() << " caracteres" << endl;**

* **endl** es un dato predefinido que corresponde a un salto de línea.

* **cin << nombre;**
Es una instrucción de entrada que hace que los datos introducidos por teclado se 
transmitan a la variable especificada, en este caso _nombre_. Este operador permite leer una palabra, pero no secuencias de palabras. Este operador lee hasta encontrar un espacio en blanco, un salto de línea o un tabulador. El limitador que se encuentre no se lee.

* **cin.get(c);**
get asocia el caracter leido a su argumento. En este caso lo utilizamos para limpiar el salto de línea teclado al terminar el nombre.

* **cin.getline(apellidos, 80);**
*Esta línea invoca a la función getline() que lee los caracteres que se teclean y los guarda en la variable "apellidos". La lectura se termina cuando se encuentra el caracter de salto de linea (ENTER) o cuando se hayan leido el número de caracteres especificado (80 en este caso) menos 1. El caracter de salto de linea se lee pero no se almacena. Esta instrucción permite leer secuencias de caracteres formadas por más de una palabra. Hay que observar que la variable sobre la que se lee (apellidos) no es un string, sino un array de caracteres.



##8.- La clase string: tratamiento de cadenas.

####8.1.- La clase string: tratamiento de cadenas

Para utilizar los objetos de tipo string debemos incluir el archivo de cabecera <**string**> de la biblioteca estándar de C++.

Un objeto string puede inicializarse de distintas formas:
```cpp
string s1( "Adios");
string s1( 8, 'x'); // cadena de 8 caracteres 'x'
string mes = "marzo";
```

A diferencia de las cadenas char * de C, los objetos string no necesariamente 
terminan en nulo. La longitud de un string se almacena en el objeto string y se puede recuperar con la función miembro **length**. El operador de subíndice **[ ]** se puede utilizar para acceder a los caracteres individuales, el primero de los cuales corresponde al subíndice 0.

La mayoría de las funciones miembro de la clase string toman como argumentos una posición de subíndice inicial y el número de caracteres sobre los que operan. Si se pasan valores mayores que los de la cadena se recortan automáticamente.
El operador de extracción de flujo (>>) está sobrecargado para soportar objetos de tipo string. Consideremos algunas operaciones para objetos de tipo string:

* **Asignación**
Existen distintas posibilidades para realiza la asignación. Por ejemplo, si s1 y s2 son objetos de la clase string
```cpp
string s1,s2;
...
s2 = s1;
```
asigna s1 a s2. Otra posibilidad es utilizar la función miembro **assign**: ```s3.assign( s1 );``` copia s1 a s3. La clase string también proporciona una versión sobrecargada (igual nombre y distinto número de argumentos) de la función assign, que copia un número específico de caracteres: ```cadena.assign(s, comienzo, numCaracteres);```

Además, las cadenas pueden tomar valores en la inicialización:
```cpp
string s1( "rojo" );
string s2( " azul" + s1);
```

* **Acceso a elementos**
Puede realizarse con el operador de subíndice: ```s2[0] = s3[2] = 'r';```
Y también con la función at_```c = s3.at(posicion);```

* **Concatenación**
La concatenación puede realizarse con el operador de suma + sobrecargado: ```s3 += "verde";```
También con la función **append**: ```s1.append("hola");```
Otra versión de append se usa en: ```s5.append(s1, 4, s1.size() );``` que agrega a s5 los caracteres desde el cuarto al último elemento. La función size devuelve el número de caracteres del objeto string s1.

* **Comparación**
Los operados relacionales '==', '<', '>', '<=', '>=', '!=', están sobrecargados para trabajar con objetos de tipo string, devolviendo valores de tipo bool, como en: ```s1 == z1```
La clase string también proporciona la función **compare** que devuelve 0 si los objetos son equivalentes, un número positivo si el primero es lexicográficamente mayor que el segundo, y un número negativo si es menor: ```int f = s1.compare( s2 );```
Otra versión sobrecargada de **compare** especifica el subíndice inicial de z1 que se utiliza en la comparación. El segundo argumento especifica la parte de z1 que se comparará. ```int f = z1.compare(0, s2.size(), s2 );```

* **Subcadenas**
La clase string proporciona la función **substr** para recuperar una subcadena de un objeto string. El primer argumento especifica el subíndice inicial de la subcadena y el último el número de caracteres a extraer. ```cout << s.substr(7, 5) << endl;```

* **Intercambio**
La clase string proporciona la función **swap** para intercambiar objetos string: ```primera.swap( segunda );```

* **Características**
La función **resize** puede usarse para incrementar la longitud: ```s.resize( s.length() + 10 );```

* **Localización de Caracteres**
Las funciones **find** de la clase string permiten encontrar cadenas y caracteres: ```s.find("subarbol");``` trata de encontrar la cadena ''subarbol'' en el objeto string s. Si la encuentra devuelve el subíndice de la posición inicial de la misma. Si no la encuentra devuelve el valor ```string::npos```, una constante de la clase string.
La función **rfind** busca la cadena comenzando desde el final: ```s.rfind("subarbol");```
La función **find_first_of** busca la primera aparición de cualquier caracter de la cadena parámetro: ```s.find_first_of( "hpxw" );```
Con **find_last_of**, la búsqueda se realiza desde el final de s. La función**find_first_not_of** se usa para buscar el primer carácter que no esté contenido en la subcadena parámetro, mientras que **find_last_not_of** busca el último carácter no contenido en la subcadena parámetro.

* **Reemplazo de Caracteres**
Algunas funciones para reemplazo y eliminación de caracteres son las siguientes: ```s.erase( 71 );``` elimina todo lo que hay desde el elemento 71 hasta el final de s. ```s.replace( n, num_reemp, s2);```
La función replace reemplaza en s los caracteres desde el subíndice indicado por el primer argumento, hasta la longitud especificada por el segundo, por la cadena de reemplazo s2.

* **Inserción de Caracteres**
Las funciones insert permiten insertar caracteres en una cadena: ```s1.insert(7, s2);``` inserta el objeto s2 antes del elemento 7. ```s3.insert(3, s4, 0, string::npos);``` inserta s4 antes del tercer elemento de s3. Los dos últimos argumento especifican el elemento inicial de s4 y el número de caracteres de s4 que se deberán insertar.

* **Conversión a Cadenas char ***
La función c str() convierte un string a un array de caracteres terminado en nulo:  ```cout << s.c_str();```



##9.- La clase fstream: flujos de datos y archivos.

####9.1.- La clase fstream: flujos de datos y archivos

C++ utiliza E/S a prueba de tipos. Cada operación de E/S se realiza automáticamente en una forma sensible al tipo de datos. Si una función de E/S se ha definido adecuadamente para que maneje un tipo de datos particular, entonces dicha función se llamará automáticamente para ese tipo de datos. Si no hay concordancia en la llamada, el compilador dará un error, evitando así que entren datos inadecuados en el sistema.

####9.2.- Flujos
La E/S de C++ se da en flujos de bytes. Un flujo es simplemente una secuencia de bytes. En las operaciones de entrada, los bytes fluyen desde un dispositivo (por ejemplo, un teclado, una unidad de disco o una conexión a red) hacia la memoria principal. En operaciones de salida, los bytes fluyen de la memoria hacia un dispositivo (pantalla, impresora, etc). La aplicación asocia significado a los bytes. 
Los bytes pueden representar caracteres ASCII, datos sin procesar en formato interno, imágenes gráficas, o cualquier otro tipo de información que pueda requerir una aplicación. C++ proporciona capacidades de E/S de bajo y alto nivel. Salvo requerimientos especiales de velocidad o de dispositivos, las de alto nivel, como las proporcionadas por las bibliotecas estandar, serán preferibles por simplicidad y claridad.

####9.3.- Archivos de encabezado de la biblioteca iostream
La biblioteca iostream de C++ proporciona cientos de capacidades de E/S. La mayoría de los programas de C++ incluyen un archivo de cabecera <**iostream**> que contiene la información básica requerida para todas las operaciones de E/S de flujo. Dicho archivo contiene los objetos **cin **y **cout******, que se corresponden respectivamente con el flujo de entrada estándar y el de salida estándar. 
El archivo de encabezado <**fstream**> contiene información para las operaciones de procesamiento de archivos controladas por el usuario.

####9.4.- Clases y objetos de entrada/salida de flujo
La biblioteca iostream contiene muchas clases para manejar una amplia variedad de operaciones de E/S. La clase **istream** soporta las operaciones de entrada de flujo. 
La clase **ostream** soporta las operaciones de salida de flujo. La clase **iostream** soporta las operaciones tanto de entrada como de salida de flujo.
La sobrecarga de operadores proporciona una notación conveniente para la realización de la E/S. El operador de desplazamiento a la izquierda (**<<**) está sobrecargado para indicar la salida de flujo y se denomina operador de inserción de flujo. Estos operadores se utilizan con los objetos de flujo estándar, como ** cin** y **cout**, y también con los objetos de flujo definidos por el usuario.
**cin **es un objeto de la clase **istream**, y se dice que está conectado al dispositivo de entrada estandar, que normalmente es el teclado. Por ejemplo, la siguiente instrucción:
```cpp
cin >> grado;
```
hace que un valor para la variable entera grado se reciba desde **cin** hacia la memoria. Hay que observar que la operación de extracción de flujo es capaz de discernir el tipo de datos que trata.

**cout** es un objeto de la clase **ostream** enlazado al dispositivo de salida estandar, que normalmente es la pantalla. Por ejemplo, la siguiente instrucción:
```cpp
cout << grado;
```
hace que el valor de la variable entera grado aparezca en pantalla.

####9.5.- Salida de flujo
La salida de flujo puede realizarse mediante el operador de inserción de flujo **<<**. 
Dicho operador está sobrecargado para dar salida a datos de tipos integrados, a cadenas, y a valores de puntero. Consideremos un ejemplo de salida de cadenas:
```cpp
#include <iostream>__int main()
{
	cout << "Bienvenido a ";
	cout << "C++!\n";
	return 0;
}
```
El efecto de la secuencia de escape **\n** (nueva línea) también se logra mediante el manipulador de flujo **endl** (fin de línea). Dicho manipulador emite un caracter de nueva línea y, además, vacía el bufér de salida (es decir, causa que el búfer de salida sea extraído de inmediato aunque no está lleno).
```cpp
#include <iostream>__using namespace std;
int main()
{
	cout << "Bienvenido a ";
	cout << "C++!";
	cout << endl;
	return 0;
}
```
El buffer de salida también puede vaciarse simplemente mediante

```cpp
	cout << flush;	
```

```cpp
#include <iostream>
using namespace std;
int main()
{
	cout << "67 + 89 es ";	
	cout << (67 + 89);	
	cout << endl;	
	return 0;	
}
```
Los operadores de inserción y extracción de flujo se pueden utilizar en forma de cascada: ```(((cout << "67 mas 89 es ") << (67 + 89) ) << endl);``` es decir, **<<** asocia de izquierda a derecha. Esto es posible debido a que el operador **<<** sobrecargado devuelve una referencia a su operando izquierdo, es decir, **cout**. 

####9.6.- Entrada de flujo

Esta puede realizarse mediante el operador de extracción de flujo sobrecargado **>>**. 
```cpp
#include <iostream>
using namespace std;
int main()
{
	int x,y;
	cout << "Introduzca dos n\'umeros enteros: ";
	cin >> x >> y;
	cout << "la suma de " << x << " y " << y << " es "
	<< (x + y) << endl;
	return 0;
}
```
La operación de extracción de flujo puede utilizarse como condición, ya que el operador sobrecargado convierte mediante _casting _(moldeado de tipo) un flujo a un apuntador de tipo void *. El valor de dicho apuntador es cero si sucede algún error mientras se trata de leer un valor o si se encuentra el indicador de fin de archivo (**ctrl-D**).
```cpp
#include <iostream>

using namespace std;
int main()
{
	int grado,mayorgrado=-1;
	cout << "Introduzca la calificacion (fin-archivo para terminar): ";
	while (cin >> grado){
		if (grado > mayorgrado)
			mayorgrado = grado;
		cout << "Introduzca la calificacion (fin-archivo para terminar): ";
	}
	cout << "\nLa calificacin mas alta es: " << mayorgrado << endl;
	return 0;
}
```
La función miembro **get** sin argumento introduce un caracter desde el flujo designado (aunque sea espacio en blanco) y devuelve dicho caracter como valor de la llamada a la función. Esta versión de get devuelve EOF cuando se llega al fin de archivo de flujo.
```cpp
char c;
c = cin.get();
```
La función miembro **getline** tiene tres argumento: un array de caracteres, un límite de tamaño y un delimitador (**\n** por defecto). La función inserta un caracter nulo en el array de caracteres después de la línea leida. Esta función elimina del flujo al delimitador (es decir, lee el caracter y lo descarta), pero no lo almacena en el array de caracteres
```cpp
#include <iostream>
int main()
{
	const int SIZE = 80;
	char buffer[SIZE];
	cout << "Introduzca una oracion:\n";
	cin.getline(buffer, SIZE);
	cout << "\nla oracion introducida es:\n" << buffer << endl;
	return 0;
}
```

####9.7.- Archivos y flujos
C++ ve cada archivo simplemente como una secuencia de bytes. Todo archivo termina ya sea con un marcador de fin de archivo o con un número de byte específico que está registrado en una estructura de datos administrativa mantenida por el sistema. Cuando se abre el archivo, se crea un objeto y se asocia un flujo con ese objeto. Para realizar el procesamiento de archivos en C++ se deben incluir los archivos de encabezado que incluyen las definiciones para las clases de flujo **ifstream** (para entrada desde un archivo), **ofstream** (para salida hacia un archivo) y **fstream** (para entrada y salida desde un archivo). Los archivos se abren mediante la creación de objetos de esas clases de flujo, las cuales se derivan de las clases **istream**, **ostream** e **iostream** respectivamente.

####9.8.- Tipos y Creación de un archivo

El primer paso para trabajar con un archivo será la declaración de una variable. El tipo de dicha variable será **ifstream**, **ofstream** o **fstream**. Estas son las tres clases definidas en el archivo de cabecera **fstream**, que podremos usar para abrir un archivo en disco, escribir y leer información.
La clase **ifstream** está especializada en la entrada de datos desde un archivo, mientras que **ofstream** es la clase a utilizar en las operaciones de salida. Si necesitamos abrir un mismo archivo para realizar operaciones de lectura y escritura, la clase a utilizar será **fstream**. Existen varios constructores definidos para cada una de las clases. El constructor por defecto facilita la creación del objeto sin necesidad de parámetros adicionales y sin asociar el objeto con ningún archivo ni realizar ninguna otra operación. Otro de los constructores toma como primer parámetro el nombre del archivo a asociar al objeto y como segundo el modode apertura. Este modo está formado por uno o más de los siguientes 

**indicadores de modo de apertura**, definidos en la clase **ios**:

* in:	 Apertura para entrada	
* out: 	 Apertura para salida	
* app: 	 Apertura para añadir	
* ate: 	 Fijar el puntero al final del archivo tras la apertura	
* trunc: 	 Eliminar el contenido actual del archivo	
* binary: 	 Abrir en modo binario, no de texto	

El constructor de la clase **ifstream **tiene como valor por defecto para el segundo parámetro **ios::in**. Análogamente, el constructor de ofstream toma el valor por defecto **ios::out**. De esta forma, estos constructores no necesitan el segundo parámetro, tan solo es preciso facilitar el nombre del archivo a abrir. Consideremos algunos ejemplos:
```cpp
// Abre un archivo ya existente para lectura
ifstream F("Fichero");
// Abre un archivo para escritura creándolo
ofstream F("Fichero");
// Abre un archivo para lectura y escritura
fstream F("Fichero", ios::in|ios::out);
// Abre un archivo en modo binario
// truncando el contenido actual
fstream F("Fichero", ios::trunc|ios::binary);
```

####9.9.- Apertura y Cierre del Archivo

Antes de poder escribir o leer ningún dato, el archivo sobre el que se va a trabajar debe ser abierto. Esta operación puede efectuarse directamente en el constructor, proporcionando el nombre del archivo, o bien posteriormente mediante el método**open**(). Este método toma los mismos parámetros descritos antes para los constructores, no existiendo valor de retorno.
El cierre de un archivo puede realizarse explícitamente, con una llamada al método **close**(), o bien de forma automática, en el momento en que el objeto salga de ámbito y se ejecute el correspondiente destructor (se explican el el módulo dedicado a Programación Orientada a Objetos).

####9.10.- Escribir y Leer Datos

Las clases **fstream, ifstream** y **ofstream** no implementan ningún método de entrada o salida de información, heredando de la clase de la que derivan los operadores de inserción, **<<**, y extracción, **>>**. A la izquierda de estos operadores facilitaremos el objeto en el que se va a efectuar la operación, mientras que a la derecha se entregarán los valores o variables a escribir o leer. En el archivo de cabecera **iostream** se hayan definidas múltiples implementaciones de los operadores de insercción y extracción que permiten tratar directamente con los tipos de datos fundamentales, como son los caracteres, cadenas de caracteres, números enteros y decimales. Si necesitamos escribir o leer cualquier otro tipo de dato, será necesario definir nuevas versiones de estos operados.
Un sistema alternativo al uso de estos operadores, para leer y escribir datos en un archivo, consiste en usar los métodos **write**() y **read**(). Mediante ellos podremos tratar cualquier tipo de dato, sin ninguna limitación. El primer parámetro de estos métodos es un puntero de tipo char, con la dirección en la que se encuentra, o en la que se va a almacenar la información. El segundo parámetro será un entero mediante el que indicamos el número de bytes a escribir o leer.

####9.11.- Posición en el Archivo

Cada archivo que tenemos abierto tiene asociado un apuntador, mediante el que se conoce la posición actual del fichero. Cuando se abre un archivo, la posción actual está al principio, en el primer elemento o dato que exista. Cada operación de lectura o escritura hace avanzar la posición al siguiente dato de forma automática.

Podemos conocer y modificar la posición actual en el archivo usando los métodos **seekg**() y **tellg**(). El primero de ellos permite un posicionamiento absoluto o relativo. Si se facilita un solo parámetro, la posición a la que deseamos desplazar el puntero, el movimiento es absoluto. El segundo parámetro se usa cuando se desea un desplazamiento relativo. Los posibles valores son **ios::beg**, **ios::cur** e **ios::end**, dependiendo de que el movimiento se deba realizar desde el inicio del archivo, desde la posición actual o desde el final, respectivamente.

####9.12.- Control de Errores

Ciertas operaciones de trabajo con archivo, como la apertura o la escritura, son susceptibles de generar un error, en caso de que se produzca un fallo.
Comprobamos esta posibilidad mediante el operador negación aplicado al 
propio objeto. Se trata, por tanto, de un operador sobrecargado.

####9.13.- Ejemplos:

**Creación de un fichero**
```cpp
#include <iostream>
#include <fstream>
int main()
{
	string nombreArch;
	cout << "Introduzca el numero de cuenta, nombre y balance\n" << "Introduzca fin de archivo para terminar \n";
	int cuenta;
	char nombre[30];
	float balance;
	while(cin >> cuenta >> nombre >> balance){
		ArchClientes << cuenta << ' ' << nombre << ' ' << balance << '\n';
		cout << "? ";
	}
	return 0;
}
```

Observe en la llamada al constructor **ofstream**, la necesidad de convertir el nombre del archivo, de tipo **string **a una cadena de caracteres usando el operador **c_str()**.
Lo mismo ocurriría en una llamada a **ifstream**.

**Lectura e Impresión de un archivo**
```cpp
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main(int argc, char* argv[])
{
	// el constructor ifstream abre el archivo	
	ifstream ArchClientes("clientes.dat");	
	if (!ArchClientes) {	
		cerr << "El archivo no pudo abrirse" << endl;	
		exit(1);
	}	
	int cuenta;
	string nombre;
	float balance;
	cout << setw(10) << "Cuenta" << setw(13) << "Nombre" << setw(10) << "Balance\n";
	while( ArchClientes >> cuenta >> nombre >> balance)
	cout << setw(10) << cuenta << setw(13) << nombre << setw(7) << balance << '\n';
	return 0;	
}
```

**setw** de la libreria **iomanip **especifica el ancho de campo del siguiente valor de la salida.

####9.14.- Archivos de texto

En un archivo podemos almacenar caracteres o cadenas de caracteres como cualquier otro dato. La escritura de una cadena puede realizarse mediante el operador de inserción. Sin embargo, la lectura no es posible con el correspondiente operador de extracción en caso de que la cadena contenga espacios.
Los objetos **ifstream** y **fstream** cuentan con un método adicional llamado** getline()** para la lectura de cadenas de carateres. El primer parámetro de este método es la cadena en la que se va a almacenar la información, y el segundo un número entero indicando el espacio disponible en ella. Opcionalmente podemos pasar un tercer parámetro especificando un caracter delimitador hasta el que se desea leer. Por defecto, este parámetro tiene el valor **\n**, lo que quiere decir que se leerá una línea completa, hasta encontrar el salto de línea.





