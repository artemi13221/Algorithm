#include <iostream>
#include <algorithm>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int a[3] = {0, };
    int tmp = 0;
    std::cin >> a[0] >> a[1] >> a[2];

    while(a[0] != 0 && a[1] != 0 && a[2] != 0) {
        std::sort(a, a+3);
        if(a[0]*a[0] + a[1]*a[1] == a[2]*a[2])
            std::cout << "right" << "\n";
        else
            std::cout << "wrong" << "\n";
        
        std::cin >> a[0] >> a[1] >> a[2];
    }
}