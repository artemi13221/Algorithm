#include <iostream>
using namespace std;

int main(void) {
    int arr[1001] = {0, };
    int N, K;
    cin >> N >> K;
    int cnt = 0;
    for(int i = 2; i <= N; i++) {
        if(arr[i] == 0) {
            for(int j = i; j <= N; j = j + i) {
                if(arr[j] == 0) {
                    arr[j] = 1;
                    cnt++;
                    if(cnt == K) {
                        cout << j << "\n";
                    }
                }
            }
        }
    }
}