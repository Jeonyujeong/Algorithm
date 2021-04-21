// 5658. [모의 SW 역량테스트] 보물상자 비밀번호
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <cmath>
using namespace std;

int n, k;
char num[28];
set<int> s;

void hex_num(int len) {
    int cnt = len;
    int val = 0;   

    for (int i=0; i<n; i++) {
        if ('0' <= num[i] && num[i] <= '9') val += pow(16, cnt-1)*(num[i]-'0');
        else if ('A' <= num[i] && num[i] <= 'F') val += pow(16, cnt-1)*(num[i]-'A'+10);
        cnt--;

        if (cnt == 0) {
            s.insert(val);
            cnt = len, val = 0;
        }
    }
}

void rotation() {
    char tmp[28] = {0};
    memcpy(tmp, num, sizeof(num));
    num[0] = tmp[n-1];
    for (int i=1; i<n; i++) num[i] = tmp[i-1];
}

int main(void) {
    int T;
    cin >> T;

    for (int tc=1; tc<=T; tc++) {        
        cin >> n>> k;

        memset(num, 0, sizeof(num));
        s.clear();
        for (int i=0; i<n; i++) cin >> num[i];

        int rotate_cnt = 0;
        int len = n/4;
        while(rotate_cnt <= len) {
            hex_num(len);
            rotation();
            rotate_cnt++;
        }
        
        vector<int> v(s.begin(), s.end());
        sort(v.rbegin(), v.rend());
        
        cout << "#"<<tc << " " << v[k-1] << "\n";
    }
    return 0;
}