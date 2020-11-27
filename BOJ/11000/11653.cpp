#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num = 0;
    cin >> num;
    int i = 2;
    while(num > 1) {
        if(num % i == 0) {
            cout << i << "\n";
            num /= i;
        }
        else {
            i++;
        }
    }
}