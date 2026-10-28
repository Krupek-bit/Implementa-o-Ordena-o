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

int particionar(int v[], int ini, int fim) {      // separa menores e maiores que o pivô (esquema de Lomuto)
    int pivo = v[fim];                            // o pivô é o último elemento do trecho
    int i = ini - 1;                              // i marca o fim da região dos menores ou iguais ao pivô
    for (int j = ini; j < fim; j++) {             // j percorre o trecho (sem incluir o pivô)
        comparacoes++;                            // conta uma comparação (v[j] com o pivô)
        if (v[j] <= pivo) {                       // se v[j] pertence à região dos menores ou iguais
            i++;                                  // aumenta a região dos menores
            if (i != j) {                         // só troca se as posições forem diferentes
                int aux = v[i];                   // guarda v[i] em uma variável auxiliar
                v[i] = v[j];                      // traz o menor v[j] para a região dos menores
                v[j] = aux;                       // manda o antigo v[i] para a posição j
                trocas++;                         // conta uma troca
            }                                     // fim do if
        }                                         // fim do if
    }                                             // fim do for
    if (i + 1 != fim) {                           // se o pivô ainda não está na posição final
        int aux = v[i + 1];                       // guarda v[i+1] em uma variável auxiliar
        v[i + 1] = v[fim];                        // coloca o pivô logo depois dos menores
        v[fim] = aux;                             // manda o antigo v[i+1] para o fim
        trocas++;                                 // conta uma troca
    }                                             // fim do if
    return i + 1;                                 // devolve a posição final do pivô
}                                                 // fim da função particionar

void quickSort(int v[], int ini, int fim, int n) {    // ordena v[ini..fim] (n só serve para imprimir)
    if (ini < fim) {                                  // só continua se o trecho tiver mais de 1 elemento
        int p = particionar(v, ini, fim);             // particiona e recebe a posição do pivô
        cout << "Apos particionar [" << ini << ".." << fim << "], pivo na posicao " << p << ": "; // informa o trecho e o pivô
        imprimir(v, n);                               // mostra o vetor completo
        quickSort(v, ini, p - 1, n);                  // ordena os elementos antes do pivô
        quickSort(v, p + 1, fim, n);                  // ordena os elementos depois do pivô
    }                                                 // fim do if
}                                                     // fim da função quickSort

int main() {                          // função principal
    int v[] = {7, 3, 5, 2, 9, 1};     // vetor de entrada do teste de mesa
    int n = 6;                        // quantidade de elementos do vetor

    cout << "Vetor original: ";       // texto antes do vetor original
    imprimir(v, n);                   // mostra o vetor antes de ordenar

    quickSort(v, 0, n - 1, n);        // chama o Quick Sort para o vetor inteiro

    cout << "Vetor ordenado: ";       // texto antes do vetor ordenado
    imprimir(v, n);                   // mostra o vetor depois de ordenar
    cout << "Comparacoes: " << comparacoes << endl;  // mostra o total de comparações
    cout << "Trocas: " << trocas << endl;            // mostra o total de trocas
    return 0;                         // indica que o programa terminou sem erro
}                                     // fim da main
