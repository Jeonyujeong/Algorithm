// BOJ 1244. 스위치 켜고 끄기

#include <iostream>

using namespace std;

int main(void) {
    int n;
    int stat[102] = {0};

    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", &stat[i]);

    int sn;
    scanf("%d", &sn);
    for (int i=1; i<=sn; i++) {
        int gen, num;
        scanf("%d%d", &gen, &num);

        if (gen == 1) {
            for (int j=num; j<=n; j+=num) stat[j] = !stat[j];
        }
        else {
            for (int j=1; j<=n; j++) {
                int l = num - j;
                int r = num + j;

                if (l<1 || r>n) break;
                if (stat[l] == stat[r]) {
                    stat[l] = !stat[l];
                    stat[r] = !stat[r];
                }
                else break;
            }
            stat[num] = !stat[num];
        }
    }
    
    for (int j=1; j<=n; j++) {
        printf("%d ", stat[j]);
        if (j%20 == 0) printf("\n");
    }
        
}