// Online C compiler to run C program online
#include <stdio.h>

int stack[20];
int top=-1;

void push(char s){
    stack[++top]=s;
}

char pop(){
    if(top==-1){
        return -1;
    }
    else{
        return stack[top--];
    }    
}

int priority(char s){
    if(s=='('){
        return 0;
    }
    else if(s=='+' || s=='-'){
        return 1;
    }
    else if(s=='*' || s=='/'){
        return 2;
    }
    else if(s=='^'){
        return 3;
    }
    return 0;
}

int main() {
    char a[30];
    char *s,x;
    printf("Enter the expression:: ");
    gets(a);
    s=a;
    while(*s!='\0'){
        if(isalnum(*s)){
            printf("%c",*s);
        }
        else if(*s=='('){
            push(*s);
        }
        else if(*s==')'){
            while((x=pop())!='('){
                printf("%c",x);
            }
        }
        else {
            while(priority(stack[top])>=priority(*s)){
                printf("%c",pop());
            }    
            push(*s);
        }
        s++;
    }
    while(top!=-1){
        printf("%c",pop());
    }

    return 0;
}
