#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num = 0;
    char ch[51] = "";
    bool isWrong = false;
    cin >> num;

    for(int i = 0; i < num; i++) {
        isWrong = false;
        ch[0] = {0, };
        cin >> ch;
        stack<char> s1;
        size_t size = strlen(ch);

        for(size_t j = 0; j < size; j++) {
            if(ch[j] == '(')
                s1.push(ch[j]);
            else {
                if(!(s1.empty())) {
                    s1.pop();
                }
                else {
                    isWrong = true;
                }
            }
        }

        if(!s1.empty())
            isWrong = true;
        
        cout << (isWrong ? "NO\n" : "YES\n");
    }
}