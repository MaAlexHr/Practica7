#include "node.h"
#include "list.h"
#include "clist.h"
#include <stdio.h>

int main(){
	printf("\nLISTA LIGADA SIMPLE\n");
	
	list *l;
        l = create_list();

	printf("Funciones para agregar\n");
	add_init(l, 1);
	add_end(l,3);
	add(l,2,2);
	add(l,4,0);
	add(l,5,3);
	print_list(l);// [4] [1] [3] [5] [2] & num 5

	printf("\nFunciones para buscar\n");
	int d = search_data(l,3); 
	printf("\n Posición: %d\n",d);//pos 2
	DATA a = search_pos(l,2); 
	printf("\n Dato : %d\n",a);//DATA 3
	node *f = search_node(l,3);
       	printf("\n Dirección Nodo : %p\t Dato en el Nodo: %d \n",f,f->data);//nodo [3]

	printf("\nFunciones para eliminar\n");
	remove_data(l, 3);
	delete_init(l);
	delete_end(l);
	delete_data(l, 1);
	print_list(l);//[1] & num 1;

	delete_list(l);

	printf("\nLISTA LIGADA CIRCULAR\n");
	clist *c;
	c = create_clist();

	printf("Funciones para agregar\n");
	ad_initc(c, 1);
	ad_endc(c,3);
	addc(c,8,2);
	addc(c,4,1);
	addc(c,5,3);
        print_clist(c);// [1] [4] [3] [5] [8] & num 5

       	printf("\nFunciones para buscar\n");
	int e = search_datac(c,3);
        printf("\n Posición : %d\n",e);//pos 2
        DATA b = search_posc(c,1);
        printf("\n Dato : %d\n",b);//DATA 4
        node *g = search_nodec(c,3);
        printf("\n Dirección Nodo : %p\t Dato en el Nodo: %d \n",g,g->data);//nodo [3]

	printf("\nFunciones para eliminar\n");
        remove_datac(c, 3);
        delete_initc(c);
        delete_endc(c);
        delete_posc(c, 1);
        print_clist(c);//[4] & num 1;

        delete_clist(c);

	return 0;
}
