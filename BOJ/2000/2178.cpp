#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int bfs(vector<string>& miro)
{
    int result = 0;
    int d[4][2] = {
        { -1, 0 },
        { 1, 0 },
        { 0, -1 },
        { 0, 1 }
    };
    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> b(miro.size(), vector<bool>(miro[0].size(), false));
    q.push(make_pair(make_pair(0, 0), 1));

    while (!q.empty()) {
        int x, y;
        x = q.front().first.first;
        y = q.front().first.second;
        int floor = q.front().second;
        q.pop();

        if (b[y][x])
            continue;

        if (x == (miro[0].size() - 1) && y == (miro.size() - 1)) {
            return floor;
        }

        for (auto& i : d) {
            int dx, dy;
            dx = x + i[0];
            dy = y + i[1];

            if (dx < 0 || dy < 0) {
                continue;
            }
            if (dx >= miro[0].size() || dy >= miro.size()) {
                continue;
            }

            if (!b[dy][dx] && miro[dy][dx] == '1') {
                q.push(make_pair(make_pair(dx, dy), floor + 1));
                b[y][x] = true;
            }
        }
    }

    return -1;
}

int main(void)
{
    int maxY, maxX;

    cin >> maxY >> maxX;
    cin.ignore();

    vector<string> miro;
    string input;

    while (getline(cin, input)) {
        miro.push_back(input);
    }

    // bfs
    int result = bfs(miro);

    cout << result;

    return 0;
}