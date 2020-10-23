#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m, n;
    int tmp;
    vector<int> mVector;
    vector<int> result(20000001, 0);
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> tmp;
        if(tmp < 0) 
            tmp = 10000000 + (-tmp);
        mVector.push_back(tmp);
    }
    cin >> n;
    for(int i = 0; i < m; i++) {
        result[mVector[i]] += 1;
    }

    for(int i = 0; i < n; i++) {
        cin >> tmp;
        if(tmp < 0) 
            tmp = 10000000 + (-tmp);
        cout << result[tmp] << " ";
    }
}