#include<stdio.h>
#include<string.h>
#define MAX 5
//prototipos
void insertar(char dato[]);
void listar ();
int validarVacio();
int validarEspacio();
int buscar(char dato[]);
int crearMenu(char texto[],int n);
void actualizar(int casilla,char nvodato[]);
int borrar(int casilla);

char arreglo[MAX][30];
int indice;

int main()
{
	//Se crean las variables locales
	char dato[30]; //La variable es un entero llamado dato
	indice=-1;
	int opcion,casilla,d;
	do{
		opcion=crearMenu("1)Insertar\n2)Listar\n3)Actualizar\n4)Borrar\n5)Buscar\n6)Salir\nOpcion:",6);
		switch(opcion){
			case 1://insertar
				if (validarEspacio()!=0)
				{
					printf("Dato: ");
					scanf("%s", &dato);
					insertar(dato);
				}
				else
					printf("\nNo hay espacio en el arreglo\n");
					break;
				case 2:
					listar();
					break;
				case 3://actualizar
					printf("Dato a actualizar: ");
					scanf("%s",&dato);
					casilla=buscar(dato);
					if(casilla!=-1)//dato existe
					{
						printf("Nuevo dato: ");
						scanf("%s",&dato);
						actualizar(casilla,dato);
					}
					break;
				case 4://borrar
					printf("Dato a borrar: ");
					scanf("%s",&dato);
					casilla=buscar(dato);
					if(casilla!=-1)//dato existe
					 d=borrar(casilla);		
					break;
				case 5://buscar
					printf("Dato: ");
					scanf("%s",&dato);
					casilla=buscar(dato);
					if(casilla!=-1)//dato existe
						printf("El dato esta %s en la casilla %i del arreglo\n",dato,casilla);
					break;
				case 6://Salir
					break;
		}
   }while(opcion!=6);
	return 0;
}
void insertar (char dato[])
{
	indice++;
	strcpy(arreglo[indice],dato);
}
int validarEspacio()
{
	return(indice<MAX-1);// El "-1" es por el número del indice, el arreglo es de 5 casillas, la última es la casilla número 4, 
	//y el MAX=5, por lo que para que MAX-1= a la casilla n˙mero 4, que es lo que toma en cuenta el indice.
	 //Se regresa el resultado de la comparaciÛn ya sea un "falso" o "verdadero", se ahorra todo el if and else
}
void listar()
{
	int a;
	if (validarVacio()==0)
	for(a=0;a<MAX;a++)
	printf("%s\t",arreglo[a]);
	printf("\n");
}
int validarVacio()
{
	return(indice==-1);
}
int buscar(char dato[]){
	//varibles locales
	int i;
	for(i=0;i<=indice;i++){
		if(strcmp(arreglo[i],dato)==0)
			return i;//la casilla donde esta almacenado
	}
	printf("No hay datos en el arreglo\n");
	return -1;//No existe el dato
}
int crearMenu(char texto[],int n){
	int opcion;
	do{
		printf("%s",texto);
		scanf("%d",&opcion);
		if(opcion<1 || opcion>n)
			printf("Error: Opcion no valida...\n");
	}while(opcion<1 || opcion>n);
	return opcion;
}
void actualizar(int casilla,char nvodato[]){
	strcpy(arreglo[casilla],nvodato);
}
int borrar(int casilla){
	char aux[30];
	strcpy(aux,arreglo[casilla]);
	strcpy(arreglo[casilla],arreglo[indice]);
	indice--;
	return aux;
}
