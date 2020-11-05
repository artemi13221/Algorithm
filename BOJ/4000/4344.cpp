#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num = 0;
    cin >> num;

    for(int i = 0; i < num; i++) {
        int tmp = 0;
        int arr[1000] = {0, };
        int sum = 0;
        int count = 0;
        double result = 0;
        cin >> tmp;
        for(int j = 0; j < tmp; j++) {
            cin >> arr[j];
            sum += arr[j];
        }
        result = sum / tmp;
        for(int j = 0; j < tmp; j++) {
            if(arr[j] > result)
                count++;
        }
        result = 1.0 * count / tmp * 100;
        cout << fixed;
        cout.precision(3);
        cout << result << "%\n";
    }
}