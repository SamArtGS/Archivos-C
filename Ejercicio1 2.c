#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int tope;
    int lista[100];
}Pila;

//declaraci�n de funciones para trabajar con la estructura

Pila crearPila();
int isEmpty(Pila);
void meter(Pila*,int);
int sacar(Pila*);
int top(Pila);
int main(){
    printf("\nVamos a crear una pila. \n");
    Pila miPila = crearPila();
    printf("Vamos a ingresar algunos elementos. \n");
	meter(&miPila,10);
    meter(&miPila,20);
    meter(&miPila,30);
    printf("\nEl valor de tope es: %d \n",miPila.tope);    //recuerda que el tope es un �ndice
	int a = sacar(&miPila);
  	int b = sacar(&miPila);
  	int c = sacar(&miPila);
    int d = sacar(&miPila);
    printf("\nvalor de a es: %d",a); 
    printf("\nvalor de b es: %d",b); 
    printf("\nvalor de c es: %d",c);
    printf("\nvalor de d es: %d",d);  
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
	if(p->tope!=0){ //checamos que no est� vacia la pila
	p->tope--; //le bajamos un escal�n a tope de manera que sea enfoque al siguiente
    return p->lista[p->tope];//retornamos el valor para poder ser usado
    }else{ //en caso que la pila est� vac�a
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
