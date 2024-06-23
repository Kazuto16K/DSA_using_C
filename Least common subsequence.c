// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>


/*typedef struct Info{
    int val;
    int diag=0;
    int up=0;
    int left=0;
}info;*/

/*typedef struct Matrix{
    info data[30][30];
}matrix;

matrix table;*/

int length(char A[]){
    int i,c=0;
    for(i=0;i<100;i++){
        if(A[i]==0){
            break;
        }
        c++;
    }
    return c;
}

void shift(char A[],int len){
    int i;
    for(i=len-1;i>=0;i--){
        A[i+1]=A[i];
    }
}

void LCS(char X[],int l1,char Y[],int l2,int **B){
    int **C,i,j;
    
    
    C=(int **)malloc((l1+1)*sizeof(int *));
    for(i=0;i<l1+1;i++){
        C[i]=(int *)malloc((l2+1)*sizeof(int));
    }
    
    for(i=0;i<l2+1;i++){
        B[0][i]=0;
        C[0][i]=0;
    }
    for(i=0;i<l1+1;i++){
        B[i][0]=0;
        C[i][0]=0;
    }
    for(i=1;i<=l1;i++){
        for(j=1;j<=l2;j++){
        	int k=rand()%2+1;
            if(X[i]==Y[j]){
                C[i][j]=C[i-1][j-1]+1;
                B[i][j]=3;      //Diagonal =3 , Up=2, Left=1
            }
            
            else{
                if(C[i-1][j]>=C[i][j-1]){
                    C[i][j]=C[i-1][j];
                    B[i][j]=k;
                }
                else{
                    C[i][j]=C[i][j-1];
                    B[i][j]=k;
                }
            } 
        }
    }
    
    for(i=0;i<l1+1;i++){
    	for(j=0;j<l2+1;j++){
    		printf("%d ",C[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	for(i=0;i<l1+1;i++){
    	for(j=0;j<l2+1;j++){
    		printf("%d ",B[i][j]);
		}
		printf("\n");
	}
}

void Print_LCS(int **B,char X[],int i,int j){
    if((i==0) || (j==0)){
        return;
    }
    if(B[i][j]==3){
        Print_LCS(B,X,i-1,j-1);
        printf("%c ",X[i]);
    }
    else if(B[i][j]==2){
        Print_LCS(B,X,i-1,j);
    }
    else{
        Print_LCS(B,X,i,j-1);
    }
}

int main() {
    char X[100],Y[100],a,b,i;
    int **B;
    printf("Enter String X: ");
    gets(X);
    printf("Enter String Y: ");
    gets(Y);
    a=length(X);
    b=length(Y);
    shift(X,a);
    shift(Y,b);
    X[0]='x';
    Y[0]='y';
    B=(int **)malloc((a+1)*sizeof(int *));
    for(i=0;i<a+1;i++){
        B[i]=(int *)malloc((b+1)*sizeof(int));
    }
    LCS(X,a,Y,b,B);
    Print_LCS(B,X,a,b);
    printf("\n\n");
    LCS(X,a,Y,b,B);
    Print_LCS(B,X,a,b);
    return 0;
}
