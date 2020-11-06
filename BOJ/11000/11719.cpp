#include <iostream>
using namespace std;

int main(void) {
    char ch[101] = "";
    while(fgets(ch, 101, stdin)) {
        cout << ch;
    }
}