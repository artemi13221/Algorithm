#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    set<string> s;
    vector<string> v;
    vector<string> v2;
    set<string>::iterator iter;
    int num1 = 0, num2 = 0;
    cin >> num1 >> num2;

    for(int i = 0; i < num1; i++) {
        string tmp;
        cin >> tmp;
        s.insert(tmp);
    }

    for(int i = 0; i < num2; i++) {
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < num2; i++) {
        iter = s.find(v[i]);
        if(iter != s.end()) {
            v2.push_back(*iter);
        }
    }

    cout << v2.size() << "\n";
    for(int i = 0; i < v2.size(); i++) {
        cout << v2[i] << "\n";
    }
}