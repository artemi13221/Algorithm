#include <iostream>
using namespace std;

int count;
int n;
int W;
int maxProfit;
int numBest;
int bestSet[17];
int include[17];
int w[17];
int p[17];

bool promising(int i, int profit, int weight)
{
    int j, k;
    int toWeight;
    float bound;

    if (weight >= W)
        return false;
    else {
        j = i + 1;
        bound = profit;
        toWeight = weight;
        while (j <= n && toWeight + w[j] <= W) {
            toWeight = toWeight + w[j];
            bound = bound + p[j];
            j++;
        }
        k = j;
        if (k <= n)
            bound = bound + (W - toWeight) * p[k] / w[k];

        return bound > maxProfit;
    }
}

void knapsack(int i, int profit, int weight)
{
    count += 1;
    if (weight <= W && profit > maxProfit) {
        maxProfit = profit;
        numBest = i;
        for (int j = 0; j < 17; j++) {
            bestSet[j] = include[j];
        }
    }

    if (promising(i, profit, weight)) {
        include[i + 1] = 1;
        knapsack(i + 1, profit + p[i + 1], weight + w[i + 1]);
        include[i + 1] = 0;
        knapsack(i + 1, profit, weight);
    }
}

int main(void)
{
    count = 0;
    maxProfit = 0;
    numBest = 0;
    cin >> n >> W;
    for (int i = 0; i < n + 1; i++) {
        cin >> p[i] >> w[i];
    }
    knapsack(0, 0, 0);

    for (int i = 1; i < n + 1; i++) {
        cout << bestSet[i] << " ";
    }
    cout << "\n"
         << maxProfit << "\n"
         << count;
}