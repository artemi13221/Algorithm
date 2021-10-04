#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int bfs(int start, vector<vector<int>>& graph)
{
    vector<int> result(graph.size(), 0);
    vector<bool> visit(graph.size(), false);
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));
    visit[start] = true;

    while (!q.empty()) {
        int index = q.front().first;
        int floor = q.front().second;
        result[index] = floor;
        q.pop();

        for (size_t t = 1; t < graph.size(); t++) {
            if (!visit[t] && graph[index][t] == 1) {
                q.push(make_pair(t, floor + 1));
                visit[t] = true;
            }
        }
    }

    int sum = 0;
    for (const auto& item : result) {
        sum += item;
    }

    return sum;
}

int main(void)
{
    int user, count;
    cin >> user >> count;
    vector<vector<int>> graph(user + 1, vector<int>(user + 1, 0));

    for (int i = 0; i < count; i++) {
        int tmp, tmp2;
        cin >> tmp >> tmp2;

        graph[tmp][tmp2] = 1;
        graph[tmp2][tmp] = 1;
    }

    int minIndex = 0;
    int min = INT32_MAX;
    // bfs
    for (int i = 1; i <= user; i++) {
        int result = bfs(i, graph);

        if (min > result) {
            min = result;
            minIndex = i;
        }
    }

    cout << minIndex;

    return 0;
}