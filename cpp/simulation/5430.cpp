#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        string p;
        cin >> p;

        int n;
        cin >> n;
        string input;
        cin >> input;

        int len = input.length()-1;
        input = input.substr(1,len-1);

        deque<int> dq;
        stringstream ss(input);
        string temp;

        while (getline(ss, temp, ',')) {
            dq.push_back(stoi(temp));
        }

        int Rcnt = 0;
        int errorFlag = 0;
        for (int i=0; i<p.length(); i++) {
            if (p[i] == 'R') {
                Rcnt++;
            }
            else  {
                if (dq.empty()) {
                    cout << "error\n" ;
                    errorFlag = 1;
                    break;
                }
                if (Rcnt%2 != 0) dq.pop_back();
                else dq.pop_front();
            }
        }

        if (errorFlag) continue;

        if (!dq.empty()) {
            cout << "[";
            if (Rcnt%2 == 0) {
                cout << dq.front();
                dq.pop_front();

                while(!dq.empty()) {
                    cout << "," << dq.front();
                    dq.pop_front();
                } 
            }
            else {
                cout << dq.back();
                dq.pop_back();

                while(!dq.empty()) {
                    cout << "," << dq.back();
                    dq.pop_back();
                } 
            }
            cout << "]\n";
        }
        else {
            cout << "[]\n";
        }
    }
}