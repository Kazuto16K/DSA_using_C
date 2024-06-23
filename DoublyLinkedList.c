#include<stdio.h>
#include<stdlib.h>

typedef struct List{
	int data;
	struct list *prev;
	struct list *next;
}node;

int n;

node *create(node *head){
	int i;
	printf("Enter number of more nodes to Enter: ");
	scanf("%d",&n);
	node *temp=head;
	for(i=0;i<n;i++){
	
		int value;
		node *q=(node *)malloc(sizeof(node));
		printf("Enter Value of next node: ");
		scanf("%d",&value);
		q->data=value;
		q->prev=head;
		q->next=NULL;
		head->next=q;
		head=q;
			
	}
	return temp;
}

void display(node *head){
	node *q=head;
	while(q->next!=NULL){
		printf(" %d <=>",q->data);
		q=q->next;
	}
	printf(" %d <=>",q->data);
	printf("NULL\n\n");
}

node *insertBegin(node *head){
	int val1;
	node *q=(node *)malloc(sizeof(node));
	q->next=q->prev=NULL;
	printf("Enter the Value to Enter: ");
	scanf("%d",&val1);
	if(head==NULL){
	    head->data=val1;
	    head->next=head->prev=NULL;
	    return head;
	}
	else{
    	q->data=val1;
    	head->prev=q;
    	q->next=head;
    	n=n+1;
    	return q;
	}	
	
}
node *insertEnd(node *head){
	int val1;
	node *temp=head;
	node *q=(node *)malloc(sizeof(node));
	//q->next=q->prev=NULL;
	while(head->next!=NULL){
		head=head->next;
	}
	printf("Enter the value to Enter: ");
	scanf("%d",&val1);
	q->data=val1;
	head->next=q;
	q->prev=head;
	n=n+1;
	return temp;
}

node *insertAny(node *head,int n){
	node *temp=head;
	int i, pos;
	printf("Enter the position : ");
	scanf("%d",&pos);
	if(pos==0){
		temp=insertBegin(head);
	}
	else if(pos==n){
		temp=insertEnd(head);
	}
	else{
	
		if(pos>n){
			printf("\nWrong Position!!Cannot Enter Value!!\n");
		}
		else{
			for(i=0;i<pos-1;i++){
				head=head->next;
				
			}
			int val1;
			node *q=(node *)malloc(sizeof(node));
			printf("Enter the value to Enter: ");
			scanf("%d",&val1);
			q->data=val1;
			node *j=head->next;
			head->next=q;
			q->next=j;
			j->prev=q;
			q->prev=head;
		}
	}
	n=n+1;
	return temp;
}

node *delBegin(node *head){
	node *temp=head;
	if(head->next!=NULL){
		head=head->next;
	}
	head->prev=NULL;
	temp->next=NULL;
	free(temp);
	n=n-1;
	return head;
}

node *delEnd(node *head){
	node *temp=head;
	while(head->next!=NULL){
		head=head->next;
		
	}
	node *j=head->prev;
	j->next=NULL;
	head->prev=NULL;
	free(head);
	n=n-1;
	return temp;
	
}
node *delMid(node *head,int position){
	node *temp=head;
	if(position==0){
		temp=delBegin(head);
	}
	else if(position==n-1){
		temp=delEnd(head);
	}
	else{
		int i;
		for(i=0;i<position-1;i++){
			head=head->next;
		}
		node *j=head->next;
		head->next=j->next;
		node *m=j->next; //->prev=head;
		m->prev=head;
		j->next=NULL;
		j->prev=NULL;
		n=n-1;
		free(j);
	}
	
	
	return temp;
	
	
}


int main(){

	node *head=(node *)malloc(sizeof(node));
	while(1){
		int ch;
		printf("*****Doubly linked List operations*****\n\n");
		printf("1.Create\n2.Insert\n3.Delete\n4.Display\n5.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		if(ch==1){
			int val;
			printf("enter value of head node: ");
			scanf("%d",&val);
			head->data=val;
			head->prev=NULL;
			head=create(head);
		}
		else if(ch==2){
			int ch1;
			printf("\n\n1.Insert at Begin\n2.Insert at a Position\n3.Insert at End\n");
			printf("\nEnter Your Choice: ");
			scanf("%d",&ch1);
			if(ch1==1){
				head=insertBegin(head);
			}
			else if(ch1==2){
				head=insertAny(head,n);
			}
			else if(ch1==3){
				head=insertEnd(head);
			}
			else{
				printf("Wrong choice!!");
			}
		}
		else if(ch==3){
			int ch2;
			printf("\n\n1.Delete at begin\n2.Delete at Mid\n3.Delete at end\n");
			printf("Enter your choice:");
			scanf("%d",&ch2);
			if(ch2==1){
				head=delBegin(head);
			}
			else if(ch2==2){
				int position;
				printf("Enter the position: ");
				scanf("%d",&position);
				if(position>n){
					printf("Wrong Position!!");
				}
				else{
					head=delMid(head,position);
				}
			}
			else{
			    head=delEnd(head);
			}
		}
		else if(ch==4){
			display(head);
		}
		else if(ch==5){
		    break;
		}
		else{
		    printf("Wrong choice!! Try again!!");
		}
	}
}
	
	
	
	
	
	
	
