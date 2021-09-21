#include <iostream>
#include <vector>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long count = 0;
  long long minNamu = 0;
  cin >> count >> minNamu;

  vector<long long> namu(count);
  long long max = 0;
  for (long long i = 0; i < count; i++)
  {
    long long tmp = 0;
    cin >> tmp;

    namu.push_back(tmp);
    max = (max < tmp) ? tmp : max;
  }

  long long result = 0;
  long long low = 0;
  long long high = max;
  long long binary = 0;
  long long tmp = 0;

  while (low <= high)
  {
    binary = (low + high) / 2;
    tmp = 0;

    for (const auto &item : namu)
      tmp += (item - binary) > 0 ? (item - binary) : 0;

    if (minNamu <= tmp)
    {
      if (result < binary)
        result = binary;
      low = binary + 1;
    }
    else
    {
      high = binary - 1;
    }
  }

  cout << result;
}