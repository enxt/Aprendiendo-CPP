##Otros aspectos de C++.html.

#### Otros aspectos de C++
En este módulo se presentan otras funcionalidades de C++, que facilitan la labor de 
programación y que contribuyen a mejorar la claidad de los programas. Una de estas 
técnicas es el uso de excepciones para el tratamiento de errores. Se presentan 
también las plantillas, el mecanismo que ofrece C++ para la programación de 
componentes genéricos (no se especifica un tipo de dato concreto). Las plantillas
permiten definir de forma genérica una familia de funciones o de clases. En este 
módulo se presenta también la biblioteca estándar de C++ que ofrece un conjunto de 
clases que implementan el concepto de contenedor. Un contenedor es un objeto 
capaz de almacenar una colección de objetos. Todos los contenedores están definidos 
como plantillas. Esto permite que se pueda especificar el tipo de los objetos 
almacenados en el contenedor.



##Tratamiento de excepciones.html.

#### 
Los errores que se pueden producir en el código de un programa se clasifican en dos 
grandes grupos: los que son detectados durante la compilación, y por lo tanto, 
pueden ser corregidos antes de que el programa llegue a funcionar, y los que se 
producen durante la ejecución. En este segundo grupo se encuentran generalmente 
los errores más difíciles de tratar, unas veces por tratarse de errores de estructura 
o lógicos, que no generan ningún tipo de aviso, pero provocan que el programa no 
haga lo que se espera de él, y otras porque son errores debidos a situaciones 
imprevistas. En los programas aparecen muchas situaciones cuyo resultado no puede 
preverse en todos los casos. Por ejemplo, se puede producir una división por cero, 
al abrir un archivo no podemos estar seguros de que exista, o al leer un dato, que 
esperamos que sea un entero puede ocurrir que no lo sea. Una posibilidad para 
tratar estas situaciones sería que nuestras funciones considerasen todos los casos 
posibles, pero esto sería muy tedioso de programar, poco flexible a las 
modificaciones que pudieramos realizar posteriormente, y daría lugar a un código 
poco legible. Por ello, la mayoría de los lenguajes de programamación existentes 
proporcionan alguna facilidad para tratar este tipo de situaciones.

C++ proporciona los medios necesarios para garantizar que las aplicaciones sean 
seguras, lo que significa que sean capaces de gestionar los errores de una forma 
elegante, sin estropear la legibilidad del código, permitiendo que la aplicación se 
recupere de los errores cuando sea posible y se interrumpa si es necesario, sin 
perder datos ni recursos. Los errores que se producen durante la ejecución de un 
programa y que provocan su ruptura, en C++ se gestionan mediante las denominadas**excepciones**. Las excepciones proporcionan un medio estructurado de separación 
de la lógica normal del programa de la lógica de gestión de errores, lo que aumenta 
en gran medida la facilidad de mantenimiento de las aplicaciones. Una excepción es 
una señal provocada por un error, tal como pueda ser una división por cero o el 
intento de acceder a los datos apuntados por un puntero nulo. Esta señal puede ser 
interceptada por el propio programa, procediendo a su tratamiento o solución, o 
bien por el código adicional añadido por el compilador, que se encargará de avisar 
mediante un mensaje de que se ha producido una excepción, interrumpiendo la 
ejecución del programa. Generalmente una excepción dispone de la información 
necesaria para conocer la causa y el punto en que se ha producido el error, 
ayudando así a su resolución. Dicha información la podemos aprovechar en nuestro 
código si interceptamos la excepción, o bien, si no la interceptamos, será mostrada
en un mensaje al usuario antes de que el programa se interrumpa.

En C++ una excepción es un objeto que contiene información sobre la existencia de 
un error y el lugar en que se ha producido. Las principales ventajas de esta 
representación de las excepciones son las siguientes:

• Las excepciones pueden agruparse en jerarqu´ıas utilizando la herencia.
• Pueden introducirse nuevas excepciones sin afectar al código existente.
• Un objeto de excepción puede transmitir información desde el punto en que se 
generó al punto en que se maneja.

Muchas situaciones de excepción y errores están ya considerados por el lenguaje, 
que los trata dando como mínimo un mensaje. Sin embargo en muchas ocasiones es 
más adecuado dar un tratamiento específico. 

#### Bloques que pueden generar excepciones


