#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int line = 0;
    int brand = 0;
    int min_package = 1000, min_danpom = 1000;
    vector<int> arr;
    cin >> line >> brand;

    for(int i = 0; i < brand; i++) {
        int tmp, tmp2;
        cin >> tmp >> tmp2;
        if(tmp < min_package) {
            min_package = tmp;
        }
        if(tmp2 < min_danpom) {
            min_danpom = tmp2;
        }
    }
    int tmp3 = 0, cost = 0;
    while(tmp3 < line) {
        tmp3 += 6;
        cost += min_package;
    }
    arr.push_back(cost);
    tmp3 -= 6;
    cost -= min_package;
    while(tmp3 < line) {
        tmp3 += 1;
        cost += min_danpom;
    }
    arr.push_back(cost);
    tmp3 = 0;
    cost = 0;
    while(tmp3 < line) {
        tmp3 += 1;
        cost += min_danpom;
    }
    arr.push_back(cost);
    int min = *min_element(arr.begin(), arr.end());

    cout << min;
}