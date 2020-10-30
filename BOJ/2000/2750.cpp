#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num = 0, tmp;
    cin >> num;
    vector<int> v;

    for(int i = 0; i < num; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < num; i++) {
        cout << v[i] << "\n";
    }
}