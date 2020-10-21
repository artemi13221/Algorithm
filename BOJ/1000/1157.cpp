#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool desc(int a, int b) {
    return a > b;
}
int main(void) {
    bool isOver = false;
    string str = "";
    cin >> str;
    
    int r[100] = {0, };
    for(char a : str) {
        if(a >= 'a' && a <= 'z')
            a -= ('a' - 'A');
        r[a] += 1;
    }
    int max = 65;
    for(int i = 65; i <=90; i++) {
        if(r[max] < r[i])
            max = i;
    }
    for(int i = 65; i <= 90; i++) {
        if(i == max)
            continue;
        if(r[max] == r[i])
            isOver = true;
    }

    if(isOver)
        cout << "?" << "\n";
    else {
        char a = (char)max;
        cout << a << "\n";
    }
}