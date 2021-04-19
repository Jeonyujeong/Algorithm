#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};
int loc[102][102];

void curve_point(vector<int> gen_dir, int y, int x) {
    loc[y][x] = 1;

    for (int i=0; i<gen_dir.size(); i++) {
        y += dy[gen_dir[i]];
        x += dx[gen_dir[i]];
        loc[y][x] = 1;
    }
}

int square_check(int y, int x) {

    if (loc[y][x+1] && loc[y+1][x] && loc[y+1][x+1]) return 1;
    else return 0;
}

int main(void) {
    int N; 
    scanf("%d", &N);
    
    while(N--) {
        int x, y, d, g;
        scanf("%d%d%d%d", &x, &y, &d, &g);
    
        vector<int> gen_dir;
        gen_dir.push_back(d);

        for (int i=0; i<g; i++) {
            vector<int> tmp;

            for (int j=gen_dir.size()-1; j>=0; j--) {
                tmp.push_back((gen_dir[j]+1)%4);
            }
            gen_dir.insert(gen_dir.end(), tmp.begin(), tmp.end());
        }

        curve_point(gen_dir, y, x);
    }

    int cnt = 0;
    for (int i=0; i<100; i++) 
        for (int j=0; j<100; j++)
            if (loc[i][j] && square_check(i, j)) cnt++;
        
    printf("%d", cnt);
}