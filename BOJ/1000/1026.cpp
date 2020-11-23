#include <iostream>
#include <algorithm>
using namespace std;
bool Compare(int x, int y) {
    return x > y;
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[50] = {0, };
    int arr2[50] = {0, };
    int result = 0;
    int num;
    cin >> num;

    for(int i = 0; i < num; i++) {
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }

    for(int i = 0; i < num; i++) {
        int tmp;
        cin >> tmp;
        arr2[i] = tmp;
    }
    sort(arr, arr+num);
    sort(arr2, arr2+num, Compare);

    for(int i = 0; i < num; i++) {
        result += arr[i] * arr2[i];
    }

    cout << result;
}