#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int bei(int n,int i1,int i2,int a[][101]);
int main(void) {
	int i = 0,n,i2 = 0,hang[20];
	int a[21][101];
	scanf("%d", &n);
	while (scanf("%d", &a[i][i2])!= EOF) {
		if (a[i][i2] == -1) break;
		if (a[i][i2] != 0) i2++;
		else {
			hang[i] = bei(n, i,i2, a);
			i++;
			i2 = 0;
		}
	}
	for (n = 0; n < i; n++) {
		if (n < i - 1) printf("%d\n", hang[n]);
		else printf("%d", hang[n]);
	}
}	
int bei(int n,int i1,int i2,int a[][101]) {
	int bei = 0;
	for (int i = 0; i < i2; i++) {
		for (int m = 0; m < i2; m++) {
			if (a[i1][i] == n * a[i1][m]) bei++;
		}
	}
	return bei;
}
