#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include "funcoes.h"

int main()
{
    LARGE_INTEGER frequency;
    LARGE_INTEGER inicio, fim;
    double elapsedtime;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&inicio);

    // =================================================================

    int x = 0;
    int *vetor = (int *)malloc(1000 * sizeof(int)); // alocacao inicial do vetor
    char nome_arquivo[30];
    int total = 0;                                  // variavel para receber o tamanho do vetor
    do
    {
        printf("\n\n======= MENU ========\n\n"); 
        printf("1. Carregar arquivo de dados\n");
        printf("2. Buscar elemento (linear ou binaria)\n");
        printf("3. Ordenar dados (Insertion, Bubble, Selection, Merge, Quick, EXTRA)\n");
        printf("4. Gerar relatorio (Log)\n");
        printf("5. Sair\n\n"); 
        scanf("%d", &x);       

        switch (x)
        {
        case 1:
            // se o usuario carregar um novo arquivo, resetamos o vetor para o tamanho base
            if (vetor != NULL)
            {
                free(vetor);
                vetor = (int *)malloc(1000 * sizeof(int));
            }

            printf("nome do arquivo: ");
            setbuf(stdin, NULL); // limpar buffer para fgets
            fgets(nome_arquivo, sizeof(nome_arquivo), stdin);
            nome_arquivo[strcspn(nome_arquivo, "\n")] = 0; // retirar "/n" no final do fgets

            // a funcao altera o endereco do vetor na main se houver realloc
            if (carregarArquivo(nome_arquivo, &vetor, &total) == 0)
            {
                printf("Sucesso, %d elementos carregados\n\n", total);
            }

            if (vetor != NULL) // verificar se carregou certo
            {
                printf("numeros lidos: ");
                for (int i = 0; i < total; i++)
                {
                    printf("%d, ", vetor[i]);
                }
                printf("\n\n");
            }
            break;
        case 2:
            // Abrir um submenu para buscar elemento (linear ou binaria)
            break;
        case 3:
            // Abrir um submenu com opções para ordenar dados (Insertion, Bubble, Selection, Merge, Quick, EXTRA)
            break;
        case 4:
            // Gerar relatorio (Log)
            break;
        case 5:
            free(vetor);
            printf("\n\nEncerrado");
            break;
        default:
            break;
        }
    } while (x != 5); // loop para o menu, se o usuario escolher a opcao 5, o programa ira sair

    // =================================================================

    QueryPerformanceCounter(&fim);
    elapsedtime = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart;
    printf("Time: %.16lf ms\n", elapsedtime);

    return 0;
}