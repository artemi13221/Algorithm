#include <iostream>
int facto(int a, int b) {
    if (b < 1)
        return 1;
    else
        return a * facto(a-1, b-1);
}
int main(void) {
    int a, b;
    std::cin >> a >> b;
    std::cout << facto(a, b) / facto(b, b);
}