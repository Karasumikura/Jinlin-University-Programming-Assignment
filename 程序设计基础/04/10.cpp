#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main() {
	char ch[256];
	fgets(ch, sizeof(ch), stdin);
	for (int i = strlen(ch) - 1; i >= 0; i--) {
		printf("%c", ch[i]);
	}
}