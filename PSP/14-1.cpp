/* 
 * 서로 다른 부분열 (distinct Subsequences)
 * 
 * 2021.Dec.1
 */

#include <iostream>
#include <vector>
using namespace std;

int result;

void subsequences(string s1, string s2, int count, int index)
{
    if (count == s2.length()) {
        result++;
        return;
    }
    for (int i = index; i < s1.length(); i++) {
        if (s2[count] == s1[i]) {
            subsequences(s1, s2, count + 1, i + 1);
        }
    }
}

int main(void)
{
    int tCase = 0;
    cin >> tCase;
    while (tCase--) {
        result = 0;
        string s1;
        string s2;
        cin >> s1 >> s2;

        subsequences(s1, s2, 0, 0);

        cout << result << "\n";
    }
}