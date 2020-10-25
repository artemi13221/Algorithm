#include <iostream>
using namespace std;

int main(void) {
    int H = 0, M = 0;
    cin >> H >> M;
    if(M - 45 < 0) {
        if(H - 1 < 0)
            H = 23;
        else
            H -= 1;
        M += 15;
    }
    else {
        M -= 45;
    }

    cout << H << " " << M << "\n";
}