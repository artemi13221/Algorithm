#include <iostream>

int main(void) {
	int num[8];
	int result = 0;

	for (int i = 0; i < 8; i++) {
		std::cin >> num[i];
	}

	if (num[0] == 1 && num[1] == 2 && num[2] == 3 && num[3] == 4 && num[4] == 5 && num[5] == 6 && num[6] == 7 && num[7] == 8)
		result = 1;
	else if (num[0] == 8 && num[1] == 7 && num[2] == 6 && num[3] == 5 && num[4] == 4 && num[5] == 3 && num[6] == 2 && num[7] == 1)
		result = 2;

	if (result == 0)
		std::cout << "mixed";
	else if (result == 1)
		std::cout << "ascending";
	else if (result == 2)
		std::cout << "descending";
}