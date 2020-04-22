#ifndef LIST_H
#define LIST_H
#include "node.h"
#include <stdbool.h>
/*Nuestra lista va a tener 
 *un solo apuntador*/ 
typedef struct _list list;
struct _list{
	node *head;
	int num;
};

list* create_list();
void delete_list(list *l);
//Funcionies para agregar a la lista
bool add_init(list *l, DATA data);
bool add_end(list *l, DATA data);
bool add(list *l, DATA data, int pos);
//Funcioin para eliminar un dato
bool remove_data(list *l, DATA data);
//Funciones para eliminar por posición
DATA delete_init(list *l);
DATA delete_end(list *l);
DATA delete_data(list *l, int pos);
//Funcioines para bsucar
int search_data(list *l, DATA data);//Nos regresa la posicioin del dato si es que existe en la lista
DATA search_pos(list *l, int pos); //Nos regresa el dato almacenado en la posición
node *search_node(list *l, DATA data); //Regresa el nodo donde se encuantra la información.
//solo nos regresa las cosas no va a sacar nada de la lista

//Funciones ultimo y penultirmo
node *ultimo(list *l);
node *penultimo(list *l);
node *anterior(list *l, int pos);
node *actual(list *l, int pos);

//Para imprimir vaciar y validar si esta vacia
void print_list(list *l);
void empty(list *l);
bool is_empty(list*l);

#endif
