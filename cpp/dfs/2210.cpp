// BOJ 2210. 숫자판 점프

#include <iostream>
#include <set>
#include <string>

using namespace std;

int board[5][5];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
set<string> s;
void dfs(int y, int x, int cnt, string res) {
    if (cnt >= 6) {
        s.insert(res);
        return;
    }

    for (int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny<0 || nx<0 || ny>=5 || nx>=5) continue;

        dfs(ny, nx, cnt+1, res+to_string(board[ny][nx]));
    }
}

int main(void) {
    string res = "";

    for (int i=0; i<5; i++) 
        for (int j=0; j<5; j++) 
            scanf("%d", &board[i][j]);
        
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            dfs(i, j, 1, res+to_string(board[i][j]));
        }
    }

    printf("%d", s.size());
}