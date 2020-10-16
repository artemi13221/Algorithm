#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    cin >> m >> n;
    vector<bool> v;
    v.assign(n + 1, true);
    v[1] = false;
    for(int i = 2; i * i <= n; i++) {
        if(v[i]) {
            for(int j = i * i; j <= n; j += i)
                v[j] = false;
        }
    }

    for(int i = m; i <= n; i++) {
        if(v[i])
            std::cout << i << "\n";
    }
}