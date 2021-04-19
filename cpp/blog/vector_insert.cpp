#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {6,7,8};

    v1.insert(v1.begin(), v2.begin()+2, v2.end());

    for (int i=0; i<v1.size(); i++) {
        cout << v1[i] << endl;
    }
}