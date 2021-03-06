##1.- Programación Orientada a Objetos en C++.

####1.1.- Programación Orientada a Objetos en C++

A medida que las aplicaciones se van haciendo más complejas, el mantenimiento del código se hace más difícil, aunque esté correctamente estructurado en funciones y dividido en múltiples módulos. Siguiendo el modelo clásico de programación estructurada, nuestro programa puede llegar a presentar decenas o centenas de funciones, cada una de las cuales necesita ciertos parámetros para su funcionamiento. En esta situación no es extraño llamar a veces a la función correcta con parámetros que no lo son o viceversa, como tampoco lo es que ciertas acciones se diferencien de otras sólo en pequeños detalles y, sin embargo, nos veamos forzados a escribir nuevos grupos de funciones. Muchos de estos problemas se
solucionan con la denominada Programación Orientada a Objetos (POO). Es una evolución de los lenguajes estructurados en una búsqueda de simplificación del mantenimiento del código y de mayores posibilidades de utilización. La POO introduce una nueva forma de abordar la programación en la que los datos están asociados de forma indisoluble a su forma de manipularlos.
Permite además ocultar la representación interna del dato, facilitando así el objetivo de la reutilización del software.

####1.2.- Conceptos básicos de la POO

Existe una terminología específica para POO que comenzaremos estudiando:

**Encapsulación**
Consiste en combinar los datos y su manipulación en una única entidad.
Es propia de los Objetos y de los TAD (Tipos Abstractos de Datos). Partiendo de un diseño correcto de los tipos de objetos, los datos que se declaren en el interior del objeto sólo serán manipulados por los métodos de ese objeto y, recíprocamente, los métodos del objeto estarán especializados en la manipulación de los datos de esa clase. En cierto modo se aisla a los datos y métodos de un objeto como si se tratase de una cápsula, impidiendo que se usen parámetros erróneos al llamar a un método, o que se modifique erróneamente el valor de un dato. La encapsulación es uno de los pilares de la POO que facilita en mantenimiento de código, ya que usando la definición de un objeto y sus métodos podemos estar seguros de que forman una unidad independiente del resto de la aplicación.

**Clase**
Es una estructura o plantilla que representa a cualquier concepto o abstracción. Esta estructura agrupa tanto variables, que constituyen los campos o atributos de la clase, como procedimientos y funciones, que se denominan métodos. A los elementos de una clase se les denomina genéricamente miembros.

**Objetos**
Un objeto es una instancia o ejemplar de una clase. Es decir, un objeto representa a un elemento particular de una cierta clase. Puede decirse que el objeto es a la clase como la variable es al tipo. Sin embargo, no debemos confundir a los objetos con las variables, ya que mientras las variables son estáticas, los objetos son dinámicos y se crean y destruyen durante la ejecución.

**Herencia**
Es la capacidad de construir clases a partir de otras, expresando solamente las diferencia de ésta en relación a aquellas. La herencia da una gran potencia a la POO ya que permite reutilizar al máximo las clases ya definidas. Las clases, a partir de las cuales se construyen las nuevas, se denominan clases padre o **clases de base**, mientras que la nueva clase se denomina **clase derivada**. La relación de clase padre entre las clases establece una **jerarquía de clases**.

Existen dos formas comunes de herencia: **la herencia simple y la herencia múltiple**. En la herencia simple se hereda de una sola clase base. Esto significa que declaramos una clase en relación a otra, que a su vez puede ser declarada en relación a otra, etc.
La herencia múltiple permite heredar de varias clases, es decir, que podemos declarar una nueva clase a partir de varias clases al mismo tiempo. La clase derivada es entonces un caso particular de cada una de las clases base.

**Polimorfismo**
Es la posibilidad de considerar una instancia de una clase también como una instancia de las clases de base de dicha clase.

**Niveles de Confidencialidad**
Los elementos de una clase, tanto datos como métodos, pueden protegerse del acceso indiscriminado desde otros módulos o programas, de manera que contamos con recursos para especificar que algunos de ellos no son accesibles o que lo son sólo por ciertas clases. Los lenguajes orientados a objetos implementan generalmente tres niveles de encapsulación:

1. Privado
Estas declaraciones sólo son accesibles al propio objeto.
2. Público
Otros programas o módulos pueden acceder a ellos.
3. Protegido
Están en un punto intermedio entre los otros dos niveles, y se trata de elementos que sólo son accesibles por el propio objeto y por objetos de clases derivadas de la del objeto.


##2.- Clases y objetos.

####2.- Estructura de una clase en C++

C++ es un lenguaje totalmente orientado a objetos, seguramente el más utilizado, contando con todos los elementos típicos de un lenguaje orientado a objetos, como la encapsulación, la herencia y el polimorfismo.

La **estructura general** de una declaración de clase tiene la siguiente forma:
```cpp
class nombre clase {
	public:
		{Variables y métodos con nivel de protección "public"}
	protected:
		{Variables y métodos con nivel de protección "protected"}
	private:
		{Variables y métodos con nivel de protección "private"}
};
```

Las variables de la parte **public** están a disposición de otros procedimientos, es decir, forman la interfaz del objeto a la que se puede acceder desde otras partes del programa. La interfaz de un objeto debe mantenerse siempre lo más pequeño posible para no permitir manipulaciones innecesarias. Las partes de un objeto que no deben ser manipuladas desde el exterior deben escribirse en el bloque de declaraciones **private**. El nivel de protección **protected** tiene básicamente el mismo comportamiento mientras no se utilice ninguna herencia. Sin embargo los elementos declarados **private** no pueden accederse desde clases derivadas, únicamente desde la propia clase, mientras que los **protected** si pueden ser accedidos.

**Ejemplo:**

