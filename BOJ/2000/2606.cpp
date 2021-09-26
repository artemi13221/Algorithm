#include <iostream>
#include <vector>
using namespace std;

void dfs(int start, vector<vector<int>>& g, vector<bool>& visit, int& result)
{
    visit[start] = true;
    result++;

    for (const auto& item : g[start]) {
        if (item == start)
            continue;
        if (!visit[item])
            dfs(item, g, visit, result);
    }
}

int main(void)
{
    int computerCount = 0;
    cin >> computerCount;

    int result = 0;
    vector<vector<int>> graph(5000);
    vector<bool> visit(5000);

    int inputCount = 0;
    cin >> inputCount;
    while (inputCount--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // dfs
    dfs(1, graph, visit, result);

    if (result > 0)
        result--;

    cout << result;
}