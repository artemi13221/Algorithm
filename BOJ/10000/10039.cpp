#include <iostream>
using namespace std;

int main(void) {
    int arr[5];
    int sum = 0;

    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
        if(arr[i] < 40) {
            arr[i] = 40;
        }
        sum += arr[i];
    }
    
    sum /= 5;

    cout << sum;
}