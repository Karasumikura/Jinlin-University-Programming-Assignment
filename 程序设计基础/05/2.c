#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void why(char* str, int* daxie, int* xiaoxie, int* kongge, int* shuzi, int* made) {
	while (*str) {
		if (*str >= 'a' && *str <= 'z') (*xiaoxie)++;
		else if (*str >= 'A' && *str <= 'Z') (*daxie)++;
		else if (*str >= '0' && *str <= '9') (*shuzi)++;
		else if (*str == ' ') (*kongge)++;
		else if(*str != '\0')  (*made)++;
		str++;
	}
}
int main() {
	char str[257];
	int daxie = 0, xiaoxie = 0, kongge = 0, shuzi = 0, made = 0;
	fgets(str, 257, stdin);
	why(str, &daxie, &xiaoxie, &kongge, &shuzi, &made);
	printf("%d %d %d %d %d", daxie, xiaoxie, kongge,shuzi, made);
}