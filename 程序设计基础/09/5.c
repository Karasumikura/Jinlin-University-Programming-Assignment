#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <malloc.h>

struct cell {//单链表结点结构体定义

    int x;

    struct cell* next;

};

struct cell* build(void) {//新建单链表，并将建好的单链表首结点地址返回

    struct cell* head, * tmp, * p;

    head = tmp = p = NULL;

    int n;

    while (scanf("%d", &n) && n != 0) {
        tmp = (struct cell*)malloc(sizeof(struct cell));
		tmp->x = n;
		tmp->next = NULL;
        if (!head) {
            head = p = tmp;
        }
        else {
            p->next = tmp;
            p = tmp;
        }
    }

    return head;//返回单链表头

}

struct cell* back(struct cell* head, int k) {//求链表倒数第k个结点，head是单链表首结点指针
	if (!head) return NULL;
    struct cell* fast = head, * slow = head;
    for (int i = 0; i < k; i++) {
		if (fast->next) fast = fast->next;
		else return NULL;
    }
    while (fast) {
		fast = fast->next;
		slow = slow->next;
    }
    return slow;
}

void release(struct cell* head) {//释放单链表空间,head是单链表首结点指针
    struct cell* t;
    while (head) {
        t = head;
        head = head->next;
        free(t);
   }

}

int main(void) {

    struct cell* head, * result;

    int k;

    head = build();

    scanf("%d", &k);

    result = back(head, k);

    if (result != NULL)

        printf("%d", result->x);

    else

        printf("NULL");

    release(head);

}

