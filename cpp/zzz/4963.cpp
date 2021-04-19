#include <iostream>
#include <queue>

using namespace std;

int dir[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
int main(void) {

    while(true) {        
        int w, h;
        int map[51][51] = {0};
        int visit[51][51] = {0};
        queue<pair<int, int>> q;
        scanf("%d %d", &w, &h);

        if (w == 0 && h == 0) break;

        for (int i=0; i<h; i++) 
            for (int j=0; j<w; j++) 
                scanf("%d", &map[i][j]);

        int cnt = 0;
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                if (map[i][j] == 1 && visit[i][j] == 0) {
                    q.push({i, j});
                    visit[i][j] = 1;
                    cnt++;
                }

                while(!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for (int k=0; k<8; k++) {
                        int ny = y+dir[k][0];
                        int nx = x+dir[k][1];

                        if (ny<0 || nx<0 || ny>=h || nx>=w) continue;
                        if (visit[ny][nx]) continue;

                        if (map[ny][nx] == 1) {
                            visit[ny][nx] = 1;
                            q.push({ny, nx});
                        }
                    }
                }
            }
        }    
        printf("%d\n", cnt);  
    }
}