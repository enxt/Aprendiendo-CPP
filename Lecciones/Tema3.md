##1.- Otros aspectos de C++

####1.1.- Introducción

En este módulo se presentan otras funcionalidades de C\+\+, que facilitan la labor de programación y que contribuyen a mejorar la claidad de los programas. Una de estas técnicas es el uso de excepciones para el tratamiento de errores. Se presentan también las plantillas, el mecanismo que ofrece C\+\+ para la programación de componentes genéricos (no se especifica un tipo de dato concreto). Las plantillas permiten definir de forma genérica una familia de funciones o de clases. En este módulo se presenta también la biblioteca estándar de C++ que ofrece un conjunto de clases que implementan el concepto de contenedor. Un contenedor es un objeto capaz de almacenar una colección de objetos. Todos los contenedores están definidos como plantillas. Esto permite que se pueda especificar el tipo de los objetos almacenados en el contenedor.



##2.- Tratamiento de excepciones

####2.1.- Tratamiento de errores

Los errores que se pueden producir en el código de un programa se clasifican en dos grandes grupos: los que son detectados durante la compilación, y por lo tanto, pueden ser corregidos antes de que el programa llegue a funcionar, y los que se producen durante la ejecución. En este segundo grupo se encuentran generalmente los errores más difíciles de tratar, unas veces por tratarse de errores de estructura o lógicos, que no generan ningún tipo de aviso, pero provocan que el programa no haga lo que se espera de él, y otras porque son errores debidos a situaciones imprevistas. En los programas aparecen muchas situaciones cuyo resultado no puede preverse en todos los casos. Por ejemplo, se puede producir una división por cero, al abrir un archivo no podemos estar seguros de que exista, o al leer un dato, que esperamos que sea un entero puede ocurrir que no lo sea. Una posibilidad para tratar estas situaciones sería que nuestras funciones considerasen todos los casos posibles, pero esto sería muy tedioso de programar, poco flexible a las modificaciones que pudieramos realizar posteriormente, y daría lugar a un código poco legible. Por ello, la mayoría de los lenguajes de programamación existentes proporcionan alguna facilidad para tratar este tipo de situaciones.

C\+\+ proporciona los medios necesarios para garantizar que las aplicaciones sean seguras, lo que significa que sean capaces de gestionar los errores de una forma elegante, sin estropear la legibilidad del código, permitiendo que la aplicación se recupere de los errores cuando sea posible y se interrumpa si es necesario, sin perder datos ni recursos. Los errores que se producen durante la ejecución de un programa y que provocan su ruptura, en C\+\+ se gestionan mediante las denominadas **excepciones**. Las excepciones proporcionan un medio estructurado de separación de la lógica normal del programa de la lógica de gestión de errores, lo que aumenta en gran medida la facilidad de mantenimiento de las aplicaciones. Una excepción es una señal provocada por un error, tal como pueda ser una división por cero o el intento de acceder a los datos apuntados por un puntero nulo. Esta señal puede ser interceptada por el propio programa, procediendo a su tratamiento o solución, o bien por el código adicional añadido por el compilador, que se encargará de avisar mediante un mensaje de que se ha producido una excepción, interrumpiendo la ejecución del programa. Generalmente una excepción dispone de la información necesaria para conocer la causa y el punto en que se ha producido el error, ayudando así a su resolución. Dicha información la podemos aprovechar en nuestro código si interceptamos la excepción, o bien, si no la interceptamos, será mostrada en un mensaje al usuario antes de que el programa se interrumpa.

En C\+\+ una excepción es un objeto que contiene información sobre la existencia de un error y el lugar en que se ha producido. Las principales ventajas de esta representación de las excepciones son las siguientes:

* Las excepciones pueden agruparse en jerarqu´ıas utilizando la herencia.
* Pueden introducirse nuevas excepciones sin afectar al código existente.
* Un objeto de excepción puede transmitir información desde el punto en que se generó al punto en que se maneja.

Muchas situaciones de excepción y errores están ya considerados por el lenguaje, que los trata dando como mínimo un mensaje. Sin embargo en muchas ocasiones es más adecuado dar un tratamiento específico.

####2.2.- Bloques que pueden generar excepciones

El primer paso para evitar las situaciones de ruptura en nuestro programa es determinar qué sentencias o bloques de sentencias de nuestro código son susceptibles de generar un error. Por ejemplo, al realizar una división por un dato proporcionado por el usuario, debemos tener en cuenta que se puede producir una división por cero y proteger esta sentencia.
Para evitar que la excepción generada por el programa lo interrumpa debemos interceptarla y responder a ella según proceda. Para ello aislaremos el bloque a proteger dentro de un bloque **try** y las sentencias a ejecutar en caso de que se produzca una excepción en un bloque **catch**. El bloque **catch** siempre va inmediatamente después del bloque **try**. Por ejemplo:

```cpp
try {
	Cociente = Dividendo / Divisor;
}
catch(...) {
	 cout << "el divisor no puede ser cero" << endl;
}
```

La palabra **catch** va seguida de un paréntesis con unos puntos suspensivos en su interior, indicando así que deseamos interceptar cualquier tipo de excepción que pueda producirse en el bloque **try**. Al ejecutar el programa, las sentencias dispuests tras la palabra **try** se ejecutan siempre, según el flujo normal de programa, mientras que las sentencias escritas a continuación de **catch** se ejecutan sólo en caso de que se produzca la excepción. Si ejecutamos un programa que contenga la construcción anterior y proporcionamos un divisor nulo, veremos que el programa no se interrumpe, sino que simplemente se muestra el mensaje.

####2.3.- Clases de excepciones

