// 최소스패닝 트리 
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#define MAX 10001
using namespace std;

int visit[MAX];
vector<pair<int, int>> vs[MAX];
int main(void) {
    int v, e;
    scanf("%d %d", &v, &e);

    for (int i=0; i<e; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        vs[a].push_back({b, c});
        vs[b].push_back({a, c});
    }

    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});

    int sum = 0;
    while(!pq.empty()) {
        int w = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (visit[cur] > 0) continue;
        visit[cur] = 1;
        sum += w;

        for (int i=0; i<vs[cur].size(); i++) {
            int next = vs[cur][i].first;
            int nw = vs[cur][i].second;
            if (visit[next] == 0) pq.push({-nw, next});
        }
    }
    printf("%d", sum);
}