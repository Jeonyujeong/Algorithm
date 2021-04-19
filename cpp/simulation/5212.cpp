#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int r, c;
    cin >> r >> c;

    vector<pair<int,int>> ground;
    vector<vector<char>> map(r, vector<char>(c));
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> map[i][j];
            if (map[i][j]=='X') ground.push_back({i, j});
        }
    }

    int ly=11, tx=11, ry=0, bx=0;
    int dy[4] = {1,0,-1,0};
    int dx[4] = {0,1,0,-1};
    vector<pair<int,int>> change;
    for (int i=0; i<ground.size(); i++) {
        int cy = ground[i].first;
        int cx = ground[i].second;
        int cnt = 0;

        for (int j=0; j<4; j++) {
            int ny = cy+dy[j];
            int nx = cx+dx[j];

            if(ny<0 || nx<0 || ny>=r || nx>=c) {cnt++; continue;}
            if(map[ny][nx]=='.') cnt++;
        }

        if (cnt >= 3) change.push_back({cy, cx});
        else {
            ly = min(ly, cy);
            ry = max(ry, cy);
            tx = min(tx, cx);
            bx = max(bx, cx);
        }
    }

    for (int i=0; i<change.size(); i++) {
        int cy = change[i].first;
        int cx = change[i].second;
        map[cy][cx] = '.';       
    }

    for (int i=ly; i<=ry; i++) {
        for (int j=tx; j<=bx; j++) {
            cout << map[i][j];
        }cout << endl;
    }
}