#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int num, tmp;
    vector<double> v;
    cin >> num;
    for(int i = 0; i < num; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    double max = v[num-1];
    double average = 0;
    for(int i = 0; i < num; i++) {
        if(max <= 0)
            break;
        else
            average += (v[i] / max * 100);
    }

    cout << average / num << "\n";
}