#include <iostream>
#include <cstring>

int main(void) {
	int num;
	std::cin >> num;
	char ch[100];
	int temp = 0;
	int temp2 = 0;

	for (int i = 0; i < num; i++) {
		ch[0] = '\0';
		std::cin >> ch;
		temp2 = 0;
		temp = 0;

		for (unsigned int j = 0; j < strlen(ch); j++) {
			if (ch[j] == 'X') {
				temp = 0;
				continue;
			}
			else if (temp && ch[j] == 'O')
				temp++;
			else if (ch[j] == 'O')
				temp = 1;

			temp2 += temp;
		}
		std::cout << temp2 << "\n";
	}

	return 0;
}