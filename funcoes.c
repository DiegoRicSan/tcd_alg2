#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int carregarArquivo(char *nome_arquivo, int **vetor, int *total) // função para carregar arquivo
{
    FILE *fp = fopen(nome_arquivo, "r");
    // abre o arquivo
    if (fp == NULL)
    {
        printf("\nErro na abertura do arquivo %s", nome_arquivo);
        return -1; // retorna caso ocorra algum erro
    }

    int i = 0;
    int tamanho = 1000;                             // tamanho minimo dos txt de entrada
    while (fscanf(fp, "%d", &((*vetor)[i])) != EOF) // while para guardar os numeros no vetor
    {
        i++;
        if (i >= tamanho) // verifica se o tamanho do arquivo é maior que o vetor
        {
            tamanho = tamanho * 10;
            int *temp = (int *)realloc(*vetor, tamanho * sizeof(int)); // aumentar tamanho do vetor
            if (temp != NULL)
            {
                *vetor = temp; // recebe o vetor realocado
            }
            else
            {
                printf("\nErro ao expandir memoria");
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
int buscaLinear(int *lista, int chave, int tam)
{
    // Percorre todos os elementos do vetor
    for (int i = 0; i < tam; i++)
    {
        // Verifica se o elemento atual é igual à chave procurada
        if (lista[i] == chave)
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
        if (vet[meio] == chave)
        {
            // Se for igual, retorna o índice onde foi encontrado
            return meio;
        }

        // Se o elemento do meio for maior que a chave
        else if (vet[meio] > chave)
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

void bubbleSort(int vet[], int tam) // Função de ordenação Bubble Sort
{

    int troca;
    int i;
    int j;

    for (i = 0; i < tam - 1; i++)
    {
        for (j = 0; j < tam - i - 1; j++) // percorre o vetor comparando elementos vizinhos
        {
            if (vet[j] > vet[j + 1]) // verifica se o elemento atual é maior que o próximo, se for ele trocam de posição
            {
                troca = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = troca;
            }
        }
    }
}

void insertionSort(int vet[], int tam) // Função de ordenação Insertion Sort
{
    int i, j, posi;
    for (i = 1; i < tam; i++) // começa do segundo elemento (i = 1), pois o primeiro já é considerado ordenado
    {
        posi = vet[i]; // guarda o valor atual que será inserido na posição correta
        j = i - 1;     // começa comparando com o elemento anterior

        while (j >= 0 && vet[j] > posi)
        {
            vet[j + 1] = vet[j]; // desloca o elemento maior para a direita
            j = j - 1;           // move para o próximo elemento para esquerda
        }
        vet[j + 1] = posi;
    }
}

void selectionSort(int vet[], int tam) // Função de ordenação Selection Sort
{
    int i;
    int j;
    int minimo;
    int troca;

    for (i = 0; i < tam - 1; i++)
    {
        minimo = i;

        for (j = i + 1; j < tam; j++)
        {
            if (vet[j] < vet[minimo])
            {
                minimo = j;
            }
        }

        if (minimo != i)
        {
            troca = vet[i];
            vet[i] = vet[minimo];
            vet[minimo] = troca;
        }
    }
}

void mergeSort(int vet[], int inicio, int fim) // Função de ordenação Merge Sort
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

void merge(int vet[], int inicio, int meio, int fim) // Função Merge do Algoritmo Merge Sort
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

void quickSort(int vet[], int inicio, int fim) // Função de ordenação Quick Sort
{
    int pivo;
    if (fim > inicio)
    {
        pivo = particiona(vet, inicio, fim); // Separa os dados em 2 partes
        quickSort(vet, inicio, pivo - 1);    // chama a função para a metade esquerda
        quickSort(vet, pivo, fim);       // chama a função para a metade da direita
    }
}
int medianaTres(int vet[], int a, int b, int c) // retorna o índice do valor mediano entre três posições do vetor
{
    if (vet[a] < vet[b]) {
        if (vet[b] < vet[c]) return b;
        if (vet[a] < vet[c]) return c;
        return a;
    } else {
        if (vet[a] < vet[c]) return a;
        if (vet[b] < vet[c]) return c;
        return b;
    }
}
int particiona(int vet[], int inicio, int fim) // função particiona, na qual particiona o vetor do quick Sort
{
    int esq = inicio;
    int dir = fim;
    int meio = inicio + (fim - inicio) / 2;
    int idxPivo = medianaTres(vet, inicio, meio, fim);
    int pivo = vet[idxPivo];
    int troca;

    while (esq <= dir)
    {
        while (vet[esq] < pivo)
            esq++;

        while (vet[dir] > pivo)
            dir--;

        if (esq <= dir)
        {
            troca = vet[esq]; // algoritmo de troca
            vet[esq] = vet[dir];
            vet[dir] = troca;

            esq++; // anda com o vetor para a direita
            dir--; // anda com o vetor para a esquerda
        }
    }

    return esq;
}
int verificaOrdenacao(int vetor[], int count) // verifica se o vetor está ordenado crescentemente. se sim = 1, se nao = 0
{
    for (int i = 1; i < count; i++)
    {
        if (vetor[i] < vetor[i - 1])
        {
            return 0;
        }
    }
    return 1;
}
void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
int criarArquivo(char nome_arqOrd[], int tamanho, int vetor[])
{
    FILE *fp;
    fp = fopen(nome_arqOrd, "w");

    if (fp == NULL)
    {
        printf("\nErro na criacao do arquivo %s", nome_arqOrd);
        return -1; // retorna caso ocorra algum erro
    }

    for (int i = 0; i < tamanho; i++)
    {
        fprintf(fp, "%d\n", vetor[i]);
    }

    fclose(fp);

    return 0;
}

void criaHeap(int vet[], int tam, int i) // essa função garante que heap sort funcione corretamente
{
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;
    int troca;

    if (esquerda < tam && vet[esquerda] > vet[maior])
        maior = esquerda;

    if (direita < tam && vet[direita] > vet[maior])
        maior = direita;

    if (maior != i)
    {
        troca = vet[i];
        vet[i] = vet[maior];
        vet[maior] = troca;

        criaHeap(vet, tam, maior);
    }
}

void heapSort(int vet[], int tam) // Função de ordenação Heap Sort, utilizada no Intro Sort
{
    int troca;

    for (int i = tam / 2 - 1; i >= 0; i--)
        criaHeap(vet, tam, i);

    for (int i = tam - 1; i > 0; i--)
    {
        troca = vet[0];
        vet[0] = vet[i];
        vet[i] = troca;

        criaHeap(vet, i, 0);
    }
}

void introsortAux(int vet[], int inicio, int fim, int depthlimit) // função auxiliar do introsort
{
    int tamanho = fim - inicio + 1;

    if (tamanho < 24)
    {
        insertionSort(vet + inicio, tamanho);

        return;
    }

    if (depthlimit == 0)
    {
        heapSort(vet + inicio, tamanho);
        return;
    }

    int p = particiona(vet, inicio, fim);

    introsortAux(vet, inicio, p - 1, depthlimit - 1);
    introsortAux(vet, p, fim, depthlimit - 1);
}

void introsort(int vet[], int tam) // função principal do Intro Sort
{
    int depthlimit = 2 * log2(tam); // limite maximo de profundidade da recursão do quickSort, também evitando que o quicksort vire O(N²)

    introsortAux(vet, 0, tam - 1, depthlimit);
}
int lerInteiro(char *mensagem, int min, int max)
{
    int valor;
    int ret;
    do
    {
        printf("%s", mensagem);
        ret = scanf("%d", &valor);
        if (ret != 1)
        {
            printf("\nEntrada invalida. Digite um numero.\n");
            limparBuffer(); // limpa o buffer até a próxima linha
        }
        else if (valor < min || valor > max)
        {
            printf("\nOpcao fora do intervalo [%d, %d]. Tente novamente.\n", min, max);
        }
        else
        {
            return valor;
        }
    } while (1);
}
