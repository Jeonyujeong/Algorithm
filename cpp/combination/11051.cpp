#include <iostream>
using namespace std;

int memo[1001][1001];
int combi(int n, int r) {
    if (memo[n][r]) return memo[n][r];

    if (n==r) return memo[n][r] = 1;
    else if (r==0) return memo[n][r] = 1;
    else if (r==1) return memo[n][r] = n;
    else return memo[n][r] = (combi(n-1, r-1) + combi(n-1, r)) % 10007;
}

int main(void) {
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%d", combi(n, k));
}