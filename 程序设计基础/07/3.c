#include<stdio.h>
int h(int m,int n) {
	if (m == 0) return n + 1;
	if (n == 0) return h(m - 1,1);
	return h(m - 1, h(m, n - 1));
}
int main() {
	int m,n;
	scanf("%d %d", &m, &n);
	printf("%d",h(m,n));
}
