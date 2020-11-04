#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int n = 0, arr[50] = {0, };
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if(n == 1) {
        cout << arr[0] * arr[0];
    }
    else {
        cout << (*max_element(arr, arr+n)) * (*min_element(arr, arr+n));
    }
}