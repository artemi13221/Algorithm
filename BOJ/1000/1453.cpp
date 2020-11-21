#include <iostream>
using namespace std;

int main(void) {
    int arr[101] = {0, };
    int num;
    int cnt = 0;
    cin >> num;

    for(int i = 0; i < num; i++) {
        int tmp;
        cin >> tmp;
        if(arr[tmp] == 1) {
            cnt++;
        }else {
            arr[tmp] = 1;
        }
    }


    cout << cnt;
}