// BOJ 1965. 상자넣기

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);

    int box[1001] = {0};
    for (int i=0; i<n; i++) {
        scanf("%d", &box[i]);
    }

    int dp[1001] = {0};
    fill(dp, dp+n, 1);

    int res = 0;
    for (int i=1; i<n; i++) {
        for (int j=i-1; j>=0; j--) {
            if (box[j] < box[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        res = max(res, dp[i]);
    }
    printf("%d ", res);
}