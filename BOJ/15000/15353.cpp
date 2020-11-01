#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string tmp = "";
    int a[10002] = {0, };
    int b[10002] = {0, };
    int add = 0;
    bool isPrint = false;
    cin >> tmp;
    int c = tmp.size();
    int count = c - 1;
    for(int i = 10001; i > 10001 - c; i--) {
        a[i] = tmp[count--] - '0';
    }
    cin >> tmp;
    c = tmp.size();
    count = c - 1;
    for(int i = 10001; i > 10001 - c; i--) {
        b[i] = tmp[count--] - '0';
    }
    for(int i = 10001; i >= 0; i--) {
        a[i] += add;
        add = a[i] + b[i];
        a[i] = add % 10;
        add /= 10;
    }
    for(int i = 0; i <= 10001; i++) {
        if(a[i] != 0) {
            isPrint = true;
        }
        if(isPrint)
            cout << a[i];
    }
}