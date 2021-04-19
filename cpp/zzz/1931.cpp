#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;


bool compare(pair<int, int> a, pair<int, int> b)  {
    if (a.second == b.second) 
        return a.first < b.first;
    else 
        return a.second < b.second;
}

int main(void) {
    int s, t, n;
    vector<pair<int, int>> v;

    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &s, &t);
        v.push_back({s, t});
    }

    // 끝나는 시간 순으로 오름차순 정렬
    sort(v.begin(), v.end(), compare);

    int cnt = 1;
    int end = v[0].second;
    for (int i=1; i<n; i++) {
        int start = v[i].first;
        if (end <= start) {
            cnt++;
            end = v[i].second;
        }
    }
    printf("%d", cnt);
}