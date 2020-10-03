#include <iostream>
bool linerSearch(int num, int arry[]) {
	bool isExist = false;
	for (int i = 0; i < 10; i++) {
		if (num == arry[i]) {
			isExist = true;
			break;
		}
	}

	return isExist;
}

int main(void) {
	int arr[10] = { 0, };
	int result[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
	int temp = 0;
	int count = 0;
	for (int i = 0; i < 10; i++)
		std::cin >> arr[i];

	for (int i = 0; i < 10; i++) {
		temp = arr[i] % 42;
		if (!(linerSearch(temp, result))) {
			result[count] = temp;
			count++;
		}
	}

	std::cout << count;
}