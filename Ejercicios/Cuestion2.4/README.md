Dadas las clases del ejercicio anterior (CArticulo, COrdenador, etc),
convierta en virtual el método VisualizarFicha de la clase CArticulo.
Añada un método virtual puro "nombre" a la clase CArticulo, que devolverá el nombre del artículo:
"Ordenador portatil", etc. Este método es llamado también en VisualizarFicha.

¿Como afecta este cambio a las llamadas que se realizan desde el programa principal para visualizar los datos?.
El nuevo método es llamado también en VisualizarFicha.

Añada nuevas clases a la jerarquía:
CSobremesa que deriva de COrdenador (y tiene un atributo pantalla de tipo string, que almacena información de la pantalla),
CImpresora, que deriva de CArticulo y tiene un atributo tipo_conexion de tipo string.