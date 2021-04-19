// 1949. [모의 SW 역량테스트] 등산로 조성

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
int map[9][9];
int visit[9][9];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int max_cnt;
void simulation(int y, int x, int h, int cnt, int kk) {
    for (int i=0; i<4; i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];

        if (ny<0 || nx<0 || ny>=n || nx>=n || visit[ny][nx]) continue;

        if (map[ny][nx] >= h && kk>0) {
            int diff = abs(map[ny][nx] - h)+1;
            if (diff <= k) {
                visit[ny][nx] = 1;
                simulation(ny, nx, map[ny][nx]-diff, cnt+1, kk-1);
                visit[ny][nx] = 0;
            }
        }

        if (map[ny][nx] < h) {
            visit[ny][nx] = 1;
            simulation(ny, nx, map[ny][nx], cnt+1, kk);
            visit[ny][nx] = 0;
        }
    }
    max_cnt = max(cnt, max_cnt);
}

int main(void) {
    int T;
    scanf("%d", &T);

    for (int tc=1; tc<=T; tc++) {
        scanf("%d%d", &n, &k);

        memset(map, 0, sizeof(map));
        memset(visit, 0, sizeof(visit));
        int max_bong = 0;
        max_cnt = 0;
        
        for (int i=0; i<n; i++) 
            for (int j=0; j<n; j++) {
                scanf("%d", &map[i][j]);
                max_bong = max(max_bong, map[i][j]);
            }
                
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (map[i][j]== max_bong) {
                    visit[i][j] = 1;
                    simulation(i, j, map[i][j], 1, 1);
                    visit[i][j] = 0;
                }
            }
        }

        printf("#%d %d\n", tc, max_cnt);
    }
    return 0;
}