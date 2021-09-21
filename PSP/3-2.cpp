#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int count = 0;
  cin >> count;
  for (int start = 1; start <= count; start++)
  {
    int n, m;
    cin >> n >> m;

    unordered_map<string, pair<int, int>> table;
    vector<vector<int>> graph;
    vector<string> indexToName;
    vector<int> connectInfo;
    int index = 0;
    cin.ignore(); // getline이 바로 종료되는 것을 막아준다.

    // 한 줄 입력받기
    for (int j = 0; j < n; j++)
    {
      string s;
      int prev = 0;
      connectInfo.clear();

      getline(cin, s);
      // 이름 구분
      for (int k = 0; k < s.length() - 1; k++)
      {
        if (s[k] == '.' && (s[k + 1] == ',' || s[k + 1] == ':'))
        {
          string name = "";
          for (int l = prev; l <= k; l++)
            name += s[l];
          prev = k + 3;
          k = k + 2;
          if (!table.count(name))
          {
            indexToName.push_back(name);
            table.insert(make_pair(name, make_pair(index++, -1)));
          }
          connectInfo.push_back(table[name].first);
        }
        if (s[k] == ':')
          break;
      }
      graph.resize(table.size());

      // Graph 배열 채우기 (List방식)
      for (const auto &item1 : connectInfo)
        for (const auto &item2 : connectInfo)
          if (item1 != item2)
            graph[item1].push_back(item2);
    }

    // bfs 시작
    vector<bool> visit(graph.size(), false);
    string name = "Erdos, P.";
    queue<pair<int, int>> q;
    if (table.count(name))
    {
      q.push(make_pair(table[name].first, 0));
      visit[table[name].first] = true;
    }
    while (!q.empty())
    {
      int x = q.front().first;
      int newIndex = q.front().second;
      table[indexToName[x]].second = newIndex;
      q.pop();

      for (int y = 0; y < graph[x].size(); y++)
      {
        int newNode = graph[x][y];
        if (!visit[newNode])
        {
          q.push(make_pair(newNode, newIndex + 1));
          visit[newNode] = true;
        }
      }
    }

    cout << "Scenario " << start << "\n";
    for (int k = 0; k < m; k++)
    {
      name = "";
      getline(cin, name);
      int result = table[name].second;

      if (result == -1 || result == 0)
        cout << name << " infinity\n";
      else
        cout << name << " " << table[name].second << "\n";
    }
  }
}
