#include <stdio.h>

int main(void) {
	int num = 0;
	int result = 0;
	char temp = '0';
	scanf("%d", &num);
	while (getchar() != '\n');

	for (int i = 0; i < num; i++) {
		scanf("%c", &temp);
		printf("%d", i);
		result += temp - '0';
	}
	printf("%d", result);
}