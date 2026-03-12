# Sistema de Busca e Ordenação

## Descrição do programa

Este programa foi desenvolvido em linguagem **C** com o objetivo de testar e comparar o desempenho de diferentes **algoritmos de ordenação e busca**.

O sistema permite carregar arquivos contendo números inteiros, realizar ordenações utilizando diferentes algoritmos e executar buscas dentro do vetor de dados. Durante a execução, o programa também mede o **tempo de execução das operações**, permitindo analisar o desempenho de cada algoritmo.

Os testes são realizados executando os algoritmos várias vezes e calculando a média dos tempos obtidos.

---

## Funcionalidades

O programa possui um menu com as seguintes opções:

1. **Carregar arquivo de dados**
   Permite carregar um arquivo `.txt` contendo números inteiros para um vetor.

2. **Buscar elemento**
   Permite procurar um valor no vetor utilizando:

   * Busca Linear
   * Busca Binária

3. **Ordenar dados**
   Permite ordenar os valores utilizando diferentes algoritmos de ordenação, como:

   * Bubble Sort
   * Insertion Sort
   * Selection Sort
   * Merge Sort
   * Quick Sort
   * IntroSort (extra)

4. **Gerar relatório**
   O programa pode gerar um relatório contendo os tempos médios de execução dos algoritmos testados.

5. **Sair**
   Encerra a execução do programa.

---

## Compilação

Para compilar o programa utilizando **linha de comando**, utilize o compilador GCC.

No terminal ou prompt de comando, execute:

```bash
gcc main.c funcoes.c -o programa
```

Esse comando compila os arquivos do projeto e gera o executável chamado **programa**.

---

## Execução

Após a compilação, o programa pode ser executado com o seguinte comando:

No Windows:

```bash
programa.exe
```

No Linux:

```bash
./programa
```

---

## Arquivos do projeto

O projeto é composto pelos seguintes arquivos:

* `main.c` – arquivo principal do programa
* `funcoes.c` – implementação das funções de ordenação e busca
* `funcoes.h` – declaração das funções utilizadas
* arquivos `.txt` contendo os dados utilizados nos testes

---

## Observação

Para utilizar a **busca binária**, os dados precisam estar previamente ordenados.
