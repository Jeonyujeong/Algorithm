#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int N, M, C;
int map[10][10];
int max_profit(int y, int x) {
    int max_profit = 0;
    
    for (int i=0; i<(1<<M); i++) {
        int sum = 0;
        int profit = 0;

        for (int j=0; j<M; j++) {
            if (i & (1<<j)) {
                sum += map[y][x+j];
                profit += (map[y][x+j]*map[y][x+j]);
            }
        }
        if (sum <= C) 
            max_profit = max(max_profit, profit);
    }
    return max_profit;
}

int solve(int y, int x) {
    int check[10][10]={0};

    int cost_a = max_profit(y, x);
    for (int i=0; i<M; i++) check[y][x+i] = 1;

    int cost_b = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N-M+1; j++) {
            if (!check[i][j] && !check[i][j+M-1]) {
                cost_b = max(max_profit(i, j), cost_b);
            }
        }
    }

    return cost_a + cost_b;
}

int main(void) {
    int T;
    scanf("%d", &T);

    for (int tc=1; tc<=T; tc++) {        
        scanf("%d%d%d", &N, &M, &C);
        memset(map, 0, sizeof(map));

        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                scanf("%d", &map[i][j]);

        int res = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N-M+1; j++) {
                res = max(res, solve(i, j));
            }
        }

        printf("#%d %d\n", tc, res);
    }
}