#include<stdio.h>

int mu(int n, int k) {

	if (k >= n) return 1;

	return mu((int)(0.4*n+0.5) , k) + mu(n - (int)(0.4 * n + 0.5), k);

}

int main() {

	int k,n;

	scanf("%d %d", &n, &k);

	printf("%d", mu(n, k));

}
