#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int n;
	const char* one[] = { "zero", "one", "two", "three", "four", "five", "six",\
    "seven", "eight", "nine" };
	const char* two[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", \
		"fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	const char* three[] = {"twenty", "thirty", "forty", "fifty", "sixty",\
		"seventy", "eighty", "ninety" };
	scanf("%d", &n);
	if (n >= 1000 || n < 0)  printf("ERR");
	else {
		if (n < 10) printf("%s", one[n]);
		else if (n < 20)printf("%s", two[n - 10]);
		else if (n < 100 && n % 10 != 0)printf("%s-%s", three[(n / 10) - 2], one[n % 10]);
		else if (n < 100 && n % 10 == 0)printf("%s", three[(n / 10) - 2]);
		else if (n % 100 == 0)printf("%s hundred", one[n / 100]);
		else if (n % 100 < 10)printf("%s hundred and %s", one[n / 100], one[n % 10]);
		else if (n % 100 < 20)printf("%s hundred and %s", one[n / 100], two[n % 10]);
		else if (n % 10 == 0)printf("%s hundred and %s", one[n / 100], three[(n % 100) / 10 - 2]);
		else printf("%s hundred and %s-%s", one[n / 100], three[(n % 100) / 10 - 2], one[n % 10]);

	}
}
