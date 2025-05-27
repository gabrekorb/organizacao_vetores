#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 100

void unico_aleatorio(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i;
    }

    for (int i = tamanho - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
}

void bubble_sort(int vetor[], int tamanho, int crescente) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            int cond = crescente ? (vetor[j] > vetor[j + 1]) : (vetor[j] < vetor[j + 1]);
            if (cond) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

void copia_vetor(int origem[], int destino[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

void imprime_vetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void pausa() {
    printf("\nPressione ENTER para continuar...");
    getchar();
    getchar();
}

int main() {
    srand(time(NULL));
    int original[TAMANHO], vetorOrdenado[TAMANHO];
    int opcao;
    
    unico_aleatorio(original, TAMANHO);

    do {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        printf("============ MENU VETORES =============\n");
        printf("1. Exibir vetor aleatório\n");
        printf("2. Exibir vetor em ordem crescente\n");
        printf("3. Exibir vetor em ordem decrescente\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nVetor aleatório:\n");
                imprime_vetor(original, TAMANHO);
                pausa();
                break;
            case 2: {
                copia_vetor(original, vetorOrdenado, TAMANHO);
                clock_t inicio = clock();
                bubble_sort(vetorOrdenado, TAMANHO, 1);
                clock_t fim = clock();
                printf("\nVetor em ordem crescente:\n");
                imprime_vetor(vetorOrdenado, TAMANHO);
                printf("Tempo: %.4f segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
                pausa();
                break;
            }
            case 3: {
                copia_vetor(original, vetorOrdenado, TAMANHO);
                clock_t inicio = clock();
                bubble_sort(vetorOrdenado, TAMANHO, 0);
                clock_t fim = clock();
                printf("\nVetor em ordem decrescente:\n");
                imprime_vetor(vetorOrdenado, TAMANHO);
                printf("Tempo: %.4f segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
                pausa();
                break;
            }
            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
                pausa();
        }
    } while (opcao != 0);

    return 0;
}
