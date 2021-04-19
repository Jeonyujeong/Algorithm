#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(void) {
    int n;
    int dp[1000001] = {0};

    scanf("%d", &n);

    for(int i=2; i<n+1; i++) {
        dp[i] = dp[i-1] + 1;
        if(i%3 == 0) dp[i] = min(dp[i], dp[i/3] + 1);
        if(i%2 == 0) dp[i] = min(dp[i], dp[i/2] + 1); 
    }

    printf("%d", dp[n]);
}