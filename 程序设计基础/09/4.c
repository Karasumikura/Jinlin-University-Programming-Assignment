#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>
//最初错误原因：嵌套关系不对


struct farlei_item {

    int numerator, denominator;

    struct farlei_item* next;

};



typedef struct farlei_item* farleipointer;



int gcd(int x, int y) {

    if (x == 0) return y;

    return gcd(y % x, x);

}



farleipointer farlei(int n) {

    if (n < 1) return NULL; // 如果n<=0,则没有法雷序列



    // 初始化链表头尾两个节点

    farleipointer fn = (farleipointer)malloc(sizeof(struct farlei_item)); // 构造0/1

    fn->numerator = 0;

    fn->denominator = 1;

    fn->next = NULL;



    farleipointer last = (farleipointer)malloc(sizeof(struct farlei_item)); // 构造1/1

    last->numerator = 1;

    last->denominator = 1;

    last->next = NULL;

    fn->next = last;



    for (int j = 2; j <= n; ++j) {

        farleipointer prev = fn;

        farleipointer curr = fn->next;



        for (int i = 1; i < j; ++i) {

            if (gcd(i, j) == 1) { // 只考虑不可约分的分数

                farleipointer newNode = (farleipointer)malloc(sizeof(struct farlei_item));

                newNode->numerator = i;

                newNode->denominator = j;

                newNode->next = NULL;



                // 找到插入位置并插入新节点

                while (curr != NULL && ((long long)newNode->numerator * curr->denominator >= (long long)newNode->denominator * curr->numerator)) {

                    prev = curr;

                    curr = curr->next;

                }

                // 插入新节点

                newNode->next = curr;

                prev->next = newNode;

            }

        }

    }



    return fn;

}



void print(farleipointer fn) {

    if (!fn) {

        printf("NULL");

        return;

    }



    farleipointer current = fn;

    while (current->next != NULL) {

        printf("%d/%d ", current->numerator, current->denominator);

        current = current->next;

    }

    printf("%d/%d", current->numerator, current->denominator); // 最后一个元素不加空格

}



void release(farleipointer head) {

    farleipointer t;

    while (head) {

        t = head;

        head = head->next;

        free(t);

    }

}



int main(void) {

    int n;

    farleipointer fn;



    scanf("%d", &n);



    fn = farlei(n); // 生成n级法雷序列



    if (fn != NULL)

        print(fn);

    else

        printf("NULL");



    release(fn);



    return 0;

}

​