```cpp
class TCirculo {

	public:
		void AsignarDatos(int intX, int intY, int intRadio);
		void Mostrar();
	private:
		int x,y, radio; /*estas variables no son manipulables
					     solo los metodos AsignarDatos y Mostrar pueden
					     acceder a ellas */
};
```

####1.3.- Uso de un Objeto

Lo primero que necesitamos es declarar una variable del tipo de la clase, igual que haríamos con cualquier otra variable. También podemos declarar un puntero a dicha clase, en cuyo caso será necesario crear el objeto mediante el operador **new**.
Una vez que se ha creado una instancia del objeto por cualquiera de los dos métodos anteriores, podemos acceder a sus miembros, manipulando las variables o llamando a los métodos. El acceso se realiza con el nombre del objeto, seguido de un punto y el nombre del método o el atributo. La manipulación directa de las variables privadas provocaría un error al compilar.

```cpp
circulopeque.x = 50; // ERROR_
```
Deben accederse mediante lo métodos públicos:

**Ejemplo:**
```cpp
TCirculo circulopeque, *circulogrande;
circulogrande = new TCirculo;
circulopeque.AsignarDatos( 50, 50, 30);
circulogrande->AsignarDatos( 100, 100, 80);
```

Observese que al ser _circulopeque_ declarado como una variable, sus métodos se acceden con .metodo, mientras que en _circulogrande_, al ser un puntero, sus métodos se acceden con ->metodo.



##3.- Las clases como tipo de datos.

####3.1.- Implementación de Métodos

Mientras la declaración de las variables es suficiente para su definición, los métodos aún deben ser definidos. Esto puede hacerse, por ejemplo, en el módulo de implementación, asociado al módulo cabecera que contiene la clase. La implementación del método tiene como cabecera la misma que se haya dado en la definición de la clase, con la única diferencia de que delante del identificador del método, _AsignarDatos_ o _Mostrar_, hay que escribir la clase del objeto, _TCirculo_, separando ambos componentes mediante el operador **::**, al que se denomina operador de resolución de ámbito. De esta forma el compilador sabrá que ese código pertenece a la definición de un método del objeto _TCirculo_, y no a una función cualquiera. Por ejemplo la implementación de la función _AsignarDatos_ podría ser la siguiente:

**Ejemplo:**

```cpp
void TCirculo::AsignarDatos(int intX, int intY, int intRadio);
{
	X = intX;
	Y = intY;
	radio = intRadio;
};
```
A las variables de la instancia se les asignan simplemente los valores enviados. Al llamar al método hay que referirse a una instancia concreta, es decir un objeto.

**Ejemplo:**

```cpp
TCirculo circulopeque;
circulopeque.AsignarDatos( 50, 50, 30);
```

También es posible llamar a otros métodos desde el método. Entonces estos métodos seguirían trabajando con la instancia particular con la que se llamó al primer método.

**Ejemplo:**

```cpp
TCirculo =
class TCirculo {

private:
	int x,y, radio;
	void AsignarX(int intX);
	void AsignarY(int intY);
	void AsignarRadio(int intRadio);

public:
	void AsignarDatos(int intX, int intY, int intRadio);
};

void TCirculo::AsignarDatos(int intX, int intY, int intRadio)
{
	AsignarX(intX);
	AsignarY(intY);
	AsignarRadio(intRadio);
}
```

Lo usual es almacenar la definición de la clase en un archivo con extensión .h (_nombre.h_) y la implementación de los métodos en uno con el mismo nombre y extensión .cpp (_nombre.cpp_), que hece un include de nombre.h.


####3.2.- Constructores y destructores

Normalmente, cuando creamos la instancia de una clase, como de TCirculo, un objeto, a continuación llamaremos a algún método de inicialización, como AsignarDatos con el fin de facilitar un valor inicial. Es decir, normalmente, detrás de la declaración de la variable, o la asignación dinámica mediante el operador **new**, tendremos una llamada a un método de este tipo. De igual forma, es habitual que antes de destruir el objeto y liberar la memoria asignada se haga uso de otro método del objeto, con el fin de liberar cualquier memoria o recursos que hayan sido asignados internamente por él. Supongamos que queremos crear una clase que nos permita trabajar con matrices de tamaño dinámico, establecido durante la ejecución. Al crear un objeto de este tipo, al que llamaremos _Tmatriz_ será necesario indicarle el número de elementos que deseamos, dato con el que el método de inicialización se encargará de asignar la memoria necesaria. De igual forma, antes de destruir el objeto será necesario liberar la memoria que se asignó para la matriz, por lo que también necesitaremos un hipotético método _Libera_(). Tendremos por tanto, que solo la creación y la destrucción del objeto generarían al menos cuatro instrucciones. Con el fin de facilitar los procesos de inicialización y destrucción de objetos, C++ dispone de unos métodos especiales a los que se denomina **constructores** y **destructores**. Para una misma clase pueden existir varios constructores, y son métodos cuyo nombre coincide con el de la clase y se caracterizan por no tener tipo de retorno, ni siquiera void. Para una clase sólo puede existir un destructor, y es un método que al igual que el constructor tiene por nombre el de la clase a la que pertenece, aunque en este caso precedido por una tilde. Un destructor no toma ni devuelve parámetros.

El constructor puede considerarse el encargado de construir el objeto, asignando la memoria necesaria y dándole valores iniciales a los distintos miembros. De igual forma que una función, un constructor puede recibir los parámetros que sean necesarios, aunque no puede devolver un valor. Al declarar un objeto de la clase se llamará automáticamente al constructor adecuado, según los parámetros que se hayan facilitado. Análogamente, el destructor es el encargado de destruir el objeto, liberando la memoria asignada. El destructor se ejecuta automáticamente cuando la variable declarada sale de su ámbito, o bien cuando se libera de forma explícita en caso de haber sido creado dinámicamente.

