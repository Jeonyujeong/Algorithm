#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    int n ;
    queue<int> q;

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        q.push(i+1);
    }

    while(q.size() > 1) {
        q.pop();

        int card = q.front();
        q.pop();
        q.push(card);
    }

    printf("%d", q.front());
}
