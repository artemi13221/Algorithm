#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num, result = 0;
    cin >> num;

    for(int i = 0; i < num; i++) {
        int H, W, N;
        cin >> H >> W >> N;
        int count = 0;
        for(int i = 1; i <= W; i++) {
            for(int j = 1; j <= H; j++) {
                count++;
                if(N == count) {
                    result = (j * 100) + i;
                }
            }
        }
        cout << result << "\n";
    }
}