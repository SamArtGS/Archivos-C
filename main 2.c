#include <stdio.h>
#include "listacirc.h"
Lista lista;
int desea(void);
int main(int argc, char** argv){
        int h, valor;
        crearLista();
        printf("Bienvenido");
        do{
            printf("\n1. Añadir elemento al principio de la lista.");
            printf("\n2. Añadir elemento al final de la lista.");
            printf("\n3. Borrar primer elemento de la lista.");
            printf("\n4. Borrar último elemento de la lista.");
            printf("\n5. Recorrer lista.");
            printf("\n6. Buscar elemento en la lista. ");
            printf("\n7. Mostrar lista");
            printf("\n\nHola, elija una opción: ");
            scanf("%d",&h);
            switch (h) {
                case 1:
                    printf("\nIngrese el número que desee agregar: ");
                    scanf("%d",&valor);
                    addPrincipioLista(&lista,valor);
                    break;
                case 2:
                    printf("\nIngrese el número que desee agregar: ");
                    scanf("%d",&valor);
                    addFinalLista(&lista,valor);
                    break;
                case 3:
                    borrarPrimero(&lista);
                    break;
                case 4:
                    borrarUltimo(&lista);
                    break;
                case 5:
                    printf("\nPrimer elemento de la lista");
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
