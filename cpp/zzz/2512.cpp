#include <iostream>
#include <vector>
#include <algorithm>
#define N 10001
using namespace std;

int bgsum_func(vector<int> &v, int maxval) {
    int sum = 0;
    for (int i=0; i<v.size(); i++) {
        if (maxval < v[i]) sum += maxval;
        else sum += v[i];
    }
    return sum;
}

int main(void) {
    int n, m;
    vector<int> bg;

    scanf("%d", &n);
    int bg_sum = 0;
    int bg_max = 0;
    for (int i=0; i<n; i++) {
        int val;
        scanf("%d", &val);
        bg.push_back(val);
        bg_sum += val;
        bg_max = max(bg_max, val);
    }
    scanf("%d", &m);

    if (bg_sum <= m) {
        printf("%d", bg_max);
        return 0;
    }
    
    int left = 0;
    int right = bg_max;
    int mid = 0, midmax = 0;
    while(left <= right) {
        mid = (left+right)/2;

        int total = bgsum_func(bg, mid);
        if (total < m) {
            left = mid+1;
            midmax = mid;
        } 
        else if (total > m) {
            right = mid-1;
        }
        else {
            midmax = mid;
            break;
        }
    }
    printf("%d", midmax);
}