#include <iostream>
using namespace std;

void isRight(string& s, int& i, int& j)
{
    if (i == s.size()) {
        return;
    }

    if (s[i] == '(') {
        j += 1;
    } else {
        j -= 1;
    }

    i += 1;

    isRight(s, i, j);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count;
    cin >> count;

    while (count--) {

        string s;
        cin >> s;

        bool result = true;
        int i = 0;
        int j = 0;

        isRight(s, i, j);

        if (j == 0) {
            result = true;
        } else {
            result = false;
        }

        cout << (result ? "YES" : "NO") << "\n";
    }
}