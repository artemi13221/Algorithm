#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arr[101][101] = {{0, }, };
    int num = 0;
    cin >> num;

    for(int i = 0; i < num; i++) {
        int tmp = 0, tmp2 = 0;
        cin >> tmp >> tmp2;

        for(int j = tmp; j < tmp + 10; j++) {
            for(int k = tmp2; k < tmp2 + 10; k++) {
                arr[j][k] = 1;
            }
        }
    }
    int result = 0;
    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= 100; j++) {
            if(arr[i][j] == 1)
                result += 1;
        }
    }

    cout << result;
}