#include <iostream>
#include <vector>
#include <string>
using namespace std;

string solution(string src) {
    string answer = "";
    vector<int> v;
    answer += src[0];
    int size = src.size();
    if(src[size - 1] == '0') {
        src += '1';
    }
    else {
        src += '0';
    }
    int count = 0;
    for(int i = 1; i < size+1; i++) {
        if(src[i - 1] != src[i]) {
            v.push_back(i - count);
            count = i;
        }
    }

    size = v.size();
    for(int i = 0; i < size; i++) {
        answer += ((v[i] - 1) + 'A');
    }
    return answer;
}

int main(void) {
    string str = "111100100011";
    cout << solution(str);
}