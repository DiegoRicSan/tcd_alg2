Sistema de Busca e Ordenação em Arquivos

#Descrição

Este programa foi desenvolvido em linguagem C com o objetivo de trabalhar com algoritmos de ordenação e busca em arquivos de números inteiros.

O sistema permite carregar um arquivo com dados, ordenar esses números utilizando diferentes algoritmos e realizar buscas dentro do conjunto de dados. Além disso, o programa mede o **tempo de execução das operações**, permitindo comparar o desempenho entre os algoritmos.

Os tempos são medidos utilizando funções de alta precisão do sistema, o que permite observar diferenças de desempenho entre os métodos de ordenação e busca.

#Funcionalidades do programa

O programa possui um menu com algumas opções principais:

1. Carregar arquivo de dados

Permite carregar um arquivo `.txt` contendo números inteiros.
Esses números são armazenados em um vetor que será utilizado nas operações de busca e ordenação.

2. Buscar elemento

Permite procurar um número dentro do vetor utilizando dois tipos de busca:

* Busca Linear
* Busca Binária (necessita que os dados estejam ordenados)

O programa também mede o tempo que a busca leva para ser executada.

3. Ordenar dados

Permite ordenar os números utilizando diferentes algoritmos de ordenação, como:

* Bubble Sort
* Insertion Sort
* Selection Sort
* Merge Sort
* Quick Sort
* IntroSort (implementação extra)

Após a execução, o tempo de execução do algoritmo é exibido.

4. Gerar relatório

O programa também pode gerar um relatório com as médias de tempo das execuções realizadas.
Esse relatório é salvo automaticamente em um arquivo separado.

5. Sair

Encerra a execução do programa.

#Compilação

Para compilar o programa utilizando GCC:

gcc main.c funcoes.c -o programa

#Execução

Após compilar, o programa pode ser executado com:

programa.exe

ou

./programa

#Arquivos do projeto

O projeto é composto pelos seguintes arquivos principais:

* `main.c` -> arquivo principal do programa
* `funcoes.c` -> implementação das funções de busca e ordenação
* `funcoes.h` -> declaração das funções utilizadas
* arquivos `.txt` com os dados de teste

#Observação

Para utilizar busca binária, os dados precisam estar previamente ordenados.

