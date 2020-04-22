# Practica7 PREGUNTAS Y CONCLUSIONES
ALUMNO HERNANDEZ ROJAS MARA ALEXANDRA
Materia EDA 1

¿Cual es la diferencia entre la lista enlazada circular y la lista enlazada?
El  apuntador siguiente del ultimo nodo de la lista enlazada circular apunta al primer nodo en la lista mientras que en
una lista simple el apuntador siguiente del ultimo nodo apunta a NULL.

Describa el proceso para insertar en una posición dada en una lista ligada
Primero creamos el nodo que queremos insertar (nuevo), despues recorremos la lista hasta la posicion dada y hacemos que el apuntador a siguiente del nodo anterior a esa posicion dada apunte al nodo nuevo, por ultimo hacemos que el apuntador a siguiente de nuevo apunte al nodo que solia estar en la posicion dada e incrementamos una unidad el contador de nodos asociado a la lista.

Describa el proceso para eliminar una posición dada en una lista ligada
Primero recorremos la lista hasta la posición dada, segundo hacemos que el apuntador a siguiente del nodo anterior a esa posición dada apunte al mismo nodo que el apuntador a siguiente del nodo que vamos a eliminar, eliminamos el espacio de memoria del nodo en la posición dada y restamos una unidad al contador de nodos asociado a la lista.

¿Como podemos saber que terminamos de recorrer una lista ligada circular?
Cuando el apuntador a siguiente del nodo en el que estamos apunta al primer nodo de la lista (t->next == l->head)

¿Que diferencia existe al implementar una lista con un solo apuntador (head) e implementarla con dos(head y tail)?
La diferencia se encuentra al realizar  las operaciones  añadir al final, eliminar al final y al momento de hacer circular la lista si no existe el apuntador tail se tiene que definir e implementar una función extra que encuentre el ultimo nodo.

Describa el proceso para buscar en una lista ligada
Dentro de una lista ligada se puede buscar por posicion recorriendo la lista mientras incrementamos un contador y regresamos el dato en la posicion dada o por dato recorriendo la lista nodo por nodo comparando los datos dentro del nodo con el que busacmos para regresar la posicion o el nodo donde se almacena.

Describa el proceso para crear una lista ligada
Creamos un apuntador a una estructura lisa y le asignamos espacio de memoria suficiente para la estructura. Finalmente hacemos que head apunte a NULL y que su contador inicie en 0.

Describa el proceso para borrar una lista
Si la lista no esta vacia la vaciamos y despues liberamos el espacio de memoria que ocupa.

En conclusion las listas ligadas son mas faciles de manejar si disponemos de dos apuntadores (head y tail) la extension del codigo disminuye, la complejidad del ejercicio radica en la implementacion de la lista circular (hacer que el siguiente del ultimo de la lista apunte al primero) ya que necesitamos cambiar las condiciones que limitan la repeticion dentro de los ciclos en las funciones basicas que conforman las operaciones para añadir, buscar y eliminar. Sin embargo podemos generalizar la forma en la que se implementan estos tres tipos de operaciones pues dependen de la forma en la que se recorre la lista y se separan una vez que se detiene en la posicion deseada.
