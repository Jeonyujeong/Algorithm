#include <iostream>
using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);
 
    long long dp[100][2] = {0};
    dp[1][1] = dp[2][0] = 1;
    
    for (int i=3; i<=n; i++) {
        dp[i][0] = dp[i-1][1] + dp[i-1][0];
        dp[i][1] = dp[i-1][0];
    }

    printf("%lld", dp[n][0]+dp[n][1]);
}