En el archivo de cabecera **TMatriz.h** podemos definir la clase del objeto _TMatriz_, con un constructor y un destructor, además de dos métodos auxiliares que son usados en un programa.

```cpp
class TMatriz
{
private:
	int * Elementos; // Puntero a la zona de memoria donde estara la matriz
	int NumElementos; // Numero de elementos de la matriz
public:
	// El constructor asigna la memoria
	TMatriz(int Num);
	// Metodo para asignar un valor a un elemento
	void Asigna(int Num, int Valor);
	// M'etodo para obtener le valor de un elemento
	int Valor(int Num);
	// El destructor libera la memoria asignada
	~TMatriz();
};
```

**TMatriz.cpp** escribimos la implementación de los métodos:

```cpp
TMatriz::TMatriz(int Num)
{
	NumElementos = Num; // Conservar el numero de elementos
	Elementos = new int[NumElementos]; // y asignar la memoria
}

void TMatriz::Asigna(int Num, int Valor)
{
	Elementos[Num] = Valor;
}

int TMatriz::Valor(int Num)
{
	return Elementos[Num];
}

TMatriz::~TMatriz()
{
	// Liberar la memoria asignada
	delete [] Elementos;
}
```

En el siguiente fragmento de programa podemos ver como al declarar una variable de tipo _TMatriz_ se indica el número de elementos que se desean, momento en el cual se ejecuta el constructor de la clase asignando la memoria necesaria. Podemos observar que para liberar el objeto no se hace una llamada explícita, ya que el destructor se ejecuta automáticamente cuando la variable Tabla sale de ámbito, en este caso cuando la función _main()_ finaliza.

```cpp
#include <iostream>

main()
{
	TMatriz Tabla(20);
	Tabla.Asigna(5, 18);
	cout << "valor = " << Tabla.Valor(5) << endl;
	return 0;
}
````

####3.3.- Métodos Estáticos

En los ejemplos que hemos visto hasta el momento, para poder llamar a un método de una clase siempre hemos creado antes una instancia de dicho tipo, y a través de este objeto hemos realizado la llamada. El objeto y sus métodos están encapsulados, por lo que cuando llamamos a un método no es necesario pasarlo como parámetro. C++ también nos permite definir miembros estáticos, nombre por el que se conoce a aquellos métodos y datos que no pertenecen a una instancia particular de la clase, sino que son miembros generales del tipo. La declaración de un miembro estático es similar a la de cualquier otro miembro, con la diferencia de que delante pondremos la palabra static. Un método estático no puede ser un constructor ni un destructor, ya que estos métodos sirven para crear o destruir una instancia, mientras que un método estático se caracteriza por no estar asociado a ningún objeto. Para llamar a un método estático no es preciso crear antes un objeto de esa clase, basta con especificar el identificador del tipo, seguido por el identificador del método, separados por el operador de ámbito. En el siguiente ejemplo se efectúa una operación no válida que generará un error de compilación, ya que se intenta acceder a un miembro que sólo existe en el interior del objeto.

```cpp
class TObjeto // Un objeto simple
{
	private:
		int N; // que tiene un miembro de datos
	public:
		static string Tipo(); // y un m'etodo estático
};

