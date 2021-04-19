#include <iostream>
#include <queue>

using namespace std;

typedef struct {
    int y, x;
} pos;

int dy[8] = {2,2,-2,-2, 1,1,-1,-1};
int dx[8] = {1,-1,1,-1, 2,-2,2,-2};
int t, l;

int bfs(pos start, pos end) {
    queue<pos> q;
    int visit[301][301]= {0};

    q.push(start);
    visit[start.y][start.x] = 1;

    while(!q.empty()) {
        pos cur =  q.front();
        q.pop();

        if(cur.y == end.y && cur.x == end.x)
            return visit[end.y][end.x]-1;

        for(int i=0; i<8; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if(ny < 0 || nx < 0 || ny >= l || nx >= l) 
                continue;

            if(visit[ny][nx]) continue;

            q.push({ny, nx});
            visit[ny][nx] = visit[cur.y][cur.x] +1;
        }
    }

    return visit[end.y][end.x]-1;
}
 

int main(void) {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &l);

        pos start, end;
        scanf("%d %d", &start.y, &start.x);
        scanf("%d %d", &end.y, &end.x);
        
        printf("%d\n", bfs(start, end));
    }
}