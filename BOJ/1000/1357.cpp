#include <iostream>
using namespace std;

int Rev(int x) {
    int result = 0;
    while(x) {
        result *= 10;
        result += (x % 10);
        x /= 10;
    }

    return result;
}

int main(void) {
    int a, b;
    cin >> a >> b;
    a = Rev(a);
    b = Rev(b);
    int result = Rev(a + b);

    cout << result;
}