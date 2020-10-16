#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num, temp = 0;
    cin >> num;
    vector<int> v;
    vector<int> v2;
    string str = "";
    stack<int> s;
    s.push(0);

    for(int i = 0; i < num; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    temp = 1;
    int j = 0;
    while(true) {
        if(j >= num)
            break;
        if(s.top() == v[j]) {
            v2.push_back(s.top());
            str += "-\n";
            s.pop();
            j++;
        }
        else if(s.top() < v[j]) {
            str += "+\n";
            s.push(temp++);
        }
        else
            break;
    }

    if(v == v2)
        cout << str;
    else
        cout << "NO";
}