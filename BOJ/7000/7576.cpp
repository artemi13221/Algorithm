#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(vector<vector<int>>& table, vector<pair<int, int>> start)
{
    int d[][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> visit(table.size(), vector<bool>(table[0].size(), false));
    for (auto& i : start) {
        q.push(make_pair(make_pair(i.first, i.second), 1));
        visit[i.second][i.first] = true;
    }

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int day = q.front().second;
        q.pop();
        table[y][x] = day;

        for (size_t t = 0; t < 4; t++) {
            int dx = x + d[t][0];
            int dy = y + d[t][1];

            if (dy < 0 || dx < 0) {
                continue;
            }
            if (dy >= table.size() || dx >= table[0].size()) {
                continue;
            }
            if ((table[dy][dx] == 0 || table[dy][dx] >= 2) && visit[dy][dx] == false) {
                q.push(make_pair(make_pair(dx, dy), day + 1));
                visit[dy][dx] = true;
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;
    vector<vector<int>> table(b, vector<int>(a, 0));
    vector<pair<int, int>> startLocation; // x, y순으로 저장

    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            cin >> table[i][j];

            if (table[i][j] == 1) {
                startLocation.push_back(make_pair(j, i));
            }
        }
    }

    bfs(table, startLocation);

    int maxValue = 0;
    for (auto& i : table) {
        for (auto& j : i) {
            if (j == 0) {
                maxValue = -1;
                break;
            } else {
                maxValue = max(j, maxValue);
            }
        }
        if (maxValue == -1)
            break;
    }

    cout << (maxValue == -1 ? maxValue : maxValue - 1);

    return 0;
}