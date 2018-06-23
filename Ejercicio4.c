#include<stdio.h>
#include<stdlib.h> //para la funciones de malloc
typedef struct{ //definimos nuestra estructura documento
	struct Documento *siguiente; //ponemos nuestro nodo
	int numPaginas; //su número de páginas
	char *nombre; //declaramos el nombre
}Documento; 
Documento *primero=0; //declaramos la función del primero en la cola
Documento *ultimo=0; //declaramos la función de último elemento
void agregar(Documento* impresion); //la función agregar
Documento *retirar(); //función de retirar los elementos
 
int main(){
  int num, i=0; //usamos estas varibles auxiliares para contar
  printf("\n\nBienvenido, ingrese los documentos que deseas imprimir:");
  scanf("%d", &num); //leemos la cantidad de estructuras que desea agregar el usuario
  for (;i<num;i++){
	  char nombres[30]; //
	  int numpag; //metemos num de paginas para asignalo a numPaginas
	  Documento* i = malloc(sizeof(Documento)); //asignamos mediante memoria dinámica el tamaño de las estructuras
	  printf("\nIngrese el nombre del documento a imprimir:");
	  scanf("%s", nombres); //leemos los nombres
	  i -> nombre = nombres; //tiene un error al imprimir las colas de impresión ya que me aparecen con el mismo nombre, creoque se soluciona con una apuntador
	  printf("\nIngrese el número de páginas del documento a imprimir:");
	  scanf("%d", &numpag); //leemos el número de páginas
	  i -> numPaginas = numpag; //asignamos el número de páginas a la estuctura i
	  agregar(i); //mandamos llamar a la función agregar para metera a i
	  }
	  Documento* j = retirar(); //retiramos a los elementos
	  while(j!=NULL){ //mientras las estructuras no sean nulas
		  printf("\n\nNombre: %s.pdf", j->nombre); 
		  printf("\nNúmero de páginas: %d\n", j->numPaginas);
		  printf("Tiempo de impresión: %d segundos\n", 5*(j->numPaginas));
		  j= retirar(); //manda a llamar a retirar a otro conjutno 
		  }
		  printf("\n");
    return 0; //termina la ejecución
}
void agregar(Documento* impresion){
	impresion -> siguiente = NULL;
	if(primero==NULL){
		primero = impresion;
		ultimo = impresion;
		}else{
			ultimo -> siguiente = impresion;
			ultimo = impresion;
			}
}
Documento *retirar(){
			Documento *impresion_r = primero;
			primero = primero -> siguiente;
			return impresion_r;
			}
