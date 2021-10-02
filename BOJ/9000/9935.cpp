#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    string result = "";
    string s1, s2;

    cin >> s1 >> s2;

    for (size_t i = 0; i < s1.size(); i++) {
        result.push_back(s1[i]);

        if (s1[i] == s2[s2.size() - 1] && result.size() >= s2.size()) {
            for (size_t j = 0; j < s2.size(); j++) {
                if (result[result.size() - 1 - j] == s2[s2.size() - 1 - j]) {
                } else {
                    break;
                }

                if (j == s2.size() - 1) {
                    for (size_t k = 0; k < s2.size(); k++) {
                        result.pop_back();
                    }
                    r
                }
            }
        }
    }

    if (result.empty()) {
        cout << "FRULA";
    } else {
        cout << result;
    }

    return 0;
}