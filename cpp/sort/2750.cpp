/* 
    수 정렬하기 
    https://www.acmicpc.net/problem/2750

    문제 : N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
*/

#include <iostream>
using namespace std;

void bubble_sort(int arr[], int N) {
    /* 
        버블 정렬 구현하기
        1. for i => 0 ~ N-1 반복
        2. for j => j 와 j+1 비교
        3. j > j+1 => swap
    */
    int i, j, tmp;

    for (i=N-1; i>0; i--) {         // 0 ~ N-1 번 반복
        for (j=0; j<i; j++) {       // 0 ~ i-1 번까지 검사
            if (arr[j] > arr[j+1]) {    // j 와 j+1 비교
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

void insert_sort(int arr[], int N) {
    /* 
        삽입 정렬 구현하기
        1. for i => 1 ~ N-1 반복
        2. for j => i번째 값(num)과 0 ~ i-1 비교
        3. num < j => 한칸씩 뒤로 이동
           num > j => break; j + 1 위치에 num 삽입
    */
    int i, j, num;

    for (i=1; i<N; i++) {   
        num = arr[i];
    
        for (j=i-1; j>=0; j--) { 
            if (arr[j] > num) {
                arr[j+1] = arr[j];
            }
            else {
                break;
            }
        }
        arr[j+1] = num;
    }
}

int main(void) {
    int N; 
    int arr[1001] = {0};

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
    }    

    bubble_sort(arr, N);
    // insert_sort(arr, N);

    for (int i=0; i<N; i++) {
        printf("%d\n", arr[i]);
    }
}
