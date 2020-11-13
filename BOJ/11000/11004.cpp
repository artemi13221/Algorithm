#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int tmp = 0;
        cin >> tmp;

        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    cout << v[k-1];
}