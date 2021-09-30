#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> failureFunction(string M);
void kmp(string M, string N, int& findCount, vector<int>& findIndex);

vector<int> failureFunction(string M)
{
    vector<int> stat(M.size() + 1, 0);

    for (size_t i = 2, j = 0; i <= M.length(); i++) {
        if (j > 0 && M[i] != M[j])
            j = stat[j];
        if (M[i] == M[j]) {
            stat[i] = ++j;
        }
    }

    return stat;
}

void kmp(string M, string N, int& findCount, vector<int>& findIndex, vector<int>& fail)
{
    size_t j = 0;
    for (size_t i = 0; i < N.length(); i++) {
        if (j > 0 && N[i] != M[j])
            j = fail[j];

        if (N.at(i) == M.at(j)) {
            j++;
            if (j == M.length()) {
                findCount++;
                findIndex.push_back(i - j + 1);

                j = fail[j];
            }
        }
    }
}

int main(void)
{
    string N = "";
    string M = "";

    getline(cin, N);
    getline(cin, M);

    int findCount = 0;
    vector<int> findIndex;

    vector<int> fail = failureFunction(M);
    kmp(M, N, findCount, findIndex, fail);

    cout << findCount << "\n";

    for (const auto& item : findIndex) {
        cout << item << " ";
    }
}