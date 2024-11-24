#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int n, ju[30][30], top = 0, bot, left = 0, right, i, num = 1;
	scanf("%d", &n);
	right = n - 1;
	bot = n - 1;
	while (top <= bot && left <= right) {
		for (i = left; i <= right; i++) {
			ju[top][i] = num++;
		}
		top++;
		for (i = top; i <= bot; i++) {
			ju[i][right] = num++;
		}
		right--;
		for (i = right; i >= left; i--) {
			ju[bot][i] = num++;
		}
		bot--;
		for (i = bot; i >= top; i--) {
			ju[i][left] = num++;
		}
		left++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%4d", ju[i][j]);
		}
		printf("\n");
	}
}