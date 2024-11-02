#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>


#define n 500

typedef struct {
    int itens[n];
    int frente;
    int tras;
} Fila;

void inicializarFila(Fila *f);

bool estaVazia(Fila *f);

void enfileira(Fila *f, int valor);

int desenfileira(Fila *f);

bool bfs(int s, int t, int pai[], int rg[n][n]);

int fordFulkerson(int g[n][n], int s, int t);


int main()
{
    int grafo[n][n];
    int N, M, ct, soc;
    char tamanhos[6][4] = {"XXL", "XL", "L", "M", "S", "XS"};
    int mym[6] = {1, 2, 3, 4, 5, 6};

    scanf("%d", &ct);

    while (ct--) {
        scanf("%d %d", &N, &M);
        memset(grafo, 0, sizeof(grafo));
        soc = N / 6;

        for (int i = 1; i <= 6; ++i) {
            grafo[0][i] = soc;
        }

        for (int i = 1; i <= M; ++i) {
            char a[4], b[4];
            scanf("%s %s", a, b);

            int a_indice = -1, b_indice = -1;
            for (int j = 0; j < 6; ++j) {
                if (strcmp(a, tamanhos[j]) == 0) a_indice = mym[j];
                if (strcmp(b, tamanhos[j]) == 0) b_indice = mym[j];
            }

            grafo[a_indice][6 + i] = 1;
            grafo[6 + i][a_indice] = 1;
            grafo[6 + i][b_indice] = 1;
            grafo[b_indice][6 + i] = 1;
            grafo[6 + i][M + 7] = 1;
            grafo[M + 7][6 + i] = 1;
        }
        int ans = fordFulkerson(grafo, 0, M + 7);
        if (ans == M)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}


void inicializaFila(Fila *f) {
    f->frente = -1;
    f->tras = -1;
}

bool estaVazia(Fila *f) {
    return f->frente == -1;
}

void enfileira(Fila *f, int valor) {
    if (f->tras == n - 1)
        return;
    if (f->frente == -1)
        f->frente = 0;
    f->tras++;
    f->itens[f->tras] = valor;
}

int desenfileira(Fila *f) {
    int item;
    if (estaVazia(f)) {
        return -1;
    } else {
        item = f->itens[f->frente];
        f->frente++;
        if (f->frente > f->tras) {
            f->frente = f->tras = -1;
        }
        return item;
    }
}

bool bfs(int s, int t, int pai[], int rg[n][n]) {
    bool vis[n];
    memset(vis, 0, sizeof(vis));
    Fila f;
    inicializaFila(&f);
    enfileira(&f, s);
    vis[s] = true;
    pai[s] = -1;
    while (!estaVazia(&f)) {
        int x = desenfileira(&f);
        for (int i = 0; i < n; ++i) {
            if (!vis[i] && rg[x][i] > 0) {
                enfileira(&f, i);
                pai[i] = x;
                vis[i] = true;
            }
        }
    }
    return (vis[t] == true);
}

int fordFulkerson(int g[n][n], int s, int t) {
    int rg[n][n];
    int x;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            rg[i][j] = g[i][j];
    int pai[n];
    int fluxo_maximo = 0;
    while (bfs(s, t, pai, rg)) {
        int fluxo_caminho = INT_MAX;
        for (int i = t; i != s; i = pai[i]) {
            x = pai[i];
            fluxo_caminho = (fluxo_caminho < rg[x][i]) ? fluxo_caminho : rg[x][i];
        }
        for (int i = t; i != s; i = pai[i]) {
            x = pai[i];
            rg[x][i] -= fluxo_caminho;
            rg[i][x] += fluxo_caminho;
        }
        fluxo_maximo += fluxo_caminho;
    }
    return fluxo_maximo;
}
