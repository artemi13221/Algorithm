#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num = 0, count = 0;
    cin >> num;

    for(int i = 0; i < num; i++) {
        char ch[101] = "";
        char tmp = 0;
        int arr[26] = {0, };
        cin >> ch;
        size_t size = strlen(ch);
        for(size_t j = 0; j < size; j++) {
            if(tmp == ch[j])
                continue;
            else {
                arr[ch[j] - 'a'] += 1;
                if(arr[ch[j] - 'a'] >= 2) {
                    count++;
                    break;
                }
            }
            tmp = ch[j];
        }
    }

    cout << num - count;
}