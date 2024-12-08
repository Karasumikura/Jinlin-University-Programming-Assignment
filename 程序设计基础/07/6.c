#include<stdio.h>
int pee(int* a, int n) {
	if (n == 1) return *a;
	int t = pee(a + 1, n - 1);
	return (*a >= t) ? *a : t;
}
int main() {
	int n;
	int a[100];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	printf("%d", pee(a, n));
}
