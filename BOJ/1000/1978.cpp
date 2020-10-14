#include <iostream>
using namespace std;
bool isPrime(int a);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num, temp, result = 0;
    cin >> num;

    for(int i = 0; i < num; i++) {
        cin >> temp;
        if(isPrime(temp))
            result++;
    }

    cout << result;
}

bool isPrime(int a) {
    bool result = true;
    if(a < 2)
        result = false;

    for(int i = 2; i * i <= a; i++) {
        if(a % i == 0) {
            result = false;
            break;
        }
    }

    return result;
}