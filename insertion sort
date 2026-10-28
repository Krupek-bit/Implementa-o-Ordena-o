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

void insertionSort(int v[], int n) {              // recebe o vetor e a quantidade de elementos
    for (int i = 1; i < n; i++) {                 // v[0..i-1] já está ordenado; vamos inserir v[i]
        int j = i;                                // j acompanha o elemento que está sendo inserido
        while (j > 0) {                           // enquanto não chegou ao início do vetor
            comparacoes++;                        // conta uma comparação (v[j-1] com v[j])
            if (v[j - 1] > v[j]) {                // se o da esquerda é maior, está fora de ordem
                int aux = v[j];                   // guarda v[j] em uma variável auxiliar
                v[j] = v[j - 1];                  // desloca o maior para a direita
                v[j - 1] = aux;                   // coloca o elemento inserido uma posição à esquerda
                trocas++;                         // conta uma troca
                j--;                              // o elemento andou uma posição para a esquerda
            } else {                              // se o da esquerda é menor ou igual
                break;                            // achou o lugar certo, para de andar
            }                                     // fim do if/else
        }                                         // fim do while
        cout << "Apos inserir v[" << i << "]: ";  // mostra qual posição foi inserida
        imprimir(v, n);                           // mostra o vetor depois da inserção
    }                                             // fim do for
}                                                 // fim da função insertionSort

int main() {                          // função principal
    int v[] = {7, 3, 5, 2, 9, 1};     // vetor de entrada do teste de mesa
    int n = 6;                        // quantidade de elementos do vetor

    cout << "Vetor original: ";       // texto antes do vetor original
    imprimir(v, n);                   // mostra o vetor antes de ordenar

    insertionSort(v, n);              // chama o Insertion Sort

    cout << "Vetor ordenado: ";       // texto antes do vetor ordenado
    imprimir(v, n);                   // mostra o vetor depois de ordenar
    cout << "Comparacoes: " << comparacoes << endl;  // mostra o total de comparações
    cout << "Trocas: " << trocas << endl;            // mostra o total de trocas
    return 0;                         // indica que o programa terminou sem erro
}                                     // fim da main
