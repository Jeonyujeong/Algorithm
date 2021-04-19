#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> split(string str, char delimiter) {

    stringstream ss(str);
    string tmp;
    vector<int> v;

    while(getline(ss, tmp, delimiter)) {
        v.push_back(stoi(tmp));
    }

    return v;
}

int main(void) {

    string input = "1,2,3,4,5,6";
    vector<int> v = split(input, ',');

    for (int i=0; i<v.size(); i++) 
        cout << v[i] << endl;
}