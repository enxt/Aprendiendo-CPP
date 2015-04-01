En este ejercicio se va a hacer un programa que permita 
implementar una pequeña base de datos de articulos informáticos. 
Para ello utilizaremos las clases definidas en el ejercicio anterior.

También se usa una variable static para ir contando el número de 
artículos que se van introduciendo a la base de datos. Añadimos en 
la parte pública de la clase CArticulo:
static int num;

Este dato se inicializa a 0 antes de la cabecera del programa principal,
int CArticulo::num=0;
y se va modificando a medida que se crean o destruyen artículos. 
Para ello se añade un destructor específico a la clase CArticulo y se 
modifica el constructor para incrementar num.

Escriba un programa principal que almacene en un array de punteros a
objetos *CArticulo[100] los distintos artículos: diveros tipos de 
ordenadores de sobremesa (distinta cpu), varios tipos distintos de 
portatiles (distinto peso), etc. A continuación escriba un bucle que 
recorra los posiciones ocupadas del array y llame a VisualizarFicha. 
Observe que en para cada articulo se llama al método que
le corresponde según la clase a la que pertenezca.