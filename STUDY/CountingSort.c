#include <stdio.h>
// 카운팅 정렬에 대해서 공부해보자.
int main(void) {
    int arr[10] = {0, }; // 들어오는 숫자는 0~9까지만 가정
    int tmp[10] = {0, }; // 총 숫자(10까지)
    int com_sort[10] = {0, }; // 정렬된 배열
    int num = 0;
    printf("개수 : ");
    scanf("%d", &num);

    for(int i = 0; i < num; i++) { //정렬할 배열을 입력받는 과정.
        printf("숫자 입력(0~9) : ");
        int temp = 0;
        scanf("%d", &temp);
        tmp[i] = temp;
        arr[temp] += 1; // 입력받은 n을 배열[n]에 차례로 저장
    }

    for(int i = 1; i < num; i++) {
        arr[i] += arr[i-1]; 
    }

    for(int i = num - 1; i > 0; i--) {
        int temp = tmp[i];
        com_sort[--(arr[temp])] = temp;
    }

    for(int i = 0; i < num; i++) {
        printf("%d ", com_sort[i]);
    }
}