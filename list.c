#include <stdio.h>
#include <stdlib.h>
#include "list.h"
list* create_list(){
	list *l;
	l = (list*)malloc(sizeof(list));
	l->head = NULL;
	l->num = 0;
	return l;
}
void delete_list(list *l){
	if(!is_empty(l)){
		empty(l);
	}
	free(l);
}
bool add_init(list *l, DATA data){
	if(l==NULL) return false;
	if(is_empty(l)){
		l->head = create_node(data);
		l->num = 1;
		return true;
	}
	node *nuevo = create_node(data);
	nuevo->next = l->head;
	l->head = nuevo;
	l->num++;
	return true;
}
bool add_end(list *l, DATA data){
	if(l==NULL) return false;
	if(is_empty(l)){
		l->head = create_node(data);
		l->num = 1;
		return true;
	}
	node *nuevo = create_node(data);
	node *fin = ultimo(l);
	fin->next = nuevo;
	l->num++;
	return true;
}
bool add(list *l, DATA data, int pos){
	if(l==NULL) return false;
	if(pos == 0 || is_empty(l)){
		return add_init(l,data);
	}else if(pos == l->num){
		return add_end(l,data);
	}else if(pos > 0 && pos < l->num){
		node *act = actual(l,pos);
		node *ant = actual(l,pos-1);
		node *nuevo = create_node(data);
		ant->next = nuevo;
		nuevo->next = act;
		l->num++;
		return true;
	}else{
		return false;
	}
}
bool remove_data(list *l, DATA data){
	if(l==NULL) return false;
	node *t = l->head;
	int i = 0;
	while(t!=NULL){
		//tenemos que encontrar el nodo anterioir al que tiene el dato correcto
		if(t->data == data){
			break;
		}
		t = t->next;
		i ++;
	}
	node *ant = actual(l, i-1);
	node *act = actual(l, i);
	ant->next = act->next;
	act->next = NULL;
	delete_node(act);
	l->num--;
	return true;
}
/*partiendo desde el principio que:
 *nuestra lista solo contiene 
 *enteros positivos
 */
DATA delete_init(list *l){
	if(l==NULL) return -1;
	if(!is_empty(l)){
		node *t = l->head;
		int d = l->head->data;
		l->head = l->head->next;
		t->next = NULL;
		delete_node(t);
		l->num--;
		return d;
	}
	return -1;
}
DATA delete_end(list *l){							         
	if(l==NULL) return -1;
	if(!is_empty(l)){
		node *ult = ultimo(l);
		node *t = penultimo(l);
		int d = ult->data;
		t->next = NULL;
		delete_node(ult);
		l->num--;
		return d;
	}
	return -1;
} 
DATA delete_data(list *l, int pos){
	int d;
	if(l == NULL) return -1;
	if(pos == 0){
		return delete_init(l);
	}else if (pos == l->num-1){
		return delete_end(l);
	}else if (pos > 0 && pos < l->num-2){
		node *ult = actual(l, pos);
		node *ant = actual(l, pos-1);
		ant->next = ult->next;
		delete_node(ult);
		l->num--;
		return d;
	}else{
		return -1;
	}
}
/* Funciones para buscar
 * retorna la posicion de un dato en la lista
 */
int search_data(list *l, DATA data){
       int pos;
	   node *t;
       for(pos=0, t=l->head; data != t->data && t->next!=NULL ; pos++, t=t->next);	       
       if(pos >= l->num) return -1;
       return pos;
}
DATA search_pos(list *l, int pos){
	node *t;
	int i;
	for(i=1, t=l->head; i==pos; i++, t=t->next);
	if(t!=NULL) return t->data;
	return -1;
}
node *search_node(list *l, DATA data){//MI funcion
	 if(is_empty(l))return NULL;
	 node *t = l->head;
	 int i = 0;
	 while(t->data != data && i < l->num){
	 	t = t->next;
	 	i++;
	 }
	 if (t->data == data) return t;
	 else return NULL;
}
node *ultimo(list *l){
	node *t = l->head;
	while(t->next!=NULL){
		t = t->next;
	}
	return t;
}
node *penultimo(list *l){
	node *t = l->head;
	while(t->next->next!=NULL){
		t = t->next;
	}
	return t;
}

node *actual(list *l, int pos){
	node *t = l->head;
	int i = 0;
	while(t->next != NULL && i < pos){
		t=t->next;
		i++;
	}
	return t;
}

node *anterior(list *l, int pos){
	node *t = l->head;
	int i = 0;
	while(t->next != NULL && i < pos-1){
		t = t->next;
		i++;
	}
	return t;
};

bool is_empty(list *l){
	if(l->head == NULL) return true;
	return false;
}
 
void empty(list *l){
	if (l->num == 1){
		delete_node(l->head);
		l->num = 0;
	}else{
		node *t = ultimo(l);
		node *ant = penultimo(l);//apunta al penultimo nodo para que no se vuelva un ciclo infinito

		while(l->num > 1){
			ant->next = NULL;
			delete_node(t);
			t = ultimo(l);
			ant = penultimo(l);
			l->num--;
		}
	}
	//cuando la funcion llegue a head ya no va a haber un penultimo;
	delete_node(l->head);
	l->num=0;
};

void print_list(list *l){
	if (l == NULL)
		printf("\nLa lista no existe\n");
	if (is_empty(l)){
		printf("\nLa lista esta vacía\n");
	}else{
		node *t = l->head;
		printf("\n");
		while(t != NULL){
			printf("[ %d ] ",t->data);
			t = t->next;
		}
		printf("\n");
	}
};

