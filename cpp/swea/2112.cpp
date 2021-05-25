#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int D, W, K;
int min_cnt;
// int film[20][20];
vector<vector<int>> film(20, vector<int>(20,0));
bool film_check() {
    for (int i=0; i<W; i++) {
        int a=0, b=0, j;
        for (j=0; j<D; j++) {
            if (film[j][i] == 0) { a++; b=0; }
            else if (film[j][i] == 1) { b++; a=0; }

            if (a >= K || b >= K) break;
        }
        if (j == D) return false;
    }
    return true;
}

void solve(vector<int> dept_film, int dept, int ab, int cnt) {
    if (film_check()) {
        min_cnt = min(min_cnt, cnt);
        return;
    }
    int tmp[20] = {0};
    for (int i=0; i<W; i++) {
        tmp[i] = film[dept][i];
        film[dept][i] = dept_film[i];
    }

    solve(dept_film, dept+1, -1, cnt);

    for (int i=0; i<W; i++) dept_film[i] = 0;
    solve(dept_film, dept+1, 0, cnt+1);

    for (int i=0; i<W; i++) dept_film[i] = 1;
    solve(dept_film, dept+1, 1, cnt+1);
    
    for (int i=0; i<W; i++) film[dept][i] = tmp[i];
}

int main(void) {
    int T;
    scanf("%d", &T);

    for (int tc=1; tc<=T; tc++) {        
        scanf("%d%d%d", &D, &W, &K);
        vector<vector<int>> film(D, vector<int>(W,0));

        for (int i=0; i<D; i++)
            for (int j=0; j<W; j++)
                scanf("%d", &film[i][j]);

        min_cnt = 1e9;
        for (int i=0; i<D; i++) {
            solve(film[i], 0, -1, 0);  // 약물투입 x
            solve(film[i], 0, 0, 1);   // a 약물
            solve(film[i], 0, 1, 1);   // b 약물
        }
        
        printf("#%d %d\n", tc, min_cnt);
    }
    return 0;
}