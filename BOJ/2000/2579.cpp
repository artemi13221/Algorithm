#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int count = 0;
    cin >> count;
    vector<int> input;
    vector<int> dp(count, 0);

    for (int i = 0; i < count; i++) {
        int tmp;
        cin >> tmp;

        input.push_back(tmp);
    }

    dp[0] = input[0];
    if (input.size() > 1) {
        dp[1] = input[0] + input[1];
    }
    if (input.size() > 2) {
        dp[2] = ((input[0] + input[2]) >= (input[1] + input[2]) ? (input[0] + input[2]) : (input[1] + input[2]));
    }

    for (size_t i = 3; i < input.size(); i++) {
        if (dp[i - 2] + input[i] >= dp[i - 3] + input[i - 1] + input[i]) {
            dp[i] = dp[i - 2] + input[i];
        } else {
            dp[i] = dp[i - 3] + input[i - 1] + input[i];
        }
    }

    cout << dp[dp.size() - 1];

    return 0;
}