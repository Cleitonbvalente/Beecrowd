#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define INF INT_MAX


typedef struct {
    int *dados;
    int tamanho;
    int capacidade;
} Vetor;

int idade[505];
Vetor v[505];
int dist[505];
int n, m, q;
int s, d;
char c;

void vetor_inicializar(Vetor *v, int capacidade);

void vetor_adicionar(Vetor *v, int valor);

void vetor_limpar(Vetor *v);

void vetor_liberar(Vetor *v);


int main()
{
    for (int i = 0; i < 505; i++) {
        vetor_inicializar(&v[i], 10);
    }

    while (scanf("%d %d %d", &n, &m, &q) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &idade[i]);
        }

        for (int i = 0; i < n; i++) {
            vetor_limpar(&v[i]);
        }

        for (int i = 0; i < m; i++) {
            scanf("%d %d", &s, &d);
            --s; --d;
            vetor_adicionar(&v[d], s);
        }

        for (int i = 0; i < q; i++) {
            getchar();
            scanf("%c %d", &c, &s);
            --s;

            if (c == 'P') {
                int fila[505], frente = 0, tras = 0;
                for (int i = 0; i < n; i++) dist[i] = INF;
                dist[s] = 0;
                fila[tras++] = s;
                int mn = INF;

                while (frente < tras) {
                    int u = fila[frente++];
                    for (int j = 0; j < v[u].tamanho; j++) {
                        int aux = v[u].dados[j];
                        if (dist[aux] > dist[u] + 1) {
                            dist[aux] = dist[u] + 1;
                            if (idade[aux] < mn) mn = idade[aux];
                            fila[tras++] = aux;
                        }
                    }
                }
                if (mn == INF) printf("*\n");
                else printf("%d\n", mn);
            } else {
                scanf("%d", &d);
                --d;

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < v[i].tamanho; j++) {
                        if (v[i].dados[j] == s)
                            v[i].dados[j] = d;
                        else if (v[i].dados[j] == d)
                            v[i].dados[j] = s;
                    }
                }
                Vetor aux = v[s];
                v[s] = v[d];
                v[d] = aux;
            }
        }
    }

    for (int i = 0; i < 505; i++) {
        vetor_liberar(&v[i]);
    }

    return 0;
}


void vetor_inicializar(Vetor *v, int capacidade) {
    v->dados = (int *)malloc(capacidade * sizeof(int));
    v->tamanho = 0;
    v->capacidade = capacidade;
}

void vetor_adicionar(Vetor *v, int valor) {
    if (v->tamanho == v->capacidade) {
        v->capacidade *= 2;
        v->dados = (int *)realloc(v->dados, v->capacidade * sizeof(int));
    }
    v->dados[v->tamanho++] = valor;
}

void vetor_limpar(Vetor *v) {
    v->tamanho = 0;
}

void vetor_liberar(Vetor *v) {
    free(v->dados);
}

