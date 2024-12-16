#include<stdio.h>
//正整数n，按第一项递减的顺序依次输出其和等于n的所有不增的正整数和式。
void jia(int n,int s,int max,int *a,int index) {
	int j;
	if (s == 0) {
		printf("%d=", n);
		for (int i = 0; i < index; i++) {
			printf("%d", a[i]);
			if (i < index - 1) printf("+");	
		}
		printf("\n");
		return;
	}
	for (j = s; j > 0; j--) {
		if (j <= max&&j != n) {
			a[index] = j;
			jia(n, s - j, j, a, index + 1);
		}
	}
}
int main() {
	int n, a[15];
	scanf("%d", &n);
	jia(n, n, n, a,0);
}
