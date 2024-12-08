#include<stdio.h>
int pee(int* a, int n, int m,int index) {
	if (index >= n) return -1;
	if (a[index] == m) return index;
	return pee(a, n, m, index + 1);
}
int main() {
	int n,m;
	int a[100];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	int j = pee(a, n, m, 0);
	if (j == -1) printf("NULL");
	else printf("%d", j);

}
