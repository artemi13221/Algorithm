#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int totalPok, totalProm;
    cin >> totalPok >> totalProm;
    unordered_map<string, int> um;
    vector<string> v;
    v.push_back("EMPTY");

    for (int i = 0; i < totalPok; i++) {
        string s = "";
        cin >> s;

        um.insert(make_pair(s, i + 1));
        v.push_back(s);
    }

    for (int i = 0; i < totalProm; i++) {
        string s2 = "";
        cin >> s2;

        if (s2[0] >= '0' && s2[0] <= '9') {
            int a = stoi(s2);

            cout << v[a] << "\n";
        } else {
            cout << um[s2] << "\n";
        }
    }

    return 0;
}