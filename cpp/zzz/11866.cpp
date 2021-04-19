#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);

    queue<int> q;
    vector<int> v;
    int cnt = 0;

    for (int i=0; i<n; i++) {
        q.push(i+1);
    }

    while(!q.empty()) {
        cnt++;
        int num = q.front();
        q.pop();
        if(cnt % k == 0) {
            v.push_back(num);
            cnt = 0;
        } else{
            q.push(num);
        }
    }

    printf("<%d", v[0]);
    for(int i=1; i<v.size(); i++) {
        printf(", %d", v[i]);
    }
    printf(">");
}