#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef struct {
    int sy, sx, ey, ex;
} Pos;

typedef struct {
    int cnt, y, x;
} Mov;

struct cmp {
    bool operator()(Mov& a, Mov &b) {
        if (a.cnt != b.cnt) return a.cnt > b.cnt;
        if (a.y != b.y) return a.y > b.y;
        return a.x > b.x;
    }
};

int n, m, oil;
int map[21][21];
int visit[21][21];
int dy[4] = {0,-1,0,1};
int dx[4] = {-1,0,1,0};

int customer_choice(int y, int x) {
    priority_queue<Mov, vector<Mov>, cmp> q;
    q.push({0,y,x});
    visit[y][x] = 1;

    while (!q.empty()) {
        y = q.top().y;
        x = q.top().x;
        int cnt = q.top().cnt;
        q.pop();

        if (map[y][x] > 1) {
            return map[y][x]-2;
        }

        for (int i=0; i<4; i++) {
            int ny = y+dy[i];
            int nx = x+dx[i];

            if (ny<0 || nx<0 || ny>=n || nx>=n) continue;
            if (visit[ny][nx] || map[ny][nx] == 1) continue;

            q.push({cnt+1, ny, nx});
            visit[ny][nx] = visit[y][x] +1;
        }
    }
    
    return -1;
}

void customer_goal(int y, int x, int ey, int ex) {
    queue<pair<int,int>> q;

    q.push({y,x});
    visit[y][x] = 1;

    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        if (y == ey && x == ex) break;

        for (int i=0; i<4; i++) {
            int ny = y+dy[i];
            int nx = x+dx[i];

            if (ny<0 || nx<0 || ny>=n || nx>=n) continue;
            if (visit[ny][nx] || map[ny][nx] == 1) continue;

            q.push({ny, nx});
            visit[ny][nx] = visit[y][x] +1;
        }
    }
}

int main(void) {
    scanf("%d%d%d", &n, &m, &oil);

    for (int i=0; i<n; i++) 
        for (int j=0; j<n; j++) 
            scanf("%d", &map[i][j]);
    
    int by, bx;
    scanf("%d%d", &by, &bx);
    by-=1; bx-=1;

    vector<Pos> v;
    for (int i=0; i<m; i++) {
        int sy, sx, ey, ex;
        scanf("%d%d%d%d", &sy, &sx, &ey, &ex);
        v.push_back({sy-1, sx-1, ey-1, ex-1});
        map[sy-1][sx-1] = i+2;
    }

    bool flag = false;
    while(true) {
        memset(visit, 0, sizeof(visit));

        int cno = customer_choice(by, bx);
        if (cno == -1) break;

        by = v[cno].sy;
        bx = v[cno].sx;
        map[by][bx] = 0;
        int dist = visit[by][bx] -1;
        if (oil - dist < 0) {
            flag = true;
            break;
        }
        // printf("cc = oil %d / dist %d\n", oil, dist);
        oil -= dist;
        memset(visit, 0, sizeof(visit));
        customer_goal(by, bx, v[cno].ey, v[cno].ex);

        by = v[cno].ey;
        bx = v[cno].ex;
        dist = visit[by][bx] -1;

        if (dist == -1 || oil - dist < 0) {
            flag = true;
            break;
        }
        // printf("cg = oil %d / dist %d\n", oil, dist);
        oil -= dist;
        oil += dist*2;
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (map[i][j] > 1) {
                printf("-1");
                return 0;
            }
        }
    }

    if (!flag) printf("%d", oil);
    else printf("-1");
}