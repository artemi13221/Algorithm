#include <iostream>
using namespace std;

int main(void) {
    int year = 1;
    int E = 1, S = 1, M = 1;
    int inputN[3] = {0, };

    cin >> inputN[0] >> inputN[1] >> inputN[2];
    while(!(E == inputN[0] && S == inputN[1] && M == inputN[2])) {
        if(E++ >= 15)
            E = 1;
        if(S++ >= 28)
            S = 1;
        if(M++ >= 19)
            M = 1;
        year++;
    }

    cout << year;
}