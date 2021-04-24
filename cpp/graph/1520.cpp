// 내리막 길
#include <iostream>
#include <queue>

using namespace std;

typedef struct {
    int h, y, x;
} Hpos;

struct cmp{
    bool operator()(Hpos a, Hpos b) {
       return a.h < b.h;
    }
};

int m, n;
int map[501][501];
int visit[501][501];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
void bfs() {
    // 높이에 따른 우선순의 큐
    priority_queue<Hpos, vector<Hpos>, cmp> pq;
    pq.push({map[0][0], 0,0});
    visit[0][0] = 1;

    while(!pq.empty()) {
        int h = pq.top().h;
        int y = pq.top().y;
        int x = pq.top().x;
        pq.pop();

        for (int i=0; i<4; i++) {
            int ny = y+dy[i];
            int nx = x+dx[i];

            if (ny<0 || nx<0 || ny>=m || nx>=n) continue;
            if (map[y][x] <= map[ny][nx]) continue;

            if (visit[ny][nx] > 0)  // 해당지점으로 다시 오는 경우. 경로의 개수를 더해준다.
                visit[ny][nx] += visit[y][x];
            else {
                visit[ny][nx] = visit[y][x];
                pq.push({map[ny][nx], ny, nx});
            } 
        }
    }
}

int main(void) {
    scanf("%d%d", &m, &n);
    for (int i=0; i<m; i++) 
        for (int j=0; j<n; j++)
            scanf("%d", &map[i][j]);
    
    bfs();
    printf("%d", visit[m-1][n-1]);
}