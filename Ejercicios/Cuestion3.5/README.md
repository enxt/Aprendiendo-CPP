Utilice un contenedor asociativo set para almacenar ordenados alfabeticamente una serie de nombres de pila,
que representan a los nombres de los hermanos de una persona:

```
typedef set< string, less<string> > THermanos;
```

Utilice un contenedor asociativo map para almacenar ordenados alfabeticamente una serie de nombres de pila,
cada uno de los cuales tiene asociado a la lista de nombres de sus hermanos:

```
typedef map< string, THermanos, less<string> > TListaPersonas;
```

El programa pide al usuario nombres, que se van almacenando en el contenedor.
La entrada de datos termina cuando se teclea un nombre que es un espacio en blanco.
Después el programa utiliza un iterador para recorrer la secuencia presentando por pantalla los datos que se han introducidos, pero ahora de ordenamos alfabeticamente.