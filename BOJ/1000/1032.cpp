#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
    char fn[51] = "\0", tmp[51];
    int num = 0;

    cin >> num;
    
    for(int i = 0; i < num; i++) {
        tmp[0] = '\0';
        cin >> tmp;
        cin.clear();
        cin.ignore();
        size_t size = strlen(tmp);
        if(i == 0)
            for(size_t i = 0; i < size; i++)
                fn[i] = tmp[i];
        
        for(size_t i = 0; i < size; i++) {
            if(fn[i] != tmp[i])
                fn[i] = '?';
        }
    }
    size_t size = strlen(fn);
    for(size_t i = 0; i < size; i++) {
        cout << fn[i];
    }
}