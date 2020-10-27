#include <iostream>
using namespace std;

int main(void) {
    int num = 0;
    cin >> num;
    num /= 10;

    switch(num) {
    case 10:
    case 9:
        cout << "A";
        break;
    case 8:
        cout << "B";
        break;
    case 7:
        cout << "C";
        break;
    case 6:
        cout << "D";
        break;
    default:
        cout << "F";
    }
}