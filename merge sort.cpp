#include <iostream>   // biblioteca de entrada e saída (cout, endl)
using namespace std;  // evita escrever std:: antes de cout e endl

int comparacoes = 0;    // contador global: quantas vezes dois elementos foram comparados
int trocas = 0;         // contador global: o Merge Sort não troca elementos de lugar (fica sempre 0)
int movimentacoes = 0;  // contador global: quantos elementos foram copiados para o vetor auxiliar
int aux[100];           // vetor auxiliar usado para juntar (intercalar) as duas metades

void imprimir(int v[], int n) {      // função que mostra o vetor na tela
    for (int i = 0; i < n; i++) {    // percorre todas as posições do vetor
        cout << v[i] << " ";         // imprime o valor da posição i
    }                                // fim do for
    cout << endl;                    // pula uma linha depois de imprimir tudo
}                                    // fim da função imprimir

void intercalar(int v[], int ini, int meio, int fim) {   // junta v[ini..meio] com v[meio+1..fim]
    int i = ini;                                         // i percorre a metade esquerda
    int j = meio + 1;                                    // j percorre a metade direita
    int k = ini;                                         // k é a posição de escrita no vetor auxiliar
    while (i <= meio && j <= fim) {                      // enquanto as duas metades ainda têm elementos
        comparacoes++;                                   // conta uma comparação (v[i] com v[j])
        if (v[i] <= v[j]) {                              // se o da esquerda é menor ou igual
            aux[k] = v[i];                               // copia o da esquerda para o auxiliar
            i++;                                         // avança na metade esquerda
        } else {                                         // senão, o da direita é menor
            aux[k] = v[j];                               // copia o da direita para o auxiliar
            j++;                                         // avança na metade direita
        }                                                // fim do if/else
        k++;                                             // avança a posição de escrita
        movimentacoes++;                                 // conta uma cópia para o auxiliar
    }                                                    // fim do while
    while (i <= meio) {                                  // sobrou algo na metade esquerda?
        aux[k] = v[i];                                   // copia o que sobrou da esquerda
        i++;                                             // avança na metade esquerda
        k++;                                             // avança a posição de escrita
        movimentacoes++;                                 // conta uma cópia para o auxiliar
    }                                                    // fim do while
    while (j <= fim) {                                   // sobrou algo na metade direita?
        aux[k] = v[j];                                   // copia o que sobrou da direita
        j++;                                             // avança na metade direita
        k++;                                             // avança a posição de escrita
        movimentacoes++;                                 // conta uma cópia para o auxiliar
    }                                                    // fim do while
    for (k = ini; k <= fim; k++) {                       // devolve o trecho ordenado para o vetor original
        v[k] = aux[k];                                   // copia de aux para v
    }                                                    // fim do for
}                                                        // fim da função intercalar

void mergeSort(int v[], int ini, int fim, int n) {       // ordena v[ini..fim] (n só serve para imprimir)
    if (ini < fim) {                                     // só divide se tiver mais de 1 elemento
        int meio = (ini + fim) / 2;                      // calcula o meio do trecho
        mergeSort(v, ini, meio, n);                      // ordena a metade esquerda (recursão)
        mergeSort(v, meio + 1, fim, n);                  // ordena a metade direita (recursão)
        intercalar(v, ini, meio, fim);                   // junta as duas metades já ordenadas
        cout << "Apos intercalar [" << ini << ".." << fim << "]: "; // mostra o trecho intercalado
        imprimir(v, n);                                  // mostra o vetor completo
    }                                                    // fim do if
}                                                        // fim da função mergeSort

int main() {                          // função principal
    int v[] = {7, 3, 5, 2, 9, 1};     // vetor de entrada do teste de mesa
    int n = 6;                        // quantidade de elementos do vetor

    cout << "Vetor original: ";       // texto antes do vetor original
    imprimir(v, n);                   // mostra o vetor antes de ordenar

    mergeSort(v, 0, n - 1, n);        // chama o Merge Sort para o vetor inteiro

    cout << "Vetor ordenado: ";       // texto antes do vetor ordenado
    imprimir(v, n);                   // mostra o vetor depois de ordenar
    cout << "Comparacoes: " << comparacoes << endl;       // mostra o total de comparações
    cout << "Trocas: " << trocas << endl;                 // mostra o total de trocas (sempre 0)
    cout << "Movimentacoes: " << movimentacoes << endl;   // mostra o total de cópias para o auxiliar
    return 0;                         // indica que o programa terminou sem erro
}                                     // fim da main
