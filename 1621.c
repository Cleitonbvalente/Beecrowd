#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int primeiro;
    int segundo;
} ii;

typedef struct {
    ii data[510 * 510];
    int front;
    int rear;
} Queue;

ii ne[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

char grade[510][510];
int dist[510][510];
int x, y;

void initQueue(Queue *q);

int Empty(Queue *q);

void enqueue(Queue *q, ii value);

ii dequeue(Queue *q);


int main()
{
    int n, m, d;
    while (scanf("%d %d", &n, &m), n | m) {
        memset(grade, 0, sizeof(grade));
        memset(dist, -1, sizeof(dist));
        for (int i = 1; i <= n; i++)
            scanf("%s", &grade[i][1]);
        
        ii rj;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (grade[i][j] == '.') {
                    rj.primeiro = i;
                    rj.segundo = j;
                    break;
                }
            }
        }
        
        d = 0;
        Queue q;
        initQueue(&q);
        enqueue(&q, rj);
        dist[rj.primeiro][rj.segundo] = 0;
        while (!isEmpty(&q)) {
            ii current = dequeue(&q);
            int i = current.primeiro, j = current.segundo;
            for (int k = 0; k < 4; k++) {
                int ni = i + ne[k].primeiro;
                int nj = j + ne[k].segundo;
                if (grade[ni][nj] == '.' && dist[ni][nj] == -1) {
                    dist[ni][nj] = dist[i][j] + 1;
                    if (dist[ni][nj] > d) {
                        x = ni;
                        y = nj;
                        d = dist[ni][nj];
                    }
                    ii proximo = {ni, nj};
                    enqueue(&q, proximo);
                }
            }
        }
        
        memset(dist, -1, sizeof(dist));
        ii inicio = {x, y};
        enqueue(&q, inicio);
        dist[x][y] = 0;
        while (!isEmpty(&q)) {
            ii current = dequeue(&q);
            int i = current.primeiro, j = current.segundo;
            for (int k = 0; k < 4; k++) {
                int ni = i + ne[k].primeiro;
                int nj = j + ne[k].segundo;
                if (grade[ni][nj] == '.' && dist[ni][nj] == -1) {
                    dist[ni][nj] = dist[i][j] + 1;
                    if (dist[ni][nj] > d) {
                        x = ni;
                        y = nj;
                        d = dist[ni][nj];
                    }
                    ii proximo = {ni, nj};
                    enqueue(&q, proximo);
                }
            }
        }
        
        printf("%d\n", d);
    }

    return 0;
}


void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, ii value) {
    q->data[q->rear++] = value;
}

ii dequeue(Queue *q) {
    return q->data[q->front++];
}

