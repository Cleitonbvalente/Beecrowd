#include <stdio.h>
#include <stdlib.h>
#define INF 999999


int main()
{
    int n, conexoes, perguntas, a, b, k, l;

    scanf("%d %d %d", &n, &conexoes, &perguntas);

    int matrizAdj[n+1][n+1];
    int i, j;
    for(i = 0; i < n+1; i++){
        for(j = 0; j < n+1; j++){
            matrizAdj[i][j] = INF;
        }
    }
    while(conexoes--){
        scanf("%d %d", &a, &b);
        matrizAdj[a][b] = 1;
        matrizAdj[b][a] = 1;
    }

    for(k = 0; k <= n; k++){
        for(i = 0; i <= n; i++){
            for(j = 0; j <= n; j++){
                if(matrizAdj[i][k] + matrizAdj[k][j] < matrizAdj[i][j])
                    matrizAdj[i][j] = matrizAdj[i][k] + matrizAdj[k][j];
            }
        }
    }
    while(perguntas--){
        scanf("%d %d", &k, &l);
        if(matrizAdj[k][l] == INF || matrizAdj[l][k] == INF) 
            printf("Deu ruim\n");
        else
            printf("Lets que lets\n");
    }

    return 0;
}

