#include <iostream>

using namespace std;

int main(void) {
    int x; 
    scanf("%d", &x);

    int sumlen = 0;
    int minlen = 64;
    int cnt = 0;
    if (x == minlen) {
        printf("1");
        return 0;
    }

    while(sumlen < x) {
        int halflen = minlen/2;

        if (sumlen + halflen > x) {
            minlen = halflen;
        } 
        else {
            cnt++;
            sumlen += halflen;
            minlen = halflen;
        }
    }
    printf("%d", cnt);
}