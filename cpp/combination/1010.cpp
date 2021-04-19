#include <iostream>
#include <cstring>
using namespace std;

// nCr = (n-1)C(r-1) + (n-1)Cr
int memo[31][31];
int combi(int n, int r) {
    if (memo[n][r]) return memo[n][r];

    if (n==r) return memo[n][r] = 1;
    else if (r==1) return memo[n][r] = n;
    else return memo[n][r] = combi(n-1, r-1) + combi(n-1, r);
}

int main(void) {
    int t;
    scanf("%d", &t);
    
    while(t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        memset(memo, 0, sizeof(memo));
        printf("%d\n", combi(m, n));
    }
}