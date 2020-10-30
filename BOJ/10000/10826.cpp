#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arr[2091] = {0, };
    int arr2[2091] = {0, };
    int add = 0;
    int num = 0;
    arr[2090] = 0;
    arr2[2090] = 1;
    cin >> num;
    if(num > 0) {
        for(int j = 0; j < num; j++) {
            for(int i = 2090; i >= 0; i--) {
                arr[i] += add;
                add = arr[i] + arr2[i];
                arr[i] = arr2[i];
                arr2[i] = add % 10;
                add /= 10;
            }
        }
        for(int i = 0; i < 2091; i++) {
            if(arr[i] != 0) {
                num = i;
                break;
            }    
        }
        for(int i = num; i < 2091; i++) {
            cout << arr[i];
        }
    }
    else {
        cout << 0;
    }
}