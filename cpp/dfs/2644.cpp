#include <iostream>
#include <vector>
#include <algorithm>
#define N 101
using namespace std;

int n, m, a, b;
vector<int> v[N];
int visit[N] = {0};

void dfs(int cur, int cnt) {
    if (cur == b) {
        visit[cur] = cnt;
        return ;
    }

    for (int i=0; i<v[cur].size(); i++) {
        int next = v[cur][i];

        if (visit[next]) continue;
        else {
            visit[next] = cnt+1;
            dfs(next, cnt+1);
        }
    }
}

int main(void) {
    
    scanf("%d", &n);
    scanf("%d%d", &a, &b); // 계산해야하는 서로다른 두사람의 번호
    scanf("%d", &m);
    
    for (int i=0; i<m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(a, 0);
    int result = visit[b];
    if (visit[b] == 0) result = -1;

    printf("%d", result);
}