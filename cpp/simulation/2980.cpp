#include <iostream>
using namespace std;

int main(void) {
    int n, l;
    scanf("%d %d", &n, &l);

    int time = 0, cur = 0;
    for (int i=0; i<n; i++) {
        int d, r, g;
        scanf("%d %d %d", &d, &r, &g);

        int runTime = d-cur;
        time += runTime;
        if (time % (r+g) < r) {
            int waitTime = r - (time % (r+g));
            time += waitTime;
        }
        cur = d;
    }

    int runTime = l-cur;
    time += runTime;
    printf("%d", time);
}