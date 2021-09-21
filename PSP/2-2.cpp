#include <iostream>
#include <vector>
using namespace std;

char value[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

int *straightFlush(vector<string> &deck) {
  int result = 8;
  char suit = deck[0][1];

  for (int i = 0; i < 5; i++) {
    if (suit != deck[i][1])
      return 0;
  }
  
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j <= 5; j++) {
      if (j == 5)
        return 0;
      if ()
    }
  }
}

int *fourCard() {

}

int *fullHouse() {

}

int *flush() {

}

int *straight() {

}

int *threeCard() {

}

int *twpPair() {

}

int *onePair() {

}

int *highCard() {

}

int whoWin(vector<string> &black, vector<string> &white) {

}

int main(void) {
  string st;
  bool tmp = true;
  string input = "";
  vector<string> black, white;

  while (tmp) {
    black.clear();
    white.clear();
    for (int i = 0; i < 5; i++) {
      if (!tmp)
        break;
      tmp = static_cast<bool>(cin >> input);
      black.push_back(input);
    }

    for (int i = 0; i < 5; i++) {
      if (!tmp)
        break;
      tmp = static_cast<bool>(cin >> input);
      white.push_back(input);
    }
  }

  whoWin(black, white);
}