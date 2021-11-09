#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<vector<int>> v(15, vector<int>(16, 1));

    for (int i = 0; i < 15; i++) {
        v[0][i] = i;
    }

    for (int i = 1; i < 15; i++) {
        for (int j = 2; j < 16; j++) {
            v[i][j] = v[i - 1][j] + v[i][j - 1];
        }
    }

    int count;
    cin >> count;

    while (count--) {
        int k, n;
        cin >> k >> n;

        cout << v[k][n] << "\n";
    }

    return 0;
}