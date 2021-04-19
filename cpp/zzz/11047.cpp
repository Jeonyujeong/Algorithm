#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n, k;
    vector<int> v;

    scanf("%d %d", &n, &k);

    int a;
    for(int i=0; i<n; i++) {
        scanf("%d", &a);
        v.push_back(a);
    }

    int result = 0;
    for(int i=v.size()-1; i>=0; i--) {
        a = v[i];
        int cnt = k/a;

        if(cnt != 0) {
            k -= cnt*a;
            result += cnt;
        }
    }

    printf("%d", result);
}