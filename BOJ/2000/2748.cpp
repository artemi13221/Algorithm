#include <iostream>
using namespace std;

int main(void) {
    long long arr[91] = {0, };
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    int num = 0;
    cin >> num;

    for(int i = 3; i <= num; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }

    cout << arr[num];
}