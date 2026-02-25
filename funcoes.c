#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>

int carregarArquivo(char *nome_arquivo, char modo)
{
    FILE *fp;
    fp = fopen("nome_arquivo", "modo");
    if (fp == NULL)
    {
        printf("Erro na abertura do arquivo\n");
        system("pause");
        exit(1);
    }
    fclose(fp);

    return 0;
}

int buscar(int *vet, int tam, int val) //Busca linear
{
    for (int i = 0; i < tam; i++)
    {
        if (val == vet[i])
        {
            return i;
        }
    }
    return -1;
}

int buscaBinaria(int *vet, int val) //Busca Binária
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

void insertionSort(int vet[], int tam) //Função de ordenação Insertion Sort
{
    int i, j, posi;
    for (i = 1; i < tam; i++) 
    {
        posi = vet[i];
        j = i - 1;
        while (j >= 0 && vet[j] > posi) 
        {
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = posi;
    }
}

