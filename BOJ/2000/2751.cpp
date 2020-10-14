#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    vector<int> v;
    int temp, num;
    scanf("%d", &num);
    
    for(int i = 0; i < num; i++) {
        scanf("%d", &temp);
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < num; i++) printf("%d\n", v[i]);
}