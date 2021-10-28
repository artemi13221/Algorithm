#include <iostream>
#include <vector>
using namespace std;

void bishop(vector<vector<int>>& v, int x, int y)
{
    int dia[4][2] = {
        { 1, -1 },
        { 1, 1 },
        { -1, 1 },
        { -1, -1 }
    };
    v[y][x] = 0;
    int i, j;
    for (int k = 0; k < 4; k++) {
        i = x;
        j = y;
        while (true) {
            i += dia[k][0];
            j += dia[k][1];
            if (i < 0 || j < 0)
                break;
            if (i >= v[0].size() || j >= v.size())
                break;
            v[j][i] = 0;
        }
    }
}

void backTracking(vector<vector<int>> v, int k, int x, int y)
{
}

int main(void)
{
    int n, k;
    while (cin >> n >> k) {
        // while (true) {
        //     vector<vector<int>> v(n, vector<int>(n, 1));
        // }
        vector<vector<int>> v(n, vector<int>(n, 1));
        bishop(v, 0, 0);
        for (auto& i : v) {
            for (auto& j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
}