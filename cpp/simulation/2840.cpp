#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> v(n,-1);
    int cur = 0;
    int check[26] = {0};
    int flag = 0;
    for (int i=0; i<k; i++) {
        int cnt; char chr;
        scanf("%d %c", &cnt, &chr);

        cur = (cur+cnt) % n;
        if (v[cur] == -1 && !check[chr-'A']) {  // 아무것도 없을때 
            v[cur] = chr-'A';
            check[chr-'A'] = 1;
        }
        else if (v[cur] == chr-'A') continue;
        else {  // 이미 바퀴에 알파벳이 있을 때
            flag = 1;
            break;
        }
    }

    if (flag) {
        printf("!");
        return 0;
    }

    for (int i=0; i<n; i++) {
        if (cur < 0) cur = n-1;
        
        if (v[cur] == -1) printf("?");
        else printf("%c", v[cur]+'A');
        cur--;
    }
}