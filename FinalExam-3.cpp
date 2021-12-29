#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class three {
public:
    int a, b, c;
    three(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

class four {
public:
    int a, b, c, d;
    four(int a, int b, int c, int d)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
};

/* // 일반 BFS
int bfs(vector<vector<int>>& v, int startX, int startY)
{
    vector<vector<int>> visited(v.size(), vector<int>(v[0].size(), 0));
    queue<pair<int, int>> q;
    q.push(make_pair(startX, startY));
    visited[startY][startX] = 1;
    int d[][2] = {
        { 0, 1 },
        { 0, -1 },
        { 1, 0 },
        { -1, 0 }
    };

    while (!q.empty()) {
        int nowX = q.front().first;
        int nowY = q.front().second;
        q.pop();

        if ((nowX == v[0].size() - 1) && (nowY == v.size() - 1)) {
            return 1;
        }

        for (int i = 0; i < 4; i++) {
            int nextX = nowX + d[i][0];
            int nextY = nowY + d[i][1];

            if (nextX < 0 || nextY < 0)
                continue;
            if (nextX >= v[0].size() || nextY >= v.size())
                continue;
            if (v[nextY][nextX] == 1 && visited[nextY][nextX] == 0) {
                q.push(make_pair(nextX, nextY));
                visited[nextY][nextX] = 1;
            }
        }
    }

    return -1;
}
*/

// Count 포함 BFS
int bfs(vector<vector<int>>& v, int startX, int startY)
{
    vector<vector<int>> visited(v.size(), vector<int>(v[0].size(), 0));
    queue<three> q;
    q.push(three(startX, startY, 1));
    visited[startY][startX] = 1;
    int d[][2] = {
        { 0, 1 },
        { 0, -1 },
        { 1, 0 },
        { -1, 0 }
    };

    while (!q.empty()) {
        int nowX = q.front().a;
        int nowY = q.front().b;
        int nowCount = q.front().c;
        q.pop();

        if ((nowX == v[0].size() - 1) && (nowY == v.size() - 1)) {
            return nowCount;
        }

        for (int i = 0; i < 4; i++) {
            int nextX = nowX + d[i][0];
            int nextY = nowY + d[i][1];

            if (nextX < 0 || nextY < 0)
                continue;
            if (nextX >= v[0].size() || nextY >= v.size())
                continue;
            if (v[nextY][nextX] == 1 && visited[nextY][nextX] == 0) {
                q.push(three(nextX, nextY, nowCount + 1));
                visited[nextY][nextX] = 1;
            }
        }
    }

    return -1;
}

int heuristicValue(int x2, int y2, int x1, int y1)
{
    return (((y2 - y1) * (y2 - y1)) + ((x2 - x1) * (x2 - x1)));
}

// A*
int aStar(vector<vector<int>>& v, int startX, int startY)
{
    vector<vector<int>> visited(v.size(), vector<int>(v[0].size(), 0));

    auto cmp = [](four s1, four s2) -> bool { return s1.d < s2.d; };
    priority_queue<four, vector<four>, decltype(cmp)> q(cmp);

    q.push(four(startX, startY, 1, heuristicValue(startX, startY, v[0].size(), v.size())));
    visited[startY][startX] = 1;
    int d[][2] = {
        { 0, -1 },
        { 0, 1 },
        { 1, 0 },
        { -1, 0 }
    };

    while (!q.empty()) {
        int nowX = q.top().a;
        int nowY = q.top().b;
        int nowCount = q.top().c;
        int nowHeuValue = q.top().d;

        q.pop();

        if ((nowX == v[0].size() - 1) && (nowY == v.size() - 1)) {
            return nowCount;
        }

        for (int i = 0; i < 4; i++) {
            int nextX = nowX + d[i][0];
            int nextY = nowY + d[i][1];
            int nextHeuValue = heuristicValue(nextX, nextY, v[0].size(), v.size());

            if (nextX < 0 || nextY < 0)
                continue;
            if (nextX >= v[0].size() || nextY >= v.size())
                continue;
            if (v[nextY][nextX] == 1 && visited[nextY][nextX] == 0) {
                q.push(four(nextX, nextY, nowCount + 1, nextHeuValue));
                visited[nextY][nextX] = 1;
            }
        }
    }

    return -1;
}

int main(void)
{
    int y, x;
    cin >> y >> x;

    vector<vector<int>> v(y, vector<int>(x, 0));

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            // cin >> v[i][j];
            char ch = cin.get();
            if (ch == '\n')
                ch = cin.get();
            v[i][j] = ch - '0';
        }
    }

    int inputY = 0, inputX = 0;
    // cin >> inputX >> inputY;

    // bfs

    int result = 0;

    // result = bfs(v, inputX, inputY);

    // cout << result << "\n";

    // A*

    result = aStar(v, inputX, inputY);

    cout << result << "\n";

    return 0;
}