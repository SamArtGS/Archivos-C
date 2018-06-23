#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int tope;
    int lista[100];
}Pila;

//declaración de funciones para trabajar con la estructura

Pila crearPila();
int isEmpty(Pila);
void meter(Pila*,int);
int sacar(Pila*);
int top(Pila);
int main(){
    printf("\nVamos a crear una pila. \n");
    Pila miPila = crearPila();
    printf("Ingrese 5 valores para agregar a la pila. \n");
    printf("1: ");
    scanf("%d",&miPila.lista[miPila.tope]);
	meter(&miPila,miPila.lista[miPila.tope]);
	printf("2: ");
    scanf("%d",&miPila.lista[miPila.tope]);
	meter(&miPila,miPila.lista[miPila.tope]);
	printf("3: ");
	scanf("%d",&miPila.lista[miPila.tope]);
	meter(&miPila,miPila.lista[miPila.tope]);
	printf("4: ");
	scanf("%d",&miPila.lista[miPila.tope]);
	meter(&miPila,miPila.lista[miPila.tope]);
	printf("5: ");
	scanf("%d",&miPila.lista[miPila.tope]);
	meter(&miPila,miPila.lista[miPila.tope]);
    printf("\nEl valor de tope es: %d \n",miPila.tope);    //recuerda que el tope es un índice
    printf("\nValor del 5to número es: %d",sacar(&miPila)); 
    printf("\nValor del 4to número es: %d",sacar(&miPila)); 
    printf("\nValor del 3er número es: %d",sacar(&miPila));
    printf("\nValor del 2do número es: %d",sacar(&miPila));
    printf("\nValor del 1er número es: %d",sacar(&miPila));
    printf("\n\nEl mayor de todos los elementos es: %d", );
	return 0;
}
Pila crearPila(){
	Pila p;
	p.tope=0;
	return p;
}
int isEmpty(Pila p){
	if(p.tope==0)
		return 1;
	return 0;
}
void meter(Pila *p,int x){
	p->lista[p->tope]=x;
	p->tope++;
};

int sacar(Pila *p){
	if(p->tope!=0){ //checamos que no esté vacia la pila
	p->tope--; //le bajamos un escalón a tope de manera que sea enfoque al siguiente
    return p->lista[p->tope];//retornamos el valor para poder ser usado
    }else{ //en caso que la pila esté vacía
	return 0; //si se termina la pila retornamos puros valores nulos, ceros
	}
}
int top(Pila p){
	if(isEmpty(p)==1){
		printf("La pila ya esta vacia.");
		return -1;
	}
	else{
		return p.lista[p.tope-1];
	}
}
