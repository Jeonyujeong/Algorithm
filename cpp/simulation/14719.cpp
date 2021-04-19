#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int h, w;
    scanf("%d %d", &h, &w);
    
    vector<int> v(w);
    for (int i=0; i<w; i++) {
        scanf("%d", &v[i]);
    }

    int result = 0;
    for (int i=1; i<w-1; i++) {
        int left = 0; int right = 0;
        
        for (int j=0; j<i; j++) left = max(left, v[j]);
        for (int j=w-1; j>i; j--) right = max(right, v[j]);
        result += max(0, min(left, right) - v[i]);
    }
    printf("%d", result);
}