#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <cctype>
using namespace std;

vector<string> split(string input, char delimeter) {
    stringstream ss(input);
    string tmp;
    vector<string> v;

    while(getline(ss, tmp, delimeter)) {
        v.push_back(tmp);
    }
    return v;
}

int main(void) {

    string inputstr;
    getline(cin, inputstr);
    
    vector<string> v = split(inputstr, ' ');
    string declare_str = v[0];

    for (int i=1; i<v.size(); i++) {
        string var = v[i];
        string new_var = declare_str;

        int idx = 0;
        for (int j=var.length()-2; j>=0; j--) {
            if (isalpha(var[j])) {
                idx = j;
                new_var += " " + var.substr(0,j+1);
                break;
            }
            else {
                if (var[j] == '[') new_var += ']';
                else if (var[j] == ']') new_var += '[';
                else new_var += var[j];
            }
        }
        cout << new_var << ";\n";
    }
}