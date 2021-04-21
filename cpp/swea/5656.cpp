// 5656. [모의 SW 역량테스트] 벽돌 깨기
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int n, w, h;
int block[20][20];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
queue<pair<int,int>> q;
int min_bk = 1e9;

void print() {
    printf("\n");
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            printf("%d ", block[i][j]);
        }printf("\n");
    }
}

void down() {
    for (int i=0; i<w; i++) {
        vector<int> b;

        for (int j=h-1; j>=0; j--) {
            if (block[j][i] > 0) 
                b.push_back(block[j][i]);
            block[j][i] = 0;
        }

        for (int j=0; j<b.size(); j++) {
            block[h-j-1][i] = b[j];
        }
    }   
}

void crush(int y, int x) {
    int visit[20][20] = {0};
    int num = block[y][x];
    block[y][x] = 0;
    visit[y][x] = 1;

    if (num == 1) {
        return;
    }

    for (int i=0; i<4; i++) {
        for (int j=0; j<num; j++) {
            int ny = y+ dy[i]*j;
            int nx = x+ dx[i]*j;

            if (ny<0 || nx<0 || ny>=h || nx>=w || !block[ny][nx] || visit[ny][nx]) continue;
            if (block[ny][nx] == 1) {
                block[ny][nx] = 0;
                continue;
            }
            q.push({ny, nx});
            visit[ny][nx] = 1;
        }
    }
}

int topPos(int x) {
    for (int i=0; i<h; i++) {
        if (block[i][x] > 0) return i;
    }
    return -1;
}

int count() {
    int cnt = 0;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (block[i][j] > 0) cnt++;
        }
    }
    return cnt;
}

void simulation(int y, int x, int cnt) {
    int tmp[20][20];
    
    crush(y, x);

    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        crush(y, x);
    }

    down();
    
    if (cnt > 0) {
        for (int i=0; i<w; i++) {
            int ty = topPos(i);
            if (ty == -1) continue;
            if (block[ty][i] == 0) continue;

            memcpy(tmp, block, sizeof(block));
            simulation(ty, i, cnt-1);
            memcpy(block, tmp, sizeof(block));
        }
    }
    min_bk = min(min_bk, count());
}


int main(void) {
    int T;
    scanf("%d", &T);

    for (int tc=1; tc<=T; tc++) {        
        scanf("%d%d%d", &n, &w, &h);

        min_bk = 1e9;
        for (int i=0; i<h; i++)
            for (int j=0; j<w; j++) {
                scanf("%d", &block[i][j]);
            }

        int tmp[20][20];        
        for (int i=0; i<w; i++) {
            int ty = topPos(i);
            if (ty == -1) continue;
            if (block[ty][i] == 0) continue;

            memcpy(tmp, block, sizeof(block));
            simulation(ty, i, n-1);
            memcpy(block, tmp, sizeof(block));
        }

        printf("#%d %d\n", tc,  min_bk);
    }
    return 0;
}