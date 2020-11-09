#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int x, y;
    cin >> x >> y;
    int arr[50] = {0, };
    int count = 0;
    int a = x;
    int b = 0;
    while(true) {
        arr[count++] = a;
        a = a * x % y;
        for(int i = 0; i < count; i++) {
            if(a == arr[i]) {
                b = i;
            }
        }
        if(b != 0)
            break;
    }
    cout << count - b;
}