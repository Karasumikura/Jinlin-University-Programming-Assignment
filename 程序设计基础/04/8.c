#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int ju[10][10],T[10][10],n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &ju[i][j]);
			T[j][i] = ju[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!j) printf("%d", T[i][j]);
			else if(j == n - 1) printf(" %d\n", T[i][j]);
			else printf(" %d", T[i][j]);
			
		}
	}

}