#include <iostream>
#include <vector>
using namespace std;

int exprMult(int n)
{
    int result = 1;
    for (int i = 0; i < n; i++) {
        result *= 2;
    }

    return result;
}

void z(vector<vector<int>>& v, int n, int i, int j)
{
    if (n < 1) {
        // Z
    } else {
        int total = exprMult(n);
    }
}

int main(void)
{
    int n, r, c;
    cin >> n >> r >> c;
    int total = 1;
    total = exprMult(n);
    cout << total << "\n";
    vector<vector<int>> v(total, vector<int>(total, 0));

    int index = 0;
    for (auto& i : v) {
        for (auto& j : i) {
            j = index++;
        }
    }

    for (auto& i : v) {
        for (auto& j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
}