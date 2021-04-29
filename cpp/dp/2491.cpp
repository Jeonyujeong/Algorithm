// 수열
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 100001
using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);

    int nums[MAX] = {0};
    int asc = 1, dec = 1;
    int maxlen = 1;

    for (int i=0; i<n; i++) {
        scanf("%d", &nums[i]);

        if (i == 0) continue;

        if (nums[i-1] < nums[i]) {
            asc++; dec=1;
        }
        else if (nums[i-1] > nums[i]) {
            dec++; asc=1;
        }
        else {
            asc++; dec++;
        }
        maxlen = max(maxlen, max(asc, dec));
    }

    printf("%d", maxlen);
}