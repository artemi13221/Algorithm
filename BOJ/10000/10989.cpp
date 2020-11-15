#include <iostream>
using namespace std;

int main(void) {
    int arr[10001] = {0, };
    int num = 0;

    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        int tmp = 0;
        scanf("%d", &tmp);
        arr[tmp] += 1;
    }

    int i = 0;
    while(i <= 10000) {
        if(arr[i] > 0) {
            printf("%d\n", i);
            arr[i] -= 1;
        }
        else {
            i++;
        }
    }
}