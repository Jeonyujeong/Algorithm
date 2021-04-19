// 선수과목 (Prerequisite)

#include <iostream>
#include <queue>
using namespace std;

int n, m;
int subject[1001];
int relation[1001][1001];
int result[1001];
queue<int> q;

bool solve(int cnt) {
    bool flag = false;

    for (int i=1; i<=n; i++) {
        if (subject[i] == 0) {
            q.push(i);
            subject[i] = -1;
            result[i] = cnt;
        }
        else if (subject[i] > 0) flag = true;
    }

    while(!q.empty()) {
        int pre = q.front();
        q.pop();
        
        for (int i=1; i<=n; i++) {
            if (relation[pre][i]) {
                relation[pre][i] = 0;
                subject[i]--;
            }
        }
    }
    return flag;
}

int main(void) {
    
    scanf("%d%d", &n, &m);
    for (int i=0; i<m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        relation[a][b] = 1;
        subject[b]++;
    }

    
    int cnt = 0;
    while(true) {
        if (solve(++cnt) == false) break;
    }
    
    for (int i=1; i<=n; i++) printf("%d ", result[i]);
}