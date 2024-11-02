#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char grade[1040][1040];
int stack[1040 * 1040][2];

void dfs_iterativa(int x, int y);


int main()
{
    int n, m, cont = 0;
    scanf("%d %d", &n, &m);
    memset(grade, '0', sizeof(grade));
    for (int i = 1; i <= n; i++)
        scanf("%s", &grade[i][1]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grade[i][j] == '.') {
                dfs_iterativa(i, j);
                cont++;
            }
        }
    }
    printf("%d\n", cont);

    return 0;
}


void dfs_iterativa(int x, int y) {
    int top = 0;
    stack[top][0] = x;
    stack[top][1] = y;
    top++;

    while (top > 0) {
        top--;
        int cx = stack[top][0];
        int cy = stack[top][1];

        if (grade[cx][cy] == 'o') continue;

        grade[cx][cy] = 'o';

        if (grade[cx + 1][cy] == '.') {
            stack[top][0] = cx + 1;
            stack[top][1] = cy;
            top++;
        }
        if (grade[cx - 1][cy] == '.') {
            stack[top][0] = cx - 1;
            stack[top][1] = cy;
            top++;
        }
        if (grade[cx][cy + 1] == '.') {
            stack[top][0] = cx;
            stack[top][1] = cy + 1;
            top++;
        }
        if (grade[cx][cy - 1] == '.') {
            stack[top][0] = cx;
            stack[top][1] = cy - 1;
            top++;
        }
    }
}

