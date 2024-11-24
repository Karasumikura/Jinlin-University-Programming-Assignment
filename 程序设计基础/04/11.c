#include<stdio.h>
#define  _CRT_SECURE_NO_WARNINGS
int main() {
	int a[1000], n, s, m,nt;
	scanf("%d %d %d", &n, &s, &m);
	nt = n;
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	s--;
	for (int j = 0; j < n; j++) {
		s += m - 1;
		s %= nt;
		if (!j) printf("%d", a[s]);
		else printf(" %d", a[s]);
		for (int i = s; i < nt - 1; i++) {
			a[i] = a[i + 1];
		}
		nt--;
	}
}
