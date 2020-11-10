#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    int a, b;
    queue<int> q;
    queue<int> q2;
    cin >> a >> b;

    for(int i = 1; i <= a; i++) {
        q.push(i);
    }

    while(!q.empty()) {
        for(int i = 0; i < b-1; i++) {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        q2.push(q.front());
        q.pop();
    }

    cout << '<';
    for(int i = 0; i < a-1; i++) {
        cout << q2.front() << ", ";
        q2.pop();
    }
    cout << q2.front() << '>';
}