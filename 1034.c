#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        int blocos[N];
        for (int x = 0; x < N; x++) {
            scanf("%d", &blocos[x]);
        }

        int dp[M+1];
        dp[0] = 0;
        for (int x = 1; x <= M; x++) {
            dp[x] = M+1;
            for (int y = 0; y < N; y++) {
                if (blocos[y] <= x) {
                    int subproblema = dp[x - blocos[y]];
                    if (subproblema != M+1 && subproblema + 1 < dp[x]) {
                        dp[x] = subproblema + 1;
                    }
                }
            }
        }
        if (dp[M] == M+1) {
            printf("Impossivel\n");
        } else {
            printf("%d\n", dp[M]);
        }
    }
    return 0;
}
