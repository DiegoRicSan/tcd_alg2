int carregarArquivo(char *nome_arquivo, int **vetor, int *total);
int buscaLinear (int *lista, int chave, int tam);
int buscaBinaria(int *vet, int chave, int inicio, int fim);
void bubbleSort(int vet[], int tam);
void insertionSort(int vet[], int tam);
void selectionSort(int vet[], int tam);
void mergeSort(int vet[], int inicio, int fim);
void merge(int vet[], int inicio, int meio, int fim);
void quickSort(int vet[], int inicio, int fim);
int particiona(int vet[], int inicio, int fim);
int verificaOrdenacao(int vetor[], int tamanho);
void limparBuffer();
int criarArquivo(char nome_arqOrd[], int tamanho, int vetor[]);
void introsort(int vet[], int tam);
void introsortAux(int vet[], int inicio, int fim, int depthlimit);
void heapSort(int vet[], int tam);
void criaHeap(int vet[], int tam, int i);
int lerInteiro(char *mensagem, int min, int max);
int medianaTres(int vet[], int a, int b, int c);


