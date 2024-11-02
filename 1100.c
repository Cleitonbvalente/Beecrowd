#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 8

typedef struct {
    int linha;
    int coluna;
} Vertice;

const int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};

int ehValido(int linha, int coluna) {
    return (linha >= 0 && linha < MAX && coluna >= 0 && coluna < MAX);
}

int movimentosCavalo(Vertice inicio, Vertice destino) {
    int dist[MAX][MAX];
    memset(dist, -1, sizeof(dist));

    dist[inicio.linha][inicio.coluna] = 0;

    Vertice fila[MAX * MAX];
    int frente = 0, tras = 0;
    fila[tras++] = inicio;

    while (frente < tras) {
        Vertice atual = fila[frente++];
        for (int i = 0; i < 8; ++i) {
            int novaLinha = atual.linha + dr[i];
            int novaColuna = atual.coluna + dc[i];
            if (ehValido(novaLinha, novaColuna) && dist[novaLinha][novaColuna] == -1) {
                dist[novaLinha][novaColuna] = dist[atual.linha][atual.coluna] + 1;
                fila[tras++] = (Vertice){novaLinha, novaColuna};
            }
        }
    }

    return dist[destino.linha][destino.coluna];
}

int main()
{

    char quadrado1[3], quadrado2[3];
    while (scanf("%s %s", quadrado1, quadrado2) != EOF) {
        Vertice inicio = {(quadrado1[1] - '1'), (quadrado1[0] - 'a')};
        Vertice destino = {(quadrado2[1] - '1'), (quadrado2[0] - 'a')};
        int movimentos = movimentosCavalo(inicio, destino);
        printf("To get from %s to %s takes %d knight moves.\n", quadrado1, quadrado2, movimentos);
    }


    return 0;
}
