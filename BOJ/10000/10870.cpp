#include <iostream>
using namespace std;

int main(void) {
    int num = 0;
    cin >> num;
    int arr[21] = {0, };
    arr[1] = 1;

    for(int i = 2; i <= num; i++) {
        arr[i] = arr[i-2] + arr[i-1];
    }

    cout << arr[num];
}