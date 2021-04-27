#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

bool cmp(string a, string b) {
    if (a.length() != b.length()) return a.length() < b.length();
    return a < b;
}

int main(void) {    
    int n; 
    cin >> n;

    set<string> s;
    for (int i=0; i<n; i++) {
        string str;
        cin >> str;
        s.insert(str);
    }
    
    vector<string> v(s.begin(), s.end());
    sort(v.begin(), v.end(), cmp);

    for (int i=0; i<v.size(); i++) {
        cout << v[i] << "\n";
    }
}