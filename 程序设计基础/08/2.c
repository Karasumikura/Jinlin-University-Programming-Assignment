#include<stdio.h>
int a[14] = { 0 };
int num = 0;
int n;
int c(int x, int y) {
	for (int i = 1; i < x; i++) {
		if (a[i] == y || i + a[i] == x + y || i - a[i] == x - y) return 0;
	}
	return 1;
}
void q(int x) {
	if (x > n) {
		num++;
		return;
	}
	for (int y = 1; y <= n; y++) {
		if (c(x,y)) {
			a[x] = y;
			q(x + 1);
			a[x] = 0;
		}
	}
}
int main() {
	scanf("%d", &n);
	q(1);
	printf("%d", num);
}
