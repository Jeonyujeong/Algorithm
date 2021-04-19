#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    vector<pair<int, int>> v;

    scanf("%d", &n);
    int a, b;
    for(int i=0; i<n; i++) {
        scanf("%d %d", &a, &b);
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    int dp[101] = {0};
    int max = 1;
    for(int i=0; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(v[j].second < v[i].second && dp[j]+1 > dp[i]){
                dp[i] = dp[j]+1;
                if(max < dp[i]){
                    max = dp[i];
                }
            }
        }
    }

    printf("%d", n-max);
}