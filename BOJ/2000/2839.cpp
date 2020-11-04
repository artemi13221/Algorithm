#include <iostream>
using namespace std;
int sugar(int n) {
    for(int i = (n / 5); i >= 0; i--) {
        for(int j = 0; j <= (n / 3); j++) {
            if(n == (i * 5) + (j * 3))
                return i;
            else if (n < (i * 5) + (j * 3))
                break;
        }
    }

    return -1;
}
int main(void) {
    int n;
    cin >> n;

    int result = sugar(n);

    if(result != -1) {
        int count = 0;
        if(result != 0)
            count = ((n - (result * 5)) / 3);
        else
            count = n / 3;
        cout << count + result;
    }else {
        cout << -1;
    }
}