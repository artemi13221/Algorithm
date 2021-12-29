/*
 ^ 젓가락 (Chopsticks)
 ^
 ^ 2021.Dec.6
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class three {
public:
    int a, b, c;
    three(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

bool cmp(three a, three b)
{
    return a.a < b.a;
}

int main(void)
{
    int tCase = 0;
    cin >> tCase;
    while (tCase--) {
        int person = 0;
        int stickCount = 0;
        cin >> person >> stickCount;
        vector<int> chop(stickCount, 0);
        vector<int> cnt(32001, 0);
        for (int i = 0; i < stickCount; i++) {
            cin >> chop[i];
            cnt[chop[i]] += 1;
        }

        cnt.resize(chop[chop.size() - 1] + 1);
        // // Bad
        // vector<int> badCase(stickCount, 0);

        // for (int i = 1; i < stickCount; i++) {
        //     badCase[i] = (chop[i + 1] - chop[i]) * (chop[i + 1] - chop[i]);
        // }

        // sort(chop.begin(), chop.end());
        // // DP
        // vector<vector<int>> dp(stickCount, vector<int>(stickCount, 9999999));

        // for (int i = 0; i <)
        // for (int i = 1; i < stickCount; i++) {
        //     for (int j = i * 3; j <= stickCount; j++) {
        //         dp[i][j] = min(dp[i][j + 1], dp[i - 1][j + 2] + badCase[j]);
        //     }
        // }

        // for (int i = 0; i < stickCount; i++) {
        //     for (int j = 0; j < stickCount; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        vector<three> v;

        for (int i = 0; i < stickCount - 1; i++) {
            int a = chop[i + 1] - chop[i];
            v.push_back(three(a, chop[i], chop[i + 1]));
        }

        sort(v.begin(), v.end(), cmp);
        int sum = 0;
        for (int i = 0; i < person + 8; i++) {
            if (i >= v.size())
                break;

            if (cnt[v[i].b] == 0 || cnt[v[i].c] == 0) {
                person += 1;
                continue;
            }
            int saveData = 0;
            bool noAns = 0;

            // cnt[v[i].b]--;
            // cnt[v[i].c]--;
            // for (int j = v[i].c; j < cnt.size(); j++) {
            //     if (cnt[j] >= 1) {
            //         noAns = 1;
            //         saveData = j;
            //         break;
            //     }
            // }
            // cnt[v[i].c]++;
            // cnt[v[i].b]++;

            for (int j = cnt.size() - 1; j >= v[i].c; j--) {
                if (cnt[j] >= 1) {
                    noAns = 1;
                    saveData = j;
                    break;
                }
            }

            if (noAns) {
                // cout << i << " " << v[i].a << " " << v[i].b << " " << v[i].c << " " << saveData << "\n";
                cnt[v[i].b]--;
                cnt[v[i].c]--;
                cnt[saveData]--;
                sum += (v[i].a * v[i].a);
            } else {
                person++;
            }
        }

        cout << sum << "\n";
    }
}