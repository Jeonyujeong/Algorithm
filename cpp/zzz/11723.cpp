#include <iostream>
#include <bitset>
#include <string>
#include <cstring>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    unsigned int set = 0x00000;
    string str;
    int m, x;

    getline(cin, str);
    m = atoi(str.c_str());

    for (int i=0; i<m; i++) {
        getline(cin, str);
        int idx = str.find(' ');
        string order = str.substr(0,idx);
        int x = atoi(str.substr(idx+1).c_str()) - 1;
        
        x = (1<<x);
        if (!order.compare("add")) {
            set |= x;
        }
        else if (!order.compare("remove")) {
            set &= ~x;  // 해당 비트만 0 나머지는 1로 만든뒤 & 연산하기 
        }
        else if (!order.compare("check")) {
            if (set & x) printf("1\n");
            else printf("0\n");
        }
        else if (!order.compare("toggle")) {
            if (set & x) set &= ~x;
            else set |= x;
        }
        else if (!order.compare("all")) {
            set = (0xfffff);
        }
        else if (!order.compare("empty")) {
            set = 0x00000;
        }
        // cout << bitset<20>(set) << endl;
    }

}