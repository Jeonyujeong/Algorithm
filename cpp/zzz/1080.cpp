#include <iostream>
#include <algorithm>

using namespace std;

int level[101];
int main(void) {
    int n;
    scanf("%d", &n);

    for (int i=0; i<n; i++) 
        scanf("%d", &level[i]);
    
    int result = 0;
    for (int i=n-1; i>0; i--) {
        if (level[i] <= level[i-1]) {
            int diff = level[i-1] - level[i] + 1;
            level[i-1] -= diff;
            result += diff;
        }
    }
    printf("%d", result);
}