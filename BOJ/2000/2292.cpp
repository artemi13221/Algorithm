#include <iostream>

int main(void) {
	int result = 0, temp = 1;
	int input = 0;
	std::cin >> input;

	for (int i = 1; ; i++) {
		if (input > temp) {
			temp += 6 * i;
		}
		else {
			result = i;
			break;
		}
	}

	std::cout << result;
}