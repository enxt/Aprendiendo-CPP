Cree la clase Rectangulo con atributos privados largo y ancho y los siguientes
métodos públicos:
- constructor por defecto (sin parametros), que asigna a alto y ancho un valor
predeterminado de 1,
- constructor con los datos de inicializacion de alto y ancho,
- lee_largo, que devuelve el valor del atributo largo,
- lee_ancho, que devuelve el valor del atributo ancho,
- perimetro, que calcula el perimetro del rectángulo,
- area, que calcula y devuelve el área del rectángulo, y
- cuadrado que devuelve un booleano indicando si el rectángulo es un cuadrado.

Escriba un programa principal que utilice la clase Rectangulo para crear dos
rectangulos: rect1 y rect2.
rect1 se creará como una variable estática:
Rectangulo rect1(largo,ancho);
rect2 es un puntero a Rectangulo y se crea como una variable dinámica.
rect2 = new Rectangulo(largo, ancho);
En este caso hay que eleminar el objeto al terminar el programa:
delete rect2;
En ambos casos los datos de piden al usuario antes de crear el objeto.
Depués el programa presenta por pantalla las características de cada rectángulo: perímetro,
 área y si es o no un cuadrado.

Entregue todos los archivos fuente necesarios para compilar el programa en un sólo
archivo comprimido(.zip o .gz), incluido el makefile si lo ha utilizado.