#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
    int T;
    cin >> T;

    // 북 동 남 서
    int dy[4] = {-1,0,1,0};
    int dx[4] = {0,1,0,-1};
    while(T--) {
        string ordstr;
        cin >> ordstr;
        int y = 0, x = 0, d = 0;
        vector<pair<int,int>> pos;

        for (int i=0; i<ordstr.length(); i++) {
            char ord = ordstr[i];

            if (ord == 'F') {
                y += dy[d];
                x += dx[d];
                pos.push_back({y,x});
            }
            else if (ord == 'B') {
                y -= dy[d];
                x -= dx[d];
                pos.push_back({y,x});
            }
            else if (ord == 'L') {
                d = (d==0)?3:(d-1);
            }
            else if (ord == 'R') {
                d = (d+1)%4;
            }
        }

        int min_y=0, min_x=0, max_y=0, max_x=0;
        for (int i=0; i<pos.size(); i++) {
            min_y = min(pos[i].first, min_y);
            min_x = min(pos[i].second, min_x);

            max_y = max(pos[i].first, max_y);
            max_x = max(pos[i].second, max_x);
        }

        cout << abs(max_y-min_y)*abs(max_x-min_x) << "\n";
    }

}