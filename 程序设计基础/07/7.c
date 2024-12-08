#include<stdio.h>
void you(int* a, int n) {
	if (n == 1) {
		printf("%d", *a);
		return;
	}
	else printf("%d ", *(a + n - 1));
	return you(a, n - 1);
}
int main() {
	int n;
	int a[100];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	you(a, n);
}
