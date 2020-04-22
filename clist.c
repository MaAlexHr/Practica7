#include <stdio.h>
#include <stdlib.h>
#include "clist.h"

clist* create_clist(){
	clist *c;
	c = (clist*)malloc(sizeof(clist));
	c->head = c->head->next = NULL;
	c->num = 0;
	return c;

}
void delete_clist(clist *c){
	if (!is_emptyc(c)){
		emptyc(c);
	}
	free(c);
}
bool ad_initc(clist *c, DATA data){
	if(c==NULL) return false;
	if(is_emptyc(c)){
		c->head = create_node(data);
		c->head->next = c->head;
		c->num = 1;
		return true;
	}
	node *u, *nuevo;
        nuevo = create_node(data);
	nuevo->next = c->head;
	c->head = nuevo;
	u = ultimoc(c);
	u->next = c->head;
	c->num++;
	return true;
}
bool ad_endc(clist *c, DATA data){
	if(c==NULL) return false;
	if(is_emptyc(c)){
		c->head = create_node(data);
		c->head->next = c->head;
		c->num = 1;
		return true;
	}
	node *nuevo;
        nuevo	= create_node(data);
	node *fin = ultimoc(c);
	fin->next = nuevo;
	nuevo->next = c->head;
	c->num++;
	return true;

}
bool addc(clist *c, DATA data, int pos){
	if(c==NULL) return false;
	if(pos == 0 || is_emptyc(c)){
		return ad_initc(c,data);
	}else if(pos == c->num){
		return ad_endc(c,data);
	}else if(pos > 0 && pos < c->num){
		node *act = actualc(c,pos);
		node *ant = actualc(c,pos-1);
		node *nuevo = create_node(data);
		ant->next = nuevo;
		nuevo->next = act;
		node *u = ultimoc(c);
		u->next = c->head;
		c->num++;
		return true;
	}else{
		return false;
	}
}
bool remove_datac(clist *c, DATA data){	
	if(c==NULL) return false;
	node *t = c->head;
	int i = 0;
	while(t!=NULL || t->next != c->head){
		//tenemos que encontrar el nodo anterioir al que tiene el dato correcto
		if(t->data == data){
			break;
		}
		t = t->next;
		i ++;
	}
	node *ant = actualc(c, i-1);
	node *act = actualc(c, i);
	ant->next = act->next;
	act->next = NULL;
	delete_node(act);
	node *u = ultimoc(c);
	c->num--;
	return true;
}
DATA delete_initc(clist *c){
	if(c==NULL) return -1;
	if(!is_emptyc(c)){
		node *t = c->head;
		node *u = ultimoc(c);
		u->next = NULL;
		int d = c->head->data;
		c->head = c->head->next;
		t->next = NULL;
		delete_node(t);
		u->next = c->head;
		c->num--;
		return d;
	}
	return -1;
}
DATA delete_endc(clist *c){
	if(c==NULL) return -1;
	if(!is_emptyc(c)){
		node *ult = ultimoc(c);
		node *t = penultimoc(c);
		int d = ult->data;
		t->next = NULL;
		ult->next = NULL;
		delete_node(ult);
		t->next = c->head;
		c->num--;
		return d;
	}
	return -1;
}
DATA delete_posc(clist *c, int pos){
	int d;
	if(c == NULL) return -1;
	if(pos == 0){
		return delete_initc(c);
	}else if (pos == c-> num-1){
		return delete_endc(c);
	}else if (pos > 0 && pos < c->num-2){
		node *ult = actualc(c, pos);
		node *ant = actualc(c, pos-1);
		delete_node(ult);
		node *u = ultimoc(c);
		u->next = c->head;
		c->num--;
		return d;
	}else{
		return -1;
	}
}
int search_datac(clist *c, DATA data){
    int pos;
	node *t;
    for(pos=0, t=c->head; data != t->data && t->next!= c->head; pos++, t=t->next);	       
    if(pos >= c->num) return -1;
    return pos;
}
DATA search_posc(clist *c, int pos){
	node *t;
	int i;
	if(pos > 0 && pos < c->num){
		for(i=0, t=c->head; i == pos-1; i++, t=t->next);
		return t->data;
	}
	return -1;	
}
node *search_nodec(clist *c, DATA data){
	if(is_emptyc(c))return NULL;
		 node *t = c->head;
	 	int i = 0;
	 	while(t->data != data && i < c->num){
		 	t = t->next;
		 	i++;
	 	}
	if (t->data == data) return t;
	else return NULL;	
} 
node *ultimoc(clist *c){
	node *t = c->head;
	while(t->next != c->head){
		t = t->next;
	}
	return t;
}
node *penultimoc(clist *c){
	node *t = c->head;
	while(t->next->next != c->head){
		t = t->next;
	}
	return t;
}
node *anteriorc(clist *c, int pos){
	node *t = c->head;
	int i = 0;
	while(t->next != c->head && i < pos-1){
		t=t->next;
		i++;
	}
	return t;
}
node *actualc(clist *c, int pos){
	node *t = c->head;
	int i = 0;
	while(t->next != c->head && i < pos){
		t=t->next;
		i++;
	}
	return t;
}
void print_clist(clist *c){
	if (c == NULL)
		printf("\nLa lista no existe\n");
	if (is_emptyc(c)){
		printf("\nLa lista esta vacía\n");
	}else{
		node *t = c->head;
		int i = 0;
		printf("\n");
		while(i < c->num){
			printf("[ %d ] ",t->data);
			t = t->next;
			i++;
		}
	}	
}
void emptyc(clist *c){
	node *t = ultimoc(c);
	node *ant;//apunta al penultimo nodo para que no se vuelva un ciclo infinito
	if (c->num != 1){
		int i = 0;
		while(t != NULL && i < c->num){
			ant = penultimoc(c);
			ant->next = NULL;
			delete_node(t);
			t = ultimoc(c);
			i++;
		}
	}else{
		//cuando la funcion llegue a head ya no va a haber un penultimo;
		delete_node(c->head);
		c->head->next = c->head;
		c->num=0;
	}
}
bool is_emptyc(clist*c){
	if(c->head == NULL) return true;
		return false;
}

