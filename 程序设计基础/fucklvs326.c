#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
}node;
int cn(int data){
    node *p = (node*)malloc(sizeof(node));
    p->data = data;
    p->prev = NULL;
    p->next = NULL;
    return p;
}
void append(node **head,int data){//指针的指针因为需要涉及到修改
    node *new = cn(data);
    if(*head == NULL){
        *head = new;
        return;
    }
    node *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new;
    new->prev = temp;
}
void print(node *head){
    while(head != NULL){
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}
int delete(node **head,int num){
    int index = 1;
    node *temp = *head;
    while(temp != NULL){
        if(temp->data == num){
            if(temp->prev == NULL){
                *head = temp->next;
                free(temp);
                return 1;
            }
            temp->prev->next = temp->next;
            if(temp->next != NULL){
                temp->next->prev = temp->prev;
            }
            free(temp);
            return index;
        }
        index++;
        temp = temp->next;
        if(temp == NULL){
            return 0;
        }
    }
}
int main(){
    node *head = NULL;
    int n,number,del;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        int x;
        scanf("%d",&x);
        append(&head,x);
    }
    scanf("%d",&del);
    number = delete(&head,del);
    printf("%d\n",number);
    print(head);
    return 0;
}