En el ejemplo anterior el control de la excepción es muy simple, ya que en la sentencia protegida no se puede producir otro error que no sea el de división por cero. Sin embargo, en la mayoría de los casos no todo es tan simple y puede ocurrir que en un mismo bloque se produzcan distintas excepciones, provocadas por distintos errores. Al producirse una excepción, automáticamente se crea un objeto con información acerca de ella. Este objeto pertenecerá a una determinada clase o tipo, que nos puede servir para determinar qué error es el que se ha producido de una forma simple. Con el fin de diferenciar en nuestro código las sentencias que se deben ejecutar en un caso u otro dependiendo del tipo de excepción que se produzca, tras la palabra **catch**, entre paréntesis, escribiremos la clase de excepción a la que se desea responder, seguida de un nombre de objeto que nos servirá para poder recuperar más información acerca de la excepción:

```cpp
try {
...
}
catch(tipo1 arg1) {
...
}
catch(tipo2 arg2) {
...
}
```

Si el tipo de la excepción lanzada coincide con el tipo del argumento de una sentencia **catch**, se ejecuta el bloque de código correspondiente. El parametro _arg_ es un nombre de parámetro opcional.

####2.4.- Mecanismos de lanzamiento de excepciones

Cuando se detecta una excepción esta se lanza usando una sentencia **throw**, dentro del bloque **try**. El formato de esta instrucción puede ser de dos formas. La primera de ellas es:

```cpp
	throw exception;
```

El operando excepción puede ser de cualquier tipo, incluyendo objetos.
Veamos un ejemplo completo:

```cpp
#include <iostream>
using namespace std;

void test(int x) {
	try {
    	if (x == 1) throw x; //int
		else
			if(x == 0) throw 'x'; // char
		else
			if(x == -1) throw 1.0; //double
		cout << "Fin de bloque try" << endl;
	}
	catch(char c) {
    	cout << "Captura de un caracter " << endl;
	}
	catch(int m) {
    	cout << "captura de un entero " << endl;
	}
	catch(double d)	{
    	cout << "Captura de un double " << endl;
	}
}

int main() {
	cout << "Prueba de varias sentencias catch " << endl;
	cout << " x == 1" << endl;
    test(1);
	cout << " x == 0" << endl;
	test(0);
	cout << " x == -1" << endl;
	test(-1);
	cout << " x == 2" << endl;
	test(2);

    return 0;
}
```

El programa muestra un ejemplo en el que se utilizan distintas sentencias catch para manejar distintos tipos de excepciones

####2.5.- Excepciones propias

La biblioteca estándar de C\+\+ proporciona una clase base diseñada específicamente para declarar objetos que se lancen como excepciones. Esta clase se denomina **exception** y se define en el archivo cabecera **<exception>**, bajo el _namespace std_.
Esta clase tiene los constructores usuales por defecto y por copia, y destructor, más una función miembro virtual adicional denominada **what** que devuelve una secuencia de caracter terminada en _null_ y que puede sobreescribirse en las clases derivadas para que contenga una descripción de la excepcion.

```cpp
// excepciones estandar
#include <iostream>
#include <exception>
using namespace std;
class miexcepcion: public exception {
	virtual const char* what() const throw() {
		return "Se ha producido mi excepcion";
	}
} miex;

int main () {
    try {
    	throw miex;
    }
    catch (exception& e) {
    	cout << e.what() << endl;
    }
    return 0;
}
```
También se pueden definir excepciones propias que no deriven de exception:

```cpp
class miex2 {
	public:
		miex2()
		: mensaje( "se ha producido mi excepcion" ) { }
		const char *what() const { return mensaje; }
	private:
		const char *mensaje;
};
```

##3.- Plantillas

####3.1.- Plantillas (Templates)

Las plantillas son una de las características más poderosas de C\+\+. Nos permiten especificar con un sólo segmento de código un rango completo de funciones relacionadas (sobrecargadas), llamadas **funciones de plantilla**, o un rango completo de clases relacionadas, llamadas clases de plantillas. Por ejemplo, podríamos escribir una sola plantilla de función para una función de ordenamiento de arrays y luego hacer que C++ generara automáticamente funciones de plantilla separadas que ordenaran un array de enteros, un array de reales, un array de cadenas, etc.
Análogamente, podríamos escribir una única plantilla de clase para la clase pila, y luego hacer que C\+\+ generara automáticamente clases de plantilla separadas, para las clases pilas de enteros, pila de reales, etc. Podemos pensar en una analogía entre las plantillas de función y las de clase y las plantillas utilizadas para dibujar formas, que determinan la forma de los trazas, pero pueden dibujarse con distintos materiales, colores, anchuras, etc.

####3.2.- Plantillas de función

Las funciones sobrecargadas se utilizan normalmente para realizar operaciones similares sobre diferentes tipos de datos. Si las operaciones son idénticas para cada tipo, esto puede realizarse en forma más compacta y conveniente mediante las plantillas de función. El programador escribe una sola definición de plantilla. Basándose en los tipos de argumento que se proporcionan en las llamadas a esta función, el compilador generará automáticamente funciones de código objeto separadas para manejar adecuadamente cada tipo de llamada. Todas las definiciones de plantilla de función comienzan con la palabra clave **template**, seguida de una lista de parámetros formales para dicha plantilla encerrados entre paréntesis angulares; cada parámetro formal que representa un tipo debe estar precedido por la palabra clave **class**, como en:
```cpp
template < class T >
o 
template < class TipoElemento >
o 
template < class Tipo1, class Tipo2 >
```
Los parámetros formales de una definición de plantilla se utilizan para especificar los tipos de los argumentos de la función, para especificar el tipo de devolución de la función y para declarar variables en el interior de la función. A continuación se presenta un ejemplo:

