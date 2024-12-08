#include<stdio.h>
float h(int n,float x) {
	if (n == 0) return 1;
	if (n == 1) return 2 * x;
	return 2 * x * h(n - 1, x) - 2 * (n - 1) * h(n - 2, x);
}
int main() {
	int n;
	float x;
	scanf("%d %f", &n, &x);
	printf("%.2f",h(n,x));
}
