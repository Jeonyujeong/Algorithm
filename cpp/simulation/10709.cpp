// BOJ 10709. 기상캐스터

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int main(void) {
    int res[101][101] = {0};
    queue<pair<int,int>> q;
    int h, w;
    char c;

    memset(res, -1, sizeof(res));
    
    cin >> h >> w;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin >> c;

            if (c == 'c') {
                res[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (x + 1 >= w || res[y][x+1] >= 0) continue;
        res[y][x+1] = res[y][x] + 1;
        q.push({y, x+1});
    }

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            printf("%d ", res[i][j]);
        } printf("\n");
    }
}