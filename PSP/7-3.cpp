#include <iostream>
#include <vector>
#define MAX_SIZE 100
using namespace std;

int main(void)
{
    vector<vector<int>> hanoi;
    vector<int> zero = stringToArray("0");
    vector<int> one = stringToArray("1");
    hanoi.push_back(zero);
    hanoi.push_back(one);

    for (int i = 2; i <= 10000; i++) {
        vector<int> tmp = arrayAddArray(hanoi[i - 1], hanoi[i - 1]);
        tmp = arrayAddArray(tmp, one);
        hanoi.push_back(tmp);
    }

    for (int i = 0; i < hanoi.size(); i++) {
        for (auto& j : hanoi[i]) {
            cout << j;
        }
        cout << "\n";
    }

    return 0;
}