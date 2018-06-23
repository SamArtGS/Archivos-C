#include<stdio.h>
#define true 1
#define false 0
#define max 7

typedef struct{
    int inicio;
    int final;
    int vector[max];
}cola;
//siempre me da la cantidad de elementos: max - inicio + final + 1
void Iniciar(cola *que);
int IsEmpty(cola *que);
int isFull(cola *que);
void add(cola *que, char c);
void del(cola *que);        
int main(){
   cola kha;
   printf("\nBienvenido, este algoritmo le permite ver una estructura circular.\n\n");
   Iniciar(&kha);
   add(&kha, 'A');
   add(&kha, 'B');
   add(&kha, 'C');
   add(&kha, 'D');
   add(&kha, 'E');
   add(&kha, 'F');
   add(&kha, 'G');
   del(&kha);
   del(&kha);
   printf("\n\nAl final el elemento inicial es %c y el final %c. \n",kha.vector[kha.inicio],kha.vector[kha.final]);
}
void Iniciar(cola *que){
    que->inicio=-1;
    que->final=-1;
}
int IsEmpty(cola *que){
    if(que->final ==-1){
        return true;
    }else{
        return false;
}
}

int Elementos(cola *que){
    if(IsEmpty(que)){
        return false;
    }else{
        if(que->inicio <= que->final){
            return que->final - que->inicio+1;
        }else{
            return max - que->inicio + que->final +1;
        }
}
}

int isFull(cola *que){
    if(Elementos(que) == max){
        return true;
    }else{
        return false;
}
}
void add(cola *que, char c){
    if(!isFull(que)){
        if(IsEmpty(que)){
        que->inicio=0;    
        }
        if(que->final == max -1){
            que->final = 0;
        }else{
        que->final++;
    }
        que->vector[que->final]=c;
        printf("Inicio actual %i\n",que->final);
        printf("%c en final %i\n\n", que->vector[que->final],que->final);
    }else{
        printf("Está llena");
    }
}
void del(cola *que){
    if(!IsEmpty(que)){
        int tmp = que->inicio;
            if(Elementos(que)==1){
                Iniciar(que);
                }else{
                    que->inicio++;
                    }
        printf("Borrar índice: %d \n", tmp);
        printf("Nuevo inicio: %c con valor %d y final %d \n\n",que->vector[que->inicio], que->inicio, que->final);
    }else{
        printf("Está vacía");
}
}
