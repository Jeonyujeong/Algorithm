#include <iostream>
#include <stack>

using namespace std;

int com[11];
int combi(int n) {
    if (com[n] != 0)
        return com[n];

    return com[n] = n * combi(n-1);
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);

    com[0] = 1;
    com[1] = 1;
    int result = combi(n)/(combi(n-k) * combi(k));
    printf("%d", result);
}