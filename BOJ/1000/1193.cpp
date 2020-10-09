#include <iostream>

int main() {
	int input;
	std::cin >> input;
	bool c = true;
	bool first = true;
	int a = 1, b = 1; // a/b

	for (int i = 1; i < input; i++) {
		if (first) {
			b++;
			first = false;
			continue;
		}
		if ((b == 1) & c) {
			a++;
			c = false;
		}
		else if ((a == 1) & (!c)) {
			b++;
			c = true;
		}
		else if (c) {
			a++;
			b--;
		}
		else {
			a--;
			b++;
		}
	}

	std::cout << a << "/" << b;
}