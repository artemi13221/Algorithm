#include <iostream>
using namespace std;

int main(void) {
    char ch[2502];
    char findch[52];
    int cnt = 0, findchsize = 0;

    fgets(ch, 2502, stdin);
    fgets(findch, 52, stdin);

    for(int i = 0; ch[i]; i++) {
        if(ch[i] == '\n') {
            ch[i] = '\0';
        }
    }
    for(int i = 0; findch[i]; i++) {
        if(findch[i] == '\n') {
            findchsize = i;
            findch[i] = '\0';
        }
    }

    for(int i = 0; ch[i]; i++) {
        int isFind = 1;
        for(int j = 0; findch[j]; j++) {
            if(ch[i+j] != findch[j]) {
                isFind = 0;
            }
        }
        if(isFind) {
            cnt++;
            i += (findchsize - 1);
        }
    }

    cout << cnt;
}