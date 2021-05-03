#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

int main(void) {    
    char str[51];
    scanf("%s", str);

    int len = strlen(str);
    int result = 0, tmpsum = 0;
    int p = 1, num = 0;

    for (int i=len-1; i>=0; i--) {
        if (str[i] == '-') {
            tmpsum += num;
            result -= tmpsum;
            
            tmpsum = 0;
            num = 0; p = 1;
        }   
        else if (str[i] == '+') {
            tmpsum += num;
            num = 0; p = 1;
        } 
        else {
            num += p*(str[i] - '0');
            p *= 10;
        }
    }
    tmpsum += num;
    result += tmpsum;

    printf("%d", result);
}