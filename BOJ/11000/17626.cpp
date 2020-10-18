#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int num = 0, count = 1;
    vector<int> v;
    cin >> num;
    for(int i = 0; i * i <= num; i++) {
        for(int j = 0; j * j <= num; j++) {
            for(int k = 0; k * k <= num; k++) {
                if((i*i + j*j + k*k) == num) {
                    if(i == 0 && j == 0)
                        count = 1;
                    else if(i == 0)
                        count = 2;
                    else
                        count = 3;
                    v.push_back(count);
                }
            }
        }
    }
    if(v.empty())
        v.push_back(4);
    
    int min = *min_element(v.begin(), v.end());

    cout << min;
}