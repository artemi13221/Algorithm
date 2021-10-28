#include <iostream>
#include <vector>
using namespace std;

int n, m;

void recursive(vector<int> goal, int num)
{
    if (goal.size() == m) {
        // print
        for (auto& i : goal)
            cout << i << " ";
        cout << "\n";
    } else {
        for (int i = num; i <= n; i++) {
            vector<int> nextGoal = goal;

            nextGoal.push_back(i);

            recursive(nextGoal, i);
        }
    }
}

int main(void)
{
    cin >> n >> m;

    recursive(vector<int>(), 1);

    return 0;
}