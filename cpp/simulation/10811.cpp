#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);

    vector<int> v(n);
    for (int i=0; i<n; i++) v[i] = i;

    for (int i=0; i<m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);

        reverse(v.begin()+a-1, v.begin()+b);
    }
    for (int i=0; i<n; i++) printf("%d ", v[i]+1);
}