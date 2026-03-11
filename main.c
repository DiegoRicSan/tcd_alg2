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

    int x = 0;       // escolha do menu
    int permiss = 0; // chave para permissao de funcionalidades

    int *vetor = (int *)malloc(1000 * sizeof(int)); // alocacao inicial do vetor
    int *ordenado = NULL;                           // copia do vetor para ser ordenado
    char nome_arquivo[30];                          // nome do arquivo txt a ser carregado
    int tamanho = 0;                                // variavel para receber o tamanho do vetor

    double tempoAlg[6] = 0;   // variavel para armazenar o tempo de cada algoritmo utilizado
    double tempoBusca[2] = 0; // variavel para armazenar o tempo de cada busca usada

    int sort = 0;  // variavel para armazenar a opcao escolhida de sort
    int busca = 0; // variavel para armazenar a opcao escolhida de busca

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

            // se o usuario carregar um novo arquivo, resetamos o vetor anterior (caso existir) para o tamanho base
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
            if (carregarArquivo(nome_arquivo, &vetor, &tamanho) == 0)
            {
                printf("Sucesso, %d elementos carregados\n\n", tamanho);

                if (ordenado != NULL) // verificar se ja existe conteudo no vetor ordenado
                {
                    free(ordenado); // caso tenha, limpa o conteudo
                }

                ordenado = (int *)malloc(tamanho * sizeof(int)); // alocacao de memoria com o tamanho do vetor original
                memcpy(ordenado, vetor, tamanho * sizeof(int));  // copiar conteudo do vetor para o ordenado

                permiss = 1; // autoriza buscar e ordenar
            }

            break;

        case 2:

            // verificar se ja carregou algum arquivo
            if (permiss == 0)
            {
                printf("Necessario carregar um arquivo para busca");
                break;
            }

            // Declaração das variáveis
            // chave -> número que o usuário deseja procurar
            // resultado -> índice retornado pela função de busca
            // opbusca -> opção escolhida pelo usuário (linear ou binária)
            int chave, resultado, opbusca;

            // Solicita ao usuário o número que será procurado no vetor
            printf("\nDigite o numero a ser buscado: ");
            scanf("%d", &chave);

            // Pergunta qual tipo de busca o usuário deseja utilizar
            printf("\nDigite o tipo de busca desejado: ");
            printf("\n1-Linear\n2-Binaria\n");
            scanf("%d", &opbusca);

            // Verifica qual tipo de busca foi escolhido
            if (opbusca == 1)
            {
                // Chama a função de busca linear
                // vetor -> lista de números
                // chave -> valor a ser buscado
                // tamanho -> quantidade de elementos do vetor
                resultado = buscaLinear(vetor, chave, tamanho);
            }
            else if (opbusca == 2)
            {
                // verifica se o vetor esta ordenado, caso nao esteja, pede ordenacao e volta
                if (verificaOrdenacao(ordenado, tamanho) != 0)
                {
                    printf("Necessario ordenar vetor para busca linear");

                    break;
                }

                // Chama a função de busca binária
                // inicio = 0 (primeira posição do vetor)
                // fim = tamanho - 1 (última posição do vetor)
                resultado = buscaBinaria(ordenado, chave, 0, tamanho - 1);
            }
            else
            {
                // Caso o usuário digite uma opção inválida
                printf("\nOpcao selecionada nao existe, escolha 1 ou 2");

                break;
            }

            // Verifica se o valor foi encontrado
            if (resultado != -1)
            {
                // Se o resultado for diferente de -1,
                // significa que a chave foi encontrada
                printf("\nO elemento %d foi encontrado no indice %d", chave, resultado);

                // autoriza o relatorio
                permiss = 2;
            }
            else
            {
                // Se o resultado for -1,
                // significa que o valor não está no vetor
                printf("\nO elemento %d nao foi encontrado", chave);

                // autoriza o relatorio
                permiss = 2;
            }
            break;

        case 3:

            // verificar se ja carregou algum arquivo
            if (permiss == 0)
            {
                printf("\nNecessario carregar um arquivo para ordenar");
                break;
            }

            int opAlg = 0;

            printf("\nArquivo selecionado: %s\n", nome_arquivo);
            printf("\nEscolha o algoritmo de ordenacao: \n\n");
            printf("1. BubbleSort\n");
            printf("2. InsertionSort\n");
            printf("3. SelectionSort\n");
            printf("4. MergeSort\n");
            printf("5. QuickSort\n");
            printf("6. EXTRA\n\n");
            scanf("%d", &opAlg);

            if (opAlg > 0 && opAlg < 7)
            {
                // o espaco reservado para o algoritmo escolhido é zerado
                tempoAlg[opAlg - 1] = 0;

                for (int i = 0; i < 100; i++)
                {
                    // aloca memoria e copia o vetor original para ser feito a ordenacao
                    int *copia = (int *)malloc(tamanho * sizeof(int));
                    memcpy(copia, vetor, tamanho * sizeof(int));

                    QueryPerformanceCounter(&inicio);

                    if (opAlg == 1)
                        bubbleSort(copia, tamanho);
                    else if (opAlg == 2)
                        insertionSort(copia, tamanho);
                    else if (opAlg == 3)
                        selectionSort(copia, tamanho);
                    else if (opAlg == 4)
                        mergeSort(copia, 0, tamanho - 1);
                    else if (opAlg == 5)
                        quickSort(copia, 0, tamanho - 1);

                    QueryPerformanceCounter(&fim);

                    elapsedtime = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart;

                    // soma o tempo total de execucao do algoritmo a posicao reservada para o algoritmo escolhido
                    tempoAlg[opAlg - 1] += elapsedtime;

                    // libera a copia do vetor
                    free(copia);
                }

                printf("\nTempo medio de execucao: %.9lf ms\n", tempoAlg[opAlg - 1] / 100);

                // autoriza o relatorio log
                permiss = 2;
            }
            else
            {
                printf("valor invalido");
            }

            break;

        case 4:

            // verificar se ja rodou algum algoritmo
            if (permiss != 2)
            {
                printf("Algum algoritmo deve ser executado antes");
                break;
            }

            // Gerar relatorio (Log)

            break;

        case 5:
            if (vetor != NULL)
                free(vetor);
            if (ordenado != NULL)
                free(ordenado);
            printf("\n\nEncerrado");

            break;

        default:

            printf("opcao invalida");

            break;
        }
    } while (x != 5); // loop para o menu, se o usuario escolher a opcao 5, o programa ira sair

    return 0;
}
