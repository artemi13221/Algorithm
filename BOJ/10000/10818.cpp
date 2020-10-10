#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int num = 0;
	std::cin >> num;
	int max = -1000000;
	int min = 1000000;
	int temp = 0;

	do {
		std::cin >> temp;
		if (max < temp)
			max = temp;
		if (min > temp)
			min = temp;
	} while (--num > 0);

	std::cout << min << " " << max;
	return 0;
}