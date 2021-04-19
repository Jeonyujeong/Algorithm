#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    priority_queue<long long> pq;
    int n, m, a;

    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
        scanf("%d", &a);
        pq.push(-a);
    }

    for (int i=0; i<m; i++) {
        long long x = pq.top();   pq.pop();
        long long y = pq.top();   pq.pop();
        long long z = x+y;
        pq.push(z); 
        pq.push(z);
    }

    long long result = 0;
    while(!pq.empty()) {
        result += pq.top();
        pq.pop();
    }
    printf("%lld", -result);
}