#include <iostream>

int main(void) {
	int row, col, i, j, min = 64, temp, k, l;
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> col;
	std::cin >> row;
	std::cin.clear();
	std::cin.ignore();
	char n[51][51];
	for (i = 0; i < col; i++)
		std::cin >> n[i];
	
	for (i = 0; i <= col-8; i++) {
		for (j = 0; j <= row - 8; j++) {
			temp = 0;
			for (k = i; k < i + 8; k++) {
				for (l = j; l < j + 8; l++) {
					if ((k + l) % 2 == 0 && n[k][l] == 'W') temp++;
					if ((k + l) % 2 == 1 && n[k][l] == 'B') temp++;
				}
			}
			temp = std::min(temp, 64 - temp);
			min = std::min(min, temp);
		}
	}
	std::cout << min;
}