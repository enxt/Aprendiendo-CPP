Utilice el contenedor vector para almacenar un texto.
Declare el siguiente tipo para almacenar la secuencia de palabras de una línea de texto:

```
typedef vector<string> TLinea;
```

Declare despues el siguiente tipo para almacenar un texto compuesto por una secuencia de líneas:

```
typedef vector<TLinea> TTexto;
```

Escriba un programa que lea de un archivo una secuencia de lineas de texto,
las almacene el una variable de tipo TTexto y después las presente todas por pantalla.
Utilice la función getline para leer líneas completas de la entrada estandar.
Recorra caracter a caracter la línea, buscando los caracteres blancos que indican el final de cada palabra.