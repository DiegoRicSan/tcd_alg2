#include <stdio.h>
#include <windows.h>
#include "funcoes.h"

int main()
{
    LARGE_INTEGER frequency;
    LARGE_INTEGER inicio,fim;
    double elapsedtime;
                
    
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&inicio);
        // =================================================================
        int x; // variavel para escolha do menu
        char nome_arquivo[30]; // variavel para ler o nome do arquivo
        do
        {
            printf("======= MENU ========\n\n"); // menu de escolhas do usuario

            printf("1. Carregar arquivo de dados\n2. Buscar elemento (linear ou binaria)\n3. Ordenar dados (Insertion, Bubble, Selection, Merge, Quick, EXTRA)\n4. Gerar relatorio (Log)\n5. Sair\n\n"); // opcoes do menu
            scanf("%d",&x); // leitura da escolha do usuario
            
            switch (x) // switch para escolha do que o usuario deseja fazer
            {
            case 1:
                
                printf("nome do arquivo: ");
                fgets(nome_arquivo, sizeof(nome_arquivo), stdin); // leitura do nome do arquivo desejado
                carregarArquivo(nome_arquivo, "r"); // funcao para carregar arquivo, no modo r (leitura caso exista)
                break;
            case 2:
                // Buscar elemento (linear ou binaria)
                break;
            case 3:
                // Ordenar dados (Insertion, Bubble, Selection, Merge, Quick, EXTRA)
                break;
            case 4:
                // Gerar relatorio (Log) 
                break;
            case 5:
                // Sair
                break; 
            default:
                break;
            }
        }  while(x != 5); // loop para o menu, se o usuario escolher a opcao 5, o programa ira sair
        // =================================================================    
    QueryPerformanceCounter(&fim);
    elapsedtime = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart;
    printf("Time: %.16lf ms\n", elapsedtime);

    return 0;
}