#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// 동남서북
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int type[8][4] = {{0,}, {1,1,1,1}, {0,1,0,1}, {1,0,1,0}, {1,0,0,1}, {1,1,0,0}, {0,1,1,0}, {0,0,1,1}}; 
int N, M, R, C, L;
int map[51][51];

int bfs(int y, int x) {
    int check[51][51] = {0};
    int cnt = 0;
    queue<pair<int,int>> q;
    q.push({y, x});
    check[y][x] = 1;

    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        // printf("%d %d %d\n", y, x, check[y][x]);
        cnt++;

        if (check[y][x] == L) continue;

        int d = map[y][x];
        for (int i=0; i<4; i++) {
            if (!type[d][i]) continue;
            
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny<0 || nx<0 || ny>=N || nx>=M || check[ny][nx]) continue;
            if (!map[ny][nx]) continue;

            int nd = map[ny][nx];
            int rd = (i+2)%4;
            if (!type[nd][rd]) continue;

            q.push({ny, nx});
            check[ny][nx] = check[y][x]+1;
        }
    }
    return cnt;
}

int main(void) {
    int T;
    scanf("%d", &T);

    for (int tc=1; tc<=T; tc++) {
        scanf("%d%d%d%d%d", &N, &M, &R, &C, &L);
        memset(map, 0, sizeof(map));

        for (int i=0; i<N; i++) {  // R
            for (int j=0; j<M; j++) {  //C
                scanf("%d", &map[i][j]);    
            }
        }

        int res = bfs(R, C);
        printf("#%d %d\n", tc, res);
    }
    return 0;
}