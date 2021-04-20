#include <iostream>

using namespace std;

int main(void) {
    int N, k, y;
    scanf("%d%d%d", &N, &k, &y);

    int cnt = 0;
    while(true) {
        if (cnt > N/2) {
            printf("-1");
            return 0;
        }

        if (k%2 != 0 && k+1 == y) break;
        else if (y%2 != 0 && y+1 == k) break;

        k = (k+1)/2;
        y = (y+1)/2;
        cnt++;
    }
    printf("%d", cnt+1);
}
