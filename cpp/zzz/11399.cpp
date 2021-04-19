#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    int n, p;
    vector<int> v;

    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &p);
        v.push_back(p);
    }

    sort(v.begin(), v.end());

    int result = 0;
    int sum = 0;
    for(int i=0; i<v.size(); i++) {
        sum += v[i];
        result += sum;
    }

    printf("%d", result);
}