```cpp
template < class T >
T maximum ( T valor1, T valor2, T valor3 ) {
    T max = valor1;
    if ( valor2 > max)
    	max = valor2;
    if ( valor3 > max)
    	max = valor3;
    return max;
}
```
Esta plantilla de función declara un solo parámetro formal de tipo T como el tipo de datos que la función _maximum_ probará. Cuando el compilador detecta una llamada a _maximum_ en el código del programa fuente, el tipo de datos pasado a máximos sustituye a T en toda la definición de la plantilla. Después se compila la nueva función. Por lo tanto, las plantillas en realidad son medios para generar código. La instanciación del tipo int es:
```cpp
int maximum ( int valor1, int valor2, int valor3 ) {
    int max = valor1;
    if ( valor2 > max)
    	max = valor2;
    if ( valor3 > max)
    	max = valor3;
    return max;
}
```
El siguiente fragmento de código ilustra el uso de la función de plantilla maximum para determinar el mayor de tres valores int, tres valores double y tres valores char.
```cpp
int int1, int2, int3;
cout << "El maximo valor de tipo int es: " << maximum(int1, int2, int3) << endl;

double double1, double2, double3;
cout << "El maximo valor de tipo double es: " << maximum(double1, double2, double3) << endl;

char char1, char2, char3;
cout << "El maximo valor de tipo char es: " << maximum(char1, char2, char3) << endl;
````

####3.3.- Sobrecarga de funciones de plantilla

Una plantilla de función se puede sobrecargar, por ejemplo, proporcionando otras plantillas de función que especifiquen el mismo nombre de función pero diferentes parámetros de función. También puede sobrecargarse proporcionando funciones que no sean de plantilla y que tengan el mismo nombre de función, pero diferentes argumentos.

####3.4.- Plantillas de clase

Una pila es una estructura de datos en la que insertamos elementos en un orden y los recuperamos en el orden último en entrar, primero en salir, independientemente del tipo de los elementos que se coloquen en ella. pero cuando se llega a la instanciación real de una pila, se debe especificar un tipo de datos. Es, por tanto, una oportunidad perfecta para la reutilización del software. Lo que se necesita son medios para describir genéricamente el concepto de pila, y para instanciar clases que sean versiones específicas de algún tipo para esa clase genérica. En C\+\+ esta capacidad la proporcionan las plantillas de clase. A las plantillas de clase se las denomina tipos parametrizados, debido a que requieren que se especifiquen uno o más parámetros de tipo para especificar la manera de personalizar una plantilla de "clase genérica" a fin de formar una clase de plantilla específica. Para producir una variedad de clases de plantilla basta con escribir la definición de plantilla de clase. Cada vez que se necesita una nueva instanciación específica de un tipo, el compilador genera automáticamente el código para ella. Por ejemplo, una plantilla de la clase _Stack_ puede convertirse en la base para la creación de muchas clases de _Stack_: _Stack_ de double, Stack de int, Stack de Empleado, etc.

La definición de una clase de plantilla es como la definición de una clase convencional, a excepción de que está precedida por el encabezado

```cpp
template < class T >
```

para especificar que esta es la definición de plantilla de clase con el parámetro de tipo T, que indica el tipo de la clase _Stack_ que va a crearse. T representa el tipo de elemento al que se instancia la clase y se utiliza en la declaración de los miembros de la clase. Consideremos el ejemplo de la pila:

```cpp
template < class T >
class Stack {
	public:
		Stack ( int = 10); // constructor predeterminado (tamano pila = 10)
		~Stack() {delete[] stackPtr;} // destructor
		bool push ( const T&); // inserta un elemento en la pila
		bool pop (T&); // saca un elemento de la pila
	private:
		int size; // num elementos de la pila
		int top; // ubicacion del elemento superior
        T *stackPtr; // apuntador hacia la pila
        bool isEmpty() { return top == -1; } //funciones
        bool isFull() { return top == size - 1; } // de utilleria
};

// constructor
template < class T >
Stack < T >::Stack( int s) {
	if ( s > 0)
		size = s;
	else
		size = 10;

	top = -1; // la pila inicialmente está vacía
	stackPtr = new T[size]; // asigna espacio para los elementos
}

// inserta un elemento en la pila
// devuelve 1 en caso satisfactorio, 0 en otro caso
template < class T >
bool Stack< T >::push ( const T &Valor) {
    if (!isFull() ) {
        top = top + 1;
        stackPtr[top] = Valor;
        return true;
    }
	return false;
}

