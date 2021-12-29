#include <iostream>
#include <string>
using namespace std;

bool isUpper(char c)
{
    return (c >= 'A' && c <= 'Z') ? true : false;
}

bool isLower(char c)
{
    return (c >= 'a' && c <= 'z') ? true : false;
}

int main(void)
{
    string s1;
    cin >> s1;
    string result;

    if (s1[0] >= 'A' && s1[0] <= 'Z') {
        // 입력이 Pascal

        // 대문자 갯수 upperCase
        int upperCase = 0;

        // 연속된 대문자에서 소문자, 소문자->대문자의 경우에서 _를 추가
        for (int i = 0; i < s1.size() - 1; i++) {
            if (isUpper(s1[i])) {
                upperCase++;
            } else {
                upperCase = 0;
            }

            if (isUpper(s1[i]) && isLower(s1[i + 1]) && upperCase >= 2) { // 대문자가 2개 이상 나오고, 소문자가 나온 경우
                int index = result.size() - 1;
                result.push_back('_');
                result.push_back(s1[i]);
            } else if (upperCase == 0 && isUpper(s1[i + 1])) { // 소문자 다음에 대문자가 나오는 경우
                result.push_back(s1[i]);
                result.push_back('_');
            } else { // 그 이외
                result.push_back(s1[i]);
            }
        }
        result.push_back(s1[s1.size() - 1]); // 맨 마지막 처리

        // 모든 문자를 소문자로 바꿔줌.
        for (int i = 0; i < result.size(); i++) {
            if (isUpper(result[i])) {
                result[i] += 32;
            }
        }

        /*
        // 대문자가 나왔을 경우 그냥 전부 다 _치는 경우
        result.push_back(s1[0] + 32);
        uint i = 1;
        while (i < s1.size()) {
            if (s1[i] >= 'A' && s1[i] <= 'Z') {
                result.push_back('_');
                result.push_back(s1[i] + 32);
            } else {
                result.push_back(s1[i]);
            }
            i++;
        }
        */

    } else {
        // 맨 앞에 _ 맨 뒤에 _를 모두 제거한다.
        int deleteChar = s1.find_first_not_of('_');
        if (deleteChar != 0)
            s1.erase(0, deleteChar);
        deleteChar = s1.find_last_not_of('_');
        if (deleteChar != s1.size() - 1)
            s1.erase(deleteChar + 1, s1.size() - 1);

        // 맨 첫번째 글자는 대문자로
        s1[0] -= 32;

        // _가 나오면 다음 'a'~'z'를 -32해줌.
        uint i = 0;
        int select = 0;
        while (i < s1.size()) {
            if (s1[i] == '_') {
                select = 1;
            } else if (select == 1 && (s1[i] >= 'a' && s1[i] <= 'z')) {
                select = 0;
                result.push_back(s1[i] - 32);
            } else {
                result.push_back(s1[i]);
            }
            i++;
        }

        /*
        result.push_back(s1[0] - 32);
        uint i = 1;
        while (i < s1.size()) {
            if (s1[i] == '_') {
                i += 1;
                if (i < s1.size() && s1[i] != '_') {
                    result.push_back(s1[i] - 32);
                }
            } else {
                result.push_back(s1[i]);
            }
            i++;
        }
        */
    }
    cout << result << "\n";
}