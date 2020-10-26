#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    stack<int> s;
    string str = "";
    int num = 0, tmp = 0;

    cin >> num;
    for(int i = 0; i < num; i++) {
        cin >> str;
        cin.clear();
        cin.ignore();

        if(str == "push") {
            cin >> tmp;
            s.push(tmp);
        }
        else if (str == "pop") {
            if(s.empty()) {
                cout << "-1\n";
            }
            else {
                cout << s.top() << "\n";
                s.pop();
            }
        }
        else if (str == "size") {
            cout << s.size() << "\n";
        }
        else if (str == "empty") {
            cout << s.empty() << "\n";
        }
        else if (str == "top") {
            if(s.empty()) {
                cout << "-1\n";
            }
            else {
                cout << s.top() << "\n";
            }
        }
    }
}