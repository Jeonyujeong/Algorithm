#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> v) {
    for (int i=0; i<v.size(); i++) {
        printf("%d ", v[i]);
    }printf("\n");
}

int main(void) {
    vector<int> v;

    for (int i=0; i<5; i++) {
        int n;
        scanf("%d", &n);
        v.push_back(n);
    }

    while(true) {
        int flag = 0;
        for (int i=0; i<v.size()-1; i++) {
            if (v[i] > v[i+1]) {
                swap(v[i], v[i+1]);
                print(v);
            }
            if (v[i] != i+1) flag = 1;
        }
        if (!flag) break;
    }
}