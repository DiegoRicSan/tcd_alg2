// funcoes que fiz na aula para exemplo

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void bogoSort(int *vet, int tam);
int isSorted(int *vet, int tam);
void ordena(int *vet, int tam);
int bubbleSort(int *vet, int tam);
int buscar(int *vet, int val);
int buscaBinaria(int *vet, int val);

int main()
{
    int tam = 7;
    int a[7] = {8, 1, 2, 7, 5, 3, 0}, res;
    int *vet = &a[0];

    bubbleSort(vet, tam);

}

int isSorted(int *vet, int tam)
{
    for (int i = 0; i < tam - 1; i++)
    {
        if (vet[i] > vet[i + 1])
        {
           return 0;
        }
    }
}

void bogoSort(int *vet, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        int x = rand() % tam, y = vet[i];
        vet[i] = vet[x];
        vet[x] = y;
    }
}

void ordena(int *vet, int tam)
{
    int try = 0;
    bogoSort(vet, tam);
    for (int i = 0; i < tam; i++)
    {
        printf("%d ",vet[i]);
    }
    printf("\n");
    try++;
    printf("\n\nTentativas: %d",try);
}

int bubbleSort(int *vet, int tam)
{
    for (int i = 0; i < tam - i - 1; i++)
    {
        int troca = 0;
        for (int j = 0; j < tam - 1; j++)
        {
            if(vet[j] > vet[j + 1])
            {
                int x = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = x;
                troca = 1;
            }
        }
        for (int i = 0; i < tam; i++)
        {
            printf("%d ",vet[i]);
        }  
        printf("\n");
        if(troca == 0)
        {
            break;
        }
    }
}

int buscar(int *vet, int val)
{
    for (int i = 0; i < 5; i++)
    {
        if (val == vet[i])
        {
            return i;
        }
    }
    return -1;
} 

int buscaBinaria(int *vet, int val)
{ 
    int esq = 0;
    int dir = 10;

    while (dir > esq)
    {
        int met = (esq + dir) / 2;

        if (val == vet[*vet+met])
        {
            return met;
        }
        if(val > vet[*vet+met])
        {
            esq = met + 1; 
        }
        if(val < vet[*vet+met])
        {
            dir = met - 1;
        }
    }
    return -1;
}