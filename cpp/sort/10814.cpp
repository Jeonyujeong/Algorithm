// BOJ 10814. 나이순 정렬

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,string> a, pair<int,string> b) {
    return a.first < b.first;
}

int main(void) {
    int N; 
    cin >> N;

    vector<pair<int, string>> v(N);
    for (int i=0; i<N; i++) {
        cin >> v[i].first >> v[i].second;
    }
    
    // sort 는 동일한 정렬 기준에 대해 순서를 유지해준다는 보장이 없다. 
    // stable_sort 는 동일한 정렬 기준에 대해 순서 유지를 보장한다.
    stable_sort(v.begin(), v.end(), compare);

    for (int i=0; i<N; i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }
}   