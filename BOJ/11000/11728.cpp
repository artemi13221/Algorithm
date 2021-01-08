#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b;
    int c = 0, d = 0;
    cin >> a >> b;
    vector<int> v1;
    vector<int> v2;
    vector<int> result;

    for(int i = 0; i < a; i++) {
        int tmp = 0;
        cin >> tmp;

        v1.push_back(tmp);
    }

    for(int i = 0; i < b; i++) {
        int tmp = 0;
        cin >> tmp;
        
        v2.push_back(tmp);
    }

    for(int i = 0; i < a + b; i++) {
        if(c >= a) {
            result.push_back(v2[d++]);
            continue;
        }
        else if(d >= b) {
            result.push_back(v1[c++]);
            continue;
        }
        if(v1[c] < v2[d]) {
            result.push_back(v1[c++]);
        }
        else {
            result.push_back(v2[d++]);
        }
    }

    for(int i = 0; i < a + b; i++) {
        cout << result[i] << " ";
    }
}