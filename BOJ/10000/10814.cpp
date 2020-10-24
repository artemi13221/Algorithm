#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    multimap<int, string> mm;
    int a, tmp;
    string str;

    cin >> a;
    for(int i = 0; i < a; i++) {
        cin >> tmp;
        cin >> str;
        cin.clear();
        cin.ignore();

        mm.insert(pair<int, string>(tmp, str));
    }

    for(auto i = mm.begin(); i != mm.end(); i++) {
        cout << i->first << " " << i->second << "\n";
    }
}