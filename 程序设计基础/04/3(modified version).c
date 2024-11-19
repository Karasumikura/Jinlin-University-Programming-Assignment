#include<stdio.h>
#define SIZE 10
void bdd(int a[], int n) {
	int j,ls;
	for (int i = 1; i < n; i++) {
		ls = a[i];
		for (j = i - 1; j >= 0 && a[j] > ls; j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = ls;
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}
}
void taffy(int a[],int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}
}

void xrr(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}
}

int main() {
	int a[SIZE];
	for (int i = 0; i < SIZE; i++) {
		scanf("%d", &a[i]);
	}
	bdd(a, SIZE);
	taffy(a, SIZE);
	xrr(a, SIZE);
	return 0;
}
