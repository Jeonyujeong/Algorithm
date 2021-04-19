// 2117. [모의 SW 역량테스트] 홈 방범 서비스
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
int result;

void bfs(int sy, int sx, vector<vector<int>>& home) {
    vector<vector<int>> service(N, vector<int>(N,0));
    queue<pair<int,int>>  q;
    int k = 1;
    
    q.push({sy, sx});
    service[sy][sx] = 1;  
    int cnt = 0;

    while (k <= N+1) {
        int size = q.size();

        for (int j=0; j<size; j++) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            if (home[y][x] == 1) cnt++;

            for (int i=0; i<4; i++) {
                int ny = y+dy[i];
                int nx = x+dx[i];

                if (ny<0 || nx<0 || ny>=N || nx>=N || service[ny][nx]) continue;
                q.push({ny, nx});
                service[ny][nx] = service[y][x] + 1;
            }
        }

        int cost = cnt*M - (k*k + (k-1)*(k-1));
        if (cost >= 0) 
            result = max(result, cnt);
        
        k++;
    }
}


int main(void) {
    int T;
    scanf("%d", &T);

    for (int test_case=1; test_case<=T; test_case++) {
        scanf("%d %d", &N, &M);
        
        vector<vector<int>> home(N+1, vector<int>(N+1,0));
        result = 0;

        for (int i=0; i<N; i++) 
            for (int j=0; j<N; j++) 
                scanf("%d", &home[i][j]);

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                bfs(i, j, home);
            }
        }
        printf("#%d %d\n", test_case, result);
    }

    return 0;    
}