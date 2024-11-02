#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dir[609][609], esq[609][609], cima[609][609], baixo[609][609];
bool visitado[609][609];
int N;

typedef struct {
    int x, y;
} Par;

Par fila[609 * 609];
int inicio, fim;

void bfs(int i, int j);


int main()
{
    int x, y, res;
    char c;
    while (scanf("%d", &N) != EOF) {
        if (N <= 0 || N > (609/2)) {
            printf("Valor de N fora do limite permitido.\n");
            continue;
        }
        for (int i = 1; i <= 2*N; i++) {
            for (int j = 1; j <= 2*N+1; j++) {
                dir[i][j] = (j < 2*N+1);
                esq[i][j] = (j > 1);
                cima[i][j] = (i > 1);
                baixo[i][j] = (i < 2*N);
                visitado[i][j] = false;
            }
        }
        for (int i = 1; i <= 2*N-1; i++) {
            for (int j = 1; j <= N; j++) {
                if (scanf(" %c", &c) != 1) {
                    printf("Erro na leitura do caractere.\n");
                    return 1;
                }
                x = i;
                if (i % 2 == 0) y = 2*j;
                else y = 2*j-1;
                dir[x][y] = dir[x+1][y] = esq[x][y+1] = esq[x+1][y+1] = (c == 'H');
                cima[x+1][y] = cima[x+1][y+1] = baixo[x][y] = baixo[x][y+1] = (c == 'V');
            }
        }
        res = -1;
        for (int i = 1; i <= 2*N; i++) {
            for (int j = 1; j <= 2*N+1; j++) {
                if (visitado[i][j]) continue;
                res++;
                bfs(i, j);
            }
        }
        printf("%d\n", res);
    }

    return 0;
}


void bfs(int i, int j) {
    inicio = fim = 0;
    fila[fim++] = (Par){i, j};
    visitado[i][j] = true;

    while (inicio < fim) {
        Par atual = fila[inicio++];
        int x = atual.x, y = atual.y;

        if (x > 1 && !visitado[x-1][y] && cima[x][y]) {
            fila[fim++] = (Par){x-1, y};
            visitado[x-1][y] = true;
        }
        if (x < 2*N && !visitado[x+1][y] && baixo[x][y]) {
            fila[fim++] = (Par){x+1, y};
            visitado[x+1][y] = true;
        }
        if (y > 1 && !visitado[x][y-1] && esq[x][y]) {
            fila[fim++] = (Par){x, y-1};
            visitado[x][y-1] = true;
        }
        if (y < 2*N+1 && !visitado[x][y+1] && dir[x][y]) {
            fila[fim++] = (Par){x, y+1};
            visitado[x][y+1] = true;
        }
    }
}

