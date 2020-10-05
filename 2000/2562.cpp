#include <iostream>

int main(void) {
	int input[10] = { 0, };

	for (int i = 0; i < 9; i++) {
		std::cin >> input[i];
	}

	int max = 0;
	int maxIndex = 0;

	for (int i = 0; i < 9; i++) {
		if (max < input[i]) {
			max = input[i];
			maxIndex = i;
		}
	}

	std::cout << max << "\n" << maxIndex + 1;
}