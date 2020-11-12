#include <iostream>
using namespace std;
unsigned long long factorial(int n, int m) {
    unsigned long long result = 1;
    for(int i = n; i > (n-m); i--) {
        result *= i;
    }

    return result;
}
int main(void) {
    int num;
    cin >> num;
    int n, m;
    
    for(int i = 0; i < num; i++) {
        cin >> m >> n;
        if(m > (n / 2)) {
            m = n - m;
        }
        cout << factorial(n, m) / factorial(m, m) << "\n";
    } 
}