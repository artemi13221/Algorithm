#include <iostream>
using namespace std;
int gcd(int a, int b) {
    return a % b ? gcd(b, a % b) : b;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num = 0;
    cin >> num;
    int tmp, tmp2;
    for(int i = 0; i < num; i++) {
        cin >> tmp >> tmp2;
        cout << tmp * tmp2 / gcd(tmp, tmp2) << "\n";
    }
}