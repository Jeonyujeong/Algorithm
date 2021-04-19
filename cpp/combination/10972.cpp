#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    int n; 
    scanf("%d", &n);

    vector<int> v(n);
    for (int i=0; i<n; i++) scanf("%d", &v[i]);

    bool check = false;
    while (next_permutation(v.begin(), v.end())) {
        for (int i=0; i<n; i++) printf("%d ", v[i]);
        check = true;
        break;
    } 
    
    if (!check) printf("-1");
}