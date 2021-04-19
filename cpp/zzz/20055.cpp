#include <iostream>
#define N 100
#define MAX 2*N+1
using namespace std;


int main(void) {
    int n, k;
    int a[MAX] = {0};

    scanf("%d %d", &n, &k);
    for (int i=1; i<=2*n; i++)
        scanf("%d", &a[i]);
    
    int zero_cnt = 0;
    int robot[MAX] = {0};
    int step = 0;
    int up = 1, dp = n;
    while(zero_cnt < k) {
        if (up == 1) up = 2*n;
        else up = (up - 1)%(2*n+1);  // 올라가는 위치에 해당하는 벨트 번호. 한칸 회전한다.

        if (dp == 1) dp = 2*n;
        else dp = (dp - 1)%(2*n+1);
        
        // int pp = up-1;
        // for (int i=0; i<n; i++) {
        //     pp += 1;
        //     if (pp == 2*n+1) pp = 1;
        //     printf("%d ", pp);
        // }printf("\n");

        robot[dp] = 0;
        int p = dp;
        for (int i=1; i<n; i++) {   // 1~n-1 번 반복
            p -= 1;
            if (p == 0) {
                p = 2*n;
                if (!robot[2*n] || robot[1] || a[1] < 1) continue;

                robot[2*n] = 0;
                robot[1] = 1;
                a[1]--;
                if (a[1] == 0) zero_cnt++;
                continue;
            }

            // 해당 벨트에 로봇이 없으면
            if (!robot[p] || robot[p+1] || a[p+1] < 1) continue; // 한 칸 이동할 수 없으면, 내구도가 0일때 

            robot[p] = 0;
            robot[p+1] = 1;
            a[p+1]--;
            if (a[p+1] == 0) zero_cnt++; 
        }


        robot[dp] = 0;
        if (!robot[up] && a[up] > 0) {  // 올라가는 위치에 로봇이 없으면 하나 올린다.
            robot[up] = 1;    
            a[up]--;
            if (a[up] == 0) zero_cnt++; 
        }
        
        // pp = up-1;
        // for (int i=0; i<n; i++) {
        //     pp += 1;
        //     if (pp == 2*n+1) pp = 1;
        //     printf("%d ", robot[pp]);
        // }printf("R\n");

        // pp = up-1;
        // for (int i=0; i<n; i++) {
        //     pp += 1;
        //     if (pp == 2*n+1) pp = 1;
        //     printf("%d ", a[pp]);
        // }printf("A\n");

        step++;
    }
    printf("%d", step);
}