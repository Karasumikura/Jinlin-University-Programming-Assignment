#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int a[100],n,i,j,t,shit;
	scanf("%d %d",&n,&j);
	j %= n;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (shit = 0; shit < j; shit++) {
		t = a[n - 1];
		for (i = n - 2; i >= 0; i--) {
				a[i + 1] = a[i];
		}
		a[0] = t;
	}
	for (i = 0; i < n; i++) {
		if (!i) printf("%d", a[i]);
		else printf(" %d", a[i]);
	}
}
