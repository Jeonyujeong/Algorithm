// 1206. [S/W 문제해결 기본] 1일차 - View
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int T=10;

    for (int tc=1; tc<=T; tc++) {
        int n;
        scanf("%d", &n);

        int h;
        vector<int> v;
        for (int i=0; i<n; i++) {
            scanf("%d", &h);
            v.push_back(h);
        }

        int result = 0;
        for (int i=2; i<n-2; i++) {
            int left = max(v[i-1], v[i-2]);
            int right = max(v[i+1], v[i+2]);

            if (left >= v[i] || right >= v[i]) continue;
            result += v[i] - max(left, right);
        }

        printf("#%d %d\n", tc, result);
    }
    return 0;
}