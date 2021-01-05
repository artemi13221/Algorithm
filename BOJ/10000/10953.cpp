#include <stdio.h>

int main(void) {
    int a, b;
    int num;

    scanf("%d", &num);
    
    for(int i = 0; i < num; i++) {
        scanf("%d,%d", &a, &b);
        printf("%d\n", a+b);
    }

    return 0;
}