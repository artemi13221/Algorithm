#include <iostream>
using namespace std;

int main(void) {
    char c[101];
    cin >> c;
    int check = 0;
    for(int i = 0; i < 10; i++) {
       for(int j = 0; j < 10; j++) {
           int index = i * 10 + j;
           if(c[index] == '\0') {
               check = 1;
               break;
           }
           printf("%c", c[index]);
       }
       if(check) {
           break;
       }
       printf("\n");
    }
}