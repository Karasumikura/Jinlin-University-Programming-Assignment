#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
bool isxianzimu(char ch) {
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_';
}
bool isshuzi(char ch) {
	return ch >= '0' && ch <= '9';
}
int main() {
	char str[258];
	int n,v = 0,iv = 0;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		int count = 1;
		fgets(str, sizeof(str), stdin);
		str[strcspn(str,"\n")] = '\0';
		if (!isxianzimu(*str)) count = 0;
		else {
			for (char* temp = str + 1;*temp != '\0'; temp++) {
				if (!isxianzimu(*temp)&&!isshuzi(*temp)) {
					count = 0;
					break;
				}
			}
		}
		if(count) v++;
		else iv++;
	}
	printf("Valid:%d\nInvalid:%d", v, iv);
}