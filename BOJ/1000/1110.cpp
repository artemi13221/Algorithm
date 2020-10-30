#include <iostream>
using namespace std;

int main(void) {
    int n, count = 0, tmp = 0, sum = 0, fist = 0, ten = 0;
    cin >> n;
    tmp = n;
    while(true) {
        count++;
        sum = 0;
        fist = tmp % 10;
        tmp /= 10;
        ten = tmp % 10;
        sum = fist + ten;
        tmp = 10 * fist + sum % 10;
        if(tmp == n)
            break;
    }

    cout << count;
}