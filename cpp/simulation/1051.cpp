#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
char arr[51][51] = {0};

int check(int y, int x, int len) {
    char c = arr[y][x];
    if (arr[y+len][x] == c && arr[y][x+len] == c && arr[y+len][x+len] == c) return 1;
    else return 0;
}

int main(void) {
    cin >> n>> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }

    int L = min(n, m);
    int l;
    for (l=L-1; l>=0; l--) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (i + l >= n || j + l >= m) continue;
                if (check(i, j, l)) {
                    printf("%d", (l+1)*(l+1));                
                    return 0;
                }
            }
        }
    }
}