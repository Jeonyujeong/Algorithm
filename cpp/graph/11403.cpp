#include <iostream>
#include <cstring>
using namespace std;

int n;
int graph[101][101];
int visit[101];
void dfs(int num) {
    for (int i=0; i<n; i++) {
        if (graph[num][i] == 1 && !visit[i]) {
            visit[i] = 1;
            dfs(i);
        }
    }
}

int main(void) {
    scanf("%d", &n);

    for (int i=0; i<n; i++) 
        for (int j=0; j<n; j++) 
            scanf("%d", &graph[i][j]);

    for (int i=0; i<n; i++) {
        memset(visit, 0, sizeof(visit));
        dfs(i);
        for (int i=0; i<n; i++) printf("%d ", visit[i]);
        printf("\n");
    }
}