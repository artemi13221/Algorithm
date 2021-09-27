#include <deque>
#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    deque<int> d;

    int count = 0;
    cin >> count;
    while (count--) {
        string tmp;
        cin >> tmp;
        if (tmp == "push_back") {
            int tmp2;
            cin >> tmp2;

            d.push_back(tmp2);
        } else if (tmp == "push_front") {
            int tmp2;
            cin >> tmp2;

            d.push_front(tmp2);
        } else if (tmp == "front") {
            if (d.empty())
                cout << "-1\n";
            else
                cout << d.front() << "\n";
        } else if (tmp == "back") {
            if (d.empty())
                cout << "-1\n";
            else
                cout << d.back() << "\n";
        } else if (tmp == "size") {
            cout << d.size() << "\n";
        } else if (tmp == "empty") {
            cout << (d.empty() ? "1" : "0") << "\n";
        } else if (tmp == "pop_front") {
            if (d.empty())
                cout << "-1\n";
            else {
                int tmp2 = d.front();
                d.pop_front();
                cout << tmp2 << "\n";
            }
        } else if (tmp == "pop_back") {
            if (d.empty())
                cout << "-1\n";
            else {
                int tmp2 = d.back();
                d.pop_back();
                cout << tmp2 << "\n";
            }
        }
    }
}