#include <iostream>
#include <vector>
#define N 1000
using namespace std;
    
int n, m;

int visit[N] = {0}; 
vector<int> v[N];

void dfs(int u) {
    
    for (int i=0; i<v[u].size(); i++) {
        int next = v[u][i];
        if (visit[next]) continue;
        else {
            visit[next] = 1;
            dfs(next);
        }
    }
}

int main(void) {
    scanf("%d%d", &n, &m);

    for (int i=0; i<m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }

    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (!visit[i]) {
            cnt++;
            dfs(i);
        }
    }
    printf("%d", cnt);
}