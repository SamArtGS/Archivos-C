#include<stdio.h>
struct producto{ //estructura del producto
	char claveP[20]; //clave
	char nombreP[20]; //nobmre del producto
	int precio;  //precio del producto
};
struct seccionT{
	char codigo[20];  //el código que consta de letras y números
	char categoria[20]; //la categoría de la sección (quesos)
	struct producto usu1; //la estructura anterior
};
struct tiendaDep{
     char nombre[20]; //nombre de la tienda
     char zona[20];  //la zona o dirección donde se encuentra
     struct seccionT usu;
};


int crearTiendaDep(struct tiendaDep *); //función que tiene como parámetro a la estructura tiendaDep, devuelve cuantos1
int crearSeccionT(struct seccionT *); //función que tiene como parámetro a la estructura seccionT, devuelve cuantos2
int crearProducto(struct producto *); //función que tiene como parámetro a la estructura producto, retorna cuantos3
void asignarProductoASeccion(struct producto *, struct seccionT *); //función para asignar los productos a las secciones
void asignarSeccionATienda(struct seccionT *, struct tiendaDep *); //función para asignar a las secciones a respectivas tiendas
void mostrarTiendasDep(struct tiendaDep *, int); //imprime la estructura de tiendaDep
void mostrarSecciones(struct seccionT *, int);//imprime la estructura de seccionT
void mostrarProductos(struct producto *, int);//imprime la producto

int main(){ //función principal
	struct tiendaDep usu[100]; //se insertan las estructuras para poder trabajarlas
	struct seccionT usu1[100];
	struct producto usu2[100];
  int opcion, pregunta=1; // se declaran varibles para nuestro ciclo
  int cuantos1=0, cuantos2=0, cuantos3=0; //se declaran varibles para imprimir los valores
  printf("\n\tBienvenido a su punto de Venta EDA, ¿qué desea hacer?\n"); //
  while(pregunta==1){ //ciclo para repetir las posibilidades para el usuario
         printf("\n1: Agregar una tienda.");  
         printf("\n2: Agregar una sección.");
         printf("\n3: Agregar un producto.");
         printf("\n4: Asignar producto a sección.");
         printf("\n5: Asignar sección a tienda.");
         printf("\n6: Mostar los departamentos de la tienda.");
         printf("\n7: Mostrar las secciones.");
         printf("\n8: Mostrar los productos.\n\t:");
         scanf("\n%d", &opcion); //lee la opción que elija el usuario
	switch(opcion){ //por medio de la decision switch abrimos los casos
		  case 1:
		  crearTiendaDep(usu);  //la función crearTiendaDep
		  printf(" ¿Desea continuar en el programa? 1: SI  2: NO   :");
		  scanf("%d",&pregunta); //repetición del ciclo
		  break;
		  case 2:
		  crearSeccionT(usu1); //llamamos a la función crearSeccionT
		  printf(" ¿Desea continuar en el programa? 1: SI  2: NO   :");
		  scanf("%d",&pregunta);//repetición del ciclo
		  break;
		  case 3:
		  crearProducto(usu2); //función crearProducto
		  printf(" ¿Desea continuar en el programa? 1: SI  2: NO   :");
		  scanf("%d",&pregunta);//repetición del ciclo
		  break;
		  case 4:
		  asignarProductoASeccion(usu2, usu1); //la asignación <<no fue concretada>>
		  printf(" ¿Desea continuar en el programa? 1: SI  2: NO   :");
		  scanf("%d",&pregunta);//repetición del ciclo
		  break;
		  case 5:
		  asignarSeccionATienda(usu1, usu);//la asignación <<no fue concretada>>
		  printf(" ¿Desea continuar en el programa? 1: SI  2: NO   :");
		  scanf("%d",&pregunta);//repetición del ciclo
		  break;
		  case 6:
		  mostrarTiendasDep(usu,cuantos1); //imprime las estructuras de las tiendas
		  printf(" ¿Desea continuar en el programa? 1: SI  2: NO   :");
		  scanf("%d",&pregunta);//repetición del ciclo
		  break;
		  case 7:
		  mostrarSecciones(usu1, cuantos2); //imprime las estructuras de las secciones
		  printf(" ¿Desea continuar en el programa? 1: SI  2: NO   :");
		  scanf("%d",&pregunta);//repetición del ciclo
		  break;
		  case 8:
		  mostrarProductos(usu2, cuantos3); //imprime las estruturas de los productos
		  printf(" ¿Desea continuar en el programa? 1: SI  2: NO   :");
		  scanf("%d",&pregunta);//repetición del ciclo
		  break;
		  default: //la opción fuera de las señaladas
		  printf("Opción no válida. Intete de nuevo");
		  }
	  }
  getchar(); //capura los scanf
  return 0; //termina la ejecución
}