// Implementacion del metodo
string TObjeto::Tipo()
{
	//N = 5; // Operacion NO valida, N no existe a este nivel
	return "TObjeto";
}
```

Como vemos en el siguiente ejemplo, se hace una llamada directa a un método estático sin necesidad de crear un objeto.

```cpp
main()
{
 cout << TObjeto::Tipo() << endl;
}
```

Un método estático está muy limitado en cuanto a los miembros del objeto que
puede utilizar, ya que pueden no existir. De forma general, cualquier método estático no tendrá acceso a aquellos miembros que pertenecen a un objeto en particular, o lo que es lo mismo, no tendrá nunca acceso a ningún miembro de datos del objeto a no ser que se llame a dicho miembro en la forma habitual, creando un objeto previamente.

####3.4.- El objeto this

Cuando se llama a un método, sin necesidad de parámetro alguno, este puede acceder a los miembros de datos del objeto que se ha utilizado para realizar la llamada. En realidad, cada vez que realizamos una llamada a un método, el objeto correspondiente, que especificamos delante del nombre del método separado por un punto, se pasa al método como un parámetro oculto llamado **this**. Este parámetro, por lo tanto, representa al objeto que ha llamado a un método y puede ser usado como cualquier otra referencia a un objeto. Cuando se llama a un método estático sin haber creado previamente un objeto, sino facilitando el identificador de clase, dichos métodos no tienen el correspondiente parámetro **this**, de ahí que no puedan acceder a los miembros de datos del objeto.


##4.- Herencia.

####4.1- La herencia en C++

Otra de las características de los lenguajes orientados a objetos es la herencia, que facilita la reutilización de código. La herencia permite crear una clase a partir de otra ya existente, acción que se conoce como derivación. Al tipo original se le conoce como tipo base o ascendiente, mientras que al nuevo tipo, que hereda las características del anterior se le llama tipo derivado o descendiente.
Supongamos que hemos diseñado una clase, _TEntidad_, para mantener información genérica sobre entidades gráficas en una pantalla. Un objeto de esta clase almacenará la posición y color de una entidad, para lo que dispondrá de miembros de datos y de métodos para recuperar esa información.

```cpp
// Esta clase es genérica, y almacena los datos mínimos de__ cualquier entidad
class TEntidad
{
	private:
		TPunto Posicion; // Posicion
		unsigned char Color; // y color de la entidad
	public:
		// El constructor recibira tres parametros
		TEntidad(int X, int Y, unsigned char C);
		// Esta funcion devolvera el nombre del objeto
		static string Clase();
		int PosX(); // Funciones que devolveran las
		int PosY(); // coordenadas del punto
};
```

Si ahora queremos crear una clase más específica, concretamente para mantener la información correspondiente a entidades gráficas de tipo círculos, debemos almacenar una posición que será el centro, un color y un radio. Podemos observar, que a excepción del radio, los restantes elementos estaban ya presentes en la clase _TEntidad_. Sin embargo, queremos que el tipo_ TEntidad_ siga existiendo como tal, sin modificarlo, por lo que la única opción posible, si no queremos crear un tipo desde cero, es hacer que el nuevo tipo que vamos a crear, _TCirculo_, herede las características de _TEntidad_. La sintaxis para derivar una clase a partir de otra consiste en facilitar el nombre de la clase base detrás del nombre de la nueva clase y separado por dos puntos. Sólo con esto ya conseguimos que el tipo derivado herede todos los miembros de la clase base, tanto de datos como métodos.

```cpp
// Esta clase esta especializada para objetos circulo,
// y hereda las caracter'isticas de la anterior
class TCirculo : TEntidad
{
	private:
		int NRadio; // Para guardar el radio
	public:
		static string Clase(); // Devuelve el nombre del objeto
		int Radio(); // Devuelve el radio del círculo
};
```

Podemos observar que en _TCirculo_ no se han declarado los miembros necesarios para almacenar el centro o el color, ya que se heredan de _TEntidad_, al igual que los métodos _PosX_ y _PosY_. Por lo tanto, cuando creemos una instancia de TCirculo podremos usarlos como si se hubieran declarado en la propia clase.

####4.2.- Limitaciones de Acceso

Como ya hemos visto, los miembros de una clase se pueden definir con distintos niveles de protección: públicos, privados o protegidos. Los miembros _Posicion_ y _Color_ de _TEntidad_ son privados, lo que quiere decir que sólo podrán ser accedidos por las instancias de esta clase. Ni siquiera las instancias de _TCirculo_, un descendiente de _TEntidad_ tiene acceso a esos miembros. Por el contrario, el constructor y los métodos de _TEntidad_ son públicos, de forma que pueden ser usados desde fuera del objeto por cualquier programa, y, por tanto, por cualquier objeto de una clase derivada de ésta como _TCirculo_. Cuando queramos definir una clase con miembros que no sean públicos, pero que estén accesibles a las posibles clases que se deriven de él, tendremos que utilizar el apartado **protected**.
El ámbito de los miembros de una determinada clase también puede ser alterado en el momento en que se deriva una nueva clase, disponiendo delante del nombre de la clase una de los modificadores **private**, **protected** o **public**. Entonces, todos los miembros heredados pasarán a formar parte de la sección privada, protegida o pública, según se haya indicado. Si no se especifica explícitamente, la derivación se realiza pasando todos los miembros heredados a la sección privada (los métodos públicos de la clase base se convierten en privados).

```cpp
// Esta clase esta especializada para objetos circulo,
// y hereda las caracteristicas de la anterior
class TCirculo : public TEntidad
{
	private:
		int NRadio; // Para guardar el radio
	public:
		TCirculo(int X, int Y, unsigned char Color, int Radio);
		static string Clase(); // Devuelve el nombre del objeto
		int Radio(); // Devuelve el radio del circulo
};
```

####4.3.- Transitividad de la herencia

La herencia es una característica que cuenta con la propiedad transitiva. Por esto, si la clase TEntidad está derivada de TObjeto y la clase TCirculo está derivada de TEntidad, entonces TCirculo indirectamente deriva de TObjeto, por lo que también hereda los miembros de esta clase.


##5.- Objetos y memoria dinámica.

####5.1.- Construcción de un Objeto

Una de las posibles formas de construir un objeto consiste en declarar una variable de la clase, momento en que se llama automáticamente al constructor adecuado. Una misma clase de objeto puede contar con múltiples constructores, recibiendo cada uno parámetros diferentes. Esto permite construir objetos a partir de diferentes datos. En muchos casos ocurrirá que una clase que actúa como base disponga de un constructor que recibe una serie de parámetros, que serán accesibles a los objetos de los tipo descendentes. Por ejemplo, un objeto _TCirculo_ recibe como parámetros la posición del centro, el radio y el color. Esta clase deriva de _TEntidad_, cuyo constructor necesita tres de estos cuatro parámetros. Por lo tanto, será necesario llamar al constructor de _TEntidad_ desde el constructor de _TCirculo_ pasándole los parámetros que corresponda. De esta forma, la clase base construirá una parte del objeto y la descendiente la otra parte. Para poder llamar desde un constructor de una clase al constructor de la clase base que corresponda, en la implementación dispondremos detrás de la cabecera, antes de abrir las llaves que delimitan el cuerpo del código, el nombre de la clase base y facilitaremos entre paréntesis los parámetros que correspondan.

```cpp
// Implementaci'on del constructor de la clase TEntidad
TEntidad::TEntidad(int X, int Y, unsigned char C)
{
	Posicion.X = X; // Preservar las coordenadas
	Posicion.Y = Y;
	Color = C; // y el color
}

