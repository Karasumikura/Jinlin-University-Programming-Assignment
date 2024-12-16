#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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
			p = (struct cell*)malloc(sizeof(struct cell));
			p->x = n;
			p->next = NULL;
			if (!head) {
				head = p;
			}
			else {
				tmp = head;
				while (tmp->next) {
					tmp = tmp->next;
				}
				tmp->next = p;
			}
	}

	return head;//返回单链表头
}
struct cell* del2one(struct cell* head) {//删除重复结点只保留一个，head是单链表首结点指针
	struct cell* c, * c2,*c2z;
	c2z = NULL;
	for (c = head; c; c = c->next) {
		if (!head || !head->next) return head;
		for (c2 = c->next,c2z = c; c2; ) {
			if (c2->x == c->x) {
					c2z->next = c2->next;
					free(c2);
					c2 = c2z->next;
			}
			else {
				c2z = c2;
				c2 = c2->next;
			}
		}
	}
	return head;//返回删除重复结点的单链表头
}
void print(struct cell* head) {//打印整个单链表,head是单链表首结点指针
	while (head) {
		if (head->next) {
			printf("%d ", head->x);
			head = head->next;
		}
		else {
			printf("%d", head->x);
			return;
		}
	}
}
void release(struct cell* head) {//释放单链表空间,head是单链表首结点指针
	struct cell* tmp;
	while (head) {
		tmp = head;
		if (head->next) {
			head = head->next;
			free(tmp);
		}
		else {
			free(tmp);
			return;
		}

	}
}
int main(void) {
	struct cell* head;
	head = build();
	head = del2one(head);
	if (head != NULL)
		print(head);
	else
		printf("NULL");
	release(head);
}
