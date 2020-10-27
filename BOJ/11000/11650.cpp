#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Location {
public:
    int x, y;
    Location(int x, int y):x(x),y(y){}
};

bool compare(Location a, Location b) {
    if(a.x == b.x) {
        return a.y < b.y;
    }
    else {
        return a.x < b.x;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num = 0, xtmp = 0, ytmp = 0;
    vector<Location> v;
    cin >> num;
    for(int i = 0; i < num; i++) {
        cin >> xtmp >> ytmp;
        v.push_back(Location(xtmp, ytmp));
    }
    sort(v.begin(), v.end(), compare);
    for(int i = 0; i < num; i++) {
        cout << v[i].x << " " <<v[i].y << "\n";
    }
}