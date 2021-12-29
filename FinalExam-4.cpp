#include <iostream>
#include <vector>
using namespace std;

int removeCount = 0;
int insertCount = 0;
int replaceCount = 0;
int moveCount = 0;

void print_path(vector<vector<pair<int, int>>>& dp, int i, int j, string s1, string s2)
{
    if (dp[i][j].second == -1)
        return;
    if (dp[i][j].second == 0) {
        print_path(dp, i - 1, j - 1, s1, s2);
        if (s1[i - 1] == s2[j - 1]) {
            moveCount++;
            cout << "M";
        } else {
            replaceCount++;
            cout << "S";
        }
    }
    if (dp[i][j].second == 1) {
        print_path(dp, i, j - 1, s1, s2);
        cout << "I";
        insertCount++;
    }
    if (dp[i][j].second == 2) {
        print_path(dp, i - 1, j, s1, s2);
        cout << "D";
        removeCount++;
    }
}

int main(void)
{
    string s1, s2, tmp;
    cin >> s1 >> s2;
    if (s2.size() > s1.size()) {
        tmp = s1;
        s1 = s2;
        s2 = tmp;
    }
    vector<vector<pair<int, int>>> dp(s2.size() + 1, vector<pair<int, int>>(s1.size() + 1, make_pair(0, -1)));
    int replaceCost = 1; // 대체 Cost dp[i - 1][j - 1]
    int insertCost = 1; // 삽입 Cost dp[i][j - 1]
    int removeCost = 1; // 삭제 Cost dp[i - 1][j]
    int count = 0;

    for (int i = 0; i < dp.size(); i++) {
        dp[i][0].first = i;
        if (i > 0)
            dp[i][0].second = 2;
        else
            dp[i][0].second = -1;
    }

    for (int i = 0; i < dp[0].size(); i++) {
        dp[0][i].first = i;
        if (i > 0)
            dp[0][i].second = 1;
        else
            dp[0][i].second = -1;
    }

    for (int i = 1; i < dp.size(); i++) {
        for (int j = 1; j < dp[0].size(); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
                dp[i][j].second = 0;
            } else {
                int a = dp[i - 1][j].first + removeCost;
                int b = dp[i][j - 1].first + insertCost;
                int c = dp[i - 1][j - 1].first + replaceCost;
                int result = min(min(dp[i - 1][j].first + removeCost, dp[i][j - 1].first + insertCost), dp[i - 1][j - 1].first + replaceCost);

                if (c == result) {
                    dp[i][j].second = 0;
                } else if (b == result) {
                    dp[i][j].second = 1;
                } else {
                    dp[i][j].second = 2;
                }
                dp[i][j].first = result;
            }
        }
    }

    cout << dp[dp.size() - 1][dp[0].size() - 1].first << "\n";

    for (int i = 0; i < dp[0].size(); i++) {
        if (i == 0)
            cout << "\t";
        cout << "\t" << s1[i];
    }
    cout << "\n";
    for (int i = 0; i < dp.size(); i++) {
        if (i == 0) {
            cout << ":\t";
        } else {
            cout << s2[i - 1] << ":\t";
        }
        for (int j = 0; j < dp[0].size(); j++) {
            cout << dp[i][j].first << "\t";
        }
        cout << "\n";
    }
    print_path(dp, dp.size() - 1, dp[0].size() - 1, s1, s2);
    cout << "\n";
    cout << "삭제 작업 횟수 : " << removeCount << "\n";
    cout << "삽입 작업 횟수 : " << insertCount << "\n";
    cout << "대체 작업 횟수 : " << replaceCount << "\n";
    cout << "move 작업 횟수 : " << moveCount << "\n";

    return 0;
}