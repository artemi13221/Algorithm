#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int arr[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string str[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int a, b;
    cin >> a >> b;

    int tmp = 0;
    for(int i = 1; i < a; i++) {
        tmp += arr[i];
    }
    tmp += b;

    int answer = tmp % 7;

    cout << str[answer];
}