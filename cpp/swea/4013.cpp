// 4013. [모의 SW 역량테스트] 특이한 자석
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int arr[4][8];
int visit[4];
queue<pair<int,int>> q;
void rotation(int n, int d) {
    int tmp[4][8];
    memcpy(tmp, arr, sizeof(arr));

    if (d == 1) {
        arr[n][0] = tmp[n][7];
        for (int i=1; i<8; i++) arr[n][i] = tmp[n][i-1];
    }
    else if (d == -1) {
        arr[n][7] = tmp[n][0];
        for (int i=0; i<7; i++) arr[n][i] = tmp[n][i+1];
    }
}

void check(int n, int d) {
    int nd = (d==1)?-1:1;

    if (n > 0) {
        if (!visit[n-1] && (arr[n-1][2] ^ arr[n][6])) {
            q.push({n-1, nd});
            visit[n-1] = 1;
            check(n-1, nd);
        }
    }
    if (n < 3) {
        if (!visit[n+1] && (arr[n+1][6] ^ arr[n][2])) {
            q.push({n+1, nd});
            visit[n+1] = 1;
            check(n+1, nd);
        }
    }
}

int main(void) {
    int T;
    scanf("%d", &T);

    for (int tc=1; tc<=T; tc++) {
        int k;
        scanf("%d", &k);

        memset(arr, 0, sizeof(arr));
        for (int i=0; i<4; i++) 
            for (int j=0; j<8; j++) 
                scanf("%d", &arr[i][j]);
            
        for (int i=0; i<k; i++) {
            int n, d;
            memset(visit, 0, sizeof(visit));

            scanf("%d%d", &n, &d);
            n--;
            q.push({n, d});
            visit[n] = 1;
            check(n, d);

            while(!q.empty()) {
                n = q.front().first;
                d = q.front().second;
                q.pop();

                rotation(n, d);
            }
        }

        int result = 0;
        for (int i=0; i<4; i++) 
            if (arr[i][0]) 
                result += (1<<i);
        printf("#%d %d\n", tc, result);
    }
    return 0;
}