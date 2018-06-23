#include <stdio.h>
#include "listacirc.h"
Lista lista;
int desea(void);
int main(){
    char nombre[10];
    char marco[10];
        int h, modelo, motor;
        crearLista();
        printf("Bienvenido a su AutoCar. Seleccione una opción");
        do{
            printf("\n1. Añadir un automóvil al principio");
            printf("\n2. Añadir un automóvil al final");
            printf("\n3. Borrar un automóvil al principio");
            printf("\n4. Borrar un automóvil al final");
            printf("\n5. Recorrer lista de autos.");
            printf("\n6. Buscar un automóvil ");
            printf("\n7. Mostrar lista");
            printf("\n\nHola, elija una opción: ");
            scanf("%d",&h);
            switch (h) {
                case 1:
                    printf("\nIngrese los datos requeridos: ");
                    printf("\nNombre: ");
                    scanf("%s",nombre);
                    printf("Marca: ");
                    scanf("%s",marco);
                    printf("Modelo: ");
                    scanf("%d",&modelo);
                    printf("Motor: ");
                    scanf("%d",&motor);
                addPrincipioLista(&lista,nombre,marco,modelo,motor);
                    break;
                case 2:
                    printf("\nIngrese los datos requeridos: ");
                    printf("\nNombre: ");
                    scanf("%s",nombre);
                    printf("Marca: ");
                    scanf("%s",marco);
                    printf("Modelo: ");
                    scanf("%d",&modelo);
                    printf("Motor: ");
                    scanf("%d",&motor);
                    addFinalLista(&lista,nombre,marco,modelo,motor);
                    break;
                case 3:
                    borrarPrimero(&lista);
                    break;
                case 4:
                    borrarUltimo(&lista);
                    break;
                case 5:
                    printf("\nPrimer elemento de la lista: ");
                    recorrerLista(lista);
                    break;
                case 6:
                    buscar(&lista);
                    break;
                case 7:
                    print_list(lista);
                    break;
                default:
                    printf("\nOpción no válida");
                    break;
            }
        }while(desea()==1);
        return 0;
    }
    int desea(){
        int i;
        do{
            printf("\n¿Desea continuar? ");
            printf("\n\tSi:1  No:0   :");
            scanf("%d",&i);
            if(i==0)
                return 0;
            if(i==1)
                return 1;
            if(i!=0||i!=1)
                printf("Opción no válida\n");
        }while(i!=0||i!=1);
        return 0;
    }
