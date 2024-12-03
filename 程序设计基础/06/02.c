#include<stdio.h>
#include<string.h>
typedef struct {
	char name[21];
	int gender;
	int age;
}mon;
int main() {
	mon tea[10];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %d %d", tea[i].name, &tea[i].gender, &tea[i].age);
	}
	printf("%s %s %d ",tea[n / 2].name,(tea[n/2].gender==0)?"Female":"Male", tea[n / 2].age);
	
}
