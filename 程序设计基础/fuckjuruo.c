#include<stdio.h>
int main(){
    char str[10000];
    int n; 
    int i = 0;
    scanf("%d",&n);
    n %= 26;
    getchar();
    while((str[i] = getchar()) != '\n'){
       if(str[i] + n > 'z'){
        str[i] += (n - 26);
       }
       else  str[i] += n;
       i++;
    }
    str[i] = '\0';
    printf("%s",str);
}