#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num = 0;
    cin >> num;
    stack<int> s;

    for(int i = 0; i < num; i++) {
        int tmp = 0;
        cin >> tmp;

        if(tmp != 0) {
            s.push(tmp);
        }
        else {
            s.pop();
        }
    }

    int sum = 0;
    int size = s.size();
    for(int t = 0; t < size; t++) {
        sum += s.top();
        s.pop();
    }

    cout << sum;
    
}