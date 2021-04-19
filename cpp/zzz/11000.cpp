#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    int n;
    priority_queue<pair<int, int>> pq;
    vector<pair<int, int>> v;

    scanf("%d", &n);
    int s, t;
    for(int i=0; i<n; i++) {
        scanf("%d %d", &s, &t);
        v.push_back({s, t});
    }

    sort(v.begin(), v.end());

    int maxSize = 0;
    for (int i=0; i<v.size(); i++) {
        
        // pq 비어있으면 넣기
        if (pq.empty()) {
            pq.push({-v[i].second, -v[i].first});
            int pqSize = pq.size();

            maxSize = max(maxSize, pqSize);
            continue;
        }

        // t가 작은 순으로 정렬되도록
        while(true) {
            t = -pq.top().first;
            s = -pq.top().second;

            int pqSize = pq.size();
            maxSize = max(maxSize, pqSize);

            // v의 값과 pq 의 가장 작은 t 값 비교
            if (v[i].first < t) {
                pq.push({-v[i].second, -v[i].first});    
                break;
            }
            pq.pop();
        }
    }
    printf("%d", maxSize);
}
