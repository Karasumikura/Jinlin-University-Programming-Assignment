#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
typedef struct {
	float shi;
	float xu;
}Fushu;
void dayin(Fushu f) {
	printf("%.2f", f.shi);
	if (f.xu > 0) {
		printf("+%.2fi", f.xu);
	}
	else if(f.xu != 0){
		printf("-%.2fi", -f.xu);
	}
}
Fushu jia(Fushu f1, Fushu f2) {
	Fushu f;
	f.shi = f1.shi + f2.shi;
	f.xu = f1.xu + f2.xu;
	return f;
}
Fushu jian(Fushu f1, Fushu f2) {
	Fushu f;
	f.shi = f1.shi - f2.shi;
	f.xu = f1.xu - f2.xu;
	return f;
}
Fushu cheng(Fushu f1, Fushu f2) {
	Fushu f;
	f.shi = f1.shi * f2.shi - f1.xu * f2.xu;
	f.xu = f1.shi * f2.xu + f1.xu * f2.shi;
	return f;
}
int main(){
	Fushu f1,f2;
	scanf("%f %f %f %f", &f1.shi, &f1.xu, &f2.shi, &f2.xu);
	dayin(jia(f1, f2));
	printf("    ");
	dayin(jian(f1, f2));
	printf("    ");
	dayin(cheng(f1, f2));
}
