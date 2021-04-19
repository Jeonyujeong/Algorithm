#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int errN[10];

string up(int cnt, int n, string result) {
    // cout << "up " << n << " " << result << endl;
    if (cnt == 0) return result;
    if (n > 9) return ""; 
    if (errN[n]) {
        return result = up(cnt, n+1, result);
    }

    if (cnt > 0) {
        result += to_string(n);
        result = up(cnt-1, 0, result);
    }
    return result;
}

string down(int cnt, int n, string result) {
    // cout << "down " << n << " " << result << endl;
    if (cnt == 0) return result;
    if (n < 0) return ""; 
    if (errN[n]) {
        return result = down(cnt, n-1, result);
    }

    if (cnt > 0) {
        result += to_string(n);
        result = down(cnt-1, 9, result);
    }
    return result;
}

int main(void) {
    string strN;
    cin >> strN;

    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int e;
        cin >> e;
        errN[e] = 1;    // 1이면 고장
    }

    int min_val = abs(stoi(strN) - 100);

    string result = "";
    for (int i=0; i<strN.length(); i++) {
        int n = strN[i] - '0';
        if (!errN[n]) {
            result += strN[i];
            continue;
        }

        int cnt = strN.length() - i;
        int up_val = 0, down_val = 0;

        string up_str = up(cnt, n+1, result);
        result = up_str;
        if (up_str != "") up_val = stoi(up_str);
        int un = abs(stoi(strN) - up_val);
        min_val = min(min_val, (int)result.length() + un);

        string down_str = down(cnt, n-1, result);
        result = down_str;
        if (down_str != "") down_val = stoi(down_str);
        int dn = abs(stoi(strN) - down_val);
        min_val = min(min_val, (int)result.length() + dn);
        // cout << up_str << ", " << down_str << endl;
        // cout << result.length() << ", " << un << ", " << dn << endl;
        break;
    }
    cout << min_val ;
}