// BOJ 5724. 파인만
#include <iostream>

using namespace std;

int main(void) {
    int n;
    int dp[101] = {0};

    for (int i=1; i<101; i++) dp[i] = dp[i-1] + i*i;

    while(true) {
        scanf("%d", &n);
        if (n == 0) break;

        printf("%d\n", dp[n]);
    }
}