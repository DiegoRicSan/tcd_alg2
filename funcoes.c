#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>

int carregarArquivo(char *nome_arquivo, int **vetor, int *total) // função para carregar arquivo
{
    FILE *fp = fopen(nome_arquivo, "r");; // abre o arquivo 
    if (fp == NULL)
    {
        printf("Erro na abertura do arquivo %s\n", nome_arquivo);
        return -1; // retorna caso ocorra algum erro
    }

    int i = 0;
    int tamanho = 1000; // tamanho minimo dos txt de entrada
    while (fscanf(fp, "%d", &((*vetor)[i])) != EOF) // while para guardar os numeros no vetor
    {
        i++;
        if(i >= tamanho) // verifica se o tamanho do arquivo é maior que o vetor
        {
            tamanho = tamanho * 10;
            int *temp = (int*) realloc(*vetor, tamanho * sizeof(int)); // aumentar tamanho do vetor
            if (temp != NULL)
            {
                *vetor = temp; // recebe o vetor realocado
            }
            else
            {
                printf("Erro ao expandir memoria\n");
                fclose(fp);
                return -1; // retorna caso erro
            }
        }
    }
    *total = i; // retorna para main quantos numeros foram lidos
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

