// Circular Queue using circular linked list
#include <stdio.h>
#include<stdlib.h>

typedef struct BST{
    int data;
    struct BST *next;
    //struct BST *RC;
}node;

node *enqueue(node *tail,int x){    //Insert at End
    node *q=(node *)malloc(sizeof(node));
    q->data=x;
    q->next=q;
    if(tail==NULL){
        tail=q;
        //return tail;
    }
    else{
        q->next=tail->next;
        tail->next=q;
        tail=q;
    }
    return tail;
}

node *dequeue(node *tail){    //Delete at begin
    if(tail==NULL){
        printf("\nUnderFlow!!\n");
        return NULL;
    }
    else{
        node *temp1=tail->next;
        node *temp2=temp1->next;
        tail->next=temp2;
        temp1->next=NULL;
        free(temp1);
        return tail;
    }    
}

void print(node *tail){
    node *temp=tail->next;
    while(temp!=tail){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("%d -> first number",tail->data);
    printf("\n");
}

int main() {
    node *tail=NULL;
    tail=enqueue(tail,40);
    tail=enqueue(tail,50);
    tail=enqueue(tail,60);
    tail=enqueue(tail,70);
    tail=enqueue(tail,80);
    print(tail);
    tail=dequeue(tail);
    print(tail);
    tail=enqueue(tail,100);
    print(tail);
    tail=dequeue(tail);
    print(tail);

    return 0;
}
