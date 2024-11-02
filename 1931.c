#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXC 10004
#define MAXV 50000

typedef struct {
    int cidade, custo;
} Aresta;

typedef struct {
    Aresta *arestas;
    int tamanho;
    int capacidade;
} ListaAdj;

ListaAdj *grafo;
int dist[MAXC][2];


void adicionarAresta(int u, int v, int custo) {
    if (grafo[u].tamanho == grafo[u].capacidade) {
        grafo[u].capacidade *= 2;
        grafo[u].arestas = realloc(grafo[u].arestas, grafo[u].capacidade * sizeof(Aresta));
    }
    grafo[u].arestas[grafo[u].tamanho].cidade = v;
    grafo[u].arestas[grafo[u].tamanho].custo = custo;
    grafo[u].tamanho++;
}

typedef struct {
    int cidade, paridade;
    int custo;
} ItemFila;

typedef struct {
    ItemFila *itens;
    int tamanho;
    int capacidade;
} FilaPrioridade;

void inicializarFila(FilaPrioridade *fila, int capacidade) {
    fila->itens = malloc(capacidade * sizeof(ItemFila));
    fila->tamanho = 0;
    fila->capacidade = capacidade;
}

void inserirFila(FilaPrioridade *fila, ItemFila item) {
    if (fila->tamanho == fila->capacidade) {
        fila->capacidade *= 2;
        fila->itens = realloc(fila->itens, fila->capacidade * sizeof(ItemFila));
    }
    fila->itens[fila->tamanho++] = item;

    int i = fila->tamanho - 1;
    while (i > 0) {
        int pai = (i - 1) / 2;
        if (fila->itens[i].custo >= fila->itens[pai].custo)
            break;
        ItemFila temp = fila->itens[i];
        fila->itens[i] = fila->itens[pai];
        fila->itens[pai] = temp;
        i = pai;
    }
}

ItemFila extrairMinimo(FilaPrioridade *fila) {
    ItemFila minItem = fila->itens[0];
    fila->itens[0] = fila->itens[--fila->tamanho];

    int i = 0;
    while (1) {
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;
        int menor = i;

        if (esq < fila->tamanho && fila->itens[esq].custo < fila->itens[menor].custo)
            menor = esq;
        if (dir < fila->tamanho && fila->itens[dir].custo < fila->itens[menor].custo)
            menor = dir;

        if (menor == i)
            break;

        ItemFila temp = fila->itens[i];
        fila->itens[i] = fila->itens[menor];
        fila->itens[menor] = temp;
        i = menor;
    }

    return minItem;
}

void dijkstra(int inicio, int fim, int C) {
    for (int i = 1; i <= C; i++) {
        dist[i][0] = dist[i][1] = INT_MAX;
    }
    dist[inicio][0] = 0;

    FilaPrioridade fila;
    inicializarFila(&fila, MAXC * 2);
    inserirFila(&fila, (ItemFila){inicio, 0, 0});

    while (fila.tamanho > 0) {
        ItemFila item = extrairMinimo(&fila);
        int u = item.cidade;
        int paridade = item.paridade;
        int custoAtual = item.custo;

        if (custoAtual > dist[u][paridade])
            continue;

        for (int i = 0; i < grafo[u].tamanho; i++) {
            int v = grafo[u].arestas[i].cidade;
            int custo = grafo[u].arestas[i].custo;
            int novaDist = custoAtual + custo;
            int novaParidade = 1 - paridade;

            if (novaDist < dist[v][novaParidade]) {
                dist[v][novaParidade] = novaDist;
                inserirFila(&fila, (ItemFila){v, novaParidade, novaDist});
            }
        }
    }

    free(fila.itens);

    if (dist[fim][0] == INT_MAX) {
        printf("-1\n");
    } else {
        printf("%d\n", dist[fim][0]);
    }
}


int main()
{
    int C, V;
    scanf("%d %d", &C, &V);

    grafo = malloc((C + 1) * sizeof(ListaAdj));
    for (int i = 1; i <= C; i++) {
        grafo[i].tamanho = 0;
        grafo[i].capacidade = 10;
        grafo[i].arestas = malloc(grafo[i].capacidade * sizeof(Aresta));
    }

    for (int i = 0; i < V; i++) {
        int C1, C2, G;
        scanf("%d %d %d", &C1, &C2, &G);
        adicionarAresta(C1, C2, G);
        adicionarAresta(C2, C1, G);
    }

    dijkstra(1, C, C);

    for (int i = 1; i <= C; i++) {
        free(grafo[i].arestas);
    }
    free(grafo);

    return 0;
}
