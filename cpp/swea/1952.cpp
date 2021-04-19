#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int fees[4];
int plan[12];
int totalfee;
void simulation(int month, int money) {
    if (month >= 12) {
        totalfee = min(money, totalfee);
        return;
    }

    int dayfee = fees[0] * plan[month];
    int monfee = fees[1];
    if (dayfee > monfee) simulation(month+1, money + monfee);
    else simulation(month+1, money+dayfee);
    
    if (month <= 10)
        simulation(month+3, money+fees[2]);
}

int main(void) {
    int T;
    scanf("%d", &T);

    for (int tc=1; tc<=T; tc++) {
        memset(fees, 0, sizeof(fees));
        memset(plan, 0, sizeof(plan));
        totalfee = 1e9;

        for (int i=0; i<4; i++) scanf("%d", &fees[i]);
        for (int i=0; i<12; i++) scanf("%d", &plan[i]);

        simulation(0,0);

        totalfee = min(totalfee, fees[3]);
        printf("#%d %d\n", tc, totalfee);
    }
    return 0;
}

