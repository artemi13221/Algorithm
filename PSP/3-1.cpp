#include <iostream>
using namespace std;

string s[] = {" of Clubs", " of Diamonds", " of Hearts", " of Spades"};
string deck[53];
int show[53];

void init()
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 13; j++)
    {
      string tmp[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
      deck[i * 13 + j + 1] = tmp[j] + s[i];
    }
  }
}

void initShow()
{
  for (int i = 0; i < 53; i++)
    show[i] = i;
}

void func(int combine[52])
{
  int newDeck[53] = {0};

  for (int i = 1; i < 53; i++)
  {
    newDeck[i] = show[combine[i - 1]];
  }

  for (int i = 1; i < 53; i++)
    show[i] = newDeck[i];

  for (int i = 1; i < 53; i++)
    cout << deck[show[i]] << "\n";
  cout << "\n";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  init();
  initShow();

  int combineDeck[101][52] = {0};
  int combineCount = 0;
  cin >> combineCount;

  for (int j = 0; j < combineCount; j++)
    for (int k = 0; k < 52; k++)
      cin >> combineDeck[j][k];

  int tmp = 0;
  while (cin >> tmp)
    func(combineDeck[tmp - 1]);
}