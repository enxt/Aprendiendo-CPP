Utilice un contenedor asociativo set para almacenar ordenados alfabeticamente una serie de nombres de pila:

```
typedef set< string, less<string> > TListaNombres;
```

El programa pide al usuario nombres, que se van almacenando en el contenedor.
La entrada de datos termina cuando se deja un nombre el blanco.
Después el programa utiliza un iterador para recorrer la secuencia presentando por pantalla los datos que se han introducidos, pero ahora ordenamos alfabeticamente

```
TListaNombres::iterator iter;
```

Utilice los metodos clear, insert, begin, y end de set.
Utilice *iter para acceder al dato apuntado por el iterador.
No olvide realizar los includes necesarios.