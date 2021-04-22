// 5650. [모의 SW 역량테스트] 핀볼 게임
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

// 북 동 남 서
int block[6][4] = {{0,}, {0,0,1,1}, {1,0,0,1}, {1,1,0,0}, {0,1,1,0}, {1,1,1,1}};
int board[101][101];
vector<pair<int,int>> worm[5];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int n;
int result;
void simulation(int y, int x, int d) {
    int cnt = 0;
    int ny = y, nx = x, nd = d;
    bool start = false;
    while(true) {
        if (y==2 && x==3 && d==1) {
            // printf("%d %d\n", ny, nx);
        }

        if (ny<0 || nx<0 || ny>=n || nx>=n) {
            nd = (nd+2)%4;  // 방향전환
            ny += dy[nd];
            nx += dx[nd];
            cnt = cnt*2 + 1;
            break;
        }

        if (board[ny][nx] == -1 || (ny==y && nx==x && start)) {
            break;
        }

        start = true;
        if (board[ny][nx] == 0) {
            ny += dy[nd];
            nx += dx[nd];
            continue;
        }

        if (1 <= board[ny][nx] && board[ny][nx] <= 5) {
            int no = board[ny][nx];
            int bd = (nd+2)%4;
            // printf("bd => %d %d\n", bd, block[no][bd]);

            if (block[no][bd]) { // 블락의 변에 맞을 때
                nd = bd;
                ny += dy[nd];
                nx += dx[nd];
                cnt = cnt*2 + 1;
                break;
            }
            else {  // 블락의 빗면에 맞을 때
                for (int i=0; i<4; i++) 
                    if (bd != i && block[no][i] == 0) { // 90도로 방향변환
                        nd = i;
                        // printf("i => %d\n", i);
                        ny += dy[nd];
                        nx += dx[nd];
                        break;
                    }
                cnt++;
            }
            continue;
        }

        if (6 <= board[ny][nx] && board[ny][nx] <=10) { // 웜홀 이동
            int no = board[ny][nx]-6;
            ny = (worm[no][0].first == ny)?worm[no][1].first:worm[no][0].first; 
            nx = (worm[no][0].second == nx)?worm[no][1].second:worm[no][0].second;
            ny += dy[nd];
            nx += dx[nd];
            continue;
        }
    }

    result = max(result, cnt);
}


int main(void) {
    int T;
    scanf("%d", &T);

    for (int tc=1; tc<=T; tc++) {  
        scanf("%d", &n);

        result = 0;
        memset(board, 0, sizeof(board));
        memset(worm, 0, sizeof(worm));
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++) {
                scanf("%d", &board[i][j]);
                if (6 <= board[i][j] && board[i][j] <=10) {
                    int no = board[i][j] - 6;
                    worm[no].push_back({i, j});
                }
            }
                
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] != 0) continue;

                for (int d=0; d<4; d++) {
                    // printf("dir => %d\n", d);
                    simulation(i, j, d);
                }
            }
        }

        printf("#%d %d\n", tc, result);
    }
    return 0;
}