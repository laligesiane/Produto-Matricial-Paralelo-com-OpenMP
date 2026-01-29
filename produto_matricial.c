#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 4  // Define o tamanho da matriz (N x N)

int main() {
    int A[N][N], B[N][N], C[N][N];
    int i, j, k;

    // Inicializa o gerador de números aleatórios
    srand(0);

    // Preenche as matrizes A e B com valores aleatórios
    // Inicializa a matriz C com zero
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
            C[i][j] = 0;
        }
    }

    /*
     * Produto matricial paralelo utilizando OpenMP.
     * A diretiva parallel for divide o loop externo (linhas da matriz)
     * entre as threads disponíveis.
     */
    #pragma omp parallel for private(j, k) shared(A, B, C)
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Exibe a matriz resultante do produto
    printf("Matriz Resultante:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%4d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
