#include <iostream>
#include <vector>
using namespace std;
class Baseball {
public:
    int a, b, c;
    Baseball(int a, int b, int c):a(a),b(b),c(c){}
};

vector<Baseball> v;
vector<Baseball> v2;
int calStrike(Baseball b1, Baseball b2) {
    int strike = 0;
    if(b1.a == b2.a)
        strike++;
    if(b1.b == b2.b)
        strike++;
    if(b1.c == b2.c)
        strike++;
    
    return strike;
}

int calBall(Baseball b1, Baseball b2) {
    int ball = 0;
    if(b1.a == b2.b)
        ball++;
    if(b1.a == b2.c)
        ball++;
    if(b1.b == b2.a)
        ball++;
    if(b1.b == b2.c)
        ball++;
    if(b1.c == b2.a)
        ball++;
    if(b1.c == b2.b)
        ball++;

    return ball;
}

void checkStrikeBall(Baseball ba, int strike, int ball) {
    v2.clear();
    for(Baseball tmp : v) {
        int s, b;
        s = calStrike(tmp, ba);
        b = calBall(tmp, ba);

        if(s == strike && b == ball) {
            v2.push_back(tmp);
        }
    }
    v.swap(v2);
}

int main(void) {
    for(int i = 1; i < 10; i++) {
        for(int j = 1; j < 10; j++) {
            if(i == j)
                continue;
            for(int k = 1; k < 10; k++) {
                if(i == j || k == j || i == k)
                    continue;
                v.push_back(Baseball(i, j, k));
            }
        }
    }
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int base, stri, bal;
        cin >> base >> stri >> bal;
        int a, b, c;
        c = base % 10;
        base /= 10;
        b = base % 10;
        base /= 10;
        a = base % 10;
        Baseball tm = {a, b, c};
        checkStrikeBall(tm, stri, bal);
    }

    cout << v.size();
}