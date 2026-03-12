# Sistema de Busca e Ordenação

## Descrição do programa

Este programa foi desenvolvido em linguagem **C** com o objetivo de testar e comparar o desempenho de diferentes **algoritmos de ordenação e busca**.

O sistema permite carregar arquivos contendo números inteiros, realizar ordenações utilizando diferentes algoritmos e executar buscas dentro do vetor de dados. Durante a execução, o programa também mede o **tempo de execução das operações**, permitindo analisar o desempenho de cada algoritmo.

Os testes são realizados executando os algoritmos várias vezes e calculando a média dos tempos obtidos.

A escolha do algoritmo extra "IntroSort" foi feita por meio de uma pesquisa aprofundada sobre algoritmos de ordenação, juntando mais de um algoritmo sendo assim um algoritmo híbrido, e pelo fato dele ser um dos mais rápido dentre os pesquisados
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
gcc -O2 -o programa main.c funcoes.c -lm
```

A opção **-O2** ativa otimizações do compilador, o que melhora o desempenho do programa durante a execução dos algoritmos.

A opção **-lm** inclui a biblioteca matemática, utilizada em algumas funções como `log2`.

Também é possível utilizar **-O3**, que aplica otimizações mais agressivas, porém em alguns casos **-O2 apresenta maior estabilidade**.

---

## Execução

Após a compilação, o programa pode ser executado com o seguinte comando:

No Windows:

```bash
programa.exe
```

## Arquivos do projeto

O projeto é composto pelos seguintes arquivos:

* `main.c` – arquivo principal do programa
* `funcoes.c` – implementação das funções de ordenação e busca
* `funcoes.h` – declaração das funções utilizadas
* arquivos `.txt` contendo os dados utilizados nos testes

---

## Observação

Para utilizar a **busca binária**, os dados precisam estar previamente ordenados.
