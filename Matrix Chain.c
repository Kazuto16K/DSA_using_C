#include <stdio.h>
#define MAX 20
#include<stdlib.h>
int M[MAX][MAX];
int S[MAX][MAX];



void Matrix_Chain(int P[]){
    int n=4; 
    int i,j,l,k,q;
    for(i=1;i<=n;i++){
        M[i][i]=0;
    }
    for(l=2;l<=n;l++){
        for(i=1;i<=n-l+1;i++){
            j=i+l-1;
            M[i][j]=99999999;
            for(k=i;k<=j-1;k++){
                q=M[i][k]+M[k+1][j]+P[i-1]*P[k]*P[j];
                if(q<M[i][j]){
                    M[i][j]=q;
                    S[i][j]=k;
                }
            }
        }
    }
    
}

void print_parens(int i,int j){
    if(i==j){
        printf("A%d",i);
    }
    else{
        printf("(");
        print_parens(i,S[i][j]);
        print_parens(S[i][j]+1,j);
        printf(")");
    }
}


int main() {
    int P[]={13,5,89,3,34};
    int i,j;
    Matrix_Chain(P);
    print_parens(1,4);
	printf("\nMINIMUM NUMBER OF MULTIPLICATIONS: %d\n",M[1][4]);

    return 0;
}