// Implementaci'on del constructor de la clase TCirculo
TCirculo::TCirculo(int X, int Y, unsigned char C, int R)__: TEntidad(X, Y, C)
{
	NRadio = R; // Preserva el radio
}
```

####5.2.- Redefinición de métodos

Las clases _TEntidad_ y _TCirculo_ tienen definido un método _Clase()_, cuya finalidad es devolver una cadena facilitando un nombre del tipo del objeto. Al ser _TCirculo_ una clase derivada de TEntidad, hereda automáticamente el método _Clase()_, pero dado que entonces no se devolvería la cadena correcta, lo que hacemos es redefinir en _TCirculo_ un método que ya existía por haberlo heredado de un tipo base. Esto es algo que se hace con frecuencia.

```cpp
// Implementacion del metodo de clase Clase
string TEntidad::Clase()
{ // Que devuelve una cadena con el nombre del objeto
	return "TEntidad";
}
// Implementacion del metodo de clase Clase
string TCirculo::Clase()
{
	return "TCirculo"; // Devolver el nombre de la clase
}
```

Al crear un objeto de un determinado tipo este siempre hará uso de los métodos definidos en el propio tipo y solo llamará a los del tipo base cuando el método no haya sido redefinido. Una clase base, como _TEntidad_ puede verse como un subconjunto de la clase derivada _TCirculo_ ya que en la clase derivada existen todos los métodos de la clase base más posiblemente otros adicionales. Por tanto, si nosotros declaramos un puntero del tipo _TEntidad_ y al crear el objeto llamamos al constructor de _TCirculo_, el compilador lo acepta, ya que en _TCirculo_ existen todos los miembros de _TEntidad_. Sin embargo, lo contrario no es cierto. Una variable del tipo _TCirculo_ no podría apuntar a un objeto _TEntidad_, ya que éste no dispone del método _Radio_ o de la variable _NRadio_, que podrían intentar ser accedidos mediante dicha variable. En el siguiente ejemplo, el método _Clase()_ devuelve el mismo valor, ya que aunque _Elemento_ apunte a un objeto de tipo _TCirculo_ realmente usa los métodos de la clase _TEntidad_, debido a que la variable es de ese tipo.

```cpp
main()
{
	TEntidad * Elemento;
	// Elemento apunta a un objeto TEntidad
	Elemento = new TEntidad(120, 80, 5);
	cout << Elemento->Clase() << endl;
	delete Elemento;
	// Elemento apunta a un objeto TCirculo, que en
	// su interior contiene un tipo TEntidad
    Elemento = new TCirculo(120, 80, 20, 5);
	cout << Elemento->Clase() << endl;
	delete Elemento;
}
```

##6.- Vinculación dinámica, poliformismo y clases abstractas.

####6.1.- Polimorfismo

Decíamos que las características principales de la POO son la encapsulación, la herencia y el polimorfismo. Una vez conocidos los dos primeros vamos a ocuparnos del tercero, quizá el más difícil de entender. La idea es que un objeto pueda pertenecer a varias clases. Pero, ¿para qué queremos que una variable de una cierta clase apunte a un objeto de otra clase, aunque sea una clase derivada?. Porque esto nos va a permitir manipular objetos de distintos tipos de una forma genética, ahorrando mucho código. Por ejemplo, supongamos una clase _TVehiculo_ que va a ser la clase base de tres clases _TBicicleta, TCiclomotor y TAutomovil_, de las que a su vez se derivan otras clases. Supongamos que tenemos una serie de objetos de estos tipos. Los podemos almacenar en una matriz de tipo _TVehiculo_, ya que una matriz de esta clase puede contener objetos de cualquiera de los tipos descendentes. Mediante esta matriz y un bucle podríamos llamar a un hipotético método _Nombre()_, que devolviese el nombre de cada objeto o a un método _Ruedas()_, que devolviese el número de ruedas del vehículo.

```cpp
TVehiculo * X[5]; // Matriz de objetos TVehiculo
// Creamos una serie de objetos derivados de TVehiculo
X[0] = new TBicicletaMontana(18);
X[1] = new TAutomovil(5, false, 110);
X[2] = new TBicicleta;
X[3] = new TBicicletaMontana(21);X[4] = new TAutomovil(4, true, 280);

// Mostrar el nombre del vehiculo y los datos generales
cout << X[N]->Nombre() << " " << X[N]->NumeroDeEjes();
cout << X[N]->NumeroDeRuedas() << endl;

