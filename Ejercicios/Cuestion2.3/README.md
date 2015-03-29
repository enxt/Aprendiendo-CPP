En este ejercicio haremos uso de la herencia. Creamos una clase CArticulo,
que será la clase base a partir de la que derivaremos las demas, y que usaremos para representar artículos informáticos.
A partir de CArticulo, derivaremos COrdenador y CAccesorio. A partir de COrdenador derivamos CPortatil.
La jerarquía queda de la siguiente forma:
CArticulo
COrdenador
CPortatil

La clase base CArticulo tiene los atributos protected:
- unidades(entero),
- precio(double).
Y los siguientes métodos:
- Un constructor con los valores de inicializacion de los datos.
- Un método VisualizarFicha que saca los datos por consola.

La clase COrdenador deriva de CArticulo (de forma pública-> class COrdenador: public CArticulo)
y tiene un atributo adicional cpu de tipo string.
Esta clase redefine el método VisualizarFicha para sacar por consola todos los datos,
y tiene su propio constructor, que utiliza al constructor de la clase base.

La clase CPortatil deriva de COrdenador (de forma publica) y tiene un atributo adicional peso de tipo float.
Esta clase redefine el método VisualizarFicha para sacar por consola todos los datos, y tiene su propio constructor.

Escriba un programa principal en el que se construya un objeto de cada una de las clases
y después se visualicen las fichas de dichos objetos.

Entregue todos los archivos fuente necesarios para compilar el programa en un sólo archivo comprimido(.zip o .gz),
incluido el makefile si lo ha utilizado.
