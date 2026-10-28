
#include <iostream> // Biblioteca para entrada e saída
#include <vector>   // Biblioteca para usar vetores
#include <algorithm> // Biblioteca para a função swap
using namespace std;

// Mostra os elementos do vetor na tela
void mostrarVetor(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " "; // Imprime cada elemento
    }
    cout << endl; // Pula para a próxima linha
}

// Troca dois elementos e conta somente trocas reais
void trocar(vector<int>& v, int i, int j, int& trocas) {
    if (i != j) { // Verifica se são posições diferentes
        swap(v[i], v[j]); // Troca os elementos
        trocas++; // Conta a troca realizada
    }
}

// 1. BUBBLE SORT
void bubbleSort(vector<int>& v, int& comp, int& trocas) {
    int n = v.size(); // Guarda o tamanho do vetor

    for (int i = 0; i < n - 1; i++) { // Percorre as passagens
        for (int j = 0; j < n - 1 - i; j++) {
            comp++; // Conta a comparação entre elementos

            if (v[j] > v[j + 1]) { // Verifica se estão fora de ordem
                trocar(v, j, j + 1, trocas); // Troca os elementos
            }
        }
        cout << "Passagem " << i + 1 << ": ";
        mostrarVetor(v); // Mostra o vetor após cada passagem
    }
}

// 2. SELECTION SORT
void selectionSort(vector<int>& v, int& comp, int& trocas) {
    int n = v.size(); // Guarda o tamanho do vetor

    for (int i = 0; i < n - 1; i++) {
        int menor = i; // Considera o primeiro elemento como menor

        for (int j = i + 1; j < n; j++) {
            comp++; // Conta a comparação

            if (v[j] < v[menor]) { // Procura um elemento menor
                menor = j; // Guarda a posição do menor
            }
        }

        trocar(v, i, menor, trocas); // Coloca o menor na posição correta

        cout << "Passagem " << i + 1 << ": ";
        mostrarVetor(v); // Mostra o vetor após a passagem
    }
}

// 3. INSERTION SORT
void insertionSort(vector<int>& v, int& comp,
                   int& trocas, int& deslocamentos) {
    int n = v.size(); // Guarda o tamanho do vetor

    for (int i = 1; i < n; i++) {
        int chave = v[i]; // Guarda o elemento que será inserido
        int j = i - 1; // Começa pelo elemento anterior

        while (j >= 0) {
            comp++; // Conta a comparação entre elementos

            if (v[j] > chave) { // Verifica se precisa deslocar
                v[j + 1] = v[j]; // Move o elemento para a direita
                deslocamentos++; // Conta o deslocamento
                j--; // Volta uma posição
            } else {
                break; // Encerra quando encontra a posição correta
            }
        }

        v[j + 1] = chave; // Insere a chave na posição correta

        cout << "Passagem " << i << ": ";
        mostrarVetor(v); // Mostra o vetor após a passagem
    }

    // Neste algoritmo, deslocamentos não são contados como trocas.
    trocas = 0;
}

// 4. MERGE SORT
void merge(vector<int>& v, int inicio, int meio, int fim,
           int& comp) {
    vector<int> temp; // Cria um vetor auxiliar

    int i = inicio; // Posição inicial da primeira metade
    int j = meio + 1; // Posição inicial da segunda metade

    while (i <= meio && j <= fim) {
        comp++; // Conta a comparação entre as metades

        if (v[i] <= v[j]) { // Verifica qual elemento é menor
            temp.push_back(v[i]); // Copia o elemento da esquerda
            i++; // Avança na primeira metade
        } else {
            temp.push_back(v[j]); // Copia o elemento da direita
            j++; // Avança na segunda metade
        }
    }

    while (i <= meio) {
        temp.push_back(v[i]); // Copia os elementos restantes
        i++; // Avança na primeira metade
    }

    while (j <= fim) {
        temp.push_back(v[j]); // Copia os elementos restantes
        j++; // Avança na segunda metade
    }

    for (int k = 0; k < temp.size(); k++) {
        v[inicio + k] = temp[k]; // Devolve os valores ao vetor
    }
}

