UNED
DEPARTAMENTO DE LENGUAJES Y SISTEMAS INFORMA ́TICOS
PROGRAMACIO ́N AVANZADA EN C++ (Curso 2013/14)
PRA ́CTICA:Generadordeun ́ındicedeuntexto
La pra ́ctica consiste en construir y presentar un  ́ındice de palabras de un texto orga- nizado en l ́ıneas. Las palabras del texto que se quiere que aparezcan en el  ́ındice est ́an marcadas con el s ́ımbolo “/” . Las palabras del  ́ındice se presentan ordenadas alfab ́etica- mente y seguidas de los nu ́meros de l ́ınea en que aparecen. El texto se lee de un fichero de texto.
Implementacio ́n
La pr ́actica se implementar ́a en el lenguaje C++.
La implementacio ́n de la pr ́actica consta de los siguientes mo ́dulos:
• indice.h: Contiene los prototipos de las funciones implementadas en indice.cpp. Esto nos permite escribirlas en cualquier orden en el mo ́dulo indice.cpp. La declaracio ́n de estos prototipos requiere que previamente se hayan declarado las clases de los par ́ametros de las funciones. La definicio ́n de la clase ListaIndice se obtiene del siguiente include:
             #include "ListaIndice.h"
Contiene tambi ́en la definicio ́n de la clase utilizada para representar el texto como un vector de lineas, donde a su vez cada l ́ınea se representa como un vector de palabras:
             typedef vector<string> TLinea;
             typedef vector<TLinea> TTexto;
• indice.cpp: Implementa el programa principal y las funciones que se encargan de la entrada/salida de datos, y la generacio ́n y visualizacio ́n del  ́ındice:
◦ void PresentarMenu();
Presenta el menu ́ principal con las siguientes opciones:
⋄ F: Selecciona y lee un nuevo fichero de texto.
⋄ T: Presenta la l ́ıneas de texto numeradas.
⋄ I: Genera el  ́ındice
⋄ V: Visualiza el  ́ındice, presentando un submenu ́.
⋄ G: Guarda el  ́ındice en un fichero, cuyo nombre se solicita al usuario. ⋄ S: Sale del programa.
◦ void Imprimirtexto(TTexto texto);
Imprime el texto por pantalla, indicando los nu ́meros de las l ́ıneas.
◦ void LeerDatos (TTexto& texto);
Pide al usuario el nombre del archivo cuyo texto, organizado en l ́ıneas, se
￼￼
desea procesar. Se usa la clase ifstream para representar el archivo. Para representar el texto se utiliza el tipo TTexto definido a partir del contenedor de secuencia vector.
◦ void GenerarIndice(TTexto texto, ListaIndice& miIndice);
Genera un  ́ındice a partir del texto representado mediante la clase Lis- taIndice. Para ello se recorre el texto l ́ınea a l ́ınea y palabra a palabra, y cada palabra marcada se inserta en el  ́ındice junto con el nu ́mero de l ́ınea en la que aparece.
◦ void VisualizarIndice(ListaIndice miIndice, TTexto texto);
Presenta un submenu ́ de visualizaci ́on (PresentarSubmenuIndice()).
◦ void PresentarSubmenuIndice();
Presenta un menu ́ con las siguientes opciones:
⋄ C: para visualizar el  ́ındice completo (lista ordenada de palabras del  ́ındice, seguidas de la lista de nu ́meros de l ́ınea en que aparecen).
⋄ P: que permite seleccionar una palabra del  ́ındice y presenta las l ́ıneas de texto en las que aparece dicha palabra.
◦ void VisualizarIndiceCompleto(ListaIndice miIndice);
Recorre el indice presentando por pantalla cada palabra y la lista de l ́ıneas en las que aparece. Para hacer el recorrido se utilizan las funciones de la clase ListaIndice que manejan el iterador (iniciar(), avanzar() y estaDen- tro()) para hacer el recorrido eficiente.
◦ void VisualizarPalabraIndice(ListaIndice miIndice, TTexto texto);
Pide una palabra al usuario y la busca en el  ́ındice. Si la encuentra pre- senta las l ́ıneas de texto completas en las que aparece la palabra. Si no se encuentra se informa al usuario.
◦ void GuardarIndice(ListaIndice miindice);
Almacena el indice en un archivo de texto cuyo nombre se pregunta al usuario. Se utiliza la clase ofstream para representar el archivo.
• NodoIndice.cpp, que implementa los m ́etodos de la clase NodoIndice.
• NodoIndice.h, que define la clase NodoIndice que representa la lista de l ́ıneas
que se asocia con cada palabra del  ́ındice. Esta clase posee un atributo privado:
        TListaLineas listaLineas;
