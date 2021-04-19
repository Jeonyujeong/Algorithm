#include <iostream>
#include <vector>

using namespace std;

int paper[129][129]={0};
int n;
int blueCnt, whiteCnt;

int check(int sy, int sx, int len) {
    int color = paper[sy][sx];

    if(len == 1) return 1;

    for(int i=0; i<len; i++) {
        for(int j=0; j<len; j++) {
            if(paper[sy+i][sx+j] != color)
                return 0;
        }
    }

    return 1;
}

void solve(int sy, int sx, int len) {

    if(check(sy, sx, len)) {
        if(paper[sy][sx]== 1) blueCnt++;
        else whiteCnt++;
        
        return ;
    }

    solve(sy, sx, len/2);
    solve(sy + len/2, sx, len/2);
    solve(sy, sx + len/2, len/2);
    solve(sy + len/2, sx + len/2, len/2);
}

int main(void) {
    scanf("%d", &n);

    for(int i=0; i<n; i++) 
        for(int j=0; j<n; j++) 
            scanf("%d", &paper[i][j]);

    solve(0,0,n);
    printf("%d\n%d\n", whiteCnt, blueCnt);
}