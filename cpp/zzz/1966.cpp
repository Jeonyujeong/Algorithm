#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    int t;
    scanf("%d", &t);
    while(t--) {
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        int n, m;

        scanf("%d %d", &n ,&m);
        for (int i=0; i<n; i++) {
            int imp;
            scanf("%d", &imp);
            q.push({i, imp});
            pq.push(imp);
        }

        int cnt = 0;
        while(!q.empty()) {
            int cur_no = q.front().first;
            int cur_imp = q.front().second;
            q.pop();

            if (cur_imp == pq.top()) {   
                pq.pop();
                cnt++;
                
                if (cur_no == m) {
                    printf("%d\n", cnt);
                    break;
                }
            }
            else q.push({cur_no, cur_imp});
        }
    }
}