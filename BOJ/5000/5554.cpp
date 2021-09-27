#include <iostream>
using namespace std;

int main(void)
{
    int tmp = 0, sum = 0;
    for (int i = 0; i < 4; i++) {
        cin >> tmp;
        sum += tmp;
    }

    cout << sum / 60 << "\n"
         << sum % 60;
}