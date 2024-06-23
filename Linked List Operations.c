// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

int count(node *head){
    int i=0;
    node *temp=head;
    if(head==NULL){
        return 0;    
    }
    else{
        while(temp->next!=NULL){
            i++;
            temp=temp->next;
        }
        i=i+1;
        return i;
    }    
}

int countelement(node *head,int x){
    int i=0;
    node *temp=head;
    if(head==NULL){
        return 0;    
    }
    else{
        while(temp->next!=NULL){
            if(temp->data==x){
                i++;
            }
            temp=temp->next;
        }
        if(temp->data==x){
                i++;
        }
        return i;
    }    
}


node *insertbegin(node *head,int x){
    node *q=(node *)malloc(sizeof(node));
    q->data=x;
    q->next=NULL;
    if(head==NULL){
        head=q;
        return head;
    }
    else{
        q->next=head;
        head=q;
        return head;
    }
}

node *insertend(node *head,int x){
    node *q=(node *)malloc(sizeof(node));
    q->data=x;
    q->next=NULL;
    if(head==NULL){
        head=q;
        return head;
    }
    else{
        node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=q;
        return head;
    }
}

node *insertposi(node *head,int x){
    node *q=(node *)malloc(sizeof(node));
    q->data=x;
    q->next=NULL;
    int pos,i;
    node *temp=head;
    printf("\nEnter Position: ");
    scanf("%d",&pos);
    if(pos>count(head)){
        printf("Invalid Position!!");
        return head;
    }
    else{
        if(pos==0){
            head=insertbegin(head,x);
        }
        else if(pos==count(head)){
            head=insertend(head,x);
        }
        else{
            for(i=0;i<pos;i++){
                temp=temp->next;
            }
            node *temp1=temp->next;
            temp->next=q;
            q->next=temp1;
        }
        return head;
    }
}

node *insert(node *head,int x){
    int ch;
    printf("\n1.Enter at Begin\n2.Enter at Position\n3.Enter at End\nEnter your choice: ");
    scanf("%d",&ch);
    if(ch==1){
        head=insertbegin(head,x);
    }
    else if(ch==2){
        head=insertposi(head,x);
    }
    else{
        head=insertend(head,x);
    }
    return head;
}

node *delbyvalue(node *head,int x){
    int j;
    
    if(countelement(head,x)==0){
        printf("Data not Found!!");
    }
    int m=countelement(head,x);
    for(j=0;j<m;j++){
        node *temp=head;
        if(head->data==x){
            head=head->next;
            temp->next =NULL;
            free(temp);
            continue;
        }
        node *temp1=head,*temp2;
        while(temp->data!=x){
            temp1=temp;
            temp=temp->next;
        }
        temp2=temp->next;
        temp->next=NULL;
        temp1->next=temp2;
        free(temp);
    }
    
    return head;
}

node *create(node *head){
    while(1){
        int val;
        printf("Enter Value of Node(-1 to stop):: ");
        scanf("%d",&val);
        if(val==-1){
            break;
        }
        else{
            head=insertend(head,val);
        }
    }
    return head;
}

int search(node *head,int x){
    int i=0;
    if(head==NULL){
        printf("Data not Found,Empty Linked List!!");
        return -1;
    }
    else if(countelement(head,x)==0){
        printf("Data not in linked list");
        return -1;
    }
    else{
        node *temp=head;
        while(temp->data!=x){
            i++;
            temp=temp->next;
        }
        return i;
    }
    
}

void print(node *head){
    node *temp=head;
    if(temp==NULL){
        printf("\nList is Empty!!\n");
    }
    else{
        while(temp->next!=NULL){
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
        printf("%d -> NULL",temp->data);
    }    
}

int main() {
    node *head=NULL;
    printf("Creating a Linked List::\n");
    head=create(head);
    while(1){
        int ch;
        printf("\n1.Insert\n2.Delete\n3.Search Index\n4.Print\n5.Exit\n");
        printf("Enter Your choice:: ");
        scanf("%d",&ch);
        if(ch==1){
            int x;
            printf("\nEnter value to be Inserted: ");
            scanf("%d",&x);
            head=insert(head,x);
        }
        else if(ch==2){
            int x;
            printf("\nEnter value to be Deleted: ");
            scanf("%d",&x);
            head=delbyvalue(head,x);
        }
        else if(ch==3){
            int x;
            printf("\nEnter value to be Searched: ");
            scanf("%d",&x);
            int loc=search(head,x);
            if(loc!=-1){
                printf("The Index of element is:: %d",loc);
            }    
        }
        else if(ch==4){
            print(head);
        }
        else if(ch==5){
            break;
        }
        else{
            printf("\nWrong option!! Try again\n");
        }
    }
}
