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

// Percorre o vetor elemento por elemento até encontrar a chave
int buscaLinear (int *lista, int chave, int tam)
{
    // Percorre todos os elementos do vetor
    for(int i = 0; i < tam; i++)
    {
        // Verifica se o elemento atual é igual à chave procurada
        if(lista[i] == chave)
        {
            // Se encontrou, retorna o índice onde o elemento está
            return i;
        }
    }

    // Se terminou o laço e não encontrou a chave,
    // retorna -1 indicando que o elemento não existe no vetor
    return -1;
}

// Procura a chave em um vetor ORDENADO dividindo o vetor ao meio a cada passo
int buscaBinaria(int *vet, int chave, int inicio, int fim)
{ 
    // Continua procurando enquanto o intervalo for válido
    while (inicio <= fim)
    {
        // Calcula o índice do elemento do meio do intervalo
        int meio = inicio + (fim - inicio) / 2;

        // Verifica se o elemento do meio é a chave procurada
        if(vet[meio] == chave)
        {
            // Se for igual, retorna o índice onde foi encontrado
            return meio;
        }

        // Se o elemento do meio for maior que a chave
        else if(vet[meio] > chave)
        {
            // A chave só pode estar na metade esquerda do vetor
            fim = meio - 1;
        }

        // Caso contrário, a chave está na metade direita
        else
        {
            inicio = meio + 1;
        }
    }

    // Se sair do laço sem encontrar a chave,
    // significa que ela não está no vetor
    return -1;
}

void bubbleSort(int vet[], int tam) //Função de ordenação Bubble Sort
{

    int troca;
    int i;
    int j;

    for(i = 0; i < tam - 1; i++)
    {
        for(j = 0; j < tam - i - 1; j++)
        {
            if(vet[j] > vet[j + 1])
            {
                troca = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = troca;
            }
        }
    }
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

void selectionSort(int vet[], int tam)//Função de ordenação Selection Sort
{
    int i;
    int j;
    int minimo;
    int troca;

    for(i = 0; i < tam - 1; i++)
    {
        minimo = i;
        for(j = i + 1; j < tam; j++)
        {
            if(vet[j] < vet[minimo])
            {
                minimo = j;
            }
        }
        if(minimo != i)
        {
            troca = vet[i];
            vet[i] = vet[minimo];
            vet[minimo] = troca;
        }
    }


}

void mergeSort(int vet[], int inicio, int fim) //Função de ordenação Merge Sort
{
    if (inicio < fim)
    {
        int meio;

        meio = (inicio + fim) / 2;

        mergeSort(vet, inicio, meio);
        mergeSort(vet, meio + 1, fim);
        merge(vet, inicio, meio, fim);
    }
}

void merge(int vet[], int inicio, int meio, int fim) //Função Merge do Algoritmo Merge Sort
{
    int i;
    int j;
    int k;

    i = inicio;
    j = meio + 1;
    k = 0;

    int temp[fim - inicio + 1];

    while (i <= meio && j <= fim)
    {
        if (vet[i] <= vet[j])
        {
            temp[k++] = vet[i++];
        }
        else
        {
            temp[k++] = vet[j++];
        }
    }

    while (i <= meio)
    {
        temp[k++] = vet[i++];
    }

    while (j <= fim)
    {
        temp[k++] = vet[j++];
    }

    for (i = inicio, k = 0; i <= fim; i++, k++)
    {
        vet[i] = temp[k];
    }
}

void quickSort(int vet[], int inicio, int fim) //Função de ordenação Quick Sort
{
    int pivo;
    if(fim > inicio)
    {
        pivo = particiona(vet, inicio, fim); // Separa os dados em 2 partes
        quickSort(vet, inicio, pivo - 1); //chama a função para a metade esquerda
        quickSort(vet, pivo + 1, fim); //chama a função para a metade da direita
    }
}

int particiona(int vet[], int inicio, int fim) //Função 'particiona' para o Quick Sort funcionar
{
    int esq;
    int dir;
    int pivo;
    int troca;

    esq = inicio;
    dir = fim;
    pivo = vet[(inicio + fim)/2];

    while(esq < dir)
    {
        while(esq <= fim && vet[esq] <= pivo)
        {
            esq++;
        }

        while(dir >= inicio && vet[dir] > pivo)
        {
            dir--;
        }
        
        if(esq < dir) // troca esq e dir
        {
            troca =  vet[esq];
            vet[esq] = vet[dir];
            vet[dir] = troca;
        }

    }
    vet[inicio] = vet[dir];
    vet[dir] = pivo;
    return dir;
}

int verificaOrdenacao(int vetor[], int count)
{
    for (int i = 0; i < count; i++)
    {
        if (vetor[i] > vetor[i+1])
        {
            return -1;
        }
    }
    return 0;
}
