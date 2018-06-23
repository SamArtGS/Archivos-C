#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
    int dato;
    struct nodo* siguiente;
    struct nodo* anterior;
}nodo;
nodo* primero = NULL;
nodo* ultimo = NULL;
void insertarNodo();
void mostrarListaPU();
void mostrarListaUP();

void insertarNodo(){
    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
    printf("Ingrese el número");
    scanf("%d",&nuevo->dato);
    if (primero==NULL){
        primero=nuevo;
        primero->siguiente = primero;
        ultimo=primero;
        primero->anterior = primero;
    }else{
        ultimo->siguiente = nuevo;
        nuevo->siguiente = primero;
        nuevo->anterior = ultimo;
        ultimo = nuevo;
        primero->anterior = ultimo;
    }
}
void mostrarListaPU(){
    nodo* actual = (nodo*)malloc(sizeof(nodo));
    actual = primero;
    if(primero==NULL){
        printf("\nLa lista está vacía");
    }else{
        do{
            printf("\n %d",actual->dato);
            actual = actual->siguiente;
        }while(actual!=primero);
}
}
void mostrarListaUP(){
    nodo* actual = (nodo*)malloc(sizeof(nodo));
    actual = ultimo;
    if(primero==NULL){
        printf("\nLa lista está vacía");
    }else{
        do{
            printf("\n %d",actual->dato);
            actual = actual->anterior;
        }while(actual!= ultimo);
    }
}
void buscarNodo(){
    nodo* actual = (nodo*)malloc(sizeof(nodo));
    actual = primero;
    int i=0, conde=0;
    printf("Ingrese el número a buscar dentro de la lista");
    scanf("%d", &i);
    if(primero==NULL){
        printf("La lista está vacía");
    }else{
        do{
            if(actual->dato == i){
                conde++;
            }
            actual=actual->siguiente;
        }while(actual!=primero && conde!=1);
    }
}
void actualizarNodo(){
    nodo* actual = (nodo*)malloc(sizeof(nodo));
    actual = primero;
    int busca = 0, conde = 0;
    printf("Ingrese el dato del nodo a buscar"); //o sea como un buscar y cada vez que lo encuentre lo modifica
    scanf("%d",&busca);
    if(primero==NULL){
        printf("La lista está vacía");
    }else{
        do{
            if(actual->dato == busca){
                printf("\nSe ha encontrado un nodo con elemento (%d)", busca);
                printf("Ingresa el nuevo dato para el nodo");
                scanf("%d", &actual->dato);
                conde++;
            }
            actual=actual->siguiente;
        }while(actual!=primero && conde!=1);
        if(conde==0){
            printf("Nodo no encontrado");
        }
    }
}
void eliminarNodo(){
    nodo* actual = (nodo*)malloc(sizeof(nodo));
    actual = primero;
    nodo* anterior = (nodo*)malloc(sizeof(nodo));
    anterior = NULL;
    int busca = 0, conde = 0;
    printf("Ingrese los números de los nodos que desea eliminar");
    scanf("%d",&busca);
    if(primero==NULL){
        printf("La lista está vacía");
    }else{
        do{
            if(actual->dato == busca){
                printf("\nSe ha encontrado un nodo con elemento (%d)", busca);
                if(actual==primero){
                    primero = primero -> siguiente;
                    primero->anterior = ultimo;
                    ultimo ->siguiente = primero;
                }else if(actual==ultimo){
                    ultimo = anterior;
                    ultimo->siguiente = primero;
                    primero -> anterior = ultimo;
                }else{
                    anterior->siguiente = actual->siguiente;
                    actual->siguiente->anterior = anterior;
                }
                conde++;
            }
            anterior = actual;
            actual=actual->siguiente;
        }while(actual!=primero && conde!=1);
        if(conde==0){
            printf("Nodo no encontrado");
        }else{
            free(anterior);
        }
    }
}
