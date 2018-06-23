#include<stdio.h>
#include<stdlib.h>
struct Nodo{
    int info;
    struct Nodo* next;
};

void print_list(struct Nodo*);
void addFinal(struct Nodo*,int );
void addPrincipio(struct Nodo**,int);
void borrarPrimero(struct Nodo**);

main(){
	printf("Bienvenido al programa \n");
 	int i=0;
	int v1,v2,v3;
	struct Nodo *head = NULL;
	for(i=0;i<5;i++){
		addPrincipio(&head,i*50);
	}
	print_list(head);
	v1 = head->next->next->info;
	v2 = head->info;
	printf("v1: %d \n",v1);
	printf("v2: %d \n",v2);


	v3 = 23;
	head->next->info = v3;

	print_list(head);

}
void print_list(struct Nodo *head) {
    struct Nodo *current = head;
    printf(" *** Inicio de la lista *** \n");
	while (current != 0) {
        printf("%d \n", current->info);
        current = current->next;
    }
    printf(" *** *** \n");

}

void addPrincipio(struct Nodo **head, int info) {
    struct Nodo *new_node;
    new_node = (struct Nodo*)malloc(sizeof(struct Nodo));
    new_node->info = info;
    new_node->next = *head;
    *head = new_node;
}
void borrarPrimero(struct Nodo **head) {
    struct Nodo *next_node = NULL;
    if (*head == NULL) {
        printf("ya no hay nodos por borrar");
    }
    else{
    	next_node = (*head)->next;
    	free(*head);
    	*head = next_node;
	}
}

