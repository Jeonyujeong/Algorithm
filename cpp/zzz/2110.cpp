#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n, m, x;
    vector<int> house;

    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        house.push_back(x);
    }

    sort(house.begin(), house.end());

    int len = house.size();
    int left = 1;
    int right = house[len-1] - house[0];
    int d = 0;
    int ans = 0;

    while(left <= right) {
        int mid = (left + right)/2;
        int start = house[0];
        int cnt = 1;

        for(int i=0; i<n; i++) {
            d = house[i] - start;
            if(mid <= d) {
                cnt++;
                start = house[i];
            }
        }

        if(cnt >= m) {
            ans = mid; 
            left = mid +1;
        } else {
            right = mid - 1;
        }
    }

    printf("%d", ans);
}