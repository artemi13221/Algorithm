#include <iostream>
#include <vector>
using namespace std;

int minValue;

int counting(int now, int target, int result)
{
    if (target > now) {
        result += (target - now);
    } else {
        result += (now - target);
    }
    // while (now != target) {
    //     if (minValue < result) {
    //         break;
    //     }
    //     if (target > now) {
    //         now++;
    //     } else {
    //         now--;
    //     }

    //     result++;
    // }

    return result;
}

int main(void)
{
    int now = 100;
    int target = 0;
    int unTouchedCount = 0;
    vector<int> unTouched = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    cin >> target >> unTouchedCount;

    for (int i = 0; i < unTouchedCount; i++) {
        int tmp = 0;
        cin >> tmp;
        unTouched[tmp] = -1;
    }
    minValue = INT32_MAX;
    minValue = counting(now, target, 0);

    // cout << minValue << "\n";

    for (int i = 0; i <= 1000000; i++) {
        int count = 0;
        int b = i;

        if (b == 0) {
            count++;

            if (unTouched[0] == -1) {
                count = 99;
            }
        }

        while (b > 0) {
            count++;
            int number = b % 10;
            b /= 10;

            if (unTouched[number] == -1) {
                count = 99;
            }
        }
        if (count >= 99) {
            continue;
        }
        int tmp = counting(i, target, count);

        if (minValue > tmp) {
            // cout << i << " " << minValue << " " << tmp << " " << count << "\n";
            minValue = tmp;
        }
    }

    cout << minValue;
}