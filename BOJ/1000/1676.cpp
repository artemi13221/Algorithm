#include <iostream>
using namespace std;

int main(void) {
    int num;
    int count = 0;
    cin >> num;

    for(int i = 1; i <= num; i++) {
        int tmp = i;
        while(tmp % 5 == 0) {
            if(tmp == 0)
                break;
            tmp /= 5;
            count++;
        }
    }

    cout << count;
}