habi ́endose definido previamente en el mismo m ́odulo la clase TListaLinea me- diante el contenedor de secuencia set:
        typedef set< int, less<int> > TListaLineas;
Esto nos permite guardar el conjunto de enteros que representan las l ́ıneas de forma ordenada y sin repeticiones.
La clase consta de los siguientes m ́etodos:
◦ NodoIndice(int unaLinea), que crea un nuevo nodo con una sola l ́ınea.
◦  ̃NodoIndice(), destructor de la clase.
◦ void insertaLinea(int unaLinea), que inserta una nueva l ́ınea en un nodo ya creado.
◦ string recuperaLineas(), que devuelve una cadena formada por la secuencia de lineas separadas por blancos.
• ListaIndice.cpp, que implementa los m ́etodos de la clase ListaIndice.
• ListaIndice.h, que define el interface de la clase ListaIndice. Para representar la lista del  ́ındice, en la que cada nodo debe contener una palabra y una lista ordenada de l ́ıneas, utilizaremos el contenedor asociativo map. Este contenedor nos permite relacionar de forma un ́ıvoca elementos de tipos distintos, en este caso la palabra y la lista de l ́ıneas, ordenar por la palabra y adem ́as s ́olo permite una aparici ́on de cada elemento clave. Este es nuestro caso, ya que por cada palabra s ́olo podemos tener una u ́nica entrada en el  ́ındice. Concretamente, nuestra clase ListaIndice tendra ́ los atributos privados:
◦ TListaOrd laLista
donde TListaOrd se define previamente en el mismo mo ́dulo como:
                    typedef map< string, NodoIndice*, less<string> > TListaOrd;
◦ TListaOrd::iterator iter lista y m ́etodos pu ́blicos:
◦ void limpiar(), para vaciar el contenedor.
◦ void insertar(string palabra, int unaLinea), para insertar un nuevo nodo
en la lista.
◦ string leerPalabra(), que devuelve la palabra correspondiente al nodo de la
lista apuntado por el iterador iter lista.
◦ string leerLineas(), que devuelve la lista de lineas de un nodo como una
cadena.
◦ void iniciar(), que coloca el iterador iter lista al comienzo de la lista.
◦ void avanzar(), que hace que el iterador iter lista avance un nodo.
◦ bool estaDentro(), que comprueba que el iterador iter lista est ́e dentro de los l ́ımites de la lista.
Ejemplo de uso del programa
El programa se invocara ́ desde la l ́ınea de comandos de Linux o ́ Windows. Supongamos que se aplica al siguiente texto de entrada:
esto /es /una /prueba
y /esto /es /otra /prueba
f: para seleccionar un nuevo fichero de texto
t: para visualizar el texto
i: para generar el indice
v: para visualizar el indice (con las lineas de texto correspondientes
g: para guardar el indice en un fichero
s: para salir
f
Introduce el nombre del archivo con el texto:
ejemplos/texto1.txt
f: para seleccionar un nuevo fichero de texto
t: para visualizar el texto
i: para generar el indice
v: para visualizar el indice (con las lineas de texto correspondientes
￼￼￼￼￼
g: para guardar el indice en un fichero
s: para salir
i
INDICE GENERADO
f: para seleccionar un nuevo fichero de texto
t: para visualizar el texto
i: para generar el indice
v: para visualizar el indice (con las lineas de texto correspondientes
g: para guardar el indice en un fichero
s: para salir
v
c: para visualizar el indice completo
p: para visualizar el texto en el que aparece una palabra seleccionada
s: para salir
c
INDICE:
es  1 2
esto  2
otra  2
prueba  1 2
una  1
c: para visualizar el indice completo
p: para visualizar el texto en el que aparece una palabra seleccionada
s: para salir
p
Selecciona la palabra:
esto
La linea aparece en:
y /esto /es /otra /prueba
c: para visualizar el indice completo
p: para visualizar el texto en el que aparece una palabra seleccionada
s: para salir
s
f: para seleccionar un nuevo fichero de texto
t: para visualizar el texto
i: para generar el indice
v: para visualizar el indice (con las lineas de texto correspondientes
g: para guardar el indice en un fichero
s: para salir
g
Introduce el nombre del fichero:
indice.txt
INDICE GUARDADO
f: para seleccionar un nuevo fichero de texto
t: para visualizar el texto
i: para generar el indice
v: para visualizar el indice (con las lineas de texto correspondientes
g: para guardar el indice en un fichero
s: para salir
s
