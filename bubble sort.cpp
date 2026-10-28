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

void bubbleSort(int v[], int n) {                 // recebe o vetor e a quantidade de elementos
    bool trocou;                                  // guarda se houve troca na passada atual
    for (int i = 0; i < n - 1; i++) {             // cada passada coloca o maior elemento no fim
        trocou = false;                           // começa a passada supondo que não vai trocar
        for (int j = 0; j < n - 1 - i; j++) {     // compara pares vizinhos (o fim já está ordenado)
            comparacoes++;                        // conta uma comparação (v[j] com v[j+1])
            if (v[j] > v[j + 1]) {                // se o da esquerda é maior que o da direita
                int aux = v[j];                   // guarda v[j] em uma variável auxiliar
                v[j] = v[j + 1];                  // move o menor para a posição j
                v[j + 1] = aux;                   // move o maior para a posição j+1
                trocas++;                         // conta uma troca
                trocou = true;                    // anota que houve troca nesta passada
            }                                     // fim do if
        }                                         // fim do for interno
        cout << "Apos passada " << i + 1 << ": "; // mostra o número da passada
        imprimir(v, n);                           // mostra o vetor depois da passada
        if (!trocou) {                            // se não trocou nada, o vetor já está ordenado
            break;                                // encerra antes de fazer passadas desnecessárias
        }                                         // fim do if
    }                                             // fim do for externo
}                                                 // fim da função bubbleSort

int main() {                          // função principal
    int v[] = {7, 3, 5, 2, 9, 1};     // vetor de entrada do teste de mesa
    int n = 6;                        // quantidade de elementos do vetor

    cout << "Vetor original: ";       // texto antes do vetor original
    imprimir(v, n);                   // mostra o vetor antes de ordenar

    bubbleSort(v, n);                 // chama o Bubble Sort

    cout << "Vetor ordenado: ";       // texto antes do vetor ordenado
    imprimir(v, n);                   // mostra o vetor depois de ordenar
    cout << "Comparacoes: " << comparacoes << endl;  // mostra o total de comparações
    cout << "Trocas: " << trocas << endl;            // mostra o total de trocas
    return 0;                         // indica que o programa terminou sem erro
}                                     // fim da main
