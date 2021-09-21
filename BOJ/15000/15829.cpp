#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count = 0;
    long long hash = 0;
    long long r = 1;
    cin >> count;
    
    for (int i = 0; i < count; i++) {
        int tmp = 0;
        tmp = cin.get();
        if (tmp == '\n')
            tmp = cin.get();

        hash += ((((tmp - 96) % 1234567891) * (r % 1234567891)) % 1234567891);
        r = (r*31) % 1234567891;
    }

    cout << hash % 1234567891;
}