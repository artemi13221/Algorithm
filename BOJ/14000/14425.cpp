#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    set<string> s;
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;

        s.insert(tmp);
    }

    int count = 0;
    for(int i = 0; i < M; i++) {
        string tmp;
        cin >> tmp;

        if(s.find(tmp) != s.end()) {
            count++;
        }
    }

    cout << count;
}