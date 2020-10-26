#include <iostream>
using namespace std;

int main(void) {
    int a, b;
    int aResult = 0, bResult = 0;
    int i = 100;
    cin >> a >> b;
    while(a) {
        aResult += i * (a % 10);
        a /= 10;
        i /= 10;
    }
    i = 100;
    while(b) {
        bResult += i * (b % 10);
        b /= 10;
        i /= 10;
    }

    aResult >= bResult ? cout << aResult : cout << bResult;
}