#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

struct Pila
{
    int tope;
    int capacidad;
    int *arreglo;
};

struct  Pila *Crear_Pila(int capacidad)
{
    struct Pila *pila = (struct Pila*)malloc(sizeof(struct Pila));//Reservamos bloque en memoria
    pila->capacidad = capacidad;//asignamos el tamaño de la pila
    pila->tope=-1;//inicializamos una posicion en el arreglo vacio 
    pila->arreglo = (int *)malloc(pila->capacidad*sizeof(int));//Creamos un arreglo para guardar palabras
    return pila;
};

int Pila_Vacia(struct Pila *pila){
    return pila->tope == -1;
}

int Pila_Llena(struct Pila *pila){
    return pila->tope == pila->capacidad-1;
}


void PUSH(struct Pila *pila, int dato){
    if(Pila_Llena(pila)){
        printf("\nNo hay espacio para guardar dato");
        return;
    }
    pila->arreglo[++pila->tope] = dato;
    printf("\nIngresando elemento %d a la pila ",dato);
}

int POP(struct Pila *pila){
    if (Pila_Vacia(pila))
    {
        printf("\nNo hay Elementos en la pila.");
        return INT_MIN;
    }
    return pila->arreglo[pila->tope--];
}

int PEEK(struct Pila *pila)
{
    if (Pila_Vacia(pila))
    {
        printf("\nNo hay Elementos en la pila");
    }
    
    return pila->arreglo[pila->tope++];
};

int buscar(struct Pila *pila,int dato)
{
    if (Pila_Vacia(pila))
    {
        printf("\nNo hay elementos en la pila");
    }
    for(int i =0 ; i <= pila->tope; i++)
        if (pila->arreglo[i] == dato)
            return pila->arreglo[i];
        
    return -1;
    
}


void mostrar_pila(struct Pila *pila){
    if (Pila_Vacia(pila))
    {
        printf("\n No hay Elementos en la pila");
        return;
    }
        printf("\n\n-----Elementos de la pila: \n");
        for (int i = 0; i <= pila->tope; i++)
        {
            printf("[%d]",pila->arreglo[i]);
        }
        printf("<--Tope");
}


int main(int argc, char const *argv[])
{
    struct Pila *pila = Crear_Pila(5);
    PUSH(pila,10);
    PUSH(pila,15);
    PUSH(pila,20);
    PUSH(pila,30);
    mostrar_pila(pila);
   
    printf("\n\nEliminando dato %d de la pila",POP(pila));
    printf("\n\nEliminando dato %d de la pila",POP(pila));
    mostrar_pila(pila);
    
    printf("\n\nElemento en la punta %d",PEEK(pila));
    
    printf("\n\nBuscando Valor si es -1 no existe valor..");
    printf("\n %d",buscar(pila,150));
   
    free(pila->arreglo);
    free(pila);
    return 0;
}
