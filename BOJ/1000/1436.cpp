#include <iostream>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int temp = 0,temp2 = 0, i = 0, n = 0, result = 665;
    bool a = false;
    std::cin >> n;

    while(i < n) {
        temp2 = 0;
        bool a = false;
        temp = ++result;
        while(temp) {
            if(temp % 10 == 6)
                temp2++;
            else
                temp2 = 0;
            if(temp2 >= 3)
                a = true;
            temp /= 10;
        }
        if(a)
            i++;
    }
    std::cout << result;
}