#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {
    int valor;
    int distancia;
} Nodo;

int BFS(int A, int B);


int main()
{
    int n;
    scanf("%d", &n);

    while (n != 0) {
        int A, B;
        scanf("%d %d", &A, &B);

        if (A == B) {
            printf("0\n");
        } else {
            printf("%d\n", BFS(A, B));
        }

        n--;
    }

    return 0;
}


int BFS(int A, int B) {
    bool vis[11000] = {false};
    Nodo fila[11000];
    int inicio = 0, fim = 0;

    fila[fim++] = (Nodo){A, 0};
    vis[A] = true;

    while (inicio < fim) {
        int aqui = fila[inicio].valor;
        int d = fila[inicio].distancia;
        inicio++;

        int soma = aqui + 1;
        int reve = 0;
        int temp = aqui;
        while (temp > 0) {
            reve = reve * 10 + temp % 10;
            temp /= 10;
        }

        if (soma > 11000 || reve > 11000) continue;

        if (soma == B || reve == B) return d + 1;

        if (!vis[soma]) {
            vis[soma] = true;
            fila[fim++] = (Nodo){soma, d + 1};
        }

        if (!vis[reve]) {
            vis[reve] = true;
            fila[fim++] = (Nodo){reve, d + 1};
        }
    }

    return -1;
}
