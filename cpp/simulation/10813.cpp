#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);

    vector<int> v(n);
    for (int i=0; i<n; i++) v[i] = i;

    for (int i=0; i<m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);

        swap(v[a-1], v[b-1]);
    }

    for (int i=0; i<n; i++) printf("%d ",v[i]+1);
}