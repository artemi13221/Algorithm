#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    vector<int> v;
    int count = 0;
    v.push_back(1);
    for(int i = 1; count <= 1000; i++) {
        for(int j = 1; j <= i; j++) {
            v.push_back(i);
            count++;
        }
    }

    int a, b;
    cin >> a >> b;
    int result = 0;
    for(int i = a; i <= b; i++) {
        result += v[i];
    }

    cout << result;
}