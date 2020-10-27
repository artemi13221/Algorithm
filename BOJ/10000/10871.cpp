#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x, n, tmp;
    cin >> n >> x;

    for(int i = 0; i < n; i++) {
        cin >> tmp;
        if(tmp < x)
            cout << tmp << " ";
    }
}