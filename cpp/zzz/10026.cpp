#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n;
char board[101][101]= {0};
int visit[101][101] = {0};
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    char cur = board[y][x];

    q.push({y, x});
    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int ny = y+dir[i][0];
            int nx = x+dir[i][1];

            if (ny<0 || nx<0 || ny>=n || nx>=n) continue;
            if (visit[ny][nx]) continue;
            if (board[ny][nx] != cur) continue;

            q.push({ny, nx});
            visit[ny][nx] = 1;
        }
    }
}

void bfs2(int y, int x) {
    queue<pair<int, int>> q;
    char cur = board[y][x];

    q.push({y, x});
    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int ny = y+dir[i][0];
            int nx = x+dir[i][1];

            if (ny<0 || nx<0 || ny>=n || nx>=n) continue;
            if (visit[ny][nx]) continue;

            if (cur == 'R' || cur == 'G') {
                if (board[ny][nx] == 'B') 
                    continue;
            }
            else {
                if (board[ny][nx] != cur) 
                    continue;
            }

            q.push({ny, nx});
            visit[ny][nx] = 1;
        }
    }
}

int main(void) {

    cin >> n;
    for (int i=0; i<n; i++) 
        for (int j=0; j<n; j++) 
            cin >> board[i][j];

    int answer1 = 0;
    for (int i=0; i<n; i++) 
        for (int j=0; j<n; j++) {
            if (visit[i][j] == 0) {
                bfs(i, j);
                answer1++;
            }
        }

    memset(visit, 0, sizeof(visit));
    int answer2 = 0;
    for (int i=0; i<n; i++) 
        for (int j=0; j<n; j++) {
            if (visit[i][j] == 0) {
                bfs2(i, j);
                answer2++;
            }
        }

    cout << answer1 << " " << answer2;
}