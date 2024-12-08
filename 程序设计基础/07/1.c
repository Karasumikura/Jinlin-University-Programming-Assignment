#include<stdio.h>
int c(int m, int n) {
	if (n < 0) return 0;
	if(n == 0)  return 1;
	if (n == 1)  return m;
	if (m < 2 * n) return c(m, m - n);
	return c(m - 1, n - 1) + c(m - 1, n);
}
int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	printf("%d", c(m, n));
}
