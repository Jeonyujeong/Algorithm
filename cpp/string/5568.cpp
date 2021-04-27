#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {    
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int nums[11] = {0};
    int n, k;
    set<string> st;

    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> nums[i];
    }

    for (int i=0; i<(1<<n); i++) {
        vector<int> v;
        int kcnt = 0;

        for (int j=0; j<n; j++) {
            if (i & (1<<j)) {
                kcnt++;
                v.push_back({nums[j]});
            }
        }

        if (kcnt == k) {
            sort(v.begin(), v.end());   // 정렬을 꼭 해줘야 next_permutation이 제대로 돌아간다!!!!!!
            do {
                string new_str = "";

                for (int l=0; l<v.size(); l++) new_str += to_string(v[l]);
                st.insert(new_str);
            } while(next_permutation(v.begin(), v.end()));
        }
    }
    cout << st.size() << "\n";
}