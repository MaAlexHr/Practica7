#ifndef CLIST_H
#define CLIST_H
#include "node.h"
#include <stdbool.h>

/*Nuestra lista va a tener 
 *un solo apuntador*/ 
 
typedef struct _clist clist;
struct _clist{
	node *head;
	int num;
};

clist* create_clist();
void delete_clist(clist *c);
//Funcionies para agregar a la lista
bool ad_initc(clist *c, DATA data);
bool ad_endc(clist *c, DATA data);
bool addc(clist *c, DATA data, int pos);
//Funcioin para eliminar un dato
bool remove_datac(clist *c, DATA data);
//Funciones para eliminar por posicion
DATA delete_initc(clist *c);
DATA delete_endc(clist *c);
DATA delete_posc(clist *c, int pos);
//Funcioines para bsucar
int search_datac(clist *c, DATA data);//Nos regresa la posicioin del dato si es que existe en la lista
DATA search_posc(clist *c, int pos); //Nos regresa el dato almacenado en la posición
node *search_nodec(clist *c, DATA data); //Regresa el nodo donde se encuantra la información.
//solo nos regresa las cosas no va a sacar nada de la lista
//Funciones ultimo y penultirmo
node *ultimoc(clist *c);
node *penultimoc(clist *c);
node *anteriorc(clist *c, int pos);
node *actualc(clist *c, int pos);
//Para imprimir vaciar y validar si esta vacia
void print_clist(clist *c);
void emptyc(clist *c);
bool is_emptyc(clist*c);

#endif//CLIST_H
