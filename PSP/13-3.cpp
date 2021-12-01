#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int revisionMinus(int a, int y)
{
    if (a - 1 < 0) {
        return y - 1;
    }
    return a - 1;
}

int revisionPlus(int a, int y)
{
    if (a + 1 >= y) {
        return 0;
    }
    return a + 1;
}

int threeMin(int a, int b, int c)
{
    int tmp = min(a, b);
    int tmp2 = min(b, c);
    int result = min(tmp, tmp2);

    return result;
}

int main(void)
{
    int x, y;
    while (cin >> y >> x) {
        vector<vector<int>> v(y, vector<int>(x, 0));
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                cin >> v[i][j];
            }
        }
        vector<vector<int>> dp = { v.begin(), v.end() };
        // Unidirectional TSP
        for (int i = x - 2; i >= 0; i--) {
            int dy = y - 1, dx = i;
            while (dy >= 0) {
                int tmp1 = dp[revisionMinus(dy, y)][dx + 1];
                int tmp2 = dp[dy][dx + 1];
                int tmp3 = dp[revisionPlus(dy, y)][dx + 1];
                int result = threeMin(tmp1, tmp2, tmp3);
                dp[dy][dx] = result + v[dy][dx];

                dy -= 1;
            }
        }

        for (auto& i : dp) {
            for (auto& j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }

        int minValue = 1 << 30;
        int index = 0;
        for (int i = 0; i < y; i++) {
            if (minValue > dp[i][0]) {
                minValue = dp[i][0];
                index = i;
            }
        }
        pair<int, vector<int>> r;
        r.first = dp[index][0];
        for (int i = 1; i <= x; i++) {
            r.second.push_back(index);
            int tmp1 = dp[revisionMinus(index, y)][i];
            int tmp2 = dp[index][i];
            int tmp3 = dp[revisionPlus(index, y)][i];
            int result = threeMin(tmp1, tmp2, tmp3);

            if (index == 0) {
                if (result == tmp2) {
                    index = index;
                } else if (result == tmp3) {
                    index = revisionPlus(index, y);
                } else {
                    index = revisionMinus(index, y);
                }
            } else if (index == y - 1) {
                if (result == tmp3) {
                    index = revisionPlus(index, y);
                } else if (result == tmp1) {
                    index = revisionMinus(index, y);
                } else {
                    index = index;
                }
            } else {
                if (result == tmp1) {
                    index = revisionMinus(index, y);
                } else if (result == tmp2) {
                    index = index;
                } else {
                    index = revisionPlus(index, y);
                }
            }
        }

        for (auto& i : r.second) {
            cout << i + 1 << " ";
        }
        cout << "\n"
             << r.first << "\n";

        // for (auto& i : r) {
        //     cout << i.first << " : ";
        //     for (auto& j: i.second) {
        //         cout << j << " ";
        //     }
        //     cout << "\n";
        // }
    }
}