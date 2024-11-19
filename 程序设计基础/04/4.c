#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int a[100], n, i,fir = 1;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++) {
		for (int j = i + 1; j < n;) {
			if (a[i] == a[j]) {
				for (int k = j; k < n - 1; k++) {
					a[k] = a[k + 1];
				}
				n--;
			}
			else {
				j++;
			}
		}
	}
	for (i = 0; i < n; i++) {
		if (fir) {
			printf("%d", a[i]);
			fir = 0;
		}
		else {
			printf(" %d", a[i]);
		}
	}
	return 0;
}