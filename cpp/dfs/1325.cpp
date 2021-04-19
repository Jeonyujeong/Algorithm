#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define N 100001
using namespace std;

vector<int> v[N];
int bfs(int cur) {
    int visit[N] = {0};
    queue<int> q;

    q.push(cur);
    visit[cur] = 1;
    
    int cnt = 1;
    while(!q.empty()) {
        cur = q.front();
        q.pop();

        for (int i=0; i<v[cur].size(); i++) {
            int next = v[cur][i];

            if (visit[next]) continue;
            q.push(next);
            visit[next] = 1;
            cnt++;
        }
    }
    return cnt;
}

int main(void) {
    int n, m;

    scanf("%d%d", &n, &m);
    for (int i=0; i<m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        v[b].push_back(a);
    }

    int max_cnt = 0;
    int vcnt[N] = {0};
    vector<int> visit(n+1,0);
    for (int i=1; i<=n; i++) {
        vcnt[i] = bfs(i);
        max_cnt = max(vcnt[i], max_cnt);
        // printf("%d %d\n", i, vcnt[i]);
    }

    vector<int> result;
    for (int i=1; i<=n; i++)
        if (max_cnt == vcnt[i])
            result.push_back(i);
    
    sort(result.begin(), result.end());
    for (int i=0; i<result.size(); i++)
        printf("%d ", result[i]);
}