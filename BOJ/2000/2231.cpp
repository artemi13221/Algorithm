#include <iostream>
using namespace std;

int main(void) {
    int num = 0, temp = 0, sum = 0, result = 0;
    cin >> num;

    for(int i = 0; i <= num; i++) {
        temp = i;
        sum = 0;
        sum += i;
        while(temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }

        if(sum == num) {
            result = i;
            break;
        }
    }

    if(num == sum)
        cout << result;
    else
        cout << 0;
}