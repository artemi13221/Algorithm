#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int count = 0;
    cin >> count;

    vector<pair<int, int>> fibo(41, make_pair(0, 0));
    fibo[0] = make_pair(1, 0);
    fibo[1] = make_pair(0, 1);

    for (size_t i = 2; i < fibo.size(); i++) {
        fibo[i] = make_pair(fibo[i - 2].first + fibo[i - 1].first, fibo[i - 2].second + fibo[i - 1].second);
    }

    for (int i = 0; i < count; i++) {
        int tmp;
        cin >> tmp;

        cout << fibo[tmp].first << " " << fibo[tmp].second << "\n";
    }

    return 0;
}