// BOJ 10867. 중복빼고 정렬하기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);

    vector<int> v(n);
    for (int i=0; i<n; i++) scanf("%d", &v[i]);

    sort(v.begin(), v.end());
    auto uq_it = unique(v.begin(), v.end());
    
    for (auto it=v.begin(); it < uq_it; it++) 
        printf("%d ", *it);
}