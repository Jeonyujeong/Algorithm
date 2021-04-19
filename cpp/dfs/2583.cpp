#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 101
using namespace std;

int m, n, k;
int board[MAX][MAX];
int visit[MAX][MAX];
void draw(int lx, int ly, int rx, int ry) {
   
    for (int i=ly; i<ry; i++) {
        for (int j=lx; j<rx; j++) {
            board[i][j] = 1;
        }
    }
}

int dfs(int y, int x, int size) {
    int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    
    visit[y][x] = 1;
    for (int i=0; i<4; i++) {
        int ny = y+dir[i][0];
        int nx = x+dir[i][1];

        if (ny<0 || nx<0 || ny>=m || nx>=n) continue;
        if (visit[ny][nx] || board[ny][nx]) continue;

        visit[ny][nx] = 1;
        size = dfs(ny, nx, size+1);
    }
    return size;
}

int main(void) {
    scanf("%d%d%d", &m, &n, &k);

    for (int i=0; i<k; i++) {
        int lx, ly, rx, ry;
        scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
        draw(lx, ly, rx, ry);
    }

    vector<int> vsize;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (!visit[i][j] && !board[i][j]) {
                int cnt = dfs(i, j, 1);
                vsize.push_back(cnt);
            }
        }
    }

    sort(vsize.begin(), vsize.end());
    printf("%d\n", vsize.size());
    for (int i=0; i<vsize.size(); i++) {
        printf("%d ", vsize[i]);
    }
}