// saca un elemento de la pila
template < class T >
bool Stack< T >::pop( T &Valor) {
    if (!isEmpty() ) {
	    Valor = stackPtr[top];
    	top = top - 1; // elimina el elemento de la pila
        return true;
    }
    return false;
}
```

Consideremos ahora un programa que utiliza la plantilla de la clase Stack. El programa comienza instanciando un objeto doubleStack de tamaño 5.
```cpp
int main() {
    Stack< double > doubleStack( 5 );
    double f = 1.1;
    cout << "Se insertan valores en doubleStack" << endl;
    while (doubleStack.push(f)){ // devuelve verdadero si es satisfactorio
        f = f + 1.1;
    }

    cout << "Pila llena; Se sacan los elementos" << endl;
    while (doubleStack.pop(f)) // devuelve verdadero si es satisfactorio
    	cout << " f = " << f << endl;
    cout <<"Pila vacia" << endl;
}
```


####3.5.- Plantillas de clase y parámetros sin tipo

En las plantillas es posible utilizar parámetros sin tipo. Un parámetro sin tipo puede tener un argumento predeterminado y se trata como const. Por ejemplo, el encabezado de plantilla podría modificarse para que tomara que tomara un parámetro _int elements_ de la siguiente manera:

```cpp
template< class T, int elements >
```
Luego una declaración como
```cpp
Stack< double, 100> NumerosmasRecientes;
```

instanciará (en tiempo de compilación) una clase de plantilla Stack de 100 elementos, llamada NumerosMasrecientes, de valores double.

####3.6.- Las plantillas y la herencia

Las plantillas y la herencia se relacionan de varias formas:
* Una plantilla de clase se puede derivar de una clase que no sea de plantilla.
* Una clase de plantilla se puede derivar de una plantilla de clase.
* Una clase que no sea de plantilla se puede derivar de una plantilla de clase.



####3.7.- Las plantillas y los miembros static

Recordemos que en las clases que no son de plantilla se comparte una copia de de los datos miembro static entre todos los objetos de la clase, y el dato miembro static debe inicializarse dentro del alcance del archivo. Cada clase de plantilla que se instancia a partir de una plantilla de clase tiene su propia copia de cada uno de los datos miembro static de la plantilla de la clase, y todos los objetos de esa clase de plantilla comparten ese único dato miembro static.


##4.- Biblioteca Estándar de Plantillas (STL) en C\+\+

####4.1.- Clases Contenedor e Iteradores

Entre los tipos más populares de clases se encuentran las contenedor, también llamadas clases de colección. Se trata de clases diseñadas para contener colecciones de objetos. Suelen proporcionar servicios como la inserción, borrado, búsqueda, clasificación, etc. Los arrays y las listas enlazadas son ejemplos de este tipo de clases. Es común asociar objetos iteradores con una clase de colección.

Un iterador es un objeto que permite recorrer los elementos de una colección. Cuando se escribe un iterador para una clase, obtener el siguiente elemento de la clase puede expresarse de forma simple. Los iterados se escriben como amigos de las clases a través de las cuales hacen la iteración. Una clase contenedor puede tener varios iteradores operando sobre ella simultáneamente. Hay estructuras de datos muy comunes, como listas, pilas, colas y colas de prioridad. Por ello, hay una gran motivación para desarrollar una biblioteca estándar de contenedores de objetos organizados en plantillas. Esto es lo que se ha hecho con la biblioteca estándar de plantillas STL (Standard Template Library). El uso de la STL puede ahorrar considerable tiempo y esfuerzo y da como resultado programas de más calidad. En la **STL** de C\+\+ accedemos a los elementos de contenedores por medio de objetos iteradores que tiene la apariencia de punteros, pero que se comportan más inteligentemente. Las clases iteradores están diseñadas para que se utilicen genéricamente en cualquier contenedor. Los contenedores encapsulan algunas operaciones primitivas, pero los algoritmos de la STL están implementados de forma independiente de los contenedores. La STL evita el uso de **new** y **delete** en favor de asignadores para la asignación y liberación de almacenamiento. Cada contenedor de la STL tiene funciones miembro asociadas. Algunas funciones se aplican a todos los contenedores de STL. Otras son específicas de contenedores particulares. Mediante las plantillas de clase **vector**, **list** y **deque** podemos ilustrar la mayoría de las funciones más comunes.


####4.2.- Contenedores

Los contenedores están divididos en tres categorías principales, de secuencia, asociativos y adaptadores de contenedores. Otros tipos se consideran casicontenedores, como los arrays estilo C y el tipo string, aunque no tienen todas las capacidades de estos. Algunos de los contenedores más comunes son los siguientes:

#####Contenedores de secuencia
Almacenan elementos en una secuencia lineal, uno tras otro. Cada elemento está relacionado con los restantes mediante su posición en la línea.
* **vector**
Inserciones y eliminaciones rápidas al final. Acceso directo a cualquier elemento.
* **deque**
Inserciones y eliminaciones rápidas al principio y al final. Acceso directo a cualquier elemento.
* **list**
Lista de enlace doble. Inserción y eliminación rápida en cualquier lugar.

#####Contenedores asociativos
Están diseñados para permitir el acceso directo a los elementos mediante claves, lo que permite almacenar colecciones de forma ordenada.
* **set**
Búsqueda rápida. No se permiten duplicados.
* **multiset**
Búsqueda rápida. Se permiten duplicados.
* **map**
Asociación de uno a uno, no se permiten duplicados, búsqueda rápida basada en clave.
* **multimap**
Asociación de uno a uno, se permiten duplicados, búsqueda rápida basada en clave.

#####Adaptadores de contenedor
Se trata de contenedores derivados que se pueden crear a partir de diferentes contenedores secuenciales. No soportan iteradores. Sin embargo, ofrecen dos funciones miembro, **pop**() y **push**(), para implementar las operaciones de inserción y eliminación.
* **stack**
LIFO (último en entrar, primero en salir).
* **queue**
FIFO (primero en entrar, primero en salir).
* **priority queue**
El elemento de más alta prioridad siempre es el primer elemento en salir.


#####Funciones comunes a todos los contenedores son las siguientes:

* **Constructor predeterminado**
es un constructor para proporcionar una inicialización predeterminada del contenedor. Normalmente, cada contenedor tiene varios constructores que proporcionan una variedad de métodos de inicialización para dicho contenedor.

* **Constructor por copia**
Es un constructor que inicializa al contenedor para que sea una copia de un contenedor existente del mismo tipo.

* Destructor
Es la función para destruir el contenedor cuando ya no es necesario.

* **empty** devuelve true si no hay elementos en el contenedor. false eoc.
* **max_size** Devuelve la cantidad máxima de elementos de un contenedor.
* **size** Devuelve la cantidad de elementos que hay actualmente en el contenedor.
* **operator =** Asigna un contenedor a otro.
* **operator <** Devuelve true si el primer contenedor es menor que el segundo.
* **operator <=**
* **operator >**
* **operator >=**
* **operator ==**
* **operator !=**
* **swap** Intercambia los elementos de dos contenedores

Otras funciones solo se encuentran en los contenedores de primera clase, es decir, los secuenciales y los asociativos:

* **begin**
Las dos versiones de esta función devuelven un iterator o un const_iterator que hace referencia al primer elemento del contenedor.
* **end**
Las dos versiones de esta función devuelven un iterator o un const_iterator que hace referencia a la siguiente posición después del final de un contenedor.
* **rbegin**
Las dos versiones de esta función devuelven un reverse_iterator o un const_reverse_iterator que hace referencia al último elemento del contenedor.
* **rend**
Las dos versiones de esta función devuelven un reverse_iterator o un const_reverse_iterator que hace referencia a la posición que está antes del primer elemento del contenedor.
* **erase**
Borra uno o más elementos del contenedor.
* **clear**
Borra todos los elementos del contenedor.

Los **archivos de encabezado** para cada uno de los contenedores de la biblioteca estándar son los siguientes:
**< vector >**
**< list >**
**< deque >**
**< stack >**
**< map >**
**< set >**
**< bitset >**

El contenido de todos estos archivos está en el **namespace std**. Sin embargo hay compiladores en los que estos archivos de encabezado difieren.
Consideremos a continuación los **typedef** más comunes (para crear sinónimos o alias para tipos) que se encuentran en los contenedores de primera clase. Se utilizan en las declaraciones genéricas de variables, parámetros de función y valores de devolución de funciones. Por ejemplo,

value_type 
es el tipo del elemento que está almacenado en el contenedor.
reference
es una referencia al tipo de elemento que está almacenado en el contenedor.
const_reference
es una referencia constante. Una referencia de este tipo sólo puede utilizarse para 
la lectura de elementos del contenedor, y para realizar operaciones de tipo const.
pointer
es una apuntador al tipo de elemento que está almacenado en el contenedor.
iterator
es un iterador que apunta al tipo de elemento que está almacenado en el contenedor.
const_iterator
es un iterador constante que sólo puede utilizarse para leer.
reverse_iterator
es un iterador a la inversa que se utiliza para iterar a través de un contenedor a la inversa.
const_reverse_iterator


Cuando se inserta un elemento en un contenedor se hace una copia de dicho 
elemento. Por esto, el tipo del elemento debe proporcionar su propio constructor 
por copia y un operador de asignación. Además, los contenedores asociativos y 
muchos algoritmos requieren que se comparen elementos. Por esto, el tipo del 
elemento debe proporcionar un operador de igualdad (==) y uno de (<).

Iteradores

Los iteradores tienen muchas características en común con los punteros y se utilizan 
para apuntar a los elementos de contenedores de primera clase, aunque también 
para otros propósitos. Pueden verse como una implementación mediante objetos 
de punteros a contenedores, disponiendo de una serie de funciones de acceso. Una 
posible aplicación es una implementación externa del punto de interés. Los 
iteradores guardan información de estado que es sensible a los contenedores 
particulares sobre los que operan y, por lo tanto, dichos iteradores están 
implementados de una forma específica para cada tipo contenedor. Sin embargo, 
determinadas operaciones de iterador son uniformes entre todos los iteradores. Por 
ejemplo, el operador (*) desreferencia a un iterador para que se pueda utilizar el 
elemento al que apunta. La operación ++ sobre un iterador devuelve un iterador al 
siguiente elemento del contenedor.

Los contenedores de primera clase de la STL proporcionan las funciones miembro 
begin() y end(). La función begin() devuelve un iterador que apunta al primer 
elemento del contenedor. La función end() devuelve un iterador al elemento 
siguiente al último del contenedor, es decir, a un elemento que no existe. Si el 
iterador i apunta a un elemento en particular, ++i apunta al siguiente elemento y =i 
hace referencia al elemento al que apunta i. Usamos un objeto de tipo iterator para 
referirnos a un elemento de tipo contenedor que puede modificarse. Usaremos un 
objeto de tipo const_iterator para referirnos a un elemento de contenedor que no 
puede modificarse.

Veamos un ejemplo de uso de un iterador:

vector< int > v;
v.push_back(2);
v.push_back(3);
v.push_back(4);
v.push_back(5);
cout << "Contenido del vector v:" << endl;
vector< int >::iterator p1;
for(p1 = v.begin(); p1 != v.end(); ++p1)
cout << *p1 << " ";


Los iteradores pueden clasificarse en categorías dependiendo del conjunto 
específico de funciones que soportan (esta jerarquía no es de herencia):
entrada
Se utilizan para leer un elemento de un contenedor. Sólo pueden moverse hacia 
adelante y sólo soportan funciones de un sólo paso, y el mismo iterador de entrada 
no se puede utilizar para pasar dos veces por una misma secuencia.
salida
Se utilizan para escribir un elemento en un contenedor. Sólo se puede mover hacia 
adelante de elemento en elemento. Sólo soportan algoritmo de un paso y no se 
pueden reutilizar.
hacia adelante
Combina las capacidades de los iterados de entrada y de salida y conserva su 
posición en el contenedor (como información de estado). Soportan algoritmos de 
varios pasos.
bidireccional
Combina las capacidades de un iterador hacia adelante con la capacidad de 
moverse hacia atrás.
acceso aleatorio
Combina las capacidades del iterador bidireccional con la habilidad de acceder 
directamente a cualquier elemento del contenedor, es decir, saltar hacia adelante 
o hacia atrás un número arbitrario de elementos.

La categoria de iterador soportada por cada contenedor determina si este
puede utilizarse con algoritmos específicos de la STL. Los contenedores que
soportan iteradores de acceso aleatorio pueden emplearse con todos los algoritmos 
de la STL. Hay que notar que sólo los contenedores de primera clase (vector, list, 
deque, set, multiset, map y multimap) se recorren con iteradores. A continuación 
tenemos el tipo de iterador de cada uno de ellos:

vector: acceso aleatorio
deque: acceso aleatorio
list: bidireccional
set: bidireccional
multiset: bidireccional
map: bidireccional
multimap: bidireccional
stack: no soporta iteradores
queue: no soporta iteradores
priority_queue: no soporta iteradores

Algoritmos

Un aspecto muy importante de la STL es que proporciona algoritmos que pueden 
utilizarse genéricamente a través de una variedad de contenedores. Hay algoritmos 
de inserción, eliminación, búsqueda y ordenamiento adecuados para algunos o todos
los contenedores de la STL. Los algoritmos operan sobre los elementos de los 
contenedores sólo indirectamente mediante de iteradores. Muchos algoritmos 
operan sobre secuencia definidas por pares de iteradores, un iterador apuntando al 
primer elemento de la secuencia, y otro apuntando al que está después del último 
de la secuencia. Estos iteradores se obtienen con las funciones miembro de 
contenedor begin() y end(). Frecuentemente, los algoritmos devuelven iteradores. 
Por ejemplo, find() localiza un elemento y devuelve un iterador hacia ese 
elemento. Si no encuentra el elemento devuelve el iterador end(). El algoritmo 
find() se puede utilizar con cada uno de los contenedores de la STL.
Existen algoritmos de secuencia cambiante, es decir, que dan como resultado 
modificaciones a los contenedores sobre los que se aplican. Entre estos algoritmo se
encuentran copy(), fill(), remove(), reverse(), swap(), rotate(), etc.
Otros algoritmos son de secuencia no cambiante, es decir, no modifican el 
contenedor sobre el que se aplican. Entre estos se encuentran count(), equal(), 
find(), for _each(), etc.

Contenedores de Secuencias

La biblioteca estándar de plantillas de C++ proporciona tres contenedores de 
secuencia: vector, list y deque. Las clases vector y deque están basadas en arrays. 
La clase list implementa una estructura de datos de lista enlazada.
Ya hemos visto la serie de operaciones comunes para todos los contenedores de la 
STL. Aparte de esta operaciones, cada contenedor proporciona otras capacidades 
adicionales. Muchas de ellas son comunes a varios contenedores. Sin embargo, estas
operaciones no son siempre igualmente eficientes para cada contenedor. Los 
programadores deben escoger el contenedor que sea más adecuado a su aplicación:
Las aplicaciones que requieren frecuentes inserciones y eliminaciones en ambos 
extremos de un contenedor normalmente utilizan un objeto de tipo deque en vez 
de uno vector. Aunque podemos insertar y eliminar elementos al principio y al final 
de un vector y uno deque, la clase deque es más eficiente que la clase vector para 
hace inserciones y eliminaciones al inicio.
Las aplicaciones que tienen frecuentes inserciones y eliminaciones en la parte 
media y/o en los extremos del contenedor normalmente utilizan un objeto list, 
debido a su implementación eficiente para la inserción y eliminación en cualquier 
lugar de la estructura de datos.
Operaciones comunes a todos los contenedores de secuencia son front(),
para devolver una referencia al primer elemento del contenedor, back() para
devolver una referencia al último elemento del contenedor, push_back, para
insertar un nuevo elemento al final del contenedor, y pop_back para eliminar
el último elemento del contenedor.

El Contenedor de Secuencia vector

Uno de los contenedores más populares de la STL es vector. Un objeto de tipo 
vector puede cambiar su tamaño dinámicamente. A diferencia de los arrays, los 
objetos de tipo vector se pueden asignar a otros. Al igual que sucede con los arrays, 
el uso de subíndices con objetos de tipo vector no realiza comprobación automática
de rango, pero la clase vector proporciona esta capacidad mediante la función at().
La clase vector proporciona una estructura de datos con localidades de memoria
contiguas. Esto permite un acceso directo y eficiente a cualquier elemento de un 
vector por medio del operador de índice, de la misma forma que se hace en un 
array. La clase vector se utiliza más comúnmente cuando los datos del contenedor 
deben estar ordenados y fácilmente accesibles por medio de un subíndice. Cuando 
se acaba la memoria de un vector, este asigna automáticamente un área de 
memoria contigua más grande, copia los elementos originales en la nueva memoria 
y libera la memoria anterior. Como consecuencia de todo esto:
Usaremos este contenedor para tener mayor eficiencia en el acceso aleatorio. Los 
objetos de esta clase proporcionan un rápido acceso indexado con el operador
sobrecargado, debido a que están guardados en un área de almacenamiento 
contiguo de forma similar a un array. 

El objeto vector soporta iteradores de acceso aleatorio, por lo que tiene 
disponibles todas las operaciones que requieren este tipo de iteradores, que son
todos los algoritmos de la STL.

Algunas operaciones disponibles para esta clase son:

push_back, para insertar un elemento al final (v.push_back(22), inserta 22 al final).

insert, para insertar en una determinada posición(v.insert( v.begin()+1,22), 
inserta 22 como segundo elemento).

erase, para borrar elemento. Hay dos versiones, erase(v.begin()) borra el elemento 
de esa posición, erare(v.begin(), v.end()) borrar todos los elementos entre ambas 
posiciones, sin incluir la última. En este caso se borran todos los elementos del 
vector.

clear, vacía el contenedor.

Ejemplo:

#include <iostream>
#include <vector>
using namespace std;
int main()
{
vector< string > v;
v.push_back("esto");
v.push_back("es");
v.push_back("un");
v.push_back("ejemplo");
cout << "Contenido del vector v:" << endl;
for(int i =0; i < v.size(); i++)
cout << v[i] << " ";
cout << endl;
}

El Contenedor de Secuencia list

El contenedor de secuencia list proporciona una implementación eficiente para las 
operaciones de inserción y eliminación en cualquier localidad del contenedor. Si la 
mayoría de estas suceden en los extremos del contenedor, la estructura de datos 
deque proporciona una implementación más eficiente. La clase list está 
implementada como una lista de enlace doble, es decir, cada nodo tiene un 
apuntador al nodo anterior y otro al siguiente. Esto permite que la clase soporte 
operadores bidireccionales. Además de las funciones miembro de todos los 
contenedores de la STL, y de las funciones miembro comunes a los contenedores de
secuencia, la clase list proporciona otras ocho funciones miembro:

back, da la referencia al último elemento,
begin, da la referencia la primer elemento,
clear, elimina todos los elementos,
empty, indica si la lista está vacía,
end, da una referencia del final de la lista,
erase, elimina los elementos especificados,
insert, inserta los elementos especificados,
merge, combina dos listas ordenadas
pop_back, elimina el último elemento,
pop_front, elimina el primer elemento, 
push_back, añade un elemento al final,
push_front, añade un elemento al principio,
sort, ordena la lista
y otras.


El Contenedor de Secuencia deque

La clase deque reune muchas de las facilidades de la clase vector y de la clase list. 
El término deque es una abreviatura de cola de dos puntas. La clase deque está 
implementada para proporcionar un acceso indexado eficiente (que utiliza 
subíndices) para la lectura y modificación de sus elementos en una forma muy 
similar a la de un objeto vector. La clase deque también esta implementada para 
las operaciones de inserción y eliminación eficientes en su inicio y su final de forma 
muy similar a list, (aunque el objeto list también es capaz de insertar y eliminar de 
manera eficiente en la parte media del mismo). La clase deque proporciona soporte 
para los iteradores de acceso aleatorio, y por tanto, los objetos deque se pueden 
utilizar con todos los algoritmos de la STL. Uno de los usos más comunes de una 
deque es el mantenimiento de una cola de elementos primero en entrar, primero en
salir. El almacenamiento adicional para una deque se puede asignar en cualquier 
extremo de la misma en bloques de memoria que son manejados, por lo general, 
como un array de apuntadores hacia esos bloques. Debido a la disposición de 
memoria no contigua de una deque, un iterador de deque debe ser más inteligente 
que los iteradores que se utilizan para iterar a través de un objeto tipo vector o 
arrays basados en apuntador. La clase deque proporciona las misma operaciones 
básicas que la clase vector, pero agrega las funciones miembro push_front y 
pop_front para permitir la inserción y eliminación al inicio del objeto deque, 
respectivamente.

En resumen:
Usaremos list cuando necesitemos frecuente inserciones y eliminaciones en 
cualquier punto del contenedor.
Usaremos vector cuando las operaciones lo más frecuente sean los accesos 
aleatorios.
Usaremos deque cuando necesitemos ambas cosas.

Contenedores Asociativos

Los contenedores asociativos de la STL están diseñados para proporcionar acceso 
directo al almacenamiento y recuperación de elementos por medio de 
claves de búsqueda. Los cuatro contenedores asociativos son multiset, set, 
multimap y map. En cada contenedor las claves se mantienen en orden. La iteración 
a través de un contenedor asociativo lo recorre en el orden del contenedor. Las 
clases multiset y set proporcionan operaciones para el manejo de conjuntos de 
valores en donde los valores son las claves, es decir, no hay otros valores asociados
con la clave. La diferencia principal entre un objeto multiset y uno set es que
multiset permite claves duplicadas y set no. Las clases multimap y map 
proporcionan operaciones para el manejo de valores asociados con la clave. La 
diferencia principal entre un objeto multimap y un objeto map es que multimap 
permite que se almacenen claves duplicadas con valores asociados, y map sólo 
permite claves únicas con valores asociados. Además de las funciones miembro 
comunes a todos los contenedores, los asociativos soportan otras funciones que 
incluyen find, lower_bound, upper_bound y count.

El Contenedor Asociativo multiset

Permite el almacenamiento y recuperación rápido de claves, con claves duplicadas. 
El ordenamiento de los elementos está determinado por un objeto de función 
comparadora. Por ejemplo, en un objeto multiset de enteros los elementos pueden 
estar ordenados en forma ascendente, ordenado las claves con el objeto de función 
comparadora less < int >. En todos los comparadores asociativos el tipo de las 
claves debe soportar la comparación adecuada basada en el objeto de función 
comparadora especificada, es decir, las claves ordenadas con less<int> deben 
soportar la comparación con operator<. Un objeto multiset soporta iteradores 
bidireccionales pero no de acceso aleatorio. 

Consideremos un ejemplo de uso:

#include <iostream>
#include <set>
using namespace std;

typedef multiset< int, less<int> > Tmse;
int main()
{
Tmse multisetent;
multisetent.insert(5);
multisetent.insert(5);
cout << " Despues de las inserciones existen " << multisetent.count(5)
<< " valores 5 en el contenedor";
Tmse::const_iterator resultado;
resultado = multisetent.find(5);
if( resultado != multisetent.end()) // el iterado no esta al final
cout << " se encontro el valor " << endl;
}
~

El Contenedor Asociativo set

Se utiliza para el almacenamiento y recuperación rápida de claves únicas.
Por lo demás, la implementación es idéntica a la de la clase multiset.

El Contenedor Asociativo multimap

Se utiliza para el almacenamiento y recuperación rápidos de claves y valores 
asociados, es decir, pares clave/valor. Cuando se hace una inserción en un objeto 
multimap o en un objeto map, se utiliza un objeto pair que contiene la clave y el 
valor. Un objeto de función comparadora como less<int > determina el 
ordenamiento de las claves. Un objeto multimap soporta iteradores bidireccionales 
pero no de acceso aleatorio. 
Consideremos un ejemplo de uso de multimap:

#include <map>
#include <iostream>
using namespace std;

typedef multimap< int, double, less< int> > Tmmed;
...
Tmmed pares;
cout << "Existen " << pares.count(5) << " pares de la clave 5 en el contenedor " << 
endl;

pares.insert(Tmmed::value_type(30, 110.3) );
pares.insert(Tmmed::value_type(30, 14.9) );
...
pares.insert(Tmmed::value_type(20, 16.87) );
for( Tmmed::const_iterator iter = pares.begin();iter != pares.end(); ++iter)
cout << iter->first << '\t'<< iter->second << endl;

La expresión Tmmed::value_type( 30, 110.3) crea un objeto pair donde first es la 
clave (15) y second es el valor asociado.

El Contenedor Asociativo map

Se utiliza para el almacenamiento y recuperación rápidas de claves únicas y valores 
asociados. Con un objeto map se especifica la clave y se obtiene rápidamente el 
dato asociado. Al proporcionar la clave en un operador de subíndice de un objeto 
map, se localiza el valor asociado con esa clave. Las inserciones y eliminaciones se 
pueden hacer en cualquier lugar de un objeto map.
Consideremos un ejemplo de código:

#include <map>
#include <iostream>
using namespace std;
...
typedef map< int, double, less< int> > Tmed;
...
Tmed pares;
cout << "Existen " << pares.count(5)
<< " pares de la clave 5 en el contenedor " << endl;
pares.insert(Tmed::value_type(30, 110.3) );
pares.insert(Tmed::value_type(30, 14.9) ); //ignora el valor duplicado
...
pares.insert(Tmed::value_type(20, 16.87) );
for( Tmed::const_iterator iter = pares.begin(); iter != pares.end(); ++iter)
cout << iter->first << '\t' << iter->second << endl;
pares[20] = 20.45; // cambia el valor asociado a 20

Tenemos las mismas operaciones que en multimap más el operador de índice.

Adaptadores de Contenedor

La STL proporciona tres adaptadores de contenedor: stack, queue y priority_queue. 
Los adaptadores no son contenedores de primera clase, debido a que no 
proporcionan la implementación de estructura de datos real en donde se puedan 
almacenar los elementos y a que no soportan iteradores. La ventaja de una clase de 
adaptador es que el programador puede elegir una estructura de datos subyacente 
adecuada. Las tres clases de adaptador proporcionan funciones miembro push y pop
que implementan los métodos adecuados para insertar y eliminar un elemento de 
cada estructura de datos de adaptador.

El Adaptador stack

La clase stack implementa la funcionalidad que permite inserciones y eliminaciones 
en un extremo de la estructura de datos subyacente, que es una estructura último en 
entrar primero en salir. Un objeto stack puede implementarse con cualquier 
contenedor de secuencia: vector, list y deque. De manera predeterminada un 
objeto stack se implementa como uno deque. Las operaciones de un objeto stack 
son: push para insertar un elemento en la parte superior de stack ( se implementa 
llamando a la función push_back del contenedor subyacente), pop para eliminar el 
elemento superior de stack (se implementa con pop_back), top para obtener una 
referencia al elemento superior de stack (se implementa con back, empty para 
comprobar si el objeto stack está vacío (se implementa con empty), y size para 
obtener el número de elementos que hay en stack (se implementa con size). Las 
implementaciones más eficientes de stack se obtienen con vector o deque.
Veamos un ejemplo de uso de stack:

#include <stack>
#include <vector>
#include <iostream>
using namespace std;
...
stack< int, vector< int > > PilaEntVector;
for (int i = 0; i < 10; ++i){
PilaEntVector.push(i);
}
while (!PilaEntVector.empty() ){
cout << PilaEntVector.top() << ' ';
PilaEntVector.pop();
}
cout << endl;

Hay que observar que pop no devuelve un valor.

El Adaptador queue

La clase queue permite inserciones al final de la estructura de datos subyacente y 
eliminaciones al inicio de esta, es decir, es una estructura de datos primero en 
entrar primero en salir. Un objeto tipo queue se puede implementar con las 
estructuras de datos de la STL list y deque. Por defecto se implementa con un 
objeto deque, con el que la implementación es más eficiente. Las operaciones más 
comunes de un objeto queue son: push para insertar un elemento al final de queue, 
pop para eliminar el elemento que está al inicio, front para obtener una referencia 
al primer elemento que hay en el objeto queue, back para obtener una referencia 
al último elemento, empty para determinar si el objeto está vacío, y size para 
obtener el número de elementos que hay en queue. 
Veamos un ejemplo de uso:

#include <queue>
#include <iostream>
using namespace std;
...
queue< double > valores;
valores.push(1.1);
valores.push(3.4);
valores.push(9.8);
while (!valores.empty() ){
cout << valores.front() << ' '; // no elimina
valores.pop();
}
cout << endl;

El Adaptador priority_queue

La clase priority_queue permite inserciones ordenadas en la estructura de datos 
subyacente y eliminación desde el principio de esta. Un objeto de tipo 
priority_queue se puede implementar mediante las estructuras de datos vector y 
deque de la STL. Por defecto se implementa con un objeto de tipo vector que da la 
implementación más eficiente. Los elementos que se agregan a un objeto 
priority_queue se insertan automáticamente por orden de prioridad, de manera que el de 
prioridad más alta será el primero en salir. La comparación de elementos se realiza
de forma predeterminada con el objeto de función comparadora less < T >, pero el 
programador puede proporcionar un comparador diferente.
Las operaciones comunes de un objeto priority_queue son: push para insertar un 
elemento de acuerdo con su orden de prioridad, pop para eliminar el elemento de 
prioridad más alta, top para obtener una referencia al elemento superior, empty 
para determinar si está vacío, y size para obtener su número de elementos. 
Consideremos un ejemplo de uso:

#include <queue>
#include <iostream>
using namespace std;
...
priority_queue< double > prioridades;
prioridades.push(1.1);
prioridades.push(9.8);
prioridades.push(3.4);
while (!prioridades.empty() ){
cout << prioridades.top() << ' '; // no elimina
prioridades.pop();
}
cout << endl;














