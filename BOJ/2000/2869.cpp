#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, v, tmp = 0, count = 0;
    cin >> a >> b >> v;

    tmp = v - a - 1;
    count = tmp / (a-b) + 1;
    if(a == v)
        count = 0;
    cout << count + 1;
}