int crearTiendaDep(struct tiendaDep usu[]){ //como parámetro la estructura tiendaDef con usu[]
	int conde, cuantos1; //declara varibles de la función
	printf("Ingrese el número de tiendas que desea agregar a su administración: ");
    scanf("%d", &cuantos1); //lee la cantidad de tiendas que desea ingresar
    for(conde=0;conde<cuantos1;conde++) //incia el ciclo para agregar elementos a las estructuras de tipo tiendaDef
    {
		struct tiendaDep usu[10]; //con una estrutura mola
		printf("\n\n\tTienda %d:", conde+1); //pone el número de la tienda
        printf("\nIngresa el nombre de la tienda: ");
        scanf("%s",usu[conde].nombre); //lee el nombre
        printf("\nIngresa la zona de la tienda: ");
        scanf("%s",usu[conde].zona); //lee la zona
         //la asigna a usu
    }
    return cuantos1; //retorna cuantos1 para poder usarlo en la impresión de las estructuras
}
int crearSeccionT(struct seccionT usu1[]){ //como parámetros
	int conde, cuantos2;
	printf("Ingrese el número secciones que desea agregar: ");
    scanf("%d", &cuantos2); 
    for(conde=0; conde<cuantos2; conde++) //incia el ciclo para agregar elementos a las estructuras de tipo seccionT
    {
		struct seccionT mole; //con una estructura mole
		printf("\n\n\tSección: %d", conde+1); //la sección
        printf("\nIngresa la categoría del departamento: ");
        scanf("%s",mole.codigo); //lee los elementos que el usuario desea insertar a la estructura
        printf("\nIngresa el código el departamento: ");
        scanf("%s",mole.categoria);
        usu1[conde] = mole; //los asigna a usu1
	}
	return cuantos2; //retorna cuantos2 para poder usarlo en la impresión de las estructuras
}
int crearProducto(struct producto usu2[]){ //como parámetro: la estructura de tipo usu2[]
	int conde, cuantos3;
	printf("Ingrese el número de productos que desea vender: ");
    scanf("%d", &cuantos3);
    for(conde=0; conde<cuantos3; conde++)
    {
		struct producto polo; //como una estructura polo
		printf("\n\n\tProducto: %d", conde+1);
        printf("\nIngresa la clave del producto: ");
        scanf("%s",polo.claveP); //se ingresa la clave del producto
        printf("\nIngresa la el nombre del producto: ");
        scanf("%s",polo.nombreP); //se ingresa el nombre del producto
        printf("\nIngresa el precio del producto: ");
        scanf("%d",&polo.precio); //se ingresa el precio
        usu2[conde]=polo; //lo asigna a usu2
	}
	return cuantos3; //retorna cuantos3 para poder usarlo en la impresión de las estructuras
}
void asignarProductoASeccion(struct producto usu2[], struct seccionT usu1[]){
	int buscar=0;
	printf("Seleccioene el número del producto que ingresó y luego asígnelo al número de sección correspondiente.");
	scanf("%s", usu2[buscar]);
	scanf("  %s", usu1[buscar]);
	//NO se concretó esta parte con éxito
}
void asignarSeccionATienda(struct seccionT usu1[], struct tiendaDep usu[]){
    int buscar=0;
    printf("Seleccioene el número de las sección que ingresó y luego asígnelo a la tienda correspondiente.");
	scanf("%s", usu1[buscar]);
	scanf("  %s", usu[buscar]);
	//No se concretó esta parte con éxito
	}
void mostrarTiendasDep(struct tiendaDep usu[], int cuantos1){ //ingresa como parámetros la estructura y el tope
	int conde;
	printf("Las tiendas que tiene a su cargo son: \n"); 
	for(conde=0; conde<cuantos1; conde++) //empieza a imprimir las estructuras correspondientes en base a lo ingresado
    {
		printf("\n%s", usu[conde].nombre); //los nombres
        printf("\n%s", usu[conde].zona); //las zonas
	}
}
void mostrarSecciones(struct seccionT usu1[], int cuantos2){//empieza a imprimir las estructuras correspondientes en base a lo ingresado
	int conde;
	printf("Las secciones totales que posee son: \n");
	for(conde=0; conde<cuantos2; conde++)
    {
		printf("\n%s", usu1[conde].codigo); //el código
        printf("\n%s", usu1[conde].categoria); //las categorías
	}
}
void mostrarProductos(struct producto usu2[10], int cuantos3){//empieza a imprimir las estructuras correspondientes en base a lo ingresado
	int conde;
	printf("Los productos que tiene a disposición son: \n");
	for(conde=0; conde<cuantos3; conde++)
    {
		printf("\n%s", usu2[conde].claveP); //la clave de los productos
        printf("\n%s", usu2[conde].nombreP); //el nombre de los productos
        printf("\n%d", usu2[conde].precio); // el precio
	}
}
