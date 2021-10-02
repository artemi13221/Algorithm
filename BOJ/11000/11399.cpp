#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    size_t count = 0;
    cin >> count;
    vector<int> list;

    for (size_t t = 0; t < count; t++) {
        int tmp;
        cin >> tmp;

        list.push_back(tmp);
    }

    sort(list.begin(), list.end());

    int result = 0;
    int sum = 0;

    for (const auto& item : list) {
        sum += item;
        result += sum;
    }

    cout << result;

    return 0;
}