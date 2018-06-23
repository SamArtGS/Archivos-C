#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int primero;
    int ultimo;
    int lista[100];
}Cola;

//declaración de funciones para trabajar con la estructura
Cola crearCola();
int isEmpty(Cola);
void encolar(Cola*,int);
int desencolar(Cola*);
int first(Cola);

int main(){
    printf("Vamos a iniciar una cola \n");
    Cola queue1 = crearCola();
    printf("vamos a ingresar algunos elementos \n");
	encolar(&queue1,10);
	encolar(&queue1,20);
	encolar(&queue1,30);
	int a = desencolar(&queue1);
  	printf("a = %d \n",a);
  	printf("%d \n",queue1.primero);    //Recuerda que primero y último son índices, no son elementos dentro de la cola
  	printf("%d \n",queue1.ultimo);
	return 0;
}
Cola crearCola(){
	Cola c;
	c.primero=1;
	c.ultimo=0;
	return c;
}
int isEmpty(Cola c){
	if(c.primero==c.ultimo+1)
		return 1;
	return 0;
}
void encolar(Cola *c,int x){
	c->lista[c->ultimo]=x;
	c->ultimo+=1;
}
int desencolar(Cola *c){
	if((isEmpty(*c))==1)
		printf("La cola esta vacia \n");
	else{
		int aux = c->lista[c->primero-1];
		c->lista[c->primero-1]=0;
		c->primero++;
		if(c->primero==c->ultimo+1){
	
			*c=crearCola();
		}
		return aux;
	}
	return 0;
}
int top(Cola c){
	// Esta función determina el elemento que se encuentra al frente sin extraerlo de la estructura
return 0;
}

