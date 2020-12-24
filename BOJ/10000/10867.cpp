#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num = 0;
    cin >> num;
    set<int> s;
    for(int i = 0; i < num; i++) {
        int tmp = 0;
        cin >> tmp;
        s.insert(tmp);
    }

    set<int>::iterator iter;
    for (iter = s.begin(); iter != s.end(); ++iter){
        cout << *iter << " ";
    }

}