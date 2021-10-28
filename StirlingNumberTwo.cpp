#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    // 제 2 스털링 수
    // S[20, 20]을 구하여라 등
    vector<vector<long long>> dp(21, vector<long long>(21, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= 20; j++) {
            if (j > i) {
                dp[i][j] = 0;
            } else if (j == 0) {
                dp[i][j] = 0;
            } else if (i == j) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j - 1] + j * dp[i - 1][j];
            }
        }
    }

    for (auto& i : dp) {
        for (auto& j : i) {
            cout << j << "\t";
        }
        cout << "\n";
    }

    cout << dp[10][10]; // S[r][n]

    return 0;
}