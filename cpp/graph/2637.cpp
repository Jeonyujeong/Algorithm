#include <iostream>
#include <queue>
using namespace std;

int N, M; 
int node[101];
int edge[101][101];

void make(int n, int cnt) {
    if (node[n] != -1) node[n]+=cnt;
    else {
        for (int i=1; i<=N; i++) {
            if (edge[n][i] > 0) make(i, cnt*edge[n][i]);
        }
    }
}

int main(void) {
    scanf("%d%d", &N, &M);
    for (int i=0; i<M; i++) {
        int X, Y, K;
        scanf("%d%d%d", &X, &Y, &K);
        edge[X][Y] = K;
        node[X] = -1;
    }

    make(N,1);

    for (int i=1; i<=N; i++) {
        if (node[i] > 0) printf("%d %d\n", i, node[i]);
    }
}