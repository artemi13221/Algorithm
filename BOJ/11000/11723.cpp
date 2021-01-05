#include <iostream>
#include <string>
using namespace std;
int n = 0;

void add(int a) {
    n = (n | (1 << a));
}

void check(int a) {
    if(n & (1 << a)) {
        cout << 1 << "\n";
    }
    else {
        cout << 0 << "\n";
    }
}

void remove(int a) {
    n = (n & ~(1 << a));
}

void toggle(int a) {
    n = n ^ (1 << a);
}

void all(void) {
    n = (1 << 21) - 1;
}

void empty(void) {
    n = 0;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num = 0;
    cin >> num;
    string input;
    for(int i = 0; i < num; i++) {
        cin >> input;
        int tmp = 0;
        if(input == "add") {
            cin >> tmp;
            add(tmp);
        }
        else if(input == "remove") {
            cin >> tmp;
            remove(tmp);
        }
        else if(input == "toggle") {
            cin >> tmp;
            toggle(tmp);
        }
        else if(input == "check") {
            cin >> tmp;
            check(tmp);
        }
        else if(input == "all") {
            all();
        }
        else if(input == "empty") {
            empty();
        }
    }
}