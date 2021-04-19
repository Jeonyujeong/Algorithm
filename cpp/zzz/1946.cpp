#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    int t;

    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);

        vector<pair<int,int>> v;        
        int a, b; // 등수(1이 높음)
        for (int i=0; i<n; i++) {
            scanf("%d %d", &a, &b);
            v.push_back({a, b});
        }
        
        // a 로 오름차순 정렬 후
        sort(v.begin(), v.end());

        int cnt = 0;
        int minval = 1e9;
        // b 의 최소값을 업데이트 하면서
        // b 보다 작은 값이면 선택
        for(int i=0; i<n; i++) {
            if (v[i].second < minval) {
                minval = min(minval, v[i].second);
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
}