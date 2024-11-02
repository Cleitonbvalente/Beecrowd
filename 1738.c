#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define INF 12345690
#define MAXN 201
#define TAM_ALFABETO 26

int fw[MAXN][MAXN][TAM_ALFABETO];
int n;

void floydwarshall()
{
for (int k = 0; k < n; k++)
for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
for (int l = 0; l < TAM_ALFABETO; l++)
fw[i][j][l] = (fw[i][j][l] < fw[i][k][l] + fw[k][j][l]) ? fw[i][j][l] : fw[i][k][l] + fw[k][j][l];
}

int main()
{
int u, v;
int flag;
char s[101];

while (1)
{
if (scanf("%d", &n) != 1 || n == 0)
return 0;

for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
for (int k = 0; k < TAM_ALFABETO; k++)
fw[i][j][k] = INF;

while (1)
{
if (scanf("%d %d", &u, &v) != 2 || (u == 0 && v == 0))
break;
scanf("%s", s);
--u;
--v;
for (int i = 0; i < strlen(s); i++)
fw[u][v][s[i] - 'a'] = 1;
}

floydwarshall();

while (1)
{
if (scanf("%d %d", &u, &v) != 2 || (u == 0 && v == 0))
break;

--u;
--v;
flag = 0;
for (int i = 0; i < TAM_ALFABETO; i++)
{
if (fw[u][v][i] != INF)
{
printf("%c", (char)(i + 'a'));
flag = 1;
}
}
if (!flag)
printf("-");
printf("\n");
}
printf("\n");
}

return 0;
}
