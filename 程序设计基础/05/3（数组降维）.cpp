#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void hongdou(int*a, int n, int m) {
	for (int i = 0; i < n * m - 1; i++) {
		for (int j = 0; j < n * m - i - 1; j++) {
			if (*(a + j) > *(a + 1 + j)) {
				int temp = *(a + j);
				*(a + j) = *(a + j + 1);
				*(a + j + 1) = temp;
			}
		}
	}
}
int main() {
	int n, m,ju[50][50],juone[2500];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &ju[i][j]);
			juone[i * m + j] = ju[i][j];
		}
		
	}
	hongdou(juone, n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (!j) printf("%d", juone[i * m + j]);
			else printf(" %d", juone[i * m + j]);
		if(i != n - 1) printf("\n");
	}
}