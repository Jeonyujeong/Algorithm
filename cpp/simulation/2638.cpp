#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 101
using namespace std;

int n, m;
int cheese[MAX][MAX];
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
int visit[MAX][MAX] = {0};
bool check_side(int y, int x) {
    int cnt = 0;
    for (int i=0; i<4; i++) {
        int ny = y+dir[i][0];
        int nx = x+dir[i][1];

        if (!cheese[ny][nx] && visit[ny][nx]) cnt++;
    }

    if (cnt >= 2) return true;
    else return false;
}

vector<pair<int,int>> chsline_bfs() {
    queue<pair<int,int>> q;
    vector<pair<int,int>> v;

    q.push({0,0});
    visit[0][0] = 1;

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int ny = y+dir[i][0];
            int nx = x+dir[i][1];

            if (ny<0 || nx<0 || ny>=n || nx>=m) continue;
            if (visit[ny][nx]) continue;

            if (cheese[ny][nx]) {
                v.push_back({ny, nx});
            } else {
                q.push({ny, nx});
            }
            visit[ny][nx] = 1;
        }
    }
    return v;
}

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d", &cheese[i][j]);
        }
    }

    int time = 0;
    while(true) {
        memset(visit, 0, sizeof(visit));
        auto chsline = chsline_bfs();
        queue<pair<int,int>> chsremove;

        for (int i=0; i<chsline.size(); i++) {
            // printf("%d %d\n", chsline[i].first, chsline[i].second);
            int y = chsline[i].first;
            int x = chsline[i].second;
            if (check_side(y, x)) {
                chsremove.push({y, x});
            }
        }

        if (chsremove.empty()) break;

        while(!chsremove.empty()) {
            int y = chsremove.front().first;
            int x = chsremove.front().second;
            chsremove.pop();

            cheese[y][x] = 0;
        }

        // for (int i=0; i<n; i++) {
        //     for (int j=0; j<m; j++) {
        //         printf("%d ", cheese[i][j]);
        //     }printf("\n");
        // }printf("\n");
        time++;
    }

    printf("%d", time);
}