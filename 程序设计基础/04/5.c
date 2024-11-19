#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int n,a[100],fir = 1,nt;
	scanf("%d", &n);
	nt = n;
	for (int i = 0; i < nt; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < nt; ) {
		if (a[i] == 0) {
			for (int j = i; j < nt - 1; j++) {
				a[j] = a[j + 1];
			}
			a[nt-- - 1] = 0;
		}
		else {
			i++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (fir) {
			printf("%d", a[i]);
			fir = 0;
		}
		else {
			printf(" %d", a[i]);
		}
	}
}