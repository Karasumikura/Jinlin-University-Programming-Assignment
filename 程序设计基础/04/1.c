#include<stdio.h>
#include<stdlib.h>
#define SIZE 1000
unsigned top = 0;
char ch;
int stack[SIZE];
void push(char x) { 
	stack[top++] = x; 
}
char pop(void) { 
	while (top > 0)  return stack[--top]; 
}
void check(char x, char y) {
	if (x != y) {
		printf("NO");
		exit(0);
	}
}
int main() {
	char out;
	while ((ch = getchar()) != '@') {
		switch (ch) {
		case'[':
		case'(':
		case'{':
			push(ch);
			break;
		case']':
			out = pop();
			check(out, '[');
			break;
		case')':
			out = pop();
			check(out, '(');
			break;
		case'}':
			out = pop();
			check(out, '{');
			break;
		default:
			break;
		}

	}
	if (top == 0) printf("YES");
	else printf("NO");

	return 0;
}
