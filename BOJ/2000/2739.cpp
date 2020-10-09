#include <iostream>

int main(void) {
	int num = 0;
	std::cin >> num;

	for (int i = 1; i <= 9; i++) {
		std::cout << num << " * " << i << " = " << num * i << "\n";
	}
}