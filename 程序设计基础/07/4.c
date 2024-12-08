#include<stdio.h>
int h(int m, int n) {
	if (m % n == 0) return n;
	return h(n, m % n);
}
int main() {
	int m,n;
	scanf("%d %d", &m, &n);
	printf("%d",h(m,n));
}