void mergeSort(vector<int>& v, int inicio, int fim, int& comp) {
    if (inicio < fim) { // Verifica se há mais de um elemento
        int meio = inicio + (fim - inicio) / 2; // Calcula o meio

        mergeSort(v, inicio, meio, comp); // Ordena a primeira metade
        mergeSort(v, meio + 1, fim, comp); // Ordena a segunda metade
        merge(v, inicio, meio, fim, comp); // Junta as duas metades
    }
}

// 5. QUICK SORT
int particionar(vector<int>& v, int inicio, int fim,
                int& comp, int& trocas) {
    int pivo = v[fim]; // Escolhe o último elemento como pivô
    int i = inicio - 1; // Marca a posição dos menores elementos

    for (int j = inicio; j < fim; j++) {
        comp++; // Conta a comparação com o pivô

        if (v[j] <= pivo) { // Verifica se o elemento deve ficar à esquerda
            i++; // Avança a posição dos menores
            trocar(v, i, j, trocas); // Coloca o elemento na posição correta
        }
    }

    trocar(v, i + 1, fim, trocas); // Posiciona o pivô
    return i + 1; // Retorna a posição definitiva do pivô
}

void quickSort(vector<int>& v, int inicio, int fim,
               int& comp, int& trocas) {
    if (inicio < fim) { // Verifica se há elementos para ordenar
        int pivo = particionar(v, inicio, fim, comp, trocas);

        quickSort(v, inicio, pivo - 1, comp, trocas);
        // Ordena os elementos antes do pivô

        quickSort(v, pivo + 1, fim, comp, trocas);
        // Ordena os elementos depois do pivô
    }
}

// FUNÇÃO PRINCIPAL
int main() {
    int opcao; // Guarda a opção escolhida
    int comp = 0; // Contador de comparações
    int trocas = 0; // Contador de trocas
    int deslocamentos = 0; // Contador de deslocamentos

    vector<int> original = {5, 1, 4, 2, 8};
    // Define o vetor de entrada utilizado nos testes

    cout << "ALGORITMOS DE ORDENACAO" << endl;
    cout << "1 - Bubble Sort" << endl;
    cout << "2 - Selection Sort" << endl;
    cout << "3 - Insertion Sort" << endl;
    cout << "4 - Merge Sort" << endl;
    cout << "5 - Quick Sort" << endl;
    cout << "Escolha o algoritmo: ";
    cin >> opcao; // Lê a opção digitada

    vector<int> v = original; // Cria uma cópia do vetor original

    cout << "\nVetor inicial: ";
    mostrarVetor(v); // Mostra a entrada

    cout << "\nPasso a passo:" << endl;

    switch (opcao) {
        case 1:
            bubbleSort(v, comp, trocas);
            break;

        case 2:
            selectionSort(v, comp, trocas);
            break;

        case 3:
            insertionSort(v, comp, trocas, deslocamentos);
            break;

        case 4:
            mergeSort(v, 0, v.size() - 1, comp);
            trocas = 0; // Merge não realiza trocas diretas
            cout << "Vetor após a ordenação: ";
            mostrarVetor(v);
            break;

        case 5:
            quickSort(v, 0, v.size() - 1, comp, trocas);
            cout << "Vetor após a ordenação: ";
            mostrarVetor(v);
            break;

        default:
            cout << "Opcao invalida!" << endl;
            return 0; // Encerra se a opção for inválida
    }

    cout << "\nVetor ordenado: ";
    mostrarVetor(v); // Mostra o resultado final

    cout << "Comparacoes: " << comp << endl;
    cout << "Trocas: " << trocas << endl;
    cout << "Deslocamentos: " << deslocamentos << endl;

    return 0; // Encerra o programa
}
