#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Pessoa {
    int x, y;
};

struct Aresta {
    int u, v;
    double peso;
};

double distancia(struct Pessoa p1, struct Pessoa p2);

int comparar(const void* a, const void* b);

int encontrar(int pai[], int i);

void unir(int pai[], int u, int v);


int main()
{
    int C;
    scanf("%d", &C);

    while (C--) {
        int n;
        scanf("%d", &n);

        struct Pessoa pessoas[n];
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &pessoas[i].x, &pessoas[i].y);
        }

        int num_arestas = n * (n - 1) / 2;
        struct Aresta arestas[num_arestas];
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                arestas[k].u = i;
                arestas[k].v = j;
                arestas[k].peso = distancia(pessoas[i], pessoas[j]);
                k++;
            }
        }

        qsort(arestas, num_arestas, sizeof(struct Aresta), comparar);

        int pai[n];
        for (int i = 0; i < n; i++) {
            pai[i] = i;
        }

        double comprimentoTotal = 0.0;
        for (int i = 0; i < num_arestas; i++) {
            int u = arestas[i].u;
            int v = arestas[i].v;
            double peso = arestas[i].peso;

            if (encontrar(pai, u) != encontrar(pai, v)) {
                unir(pai, u, v);
                comprimentoTotal += peso;
            }
        }

        printf("%.2lf\n", comprimentoTotal/100); // Correção aqui
    }

    return 0;
}


double distancia(struct Pessoa p1, struct Pessoa p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int comparar(const void* a, const void* b) {
    return ((struct Aresta*)a)->peso > ((struct Aresta*)b)->peso;
}

int encontrar(int pai[], int i) {
    if (pai[i] == i)
        return i;
    return encontrar(pai, pai[i]);
}

void unir(int pai[], int u, int v) {
    int raiz_u = encontrar(pai, u);
    int raiz_v = encontrar(pai, v);
    pai[raiz_u] = raiz_v;
}
