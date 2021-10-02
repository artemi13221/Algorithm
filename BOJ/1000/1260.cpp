#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void dfs(int start, vector<vector<int>>& graph, vector<bool>& visit, vector<int>& result)
{
    result.push_back(start);
    visit[start] = true;

    for (size_t i = 1; i <= graph[start].size(); i++) {
        if (!visit[i] && graph[start][i] == 1) {
            dfs(i, graph, visit, result);
        }
    }
}

vector<int> bfs(int start, vector<vector<int>>& graph)
{
    vector<int> result;
    queue<int> q;
    vector<bool> visit(graph.size(), false);
    q.push(start);
    visit[start] = true;

    while (!q.empty()) {
        int index = q.front();
        result.push_back(index);
        q.pop();

        for (size_t i = 1; i <= graph[index].size(); i++) {
            if (!visit[i] && graph[index][i] == 1) {
                q.push(i);
                visit[i] = true;
            }
        }
    }

    return result;
}

int main(void)
{
    int totalNode = 0;
    int count = 0;
    int start = 0;

    cin >> totalNode >> count >> start;

    vector<vector<int>> graph(totalNode + 1, vector<int>(totalNode + 1, 0));
    for (size_t i = 0; i < count; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        graph[tmp1][tmp2] = 1;
        graph[tmp2][tmp1] = 1;
    }

    // dfs
    vector<int> result;
    vector<bool> visit(totalNode + 1, false);

    dfs(start, graph, visit, result);

    for (const auto& item : result) {
        cout << item << " ";
    }
    cout << "\n";

    // bfs

    result = bfs(start, graph);
    for (const auto& item : result) {
        cout << item << " ";
    }

    return 0;
}