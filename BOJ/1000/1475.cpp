#include <iostream>
using namespace std;

int main(void) {
    int num = 0;
    int arr[10] = {0, };
    cin >> num;

    if(num == 0) {
        arr[0] += 1;
    }
    while(num > 0) {
        arr[num % 10] += 1;
        num /= 10;
    }

    arr[6] += arr[9];
    arr[6] += 1;
    arr[6] /= 2;
    int max = 0;
    for(int i = 0; i < 9; i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }

    cout << max;
}