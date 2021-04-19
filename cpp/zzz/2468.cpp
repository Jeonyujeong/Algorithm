#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define N 101
using namespace std;

int n;
int map[N][N];
int hs[N];
int visit[N][N];
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
void bfs(int y, int x, int h) {
    queue<pair<int, int>> q;

    q.push({y, x});
    visit[y][x] = 1;
    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int ny = cy + dir[i][0];
            int nx = cx + dir[i][1];

            if (ny<0 || nx<0 || ny>=n || nx>=n) continue;
            if (visit[ny][nx] || map[ny][nx] <= h) continue;
            q.push({ny, nx});
            visit[ny][nx] = 1;
        }
    }
}

int main(void) {
    scanf("%d", &n);

    int maxH = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int h;
            scanf("%d", &h);
            map[i][j] = h;
            
            if (hs[h] == 0) {
                hs[h] = 1;
                maxH = max(h, maxH);
            }
        }
    }

    int result = 0;
    hs[0] = 1;
    for (int h=0; h<=maxH; h++) {
        if (!hs[h]) continue;

        memset(visit, 0, sizeof(visit));
        int cnt = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (visit[i][j] || map[i][j] <= h) continue;

                cnt++;
                bfs(i, j, h);
            }
        }
        // printf("%d %d\n", h, cnt);
        result = max(result, cnt);
    }
    printf("%d", result);
}