```

Sin embargo, queda un problema por resolver, ya que aunque una clase derivada puede redefinir un método heredado, si le asignamos a una variable de la clase base se seguirá llamando al método original.

####6.2.- Métodos Virtuales

Los objetos cuentan con un enlace o asociación con los métodos de su clase. En general, este enlace se realiza durante la compilación y por ello, una variable que haya sido declarada de tipo _TVehiculo_ llamará a los métodos de esta clase aunque en realidad contenga un objeto de clase _TAutomovil_. Hay que tener en cuenta que la creación de los objetos se produce durante la ejecución, por lo que el compilador no puede saber de antemano si una variable de la clase _TVehiculo_ va a apuntar a un objeto de esta clase o de una derivada.
La solución a este problema consiste en enlazar el objeto con los métodos que le corresponden durante la ejecución, y no en la compilación. Esta técnica de enlace en ejecución permite una gran flexibilidad, pero a cambio se paga en tamaño de código y en velocidad. Por ello el enlace dinámico o en ejecución no se utiliza de una forma generalizada y sólo se aplica a aquellos métodos que han sido definidos como **virtuales**. Un método virtual es un método de una clase que puede tener una implementación diferente en sus subclases.
Un método virtual se declara colocando la palabra **virtual** delante del nombre al declarar el método en la clase. No es necesario hacer lo mismo en la implementación. Un método tan sólo será declarado como virtual en la clase base, en nuestro caso _TVehiculo_, mientras que en las clases descendentes simplemente se redefinirá. Esto asegura que el método que se redefine no se enlaza en la compilación, sino en la ejecución. Una determinada clase no puede declarar un método como virtual si este se ha heredado de otra clase en la que no estaba definido como tal.

####6.3.- Clases Abstractas

Es habitual cuando se está creando una jerarquía de clases que se cree un tipo base que sea el que fije los miembros genéricos de todos las clases descendientes. Sin embargo, muchas veces los métodos que serán redefinidos en esas clases no tienen ningún significado en la clase base, ya que su finalidad es únicamente la de implementar una interfaz común. Por ejemplo, ¿que devolvería el método _Ruedas_ aplicado a un objeto de tipo _TVehiculo_?.

En estos casos lo que se hace es declarar el método como virtual puro, que es un método que no se implementa en la clase base sino en las descendentes.

Para definir un método como virtual puro añadimos al final de la declaración el signo **=** y el número **0**. Las clases que cuentan con al menos un método virtual puro se denominan clases abstractas, no siendo posible crear objetos de estas clases. En nuestro ejemplo, la clase TVehiculo sería una clase abstracta, ya que el método _Nombre()_ se declara como virtual puro. Sin embargo, los métodos _NumeroDeEjes()_ y _NumeroDeRuedas()_ no se declaran como virtuales, sino que se implementan en la clase base usando las variables que almacenan la información que necesitan. De esta forma se evita la sobrecarga que supone en velocidad y tamaño la definición y posterior redefinición de dos métodos como virtuales. Sin embargo esto no siempre es posible, ya que por ejemplo el nombre no está almacenado en ninguna variable.

```cpp
class TVehiculo
{
	private: // Miembros de datos, privados
		short NEjes, NRuedas;
		bool TieneMotor;
	public: // Metodos publicos
		// El constructor toma como tres parametros
		TVehiculo(short Ejes, short Ruedas, bool Motor);
		/* Esta funcion es virtual abstracta, lo que significa
		que no tiene implementacion en esta clase, y
		tendra que ser necesariamente implementada por
		los descendientes de TVehiculo */
		virtual string Nombre() = 0;
		// Estas funciones son informativas, y serviran para
		// obtener algunos datos del vehiculo
		short NumeroDeEjes();
		short NumeroDeRuedas();
		bool FuncionaConMotor();
};

// La clase TBicicleta esta derivada de TVehiculo,
// heredando sus miembros y metodos
class TBicicleta : public TVehiculo
{
	public:
		TBicicleta(); // El constructor no necesita parametros
		string Nombre(); // Se redefine el metodo Nombre
};

// La clase TBicicletaMontana esta derivada de TBicicleta
class TBicicletaMontana : public TBicicleta
{
	private:
		short NCambios; // N'umero de cambios
	public:
		TBicicletaMontana(short Cambios); // Constructor
		string Nombre(); // Redefinimos el metodo Nombre
		short NumeroDeCambios(); // Devuelve el numero de cambios
};

// La clase TAutomovil esta derivada de TVehiculo, y no
// de TBicicleta, abriendo asi una nueva rama en la jerarquia
class TAutomovil : public TVehiculo
{
	private:
		short NCambios; // N'umero de cambios
		bool CAutomatico; // Cambio automatico
		int NPotencia; // Potencia en caballos
	public:
		// El constructor recibe los datos adicionales necesarios
		TAutomovil(short Cambios, bool Automatico, int Potencia);
		string Nombre(); // Redefinimos el metodo nombre
		short NumeroDeCambios(); // Y anhadimos los metodos necesarios
		bool EsAutomatico(); // para devolver el resto de los datos
		int Potencia();
};
```

####6.4.- Información de Tipos en Tiempo de Ejecución

Ahora ya podemos construir en un programa la matriz de vehículos, en la que cada uno de los elementos puede ser de un tipo. Si llamamos al método _Nombre()_ de cualquiera de los elementos, por ejemplo _X[1]->Nombre()_ obtenemos en cada caso el resultado apropiado. Aunque los elementos de la matriz X son todos iguales, los objetos a los que apuntan no lo son, y de hecho, algunos de ellos, como _TAutomovil_ cuentan con métodos que no están definidos en el resto de las clases, como ocurre con el método _Potencia()_. Para poder llamar al método _Potencia()_ correspondiente al objeto _TAutomovil_ al que apunta _X[1]_, será necesario realizar una conversión de tipo que podemos realizar con los moldeadores de tipo. Entonces la siguiente instrucción será válida:

```cpp
cout << (TAutomovil *)X[1]->Potencia() << endl;_
```

Pero antes de realizar un moldeado de esta forma hemos de asegurarnos de que el tipo al que apunta la variable es realmente el que suponemos, ya que de lo contrario el resultado estará indefinido. Para comprobar la clase de un objeto utilizaremos el operador **typeid**. Este operador puede tomar como parámetro un objeto o un nombre de tipo, devolviendo un objeto, de la clase **typeinfo**, con información de tipo obtenido en tiempo de ejecución.
La comprobación podría tener la siguiente forma:

```cpp
cout << "nombre del tipo = " << typeid(*X[1]).name() << endl;
````

El método **name** nos devolverá un puntero a una cadena con el nombre de la clase que se almacena internamente.

C++ ofrece la posibilidad de realizar moldeados de tipo dinámicos, mediante **dynamic_cast**, que realiza la conversión de un tipo a otro sólo si el tipo al que se desea convertir es válido, y generando un error en caso contrario.

