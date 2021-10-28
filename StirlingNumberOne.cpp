#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    // 제 1 스털링 수
    // S[20, 20]을 구하여라 등
    // DP[i][j] = DP[i - 1][j - 1] + (i - 1)DP[i - 1][j];
    vector<vector<long long>> dp(21, vector<long long>(21, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= 20; j++) {
            dp[i][j] = dp[i - 1][j - 1] + (i - 1) * dp[i - 1][j];
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