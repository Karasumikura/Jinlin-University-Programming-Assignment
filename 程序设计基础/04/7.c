#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int n, a[100],j = 0;
	scanf("%d", &n);
	for (int i = 0; i < n * n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n * n; i++) {
		for (int j = i + 1; j < n * n; j++) {
			if (a[i] == a[j]) {
				printf("YES");
				exit(0);
			}
		}
	}
	printf("NO");
}