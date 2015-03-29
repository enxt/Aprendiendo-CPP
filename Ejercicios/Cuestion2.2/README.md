Utilizando la clase Rectangulo del ejercicio anterior, cree una clase VecRect para trabajar con un array de rectángulos.
La clase consta de los siguiente miembros:

- Atributos privados:
+ array_rect, que es un array de punteros a rectángulos,
  que creará el constructor de la clase.
+ total, un entero que almacena el número de rectángulos del array

- Métodos públicos:
+ constructor(int valor), que crea un número de rectángulos igual a valor colocándolos a partir del comienzo del array.
  Si valor es mayor que 20, no se crean los rectángulos y se presenta un mensaje de error.
  Los rectángulos creados son elementales de largo y ancho igual a 1 (con el constructor por defecto de la clase Rectangulo.)
  El constructor asigna valor al atributo total.
+ destructor: que elimina el array de rectángulos
+ asignaDatos(int i, float Vlargo, float Vancho), que asigna los datos Vlargo y Vancho al rectángulo de la posicion i'esima del array
  añadir los métodos escribe_ancho y escribe_alto a la clase Rectángulo para realizar los cambios).
+ presentaDatos(int i), que presenta por pantalla las características (área, perímetro, si es cuadrado) de la posición i'esima del array.

Escriba un programa principal que utilice la clase VecRect para crear un array de 10 rectángulos,
que después modifique los datos de uno de los rectangulos (el que elija el usuario), y finalmente presente por pantalla los datos de todos los rectángulos.

Entregue todos los archivos fuente necesarios para compilar el programa en un sólo archivo comprimido(.zip o .gz), incluido el makefile si lo ha utilizado.