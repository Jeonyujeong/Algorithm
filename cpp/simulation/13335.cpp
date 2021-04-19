#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
    int n, w, l;
    scanf("%d%d%d", &n, &w, &l);

    queue<int> aq;
    for (int i=0; i<n; i++) {
        int a;
        scanf("%d", &a);
        aq.push(a);
    }

    queue<pair<int,int>> bq;
    int weight = 0, time = 0;
    bq.push({aq.front(), time});
    weight += aq.front();
    aq.pop();

    while(!bq.empty()) {
        time++;

        int bt = bq.front().second;
        if (time - bt >= w) {
            weight -= bq.front().first;
            bq.pop();
        } 
        
        int cur = aq.front();
        if (!aq.empty() && bq.size()+1 <= w && weight+cur <= l) {
            bq.push({cur, time});
            weight += cur;
            aq.pop();
        }
    }
    printf("%d", time+1);
}