El primer paso para evitar las situaciones de ruptura en nuestro programa
es determinar qué sentencias o bloques de sentencias de nuestro código son
susceptibles de generar un error. Por ejemplo, al realizar una división por
un dato proporcionado por el usuario, debemos tener en cuenta que se puede
producir una división por cero y proteger esta sentencia.
Para evitar que la excepción generada por el programa lo interrumpa
debemos interceptarla y responder a ella según proceda. Para ello aislaremos
el bloque a proteger dentro de un bloque **try** y ****las sentencias a ejecutar en caso de
que se produzca una excepción en un bloque **catch**. El bloque **catch** siempre
va inmediatamente después del bloque **try**. Por ejemplo:

_try{_

```cpp
	Cociente = Dividendo / Divisor;	
```
_}_
_catch(...){___
```cpp
	 cout << "el divisor no puede ser cero" << endl;	
```
_}_La palabra **catch** va seguida de un paréntesis con unos puntos suspensivos en su 
interior, indicando así que deseamos interceptar cualquier tipo de excepción que 
pueda producirse en el bloque **try**. Al ejecutar el programa, las sentencias dispuests 
tras la palabra** try** se ejecutan siempre, según el flujo normal de programa, mientras 
que las sentencias escritas a continuación de **catch** se ejecutan sólo en caso de que 
se produzca la excepción. Si ejecutamos un programa que contenga la construcción 
anterior y proporcionamos un divisor nulo, veremos que el programa no se 
interrumpe, sino que simplemente se muestra el mensaje.

#### Clases de excepciones


En el ejemplo anterior el control de la excepción es muy simple, ya que en la 
sentencia protegida no se puede producir otro error que no sea el de división por 
cero. Sin embargo, en la mayoría de los casos no todo es tan simple y puede ocurrir 
que en un mismo bloque se produzcan distintas excepciones, provocadas por 
distintos errores. Al producirse una excepción, automáticamente se crea un objeto 
con información acerca de ella. Este objeto pertenecerá a una determinada clase o
tipo, que nos puede servir para determinar qué error es el que se ha producido
de una forma simple. Con el fin de diferenciar en nuestro código las sentencias
que se deben ejecutar en un caso u otro dependiendo del tipo de excepción
que se produzca, tras la palabra **catch**, entre paréntesis, escribiremos la clase
de excepción a la que se desea responder, seguida de un nombre de objeto
que nos servirá para poder recuperar más información acerca de la excepción:

_try_
_{_
_..._
_}_
_catch(tipo1 arg1)_
_{_
_..._
_}_
_catch(tipo2 arg2)_
_{_
_..._
_}_

Si el tipo de la excepción lanzada coincide con el tipo del argumento de una
sentencia **catch**, se ejecuta el bloque de código correspondiente. El parametro _arg_
es un nombre de parámetro opcional.
__

#### Mecanismos de lanzamiento de excepciones


Cuando se detecta una excepción esta se lanza usando una sentencia **throw**, dentro
del bloque **try**. El formato de esta instrucción puede ser de dos formas. La primera
de ellas es:

```cpp
	throw exception;```
El operando excepción puede ser de cualquier tipo, incluyendo objetos.
__Veamos un ejemplo completo:

_#include <iostream>_
_using namespace std;_

_void test(int x)_
_{_
```cpp
	try{		if (x == 1) throw x; //int		
		else		
			if(x == 0) throw 'x'; // char			
		else		
			if(x == -1) throw 1.0; //double			
		cout << "Fin de bloque try" << endl;		
			}	
	catch(char c)	
	{		cout << "Captura de un caracter " << endl;		
			}	
	catch(int m)	
	{		cout << "captura de un entero " << endl;		
			}	
	catch(double d)	
	{		cout << "Captura de un double " << endl;		
			}	```
___}_
_int main()_
_{_

```cpp
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
```
_}_El programa muestra un ejemplo en el que se utilizan distintas sentencias catch para 
manejar distintos tipos de excepciones
__#### Excepciones propias


La biblioteca estándar de C++ proporciona una clase base diseñada específicamente 
para declarar objetos que se lancen como excepciones. Esta clase se denomina**exception** y se define en el archivo cabecera **<exception>**, bajo el _namespace std_.
Esta clase tiene los constructores usuales por defecto y por copia, y destructor, 
más una función miembro virtual adicional denominada **what** que devuelve una
secuencia de caracter terminada en _null_ y que puede sobreescribirse en las clases
derivadas para que contenga una descripción de la excepcion.
_// excepciones estandar__#include <exception>__using____namespace__ std;__class__ miexcepcion: __public__ exception_

```cpp
