#include <iostream>
using namespace std;

int func(string &source, string &dist)
{
  int result = 0;
  int one = 0, zero = 0;
  for (int i = 0; i < source.length(); i++)
  {
    if (source[i] == dist[i])
      continue;
    if (source[i] == '1')
      one++;
    else
      zero++;
  }
  result = min(one, zero);
  result += (one >= zero) ? one - zero : zero - one;

  return result;
}

int main()
{
  int count = 0;
  cin >> count;

  for (int i = 0; i < count; i++)
  {
    string source;
    string dist;

    cin >> source >> dist;

    cout << func(source, dist) << "\n";
  }

  return 0;
}