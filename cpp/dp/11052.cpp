// BOJ 11052. 카드구매하기
#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    int p[1001] = {0}, dp[1001] = {0};

    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", &p[i]);

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            dp[i] = max(dp[i], p[j] + dp[i-j]);
        }
    }
    printf("%d", dp[n]);
}