```cpp
cout << dynamic_cast<TAutomovil *>(X[1])->Potencia() << endl;
````

Para usar estos operadores debemos incluir el archivo de cabecera **<typeinfo>**.

####6.5.- Destructores Virtuales

Un objeto que pertenece a una clase derivada de otra puede llamar en su creación a múltiples constructores. Un constructor de una clase derivada llama explícitamente al constructor base pasando los parámetros adecuados. Al destruir el objeto se realizan las llamadas a los destructores de la clase derivada y de la clase base, en orden inverso a la ejecución de los constructores, primero el de la clase derivada, y después el de la clase base. En los destructores no se indica la forma explícita en que hay que llamar al destructor de la clase base, ya que estos métodos especiales no toman parámetros. Sin embargo, cuando se trabaja con objetos polimórficos la secuencia de llamadas a los destructores puede ser incorrecta ya que como ocurre con los demás métodos, los destructores se enlazan en tiempo de compilación. En el ejemplo de _TVehiculo_, al destruir los objetos mediante el operador **delete** no se llamaría al destructor correspondiente a cada uno de los elementos, sino al destructor de la clase _TVehiculo_ en todos los casos. La solución a este problema consiste simplemente en declarar virtual al destructor de la clase base, de la que derivarán aquellas clases cuyos objetos se van a tratar de forma polimórfica.

####6.6.- Estudio de los Constructores

Una misma clase puede contar con múltiples constructores cada uno de ellos con diferentes parámetros. Al hecho de definir múltiples veces un mismo método se le denomina sobrecarga. Los constructores son por tanto métodos sobrecargados. Consideremos algunos tipos de constructor.

**El constructor por defecto**
Se denomina constructor por defecto a aquel que no toma ningún parámetro, siendo por lo tanto el utilizado cuando se crea o declara un objeto sin más datos. Si al definir una clase no se facilita ningún constructor, C++ añade automáticamente un constructor por defecto, ya que de lo contrario no se podría crear objetos de esa clase. Por lo tanto, si no necesitamos realizar ningún proceso de inicialización al crear el objeto, no es necesario que facilitemos nuestro propio constructor por defecto. Sin embargo, esta situación cambia en el momento en el que se define cualquier otro constructor en la clase, ya que entonces el compilador ya no añade automáticamente el constructor por defecto. Por ejemplo, dada la siguiente definición no sería posible crear un objeto de la clase _TObjeto_ sin facilitar obligatoriamente un parámetro entero.

```cpp
class TObjeto{
	public:
	TObjeto(int N);
};
```
por lo tanto, si deseamos dar la opción de crear un objeto de la clase _TObjeto_ sin necesidad de facilitar ese parámetro, tendremos que definir nosotros mismos el constructor por defecto.

**El constructor de Copia**
Al crear un objeto, la inicialización no siempre se realiza a partir de valores simples, como número o caracteres, y en ocasiones es necesario crear un objeto a partir de otro o bien realizar una asignación. Un objeto es una estructura compleja que en muchas ocasiones no puede ser asignada a otro objeto de la misma clase directamente realizando una copia byte a byte.
Para facilitar estas operaciones tendremos que definir un constructor de copia, que se caracteriza por recibir un solo parámetro que es una referencia a un objeto de la misma clase. Con este parámetro el constructor realizará toda la asignación que sea necesaria, incluyendo la copia de miembros del objeto existente en los del que se está creando, como en el ejemplo:

```cpp
class TObjeto{
	public:
		int Dato;
		TObjeto(int );
		TObjeto(TObjeto &);
};

TObjeto::TObjeto(int N)
{
	Dato = N;
}

