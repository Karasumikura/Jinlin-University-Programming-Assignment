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
	
	while(scanf("%d",&n)&& n != 0){
		tmp = (struct cell*)malloc(sizeof(struct cell));
		tmp->x = n;
		tmp->next = NULL;
		if (!p) {
			p = head = tmp;
		}
		else {
			p->next = tmp;
			p = tmp;
		}
	}

	return head;//返回单链表头

}

struct cell* mid(struct cell* head) {//寻找链表中间位置结点地址并返回，head是单链表首结点指针
	if (!head) return NULL;
	struct cell* fast = head, * slow = head;
	while (fast && fast->next && fast->next->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

void print(struct cell* head) {//打印整个单链表,head是单链表首结点指针
	if (!head) {
		printf("NULL");
		return;

	}
	for (; head; head = head->next) {
		if (head->next) printf("%d ", head->x);
		else printf("%d", head->x);
	}

}

void release(struct cell* head) {//释放单链表空间,head是单链表首结点指针

	while (head) {
		struct cell* p = head;
		head = head->next;
		free(p);
	}


}

int main(void) {

	struct cell* head, * half;

	head = build();

	half = mid(head);

	if (half != NULL)

		print(half);

	else

		printf("NULL");

	release(head);

}
