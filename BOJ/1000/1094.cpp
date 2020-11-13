#include <iostream>
using namespace std;

int main(void) {
    int x = 64, result = 0;
    int num = 0;
    int count = 0;
    cin >> num;

    while(true) {
        if((x + result) > num)
            x = x >> 1;
        else {
            result += x;
            count++;
        }
        if(result == num) {
            break;
        }
    }

    cout << count;
}