#include <iostream>
#include <cstring>

int linerSerach(char a, char ch[], int len);
int main(void) {
	char ch[100];
	int alphabat[26];

	std::cin >> ch;
	int len = strlen(ch);

	for (int i = 0; i < 26; i++) {
		alphabat[i] = linerSerach(i+97, ch, len);
	}

	for (int i = 0; i < 26; i++) {
		std::cout << alphabat[i] << " ";
	}
}

int linerSerach(char a, char ch[], int len) {
	for (int i = 0; i < len; i++) {
		if (a == ch[i]) {
			return i;
		}
	}

	return -1;
}