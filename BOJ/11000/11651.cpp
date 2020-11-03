#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Location {
public:
    int x, y;

    Location(int _x, int _y) {
        x = _x;
        y = _y;
    }
};
bool Compare(Location a, Location b) {
    if(a.y == b.y)
        return a.x < b.x;
    else
        return a.y < b.y;
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num = 0, tmpX, tmpY;
    vector<Location> v;
    cin >> num;

    for(int i = 0; i < num; i++) {
        cin >> tmpX >> tmpY;
        v.push_back(Location(tmpX, tmpY));
    }
    sort(v.begin(), v.end(), Compare);

    size_t size = v.size();
    for(size_t i = 0; i < size; i++) {
        cout << v[i].x << " " << v[i].y << "\n";
    }
}   