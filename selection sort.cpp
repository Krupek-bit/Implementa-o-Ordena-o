#include <iostream>   // biblioteca de entrada e saída (cout, endl)
using namespace std;  // evita escrever std:: antes de cout e endl

int comparacoes = 0;  // contador global: quantas vezes dois elementos foram comparados
int trocas = 0;       // contador global: quantas vezes dois elementos trocaram de lugar

void imprimir(int v[], int n) {      // função que mostra o vetor na tela
    for (int i = 0; i < n; i++) {    // percorre todas as posições do vetor
        cout << v[i] << " ";         // imprime o valor da posição i
    }                                // fim do for
    cout << endl;                    // pula uma linha depois de imprimir tudo
}                                    // fim da função imprimir

void selectionSort(int v[], int n) {              // recebe o vetor e a quantidade de elementos
    for (int i = 0; i < n - 1; i++) {             // i é a posição que vai receber o menor valor
        int menor = i;                            // supõe que o menor valor está na posição i
        for (int j = i + 1; j < n; j++) {         // procura o menor valor no restante do vetor
            comparacoes++;                        // conta uma comparação (v[j] com v[menor])
            if (v[j] < v[menor]) {                // se achou um valor menor que o menor atual
                menor = j;                        // atualiza a posição do menor valor
            }                                     // fim do if
        }                                         // fim do for interno
        if (menor != i) {                         // só troca se o menor não estiver já na posição i
            int aux = v[i];                       // guarda v[i] em uma variável auxiliar
            v[i] = v[menor];                      // coloca o menor valor na posição i
            v[menor] = aux;                       // coloca o valor antigo de v[i] onde estava o menor
            trocas++;                             // conta uma troca
        }                                         // fim do if
        cout << "Apos passo " << i + 1 << ": ";   // mostra o número do passo
        imprimir(v, n);                           // mostra o vetor depois do passo
    }                                             // fim do for externo
}                                                 // fim da função selectionSort

int main() {                          // função principal
    int v[] = {7, 3, 5, 2, 9, 1};     // vetor de entrada do teste de mesa
    int n = 6;                        // quantidade de elementos do vetor

    cout << "Vetor original: ";       // texto antes do vetor original
    imprimir(v, n);                   // mostra o vetor antes de ordenar

    selectionSort(v, n);              // chama o Selection Sort

    cout << "Vetor ordenado: ";       // texto antes do vetor ordenado
    imprimir(v, n);                   // mostra o vetor depois de ordenar
    cout << "Comparacoes: " << comparacoes << endl;  // mostra o total de comparações
    cout << "Trocas: " << trocas << endl;            // mostra o total de trocas
    return 0;                         // indica que o programa terminou sem erro
}                                     // fim da main
