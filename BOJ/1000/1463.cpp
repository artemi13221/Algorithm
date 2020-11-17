#include <iostream>
using namespace std;

int main(void) {
    int arr[1000001] = {0, };
    arr[1] = 0;
    int num = 0;
    cin >> num;

    for(int i = 2; i <= num; i++) {
        arr[i] = arr[i - 1] + 1;
        if(i % 2 == 0) {
            if(arr[i] > (arr[i/2] + 1)) {
                arr[i] = arr[i/2] + 1;
            }
        }
        if(i % 3 == 0) {
            if(arr[i] > (arr[i/3] + 1)) {
                arr[i] = arr[i/3] + 1;
            }
        }
    }

    cout << arr[num];
}