TObjeto::TObjeto(TObjeto &OtroObjeto)
{
	this->Dato = OtroObjeto.Dato;
}
```

Con este constructor podemos crear y copiar objetos como en el siguiente código:

```cpp
TObjeto MiObjeto(5), *MiOtroObjeto;
MiOtroObjeto = new TObjeto(MiObjeto);
cout << MiOtroObjeto->Dato << endl;
```

**Parámetros por defecto de los Constructores**
Los parámetros de un constructor, como los de cualquier otro método pueden tomar parámetros por defecto. Sin embargo, estos valores puede causar ambigüedades en caso de que existan varios constructores, por ejemplo uno por defecto y otro que tome un solo parámetro que tiene un valor por defecto, como en el ejemplo:

```cpp
class TObjeto{
	public:
		int Dato;
		TObjeto();
		TObjeto(int = 0);
```

Al crear un objeto de la clase TObjeto sin facilitar ningún parámetro no se sabe a cual de los dos constructores se llamaría. En estos casos el compilador genera un error indicando que no es posible determinar a que constructor debe llamar.

####6.7.- Sobrecarga

Una de las características de C++ que le distingue de muchos otros lenguajes es la posibilidad de definir múltiples métodos con el mismo nombre pero diferentes parámetros, característica a la que se conoce como sobrecarga. Ya hemos usado esta capacidad al definir varios constructores para una misma clase. La sobrecarga no está limitada a los constructores, siendo posible usarla con cualquier método que forme parte de una clase, a excepción del destructor, ya que este no recibe parámetro alguno que pudiera diferenciarlo. También es posible usar esta técnica para modificar el comportamiento de ciertos operadores cuando se aplican sobre objetos de la clase.

**Sobrecarga de funciones**
Una función puede ser redefinida en el interior de una clase tantas veces como deseemos, siempre que la lista de parámetros de cada una de ellas sea diferente a la de las demás. Esta posibilidad nos proporciona una mayor flexibilidad y, sobre todo, la posibilidad de crear clases de objetos en las que ciertas operaciones puedan ser simplificadas, reduciendo el número de métodos que es necesario recordar. En el siguiente ejemplo se define un método _Valor()_ que permite tanto la asignación de una valor a un miembro privado de la clase como la obtención de este valor.

```cpp
class TObjeto{
	int Dato:
	public:
		TObjeto(int);
		int Valor();
		void Valor(int);
};
int TObjeto::Valor()
{
	return Dato;
}

int TObjeto::Valor(int N)
{
	Dato = N;
}
```

**Sobrecarga de operadores**
Tanto o más interesante que la sobrecarga de métodos es la sobrecarga de operadores. Volviendo a la clase del ejemplo _TMatriz_ que usábamos para trabajar con matrices cuyo número de elementos se determinaba en ejecución, teníamos un método llamado _Asigna()_, para asignar un valor a un cierto elemento, y otro llamado _Valor()_ para obtener el valor de un elemento. Sin embargo, puesto que el objeto es en realidad una matriz, sería más cómodo acceder a sus elementos mediante el operador correspondiente, es decir, disponiendo el número de elementos entre corchetes tras el propio objeto. La clase queda entonces como sigue:

```cpp
class TMatriz
{
	private: // Puntero a la zona de memoria donde estara la matriz
		int * Elementos;
		int NumElementos; // Numero de elementos de la matriz
	public:
		// El constructor asignara la memoria
		TMatriz(int Num);
		// Metodo para obtener le valor de un elemento
		int & operator[](int Num);
		// El destructor liberara la memoria asignada
		~TMatriz();
};
```

La implementación del nuevo método devuelve una referencia al elemento correspondiente al número recibido como parámetro. Al devolver una referencia y no el valor del elemento, permitimos también la modificación de su contenido:

```cpp
int & TMatriz::operator[](int Num)
{
	return Elementos[Num];
}
````

Su uso es ahora mucho más cómodo ya que se puede utilizar la notación habitual en C++ para acceder a los elementos de cualquier matriz:

```cpp
main()
{
	TMatriz Tabla(20);
	Tabla[5] = 18;
	cout << Tabla[5] << endl;
```

####6.8.- Herencia Múltiple

Hasta ahora hemos estudiado la herencia simple, en la que cada clase se deriva exactamente de una clase base. Sin embargo, una clase se puede derivar a partir de más de una clase base y esta derivación se denomina herencia múltiple. La herencia múltiple significa que una clase derivada hereda los miembros de varias clases base. Esta poderosa capacidad permite formar interesantes de reutilización del software, pero puede provocar problemas de ambigüedad. Para declarar la herencia múltiple solo hay que colocar a continuación de los dos puntos que siguen al nombre de la clase una lista separada por comas de clases base. Consideremos el siguiente ejemplo:

```cpp
class Base1 {
	public:
		Base1 (int x) { valor = x; }
		int getDato() { return valor; }
	protected:
		int valor;
};

class Base2 {
	public:
		Base2 (char c) { letra = c; }
		int getDato() { return letra; }
	protected:
		char letra;
};

// herencia multiple
class Derivada : public Base1, public Base2 {
	friend void operacion(Derivada & );
	public:
		Derivada (int, char, double);
		double getReal(){return real;};
	private:
		double real;
};

// Implementacion
// El constructor de Derivada llama a los constructores de las clases
// Base1 y base2
Derivada::Derivada (int i, char c, double f)__: Base1 (i), Base2(c), real(f) {}
// Devuelve el valor de real
// usa todos los datos miembros de Derivada
void operacion ( Derivada &d)
{
	cout << d.valor << d.letra << d.real;
}

// Uso
int ejemplo()
{
	Base1 b1 (10), *base1Ptr = 0; // crea el objeto b1
	Base2 b2 ('Z'), *base2Ptr = 0; // crea el objeto b2
	Derivada d(7, 'A', 3.5); // crea el objeto d
	// imprime los miembros de los objetos de las clases base
	cout << b1.getDato() + b2.getDato() << endl;
	// imprime los miembros del obj de la clase derivada usando el
	// operador de resoluci'on de ambito
	cout << d.Base1::getDato() << d.Base2::getDato() << d.getReal()<<endl;
	// trata d como objeto de Base1
	base1Ptr = &d;
	cout << base1Ptr->getDato() << endl;
	// trata d como objeto de Base2
	base2Ptr = &d;
	cout << base2Ptr->getDato() << endl;
}
```

Las funciones **friend** de una clase no pertenecen a la clase, pero tienen derecho a acceder a los miembros **private** y **protected** de la clase. Se puede declarar que una función o una clase entera es friend de otra. Por ejemplo, se usan con frecuencia en la sobrecarga de operadores. Para declarar una función como friend de una clase, se coloca un prototipo de la función precedido de la palabra clave friend en la definición de la clase. Para declarar que una clase, _Clase2_ es friend de otra clase _Clase1_ se incluye una declaración de la forma:

```cpp
friend class Clase2;
```

en la definición de la clase1. Consideremos un ejemplo:

```cpp
class Contador {
	friend void setX( Contador &, int); // declaracion friend
	public:
	Contador() { x = 0;} // constructor
	...
	private:
		int x; // dato miembro
		// SetX puede modificar datos privadas de contador, aunque
		// la forma de acceso no es la del metodos miembro de la clase
}

void setX( Contador &c, int val)
{
	c.x = val;
}

int main()
{
	Contador cuenta;
	setX(cuenta, 8);\\
	...
}
```

Podemos hacer que todas las funciones de la clase Y sean friend de la clase X con una única declaración:

```cpp
class Y; // declaracion incompleta
class X {
	friend Y;
	int i;
	void funcX();
}

class Y { // completa la declaracion
	void funcY1( X &); // funcion friend de X
	void funcY2( X*); // funcion friend de X
	...
}
```

También es posible declarar una función miembro individual de la clase X como friend de la clase Y:

```cpp
class X {
	...
	void funcX();
}

class Y {
	int i;
	friend void X::funcX();
	...
};
````

La amistad se otorga, no se toma, es decir, para que la clase B sea amiga de la clase A, esta última debe declarar explícitamente que la clase B es friend.
Además, la amistad no es simétrica, ni transitiva, es decir, si la clase A es friend de la B, y la B lo es de la C, no se puede inferir que la B es friend de la A, que la C es friend de la B ni que la A es friend de la C.



