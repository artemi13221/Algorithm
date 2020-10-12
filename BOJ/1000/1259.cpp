#include <iostream>

bool isPalindrome(int num) {
	bool result = true;
	int arr[5] = { 0, }, i = 0, len = 0;
	while (num) {
		arr[i++] = num % 10;
		num /= 10;
		len = i;
	}
	len--;

	for (i = 0; i <= len; i++) {
		if (arr[i] != arr[len - i])
			result = false;
	}

	return result;
}
int main(void) {
	int num = 0;
	std::cin >> num;

	while (num) {
		if (isPalindrome(num))
			std::cout << "yes" << "\n";
		else
			std::cout << "no" << "\n";

		std::cin >> num;
	}
}
/*
���� �����ϴ� ��� �̿ܿ���
String���� reverse�� �̿��Ͽ� Ǫ�� ����� ����.
*/