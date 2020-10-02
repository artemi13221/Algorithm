#include <iostream>
#include <string>

int main(void) {
	std::string str;
	std::cin >> str;
	int result = 0;
	int temp = 0;
	
	for (unsigned int i = 0; i < str.length(); i++) {
		temp = str[i] + 1;
		if (temp > 80) {
			if (temp > 80 && temp < 85)
				result += 8;
			else if (temp >= 85 && temp < 88)
				result += 9;
			else
				result += 10;
		}
		else {
			result += (temp / 3) - 19;
		}
	}

	std::cout << result;
}