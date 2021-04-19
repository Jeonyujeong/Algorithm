#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int visit[101];
int sy, sx;
int maxResult = -1;
int N;
vector<vector<int>> v;
int dy[4] = {1,1,-1,-1};
int dx[4] = {-1,1,1,-1};
void dfs(int y, int x, int d, int cnt, int pathCnt) {

    // printf("%d [%d %d] [%d %d] %d %d %d\n", cnt, sy, sx, y, x, d, pathCnt, v[y][x]);

    if (cnt == 4 && sy == y && sx == x) {
        
        maxResult = max(maxResult, pathCnt);
        // printf("%d\n", maxResult);
        return ;
    }

    int nd = (d+1)%4;
    int ny = y + dy[nd];
    int nx = x + dx[nd];
    // printf("- %d %d\n", ny, nx);
    if (ny>=0 && nx>=0 && ny<N && nx<N && !visit[v[ny][nx]]) {
        visit[v[ny][nx]] = 1;
        dfs(y + dy[nd], x + dx[nd], nd, cnt+1, pathCnt+1);
        visit[v[ny][nx]] = 0;
    }
        
    ny = y + dy[d];
    nx = x + dx[d];
    // printf("= %d %d\n", ny, nx);
    if (ny>=0 && nx>=0 && ny<N && nx<N && !visit[v[ny][nx]]) {
        visit[v[ny][nx]] = 1;
        dfs(y + dy[d], x + dx[d], d, cnt, pathCnt+1);
        visit[v[ny][nx]] = 0;
    }
}

int main(void) {
    int T;
    cin >> T;

    for (int test_case=1; test_case<=T; test_case++) {
        cin >> N;
        v.clear();
        v.resize(N+1, vector<int>(N+1));
        maxResult = -1;

        for (int i=0; i<N; i++) 
            for (int j=0; j<N; j++)
                cin >> v[i][j];

        for (int i=0; i<N-2; i++) {
            for (int j=1; j<N-1; j++) {
                sy = i; sx = j;

                visit[v[i+dy[0]][j+dx[0]]] = 1;
                dfs(i + dy[0], j + dx[0], 0, 1, 1);
                // dfs(i, j, 0, 1, 1);
                visit[v[i+dy[0]][j+dx[0]]] = 0;
            }
        }
        cout << "#" << test_case << " " << maxResult << "\n";
    }
    return 0;
}