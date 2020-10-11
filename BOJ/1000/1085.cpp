#include <iostream>

int main(void) {
	int x, y, w, h, temp;

	std::cin >> x >> y >> w >> h;
	temp = std::min(x, y);
	w = std::min(w - x, h - y);
	temp = std::min(temp, w);

	std::cout << temp;
}