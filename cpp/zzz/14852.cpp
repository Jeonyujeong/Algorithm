#include <iostream>
#define MOD 1000000007
using namespace std;

int main(void) {
    long n;

    scanf("%d", &n);

    long first = 2;
    long second = 7;
    long dd = 0;

    if (n == 1) dd = first;
    else if (n == 2) dd = second;

    for (int i=0; i<=n-3; i++) {
        if (i == 0) dd = ((first<<2)% MOD + (second<<1)%MOD)%MOD;
        else dd = ((first<<2)% MOD + (second<<1)%MOD)%MOD - (1<<(i-1));
        first = second;
        second = dd;
    }
    printf("%d ", dd);

    long dp[10] = {0}; 
    long dp2[10] = {0}; 
    dp[1]=2; 
    dp[2]=7; 
    dp[3]=22; 
    dp2[3]=1; 
    for(int i = 4; i<=n; i++){ 
        dp2[i] = (dp2[i-1]+dp[i-3])%MOD; 
        dp[i] = (dp[i-2]*3+dp[i-1]*2+dp2[i]*2)%MOD; 
    }
    printf("%d", dp[n]);
}