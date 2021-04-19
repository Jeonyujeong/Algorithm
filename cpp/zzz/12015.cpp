#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    int n, a;
    vector<int> arr;
    vector<int> lis;

    
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a);
        arr.push_back(a);
    }

    lis.push_back(arr[0]);
    for(int i=1; i<n; i++) {
        int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
        
        // printf("%d ", idx);
        if(idx >= lis.size()) 
            lis.push_back(arr[i]);
        
        if(arr[i] < lis[idx]) {
            lis[idx] = arr[i];
        }
    }

    printf("%d", lis.size());
}