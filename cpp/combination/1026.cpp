// BOJ 1026. 보물
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp (int &a, int &b) {
    return a > b;
}

int main(void) {
    int n; 
    scanf("%d", &n);

    int a[51] = {0}, b[51] = {0};
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    for (int i=0; i<n; i++) scanf("%d", &b[i]);

    sort(a, a+n);
    sort(b, b+n, cmp);

    int res = 0;
    for (int i=0; i<n; i++) res += a[i]*b[i];

    printf("%d", res);
}