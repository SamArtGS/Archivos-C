#include<stdio.h>
#include<stdlib.h>

typedef struct Nodo{
    int val;
    struct Nodo* next;
    struct Nodo* prev;
}Nodo;

typedef struct{
	int tamano;
	struct Nodo* head;
}Lista;

void print_list(Lista);
void addPrincipioLista(Lista*,int);   
void addFinalLista(Lista*,int);
void primerNodo(Lista*,int);
void borrarPrimero(Lista*);
void borrarUltimo(Lista*);
void recorrerLista(Lista);

Lista crearLista(){
	Lista lista;
	lista.head = NULL;
	lista.tamano=0;
	return lista;
}

void recorrerLista(Lista lista){
	int var = 0;
	Nodo *temp = lista.head;
	do{
		printf("El elemento actual es %d \n",temp->val);
		printf("Mostrar Siguiente Presione 1 \n");
		printf("Salir Presione 2 \n");
		scanf("%d",&var);
		temp=temp->prev;
		
	}while (var!=2);
}


void print_list(Lista lista) {
    int tamano = lista.tamano;
	if(lista.head==NULL){
    	printf("LA LISTA ESTA VACIA \n");
    }
    else{
    	printf("Los elementos de la lista son: \n");
    	Nodo *current = lista.head;
   		while (tamano>0){
		   printf("%d\n",current->val) ;
		   current = current->next; 
		   tamano--;
		}	
	}
}

//dentro de la funcionalidad F68 y G53 ydentrode l
void addFinalLista(Lista *lista, int val) {
	if(lista->head==NULL){
		primerNodo(lista,val);
	}	
	else
	{
		Nodo *new_node, *temp;
    	new_node = (Nodo*)malloc(sizeof(Nodo));
    	new_node->val = val;
    	new_node->next = lista->head;
    	new_node->prev = lista->head->prev;
		lista->head->prev=new_node;
		temp=lista->head;
		
		while(temp->next!=lista->head)
			temp=temp->next;
    	temp->next=new_node;
	}	
	lista->tamano++;
}


void addPrincipioLista(Lista *lista, int val) {
	if(lista->head==NULL){
		primerNodo(lista,val);
	}	
	else{
		Nodo *new_node, *temp;
    	new_node = (Nodo*)malloc(sizeof(Nodo));
    	new_node->val = val;
    	new_node->next = lista->head;
    	new_node->prev = lista->head->prev;
    	lista->head->prev=new_node;
		
		temp=lista->head;
		
		while(temp->next!=lista->head)
			temp=temp->next;
    	temp->next=new_node;
		
		lista->head = new_node;
	}
	lista->tamano++;
}

void primerNodo(Lista *lista, int val){
	Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
	nodo->val = val;
    nodo->next = nodo;
    nodo->prev = nodo;
    lista->head = nodo;
}

void borrarPrimero(Lista *lista) {
    if (lista->head == NULL) {
        printf("La lista esta vacia");
    }
    else{
    	
	}
}

void borrarUltimo(Lista *lista) {
    if (lista->head == NULL) {
        printf("La lista esta vacia");
    }
    else{
    	
	}

}

void MayoresyMenores(Lista *lista,int x){
    Nodo* tmp = (Nodo*)malloc(sizeof(Nodo));
    tmp = lista->head;
    Nodo* tmp1 = (Nodo*)malloc(sizeof(Nodo));
    tmp1 = lista->head;
    Nodo* tmp2 = (Nodo*)malloc(sizeof(Nodo));
    tmp2 = lista->head;
    while(tmp->next!=NULL){
        if(tmp->next->val<x){
            printf("%d, ",tmp->next->val);
        }
        tmp=tmp->next;
    }
    while(tmp1->next!=NULL){
        if(tmp1->next->val==x){
            printf("%d, ",tmp1->next->val);
        }
        tmp1=tmp1->next;
    }
    while(tmp2->next!=NULL){
        if(tmp2->next->val>x){
            printf("%d, ",tmp2->next->val);
        }
        tmp2=tmp2->next;
    }
}


