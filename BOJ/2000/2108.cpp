#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
    int num = 0, sum = 0;
    cin >> num;
    vector<int> v;
    vector<int> v2;
    int arr[8001] = {0, };
    for(int i = 0; i < num; i++) {
        int tmp;
        cin >> tmp;
        sum += tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    int maxCount = 0;
    for(int i = 0; i < num; i++) {
        arr[4000 + v[i]] += 1;
        if(arr[4000 + v[i]] > maxCount)
            maxCount = arr[4000+v[i]];
    }
    for(int i = 0; i < num; i++) {
        if(arr[4000 + v[i]] == maxCount && (v2.empty() ? true : v2.back() != v[i])) {
            v2.push_back(v[i]);
        }
    }
    if(v2.size() == 1)
        maxCount = 0;
    else
        maxCount = 1;
    double average = (1.0 * sum) / num;
    average = round(average);
    cout << average << "\n";
    cout << v[num/2] << "\n";
    cout << v2[maxCount] << "\n";
    cout << v[num-1] - v[0] << "\n";
}