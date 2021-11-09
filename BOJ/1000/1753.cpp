#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MyCompareClass {
public:
    bool operator()(pair<int, int> s1, pair<int, int> s2)
    {
        return s1.second > s2.second;
    }
};

vector<int> dijkstra(int start, vector<vector<pair<int, int>>> graph)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, MyCompareClass> pq;
    vector<int> dp(graph.size(), 1999999999);

    // 시작점 설정
    dp[start] = 0;
    pq.push(make_pair(start, 0));

    // 큐 무한반복
    while (!pq.empty()) {
        pair<int, int> queueInfo = pq.top();
        pq.pop();

        int vertex = queueInfo.first;
        int distance = queueInfo.second;

        // 이미 갱신된 데이터라면 탈출한다
        if (dp[vertex] < distance) {
            continue;
        }

        // 인접한 노드들을 순회
        for (int i = 0; i < graph[vertex].size(); i++) {
            // dp 갱신 및 큐에 삽입
            int nextVertex = graph[vertex][i].first;
            int nextDistance = graph[vertex][i].second + distance;

            if (dp[nextVertex] > nextDistance) {
                dp[nextVertex] = nextDistance;
                pq.push(make_pair(nextVertex, nextDistance));
            }
        }
    }

    return dp;
}
/*

1 -> [2, 2], [3, 3]
2 -> [3, 4], [4, 5]
3 -> [4, 6]
4 ->
5 -> [1, 1]


*/

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V, E;
    int start;

    cin >> V >> E >> start;

    vector<vector<pair<int, int>>> graph(V + 1);

    for (int i = 1; i <= E; i++) {
        int u, v, w;

        cin >> u >> v >> w;

        graph[u].push_back(make_pair(v, w));
    }

    // Go 다익스트라
    // BFS

    vector<int> result = dijkstra(start, graph);

    for (int i = 1; i < result.size(); i++) {
        if (result[i] == 1999999999) {
            cout << "INF\n";
        } else {
            cout << result[i] << "\n";
        }
    }
}