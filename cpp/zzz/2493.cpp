#include <iostream>
#include <stack>
#include <vector>
#define MAX 500001
using namespace std;

int main(void) {
    int n, h;
    vector<int> vtop;

    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &h);
        vtop.push_back(h);
    }

    stack<int> s;
    int answer[MAX] = {0};
    for (int i=vtop.size()-1; i>=0; i--) {
        if (s.empty()) {
            s.push(i);
            continue;
        }

        int curH = vtop[i];
        int sH = vtop[s.top()];
        while (curH > sH) {
            answer[s.top()] = i+1;
            s.pop();

            if (s.empty()) break;
            sH = vtop[s.top()];
        }
        s.push(i);
    }

    for (int i=0; i<n; i++) {
        printf("%d ", answer[i]);
    }
}