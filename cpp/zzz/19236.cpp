#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    int n, d;
    int y, x;   // 위치
} fish;

// 위에서부터 반시계방향
int dir[8][2] = {{-1,0}, {-1,-1}, {0,-1}, {1,-1}, {1,0}, {1,1}, {0,1}, {-1,1}};


bool compare(fish a, fish b) {
    return a.n < b.n;
}

void print(vector<vector<int>>& space) {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            printf("%d ", space[i][j]);
        }printf("\n");
    }printf("\n");
}

void eatfish(int y, int x, vector<vector<int>>& space, fish& shark, vector<fish>& fishs)  {
    int n = space[y][x]-1;  // 먹힐 물고기 번호
    fish f = fishs[n];

    space[shark.y][shark.x] = 0;    // 상어가 있던 자리
    shark = f;
    space[shark.y][shark.x] = -1;   // 물고기 먹은 자리
}


void swap(fish cur, fish next, vector<vector<int>>& space, vector<fish>& fishs) {

    fishs[next.n-1].y = cur.y;
    fishs[next.n-1].x = cur.x;
    space[cur.y][cur.x] = next.n;

    fishs[cur.n-1].y = next.y;
    fishs[cur.n-1].x = next.x;
    space[next.y][next.x] = cur.n;
}

int movement(vector<vector<int>> space, vector<fish> fishs, fish shark, int eatsum) {
    // 물고기 이동
    for (int i=0; i<fishs.size(); i++) {
        fish cur = fishs[i];
        // printf("%d: ", cur.n);
        if (space[cur.y][cur.x] != cur.n) continue; // ---> 이거때문에 .. 고생함..
        

        for (int j=0; j<8; j++) {
            int d = (cur.d + j) % 8;
            int ny = cur.y + dir[d][0];
            int nx = cur.x + dir[d][1];

            if (ny<0 || nx<0 || ny>=4 || nx>=4) continue;   // 범위
            if (space[ny][nx] == -1) continue; // 상어있을 때

            if (space[ny][nx] == 0) {   // 이동하는 칸에 물고기가 없을 때
                fishs[i].y = ny;
                fishs[i].x = nx;
                fishs[i].d = d;
                space[ny][nx] = cur.n;
                space[cur.y][cur.x] = 0;
                // printf("%d(%d,%d) %d(%d,%d)\n", space[fishs[i].y][fishs[i].x], fishs[i].y, fishs[i].x, space[fishs[0].y][fishs[0].x], fishs[0].y, fishs[0].x);
                break;
            }
            else if (space[ny][nx] > 0) {
                // 이동하는 칸에 물고기가 있을 때
                int nn = space[ny][nx]-1;
                fish next = fishs[nn];  // 바꿀 물고기 정보
                
                // printf("%d(%d,%d) %d(%d,%d)\n", space[fishs[i].y][fishs[i].x], fishs[i].y, fishs[i].x, space[fishs[nn].y][fishs[nn].x], fishs[nn].y, fishs[nn].x);
                swap(cur, next, space, fishs);                
                fishs[i].d = d;  // 이동한 물고기 방향 전환
                // printf("%d(%d,%d) %d(%d,%d)\n", space[fishs[i].y][fishs[i].x], fishs[i].y, fishs[i].x, space[fishs[nn].y][fishs[nn].x], fishs[nn].y, fishs[nn].x);
                break; 
            }
        }
    }
    // print(space);

    // 상어 이동 
    int d = shark.d;
    int ny = shark.y;
    int nx = shark.x;
    int result = eatsum;
    for (int i=0; i<4; i++) {
        ny += dir[d][0];
        nx += dir[d][1];

        if (ny<0 || nx<0 || ny>=4 || nx>=4) break;   // 범위
        if (space[ny][nx] == 0) continue; // 물고기 없을 때

        if (space[ny][nx] > 0) {
            int eatN = space[ny][nx]-1;
            fish eat = fishs[eatN];
            fish beforeshark = shark;
            vector<vector<int>> beforespace = space;

            // printf("%d %d\n", space[ny][nx], eatsum);
            eatfish(ny, nx, space, shark, fishs);
            // print(space);
            result = max(movement(space, fishs, shark, eatsum+eatN+1), result);
            
            shark = beforeshark;
            space = beforespace;
        }
    }
    // printf("\n");
    return result;
}

int main(void)  {
    int a, b;
    vector<vector<int>> space(5, vector<int>(5));
    vector<fish> fishs;
    fish shark = {0,0,0,0};
    int eatsum = 0;
    
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            scanf("%d %d", &a, &b);
            fish f = {a, b-1, i, j};
            fishs.push_back(f);
            space[i][j] = f.n;
        }
    }

    sort(fishs.begin(), fishs.end(), compare);
    // print(space);

    eatsum = space[0][0];
    eatfish(0, 0, space, shark, fishs);  // (0,0) 먹고 들어간다.
    eatsum = movement(space, fishs, shark, eatsum);
    printf("%d", eatsum);
}