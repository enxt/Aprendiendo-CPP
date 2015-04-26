Escriba un programa con los siguientes elementos:

* (a) Una definición de excepcion ExceptionFueraDeRango, que se lanza cuando un numero entero no está entre -100 y 100.
* (b) Una definición de excepcion ExcepcionDeDivisionEntreCero, que se lanza cuando se detecta una división por cero.
* (c) Una funcion para leer un numero, comprobando que este en el rango de -100 a 100. Si no lo está lanza una excepcion ExceptionFueraDeRango.
* (d) Una función para calcular la división de dos números, que lanza una excepción ExcepcionDeDivisionEntreCero si el denominador es cero.
* (e) Un bloque try para lanzar una excepción cuando se introduce un numero fuera del rango -100-100.
* (f) Un bloque try para detectar y lanzar una excepción si se produce una condición de división por cero.
* (g) Un bloque catch adecuado para menejar las excepciones lanzadas.

El programa se repite hasta que los datos sean correctos:

```
while(true){
    try{
        ...
        break;
    }
    catch...
    {
        ...
    }
    catch...
    {
        ...
    }
} // while
```