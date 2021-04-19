#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    string s;
    cin >> s ;

    int len = s.length();
    vector<char> v(len);
    for (int i=0; i<len; i++) v[i] = s[i];

    int cnt = 0;
    sort(v.begin(), v.end());
    do {
        char cur = v[0];
        int i;
        for (i=1; i<len; i++) {
            if (cur == v[i]) break;
            cur = v[i];
        }
        if (i==len) cnt++;
    } while(next_permutation(v.begin(), v.end()));
    cout << cnt;
}