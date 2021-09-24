#include <iostream>
#include <vector>
using namespace std;

int d[4][2] = { { 1, 0 }, { 0, -1 }, { -1, 0 }, { 0, 1 } };

void dfs(int x, int y, vector<vector<int>>& location)
{
    location[x][y] = 2;
    for (int i = 0; i < 4; i++) {
        if (x + d[i][0] < 0 || y + d[i][1] < 0)
            continue;
        if (x + d[i][0] >= location.size() || y + d[i][1] >= location[0].size())
            continue;
        if (location[x + d[i][0]][y + d[i][1]] == 1) {
            dfs(x + d[i][0], y + d[i][1], location);
        }
    }
}

int countCar(int maxX, int maxY, vector<vector<int>>& location)
{
    int result = 0;
    for (int i = 0; i < maxX; i++) {
        for (int j = 0; j < maxY; j++) {
            if (location[i][j] == 1) {
                result++;
                dfs(i, j, location);
            }
        }
    }

    return result;
}

int main(void)
{
    int testCase = 0;
    cin >> testCase;

    for (int tCase = 0; tCase < testCase; tCase++) {
        int maxX, maxY, count;
        cin >> maxX >> maxY >> count;
        vector<vector<int>> location(maxX, vector<int>(maxY, 0));

        for (int i = 0; i < count; i++) {
            int x, y;
            cin >> x >> y;

            location[x][y] = 1;
        }

        // bfs
        int result = countCar(maxX, maxY, location);

        cout << result << "\n";
    }

    return 0;
}