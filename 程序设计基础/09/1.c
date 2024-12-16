#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

struct cell { //单链表结点结构体定义

    int x;

    struct cell* next;

};

struct cell* build(void) { //新建单链表，并将建好的单链表首结点地址返回

    struct cell* head, * tmp, * p;

    head = tmp = p = NULL;

    int n;
    while (scanf("%d", &n)) {
        if (n) {
            p = (struct cell*)malloc(sizeof(struct cell));
			p->next = NULL;
			p->x = n;
            if (!head) {
				head = p;
            }
            else {
                tmp = head;
                while (tmp->next) tmp = tmp->next;
				tmp->next = p;
            }
        }
        else break;
    }

    return head;//返回单链表头

}

void print(struct cell* head) {//打印整个单链表,head是指向单链表首结点的指针

    while (head) {
        if (head->next) {
            printf("%d ", head->x);
            head = head->next;
        }
        else
        {
            printf("%d", head->x);
            break;
        }
    }

}

void release(struct cell* head) {//释放单链表空间,head是指向单链表首结点的指针
	struct cell* tmp;

    while (head) {
        tmp = head;
        if (head->next) {
            head = head->next;
            free(tmp);
        }
        else
        {
            free(tmp);
            break;
        }
    }

}

int main(void) {

    struct cell* head;

    head = build();

    if (head != NULL)

        print(head);

    else

        printf("NULL");

    release(head);

}

