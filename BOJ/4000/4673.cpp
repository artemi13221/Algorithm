#include <iostream>
using namespace std;

int main(void) {
    int arr[10001] = {0, };
    int n = 0;
    int i = 0;
    int cnt = 0;
    while(n <= 10000) {
        i = n;
        int tmp = n;
        while(i) {
            tmp += i % 10;
            i /= 10;
        }
        if(tmp <= 10000) {
            arr[tmp] = 1;
        }
        n++;
    }
    for(int i = 1; i <= 10000; i++) {
        if(arr[i] == 0)
            cout << i << "\n";
    }
}