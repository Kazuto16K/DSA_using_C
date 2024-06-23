// Online C compiler to run C program online
#include <stdio.h>
typedef struct Node{
    int data;
    struct Node *next;
}node;

node *push(node *p,int x){
    node *q=(node *)malloc(sizeof(node));
    q->data=x;
    q->next=NULL;
    if(p==NULL){
        p=q;
        return p;
    }
    else{
        q->next=p;
        return q;
    }
    
}

node *pop(node *p){
    node *q;
    if(p==NULL){
        printf("\nUnderflow!!");
    }
    else{
        q=p->next;
        p->next=NULL;
        printf("\nPopped Element: %d\n",p->data);
        free(p);
        return q;
    }
}

void print(node *p){
    while(p->next!=NULL){
        printf("%d ->",p->data);
        p=p->next;
    }
    printf("%d",p->data);
}

int main() {
    
    node *head=NULL;
    while(1){
        int ch;
        printf("\n\nStack operations!!\n1.Push\n2.Pop\n3.Display\nEnter Your choice:: ");
        scanf("%d",&ch);
        if(ch==1){
            int val;
            printf("Enter value to be Pushed:: ");
            scanf("%d",&val);
            head=push(head,val);
        }
        else if(ch==2){
            head=pop(head);
        }
        else if(ch==3){
            print(head);
        }
        else{
            break;
        }
    }

    return 0;
}
