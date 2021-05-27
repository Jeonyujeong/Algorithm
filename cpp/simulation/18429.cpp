#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);

    int warr[51] = {0};
    int no[51] = {0};
    for (int i=0; i<n; i++) {
        scanf("%d", &warr[i]);
        no[i] = i;
    }

    int res = 0;
    do {
        int curw = 500;
        int i;

        for (i=0; i<n; i++) {
            curw += warr[no[i]];
            curw -= k;
            
            if (curw < 500) break; 
        }
        
        if (i == n) res++;

    } while (next_permutation(no, no+n));
    
    printf("%d", res);
}