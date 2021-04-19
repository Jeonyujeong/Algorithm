#include <iostream>

using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);

    if (n == 1 || n == 3) printf("SK");
    else if (n == 2) printf("CY");
    else {
        if (n%2 == 0) printf("CY");
        else printf("SK");
    }
}