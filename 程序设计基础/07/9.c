#include<stdio.h>
void huan(long n, int b,char*res,int* i) {
	if (n == 0) return;
	huan(n / b, b, res, i);
	if (n % b < 10) res[(*i)++] = n % b + '0';
	else res[(*i)++] = n % b - 10 + 'A';
}
int main() {
	int b;
	int i = 0;
	long n;
	char res[32];
	scanf("%ld %d", &n, &b);
	if (n == 0) {
		printf("0");
		return 0;
	}
	huan(n, b, res, &i);
	res[i] = '\0';
	printf("%s", res);
}
