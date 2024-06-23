// Online C compiler to run C program online
#include <stdio.h>

void push(int S[],int *top,int x){
    S[*top+1]=x;
    *top=*top+1;
}

int pop(int S[],int *top){
    int k=S[*top];
    *top=*top-1;
    return k;
}

void enqueue(int S1[],int *top1,int x){
    push(S1,top1,x);
}

void dequeue(int S1[],int S2[],int *top1,int *top2){
    if(*top2==-1){
        if(*top1==-1){
            printf(" UnderFlow!! \n");
        }
        else{
            while(*top1!=-1){
                int x=pop(S1,top1);
                push(S2,top2,x);
            }
            int x=pop(S2,top2);
            printf("\nPopped Element: %d\n",x);
        }    
    }
    else{
        int x=pop(S2,top2);
        printf("\nPopped Element: %d\n",x);
    }
}

void print(int S1[],int S2[],int *top1,int *top2){
    int x,y;
    printf("\nThe queue from first to last is::  ");
    for(y=*top2;y>=0;y--){
        printf("%d ",S2[y]);
    }
    for(x=0;x<=*top1;x++){
        printf("%d ",S1[x]);
    }
}
int main() {
    int S1[10],S2[10];
    int top1=-1;
    int top2=-1;
    dequeue(S1,S2,&top1,&top2);
    enqueue(S1,&top1,5);
    enqueue(S1,&top1,7);
    enqueue(S1,&top1,9);
    enqueue(S1,&top1,11);
    enqueue(S1,&top1,13);
    print(S1,S2,&top1,&top2);
    dequeue(S1,S2,&top1,&top2);
    dequeue(S1,S2,&top1,&top2);
    print(S1,S2,&top1,&top2);

    return 0;
}
