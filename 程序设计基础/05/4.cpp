#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
char* crying(char* str, int qi, int shu) {
	for (int i = qi - 1; i < 257 - shu; i++) {
		*(str + i)= *(str + shu + i);
	}
	return str;
}
int main() {
	char str[257];
	int qi, shu;
	scanf("%d %d ", &qi, &shu);
	fgets(str, 257, stdin);
	printf("%s", crying(str, qi, shu));
}