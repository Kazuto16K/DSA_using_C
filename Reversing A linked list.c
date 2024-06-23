// Reversing A Linked List
#include <stdio.h>
#include <stdlib.h>

typedef struct BST{
    int data;
    struct BST *next;
}node;

node *reverse(node *head){
    node *p=head->next;
    head->next=NULL;
    while(p!=NULL){
        node *q=head;
        head=p;
        p=p->next;
        head->next=q;
    }
    return head;
}

node *create(node *head,int x){
    node *q=(node *)malloc(sizeof(node));
    q->data=x;
    q->next=NULL;
    if(head==NULL){
        head=q;
        //return head;
    }
    else{
        node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=q;
        //return head;
    }
    return head;
    
}

void print(node *head){
    node *temp=head;
    while(temp->next!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}

int main() {
    node *head=NULL;
    head=create(head,10);
    head=create(head,20);
    head=create(head,30);
    head=create(head,40);
    print(head);
    head=reverse(head);
    head=create(head,50);
    printf("\n");
    print(head);
    return 0;
}
