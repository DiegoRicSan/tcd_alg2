#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include "funcoes.h"
#include <limits.h>

int main()
{
    // para medir o tempo
    LARGE_INTEGER frequency;
    LARGE_INTEGER inicio, fim;
    QueryPerformanceFrequency(&frequency);

    int opc = 0;                // escolha do menu
    int arquivoCarregado = 0;   // chave de permissao das funcionalidades 2 e 3
    int algoritmoExecutado = 0; // chave de permissao da funcionalidade 4

    int *vetor = NULL;     // vetor do arquivo original
    int *ordenado = NULL;  // copia do vetor para ser ordenado
    char nome_arquivo[30]; // nome do arquivo a ser carregado
    int tamanho = 0;       // variavel para receber o tamanho do vetor
    int chave;             // variavel para receber numero a ser buscado

    int sort[6] = {0};  // variavel para armazenar as opcoes de sort utilizadas
    int busca[2] = {0}; // variavel para armazenar as opcoes de busca utilizadas

    do
    {
        // menu inicial
        printf("\n\n========= MENU ==========\n\n");
        printf("- 1. Carregar arquivo de dados\n- 2. Buscar elemento (linear ou binaria)\n");
        printf("- 3. Ordenar dados (Insertion, Bubble, Selection, Merge, Quick, EXTRA)\n");
        printf("- 4. Gerar relatorio (Log)\n- 5. Sair\n\n========= MENU ==========\n");
        opc = lerInteiro("\nEscolha: ", 1, 5);
        printf("\n");

        // switch para opção escolhida
        switch (opc)
        {
        case 1:

            // libera vetor anterior se existir e aloca espaço inicial
            if (vetor != NULL)
            {
                free(vetor);
            }
            vetor = (int *)malloc(1000 * sizeof(int));

            // le nome do arquivo, exemplo de entrada: "crescente_1000.txt"
            printf("Nome do arquivo: ");
            limparBuffer(); // limpar buffer para fgets
            fgets(nome_arquivo, sizeof(nome_arquivo), stdin);
            nome_arquivo[strcspn(nome_arquivo, "\n")] = 0; // retirar "/n" no final do fgets

            // a funcao altera o endereco do vetor na main se houver realloc
            if (carregarArquivo(nome_arquivo, &vetor, &tamanho) == 0)
            {
                printf("\nSucesso, %d elementos carregados", tamanho);

                if (ordenado != NULL) // verifica se ja existe conteudo no vetor ordenado
                {
                    free(ordenado); // caso tenha, limpa o conteudo
                }

                ordenado = (int *)malloc(tamanho * sizeof(int)); // alocacao de memoria com o tamanho do vetor original
                memcpy(ordenado, vetor, tamanho * sizeof(int));  // copiar conteudo do vetor para o ordenado

                // zerar as flags
                algoritmoExecutado = 0;
                memset(busca, 0, sizeof(busca));
                memset(sort, 0, sizeof(sort));

                arquivoCarregado = 1; // autoriza buscar e ordenar
            }
            else
            {
                free(vetor);
                vetor = NULL;
            }
            break;

        case 2:

            // verifica se ja carregou algum arquivo
            if (arquivoCarregado == 0)
            {
                printf("Necessario carregar um arquivo para busca");
                break;
            }

            // Declaração das variáveis
            // chave -> número que o usuário deseja procurar
            // resultado -> índice retornado pela função de busca
            // opbusca -> opção escolhida pelo usuário (linear ou binária)
            // tempo -> tempo de busca
            int resultado, opbusca;
            double tempo;

            // Solicita ao usuário o número que será procurado no vetor
            chave = lerInteiro("Digite o numero a ser buscado: ", INT_MIN, INT_MAX);

            // Pergunta qual tipo de busca o usuário deseja utilizar
            printf("\nDigite o tipo de busca desejado: \n");
            printf("\n- 1. Linear\n- 2. Binaria\n");
            opbusca = lerInteiro("\nEscolha: ", 1, 2);

            // Verifica qual tipo de busca foi escolhido
            if (opbusca == 1)
            {
                QueryPerformanceCounter(&inicio);

                // Chama a função de busca linear
                // vetor -> lista de números
                // chave -> valor a ser buscado
                // tamanho -> quantidade de elementos do vetor
                resultado = buscaLinear(vetor, chave, tamanho);

                QueryPerformanceCounter(&fim);

                // armazena que a busca escolhida foi utilizada
                busca[opbusca - 1] = 1;

                tempo = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart;
            }
            else if (opbusca == 2)
            {
                // verifica se o vetor esta ordenado, caso nao esteja solicita ordenacao
                if (verificaOrdenacao(ordenado, tamanho) != 1)
                {
                    printf("\nNecessario ordenar vetor para busca binaria");
                    break;
                }

                QueryPerformanceCounter(&inicio);

                // Chama a função de busca binária
                // inicio = 0 (primeira posição do vetor)
                // fim = tamanho - 1 (última posição do vetor)
                resultado = buscaBinaria(ordenado, chave, 0, tamanho - 1);

                QueryPerformanceCounter(&fim);

                tempo = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart;

                // armazena que a busca escolhida foi utilizada
                busca[opbusca - 1] = 1;
            }

            // Verifica se o valor foi encontrado
            if (resultado != -1)
            {
                // Se o resultado for diferente de -1,
                // significa que a chave foi encontrada
                printf("\nO elemento %d foi encontrado no indice %d | Tempo: %.9lf", chave, resultado, tempo);

                // primeiro fator autorizado para o relatorio
                algoritmoExecutado = 1;
            }
            else
            {
                // Se o resultado for -1,
                // significa que o valor não está no vetor
                printf("\nO elemento %d nao foi encontrado | Tempo: %.9lf", chave, tempo);

                // autoriza a funcionalidade 4 (log)
                algoritmoExecutado = 1;
            }
            break;

        case 3:

            // verificar se ja carregou algum arquivo
            if (arquivoCarregado == 0)
            {
                printf("Necessario carregar um arquivo para ordenar");
                break;
            }

            int opAlg = 0;
            int arqOrd = 0;

            // submenu para escolher algoritmo, exemplo de entrada: "2"
            printf("Arquivo selecionado: %s\n\nEscolha o algoritmo de ordenacao: \n\n", nome_arquivo);
            printf("- 1. BubbleSort\n- 2. InsertionSort\n- 3. SelectionSort\n");
            printf("- 4. MergeSort\n- 5. QuickSort\n- 6. EXTRA\n");
            opAlg = lerInteiro("\nEscolha: ", 1, 6);
            printf("\n");

            if (opAlg > 0 && opAlg < 7)
            {
                free(ordenado);
                ordenado = (int *)malloc(tamanho * sizeof(int));
                memcpy(ordenado, vetor, tamanho * sizeof(int));

                QueryPerformanceCounter(&inicio);

                if (opAlg == 1)
                    bubbleSort(ordenado, tamanho);
                else if (opAlg == 2)
                    insertionSort(ordenado, tamanho);
                else if (opAlg == 3)
                    selectionSort(ordenado, tamanho);
                else if (opAlg == 4)
                    mergeSort(ordenado, 0, tamanho - 1);
                else if (opAlg == 5)
                    quickSort(ordenado, 0, tamanho - 1);
                else if (opAlg == 6)
                {
                    introsort(ordenado, tamanho);
                }

                QueryPerformanceCounter(&fim);

                double tempo = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart;

                printf("Vetor ordenado! Tempo total: %.9lf\n", tempo);

                // armazena que o algoritmo escolhido foi utilizada
                sort[opAlg - 1] = 1;

                // autoriza a funcionalidade 4 (log)
                algoritmoExecutado = 1;

                // opcao para o usuario salvar o vetor ordenado em um novo arquivo
                printf("\nDeseja salvar o vetor ordenado em um novo arquivo?\n");
                printf("\n- 1. Sim\n- 2. Nao\n");
                arqOrd = lerInteiro("\nEscolha: ", 1, 2);

                if (arqOrd == 1 || arqOrd == 2)
                {
                    if (arqOrd == 1)
                    {
                        char nome_arqOrd[50]; // variavel para receber o nome deseja

                        printf("\nNome do arquivo: ");
                        limparBuffer(); // limpar buffer para fgets
                        fgets(nome_arqOrd, sizeof(nome_arqOrd), stdin);
                        nome_arqOrd[strcspn(nome_arqOrd, "\n")] = 0; // retirar "/n" no final do fgets

                        if (criarArquivo(nome_arqOrd, tamanho, ordenado) == 0)
                        {
                            printf("\nArquivo criado com sucesso");
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    printf("valor invalido");
                }
            }
            else
            {
                printf("valor invalido");
            }

            break;

        case 4:

            // verificar se ja rodou algum algoritmo
            if (algoritmoExecutado == 0)
            {
                printf("Nenhum algoritmo foi executado ainda. Execute uma busca ou ordenacao primeiro.\n");
                break;
            }

            // Abertura/criacao do arquivo para o relatório
            FILE *log;
            log = fopen("log.txt", "w");

            // verificação se o arquivo foi aberto
            if (log == NULL)
            {
                printf("\nErro na criacao do relatorio\n");
                break;
            }

            // menu que vai aparecer no relatório
            fprintf(log, "===MEDIAS DE 100 EXECUCOES===\n");
            fprintf(log, "Nome do arquivo: %s\n", nome_arquivo);
            fprintf(log, "Tamanho do arquivo: %d\n", tamanho);

            // Buscas no relatorio
            fprintf(log, "Buscas: \n");
            for (int i = 0; i < 2; i++) // percorre os tipos de busca (linear e binaria)
            {
                if (busca[i] == 1 && i == 0) // verifica se é busca linear e se ela foi utilizada
                {
                    double soma = 0;              // variavel para armazenar as somas dos tempos de execução das 100 buscas
                    for (int j = 0; j < 100; j++) // executa 100 vzs a busca
                    {
                        QueryPerformanceCounter(&inicio); // marca o inicio do tempo de execução
                        buscaLinear(vetor, chave, tamanho);
                        QueryPerformanceCounter(&fim);                                                 // marca o fim do tempo de execução
                        double tempo = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart; // cálculo do tempo de execução da busca
                        soma += tempo;                                                                 // soma dos tempos
                    }
                    double media = soma / 100;                 // media dos tempos
                    fprintf(log, "Linear: %.9lf ms\n", media); // printa no relatorio o tempo de execução gasto nas buscas
                }
                else if (busca[i] == 1 && i == 1) // verifica se é busca binaria e se ela foi utilizada
                {
                    double soma = 0;              // variavel para armazenar as somas dos tempos de execução das 100 buscas
                    for (int j = 0; j < 100; j++) // executa 100 vzs a busca
                    {
                        QueryPerformanceCounter(&inicio); // marca o inicio do tempo de execução
                        buscaBinaria(ordenado, chave, 0, tamanho - 1);
                        QueryPerformanceCounter(&fim);                                                 // marca o fim do tempo de execução
                        double tempo = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart; // cálculo do tempo de execução da busca
                        soma += tempo;                                                                 // soma dos tempos
                    }
                    double media = soma / 100;                  // media dos tempos
                    fprintf(log, "Binaria: %.9lf ms\n", media); // printa no relatorio o tempo de execução gasto nas buscas
                }
            }

            fprintf(log, "Ordenacoes: \n");

            for (int i = 0; i < 6; i++) // percorre os tipos de sorts
            {
                if (sort[i] == 1)
                {                    // Só processa se foi usado
                    double soma = 0; // variavel para armazenar as somas dos tempos de execução das 100 ordenações

                    for (int j = 0; j < 100; j++) // executa 100 vzs o sort
                    {
                        // copia do vetor original ainda não ordenado para que possa ordena-lo sem mecher no vetor original
                        int *copia = (int *)malloc(tamanho * sizeof(int));
                        memcpy(copia, vetor, tamanho * sizeof(int));

                        QueryPerformanceCounter(&inicio); // marca o inicio do tempo de execução
                        // seleciona qual o sort a ser executado
                        switch (i + 1)
                        {
                        case 1:
                            bubbleSort(copia, tamanho);
                            break;
                        case 2:
                            insertionSort(copia, tamanho);
                            break;
                        case 3:
                            selectionSort(copia, tamanho);
                            break;
                        case 4:
                            mergeSort(copia, 0, tamanho - 1);
                            break;
                        case 5:
                            quickSort(copia, 0, tamanho - 1);
                            break;
                        case 6:
                            introsort(copia, tamanho);
                            break;
                        }
                        QueryPerformanceCounter(&fim); // marca o fim do tempo de execução

                        double tempo = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart; // calculo do tempo da ordenação
                        soma += tempo;                                                                 // soma dos tempos
                        free(copia);                                                                   // libera a memoria alocada
                    }

                    double media = soma / 100; // calculo da media dos tempos

                    // Print no arquivo com nome do sort
                    switch (i + 1)
                    {
                    case 1:
                        fprintf(log, "Bubble Sort: %.9lf ms\n", media);
                        break;
                    case 2:
                        fprintf(log, "Insertion Sort: %.9lf ms\n", media);
                        break;
                    case 3:
                        fprintf(log, "Selection Sort: %.9lf ms\n", media);
                        break;
                    case 4:
                        fprintf(log, "Merge Sort: %.9lf ms\n", media);
                        break;
                    case 5:
                        fprintf(log, "Quick Sort: %.9lf ms\n", media);
                        break;
                    case 6:
                        fprintf(log, "IntroSort (EXTRA): %.9lf ms\n", media);
                        break;
                    }
                }
            }
            fclose(log); // fecha o arquivo do relatório

            break;

        case 5:
            if (vetor != NULL)
                free(vetor);
            if (ordenado != NULL)
                free(ordenado);
            printf("Encerrado\n");

            break;

        default:

            printf("opcao invalida");

            break;
        }
    } while (opc != 5); // loop para o menu, se o usuario escolher a opcao 5, o programa ira sair

    return 0;
}
