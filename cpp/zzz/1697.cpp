#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

int main(void) {
    int n, k;

    scanf("%d %d", &n, &k);
    queue<pair<int, int>> q;
    int visit[MAX] = {0};

    q.push({0, n});

    while(!q.empty()) {
        int cnt = q.front().first;
        int x = q.front().second;
        q.pop();

        if (x == k) {
            printf("%d", cnt);
            break;
        }

        int next = x-1;
        if (next >= 0 && visit[next] == 0) {
            visit[next] = cnt;
            q.push({cnt+1, next});
        } 

        next = x+1;
        if (next < MAX && visit[next] == 0) {
            visit[next] = cnt;
            q.push({cnt+1, next});
        } 

        next = x*2;
        if (next < MAX && visit[next] == 0) {
            visit[next] = cnt;
            q.push({cnt+1, next});
        }
    }
}