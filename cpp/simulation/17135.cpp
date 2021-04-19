#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, D;
int maxCnt;
void bfs(vector<vector<int>> &board, int y, int x) {
    int visit[16][16] = {0};
    int dy[4] = {0,1,-1,0};
    int dx[4] = {-1,0,0,1};

    queue<pair<int,int>> q;
    q.push({y, x});
    
    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        if (visit[y][x] > D) break;

        if (board[y][x] == 1 || board[y][x] == -1) {
            board[y][x] = -1;
            break;
        }

        for (int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (ny<0 || nx<0 || ny>=N || nx>=M || visit[ny][nx]) continue;
            q.push({ny, nx});
            visit[ny][nx] = visit[y][x]+1;
        }
    }
}


void simulation(vector<pair<int, int>> bow_pos, vector<vector<int>> board, int cnt) {
    
    for (int i=0; i<bow_pos.size(); i++) {
        int by = bow_pos[i].first;
        int bx = bow_pos[i].second;

        bfs(board, by, bx);
    }

    bool check = false;
    for (int i=N-1; i>=0; i--) {
        for (int j=0; j<M; j++) {
            if (board[i][j] == -1) {
                cnt++;
                board[i][j] = 0;
            }
            else if (board[i][j] == 1) {
                if (i+1 < N) {
                    board[i+1][j] = 1;
                    check = true;
                }
                board[i][j] = 0;
            }
        }
    }

    if (check) simulation(bow_pos, board, cnt);
    maxCnt = max(cnt, maxCnt);
}

int main(void) {
    
    scanf("%d%d%d", &N, &M, &D);

    vector<vector<int>> board(N+1, vector<int>(M+1,0));
    for (int i=0; i<N; i++) 
        for (int j=0; j<M; j++) {
            scanf("%d", &board[i][j]);
        }
            
    for (int i=0; i<(1<<M); i++) {
        int cnt = 0;

        for (int j=0; j<M; j++) {
            if (i &(1<<j)) cnt++;
        }
        if (cnt == 3) {
            vector<pair<int, int>> bow_pos;
            for (int j=0; j<M; j++) {
               if (i &(1<<j)) bow_pos.push_back({N, j});
            }
            
            simulation(bow_pos, board, 0);
        }
    }

    printf("%d", maxCnt);
}