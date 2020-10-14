#include <iostream>
using namespace std;
int gcd(int a, int b) {
    return a%b ? gcd(b, a%b) : b;
}
int lcm(int a, int b, int c) {
    return ((a * b) / c);
}
int main(void) {
    int a, b, gcdNum;
    scanf("%d %d", &a, &b);
    gcdNum = gcd(a, b);
    printf("%d\n%d", gcdNum, lcm(a, b, gcdNum));
}