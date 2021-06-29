// BOJ 10973. 이전순열

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool permutation(vector<int>& arr, int n) {
    int i = n-1;
    while(i>0 && arr[i-1] < arr[i]) i--;
    if (i <= 0) return false;

    int j = n-1;
    while(j>0 && arr[j] > arr[i-1]) j--;
    iter_swap(arr.begin()+i-1, arr.begin()+j);
    
    j = n-1;
    while(i < j) {
        iter_swap(arr.begin()+i, arr.begin()+j);
        i++; j--;
    }
    return true;
}

int main(void) {
    int n;
    scanf("%d", &n);

    vector<int> arr(n);
    for (int i=0; i<n; i++) scanf("%d", &arr[i]);

    if (!permutation(arr, n)) {
        printf("-1");
        return 0;
    }

    for (int i=0; i<n; i++) printf("%d ", arr[i]);
}


