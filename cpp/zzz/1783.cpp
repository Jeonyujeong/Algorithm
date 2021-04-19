// 1783
// #include <iostream>
// #include <algorithm>

// using namespace std;

// int main(void) {
//     int n, m, result=0;
//     scanf("%d %d", &n, &m);

//     if (n == 1) result = 1;
//     else if (n == 2) result = min((m+1)/2, 4);
//     else {
//         if (m < 7) result = min(m, 4);
//         else result = m - 7 + 5;
//     }
//     printf("%d", result);
// }

// 1449
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
    int n, l;
    scanf("%d %d", &n, &l);

    vector<int> v;
    int p;
    for (int i=0; i<n; i++) {
        scanf("%d", &p);
        v.push_back(p);
    }
    
    sort(v.begin(), v.end());

    int cnt = 0;
    int length = 0;
    int st = v[0]-0.5;
    for (int i=0; i<n; i++) {
        int cur = v[i];
        cnt++;
        int j = i;
        while(cur + l > v[++j] || j == n) i++;
    }
    printf("%d", cnt);
}