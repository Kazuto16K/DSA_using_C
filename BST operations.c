// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

typedef struct BST{
    int data;
    struct BST *LC;
    struct BST *RC;
}node;

node *move(node *head,int x){
    if(head->data>x){
        if(head->LC!=NULL){
            return move(head->LC,x);
        }
        else
            return head;
    }
    else{
        if(head->RC!=NULL){
            return move(head->RC,x);
        }
        else
            return head;
    }
}

node *insert(node *head,int x){
    node *q=(node *)malloc(sizeof(node));
    q->data=x;
    q->LC=NULL;
    q->RC=NULL;
    if(head==NULL){
        head=q;
        return head;
    }
    else{
        node *temp=head;
        node *parent=move(head,x);
        if(parent->data>x){
            parent->LC=q;
        }
        else{
            parent->RC=q;
        }
        return temp;
    }
}

node *search(node *head,int x){
    if(head==NULL){
        printf("\nData Not Found!!\n");
        return head;
    }
    else if(head->data==x){
        return head;
    }
    else if(head->data>x){
        return search(head->LC,x);
    }
    else
        return search(head->RC,x);
        
}

node *min(node *p){
    if(p==NULL||p->LC==NULL){
        return p;
    }
    else
        return min(p->LC);
}

node *del(node *head,int x){
    if(head==NULL){
        printf("\nData not Found!!\n");
        return head;
    }
    else if(head->data>x){
        head->LC=del(head->LC,x);
    }
    else if(head->data<x){
        head->RC=del(head->RC,x);
    }
    else{
        if(head->LC==NULL){
            node *temp=head->RC;
            free(head);
            return temp;
        }
        else if(head->RC==NULL){
            node *temp=head->LC;
            free(head);
            return temp;
        }
        else{
            node *temp=min(head->RC);
            head->data=temp->data;
            head->RC=del(head->RC,temp->data);
        }
        
    }
    return head;
    
    
}

void inorder(node *head){
    if(head){
        inorder(head->LC);
        printf("%d ",head->data);
        inorder(head->RC);
    }
}

void preorder(node *head){
    if(head){
        printf("%d ",head->data);
        preorder(head->LC);
        preorder(head->RC);
    }
}
int main() {
    node *head=NULL;
    head=insert(head,3);
    head=insert(head,5);
    head=insert(head,2);
    head=insert(head,4);
    head=insert(head,11);
    head=insert(head,7);
    head=del(head,19);
    preorder(head);
    printf("\n");
    del(head,7);
    inorder(head);
    return 0;
}
