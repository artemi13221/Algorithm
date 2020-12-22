#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    char arr[11];
    int num;
    int i = 0;

    cin >> num;
    while(num) {
        arr[i++] = (num % 10) - '0';
        num /= 10;
    }
    arr[i] = '\0';

    sort(arr, arr+i, greater<>());

    for(int j = 0; j < i; j++) {
        cout << arr[j] + '0';
    }
}