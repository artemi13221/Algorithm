#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

bool campare(const vector<int> &v1, const vector<int> &v2)
{
  if (v1[1] == v2[2])
    return v1[2] > v2[2];
  else
    return v1[1] > v2[1];
}

vector<string> split(string input, char ch)
{
  vector<string> result;
  stringstream ss(input);
  string tmp;

  while (getline(ss, tmp, ch))
  {
    result.push_back(tmp);
  }

  return result;
}

int main(void)
{
  vector<vector<int>> correct;
  vector<vector<int>> incorrect;
  vector<bool> attend(101, false);

  do
  {
    string tmp;
    getline(cin, tmp);

    if (tmp == "")
      break;

    vector<string> s = split(tmp, ' ');

    if (!s.empty())
    {
      attend[stoi(s[0])] = true;
      if (s[3] == "C")
      {
        bool isRetry = false;
        vector<int> tmp;
        for (int i = 0; i < 3; i++)
          tmp.push_back(stoi(s.at(i)));
        int time = 0;
        for (const auto &item : incorrect)
        {
          if (item[0] == tmp[0] && item[1] == tmp[1])
          {
            time += 20;
          }
        }
        tmp[2] += time;
        tmp.push_back(0);
        for (const auto &item : correct)
        {
          if (item[0] == tmp[0] && item[1] == tmp[1])
          {
            isRetry = true;
            break;
          }
        }
        if (!isRetry)
          correct.push_back(tmp);
      }
      else if (s[3] == "I")
      {
        vector<int> tmp;
        for (int i = 0; i < 3; i++)
          tmp.push_back(stoi(s.at(i)));
        incorrect.push_back(tmp);
      }
    }
  } while (true);

  vector<vector<int>> result;
  vector<int> l;
  for (auto &item : correct)
  {
    l.clear();
    if (!item[3])
    {
      item[3] = 1;
      for (int a = 0; a < 3; a++)
        l.push_back(item[a]);
      l[1] = 1;
      for (auto &item2 : correct)
      {
        if (item != item2 && item[0] == item2[0])
        {
          item2[3] = 1;
          l[1]++;
          l[2] += item2[2];
        }
      }
    }
    if (!l.empty())
    {
      result.push_back(l);
      attend[l[0]] = false;
    }
  }

  for (size_t t = 1; t < attend.size(); t++)
  {
    if (attend[t])
    {
      vector<int> l;
      l.push_back(t);
      l.push_back(0);
      l.push_back(0);
      result.push_back(l);
    }
  }

  sort(result.begin(), result.end(), campare);

  for (const auto &item : result)
  {
    for (const auto &item2 : item)
    {
      cout << item2 << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}