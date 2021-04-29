// 날짜 계산
#include <iostream>

using namespace std;

int main(void) {
    int e, s, m;
    scanf("%d%d%d", &e, &s, &m);

    int ee=0, ss=0, mm=0, cnt=0;
    while(true) {
        if (ee==e && ss==s && mm==m) break;

        if (ee == 15) ee = 1;
        else ee++;

        if (ss == 28) ss = 1;
        else ss++;

        if (mm == 19) mm = 1;
        else mm++;

        cnt++;
    }
    printf("%d", cnt);
}