#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& v, int x, int y)
{
    if (x < 0 || y < 0)
        return;
    if (y >= v[0].size() || x >= v.size())
        return;

    if (v[x][y] == 0) {
        v[x][y] = 2;

        dfs(v, x + 1, y);
        dfs(v, x, y + 1);
        dfs(v, x - 1, y);
        dfs(v, x, y - 1);
    }
    return;
}

int maxfind(vector<vector<int>>& v, int m, int n)
{
    int result = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // cout << v[i][j] << " ";
            if (v[i][j] == 0)
                result++;
        }
        // cout << "\n";
    }
    // cout << result << "\n\n";
    return result;
}

int main(void)
{
    int m, n;
    cin >> m >> n;
    int result = 0;
    vector<vector<int>> v(m, vector<int>(n, 0));
    vector<pair<int, int>> virus;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;

            if (tmp == 2) {
                virus.push_back(make_pair(i, j));
            }

            v[i][j] = tmp;
        }
    }

    int i = 0, j = 0;
    for (int first = 0; first < m * n; first++) {
        i = first / n;
        j = first % n;

        if (v[i][j] != 0)
            continue;

        v[i][j] = 1;
        int i2 = 0, j2 = 0;
        for (int sec = first + 1; sec < m * n; sec++) {
            i2 = sec / n;
            j2 = sec % n;

            if (v[i2][j2] != 0)
                continue;

            v[i2][j2] = 1;
            int i3 = 0, j3 = 0;
            for (int th = sec + 1; th < m * n; th++) {
                i3 = th / n;
                j3 = th % n;

                if (v[i3][j3] != 0)
                    continue;

                v[i3][j3] = 1;

                vector<vector<int>> v2(m, vector<int>(n, 0));
                // dfs
                copy(v.begin(), v.end(), v2.begin());

                for (auto& item : virus) {
                    dfs(v2, item.first + 1, item.second);
                    dfs(v2, item.first, item.second + 1);
                    dfs(v2, item.first - 1, item.second);
                    dfs(v2, item.first, item.second - 1);
                }

                int find = maxfind(v2, m, n);
                result = max(find, result);

                v[i3][j3] = 0;
            }
            v[i2][j2] = 0;
        }
        v[i][j] = 0;
    }

    cout << result;

    return 0;
}