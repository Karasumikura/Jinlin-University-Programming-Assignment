#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int useless(char* str) {
	int fkingle = 0;
	while (*str != '\0') {
		str++;
		fkingle++;
	}
	return fkingle;
}
int main() {
	char str[257];
	fgets(str, sizeof(str), stdin);
	printf("%d", useless(str));
}
