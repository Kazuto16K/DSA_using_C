#include<stdlib.h>
#include <stdio.h>

void swap1(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void swap2(float *a,float *b){
	float temp=*a;
	*a=*b;
	*b=temp;
}


void knapsack(float *V,int **A,int n,float size){
    int i;
    for(i=0;i<n;i++){
        V[i]=0.0;
    }
    for(i=0;i<n;i++){
        if(A[1][i]>size){
            break;
        }
        V[i]=1.0;
        size=size-A[1][i];
    }
    if(i<=n){
        V[i]=(float)(size/A[1][i]);
    }
    
}

int main() {
   int **A,i,j,N;
   float *P,*V,profit=0,size;
   printf("Enter Size of Knapsack: ");
   scanf("%f",&size);
   printf("Enter Number of Elements: ");
   scanf("%d",&N);
   A=(int **)malloc(2*sizeof(int *));
   for(i=0;i<2;i++){
   		A[i]=(int *)malloc(N*sizeof(int));
   }
   P=(float *)malloc(N*sizeof(float));
   V=(float *)malloc(N*sizeof(float));
   for(i=0;i<N;i++){
           printf("Enter Profit of Element %d:",i+1);
           scanf("%d",&A[0][i]);
           printf("Enter Weight of Element %d:",i+1);
           scanf("%d",&A[1][i]);
           
   }
   
   //Printing The Input
   printf("\n****The Input Array****\n");
   for(i=0;i<2;i++){
        for(j=0;j<N;j++){
            printf("%d  ",A[i][j]);
        }
        printf("\n");
    }
    printf("The profit/weight Array:\n");
    for(i=0;i<N;i++){
        P[i]=(float)(A[0][i]/A[1][i]);
    }
    
    //printf("The profit Array::\n");
    for(i=0;i<N;i++){
        printf("%.2f  ",P[i]);
    }
    for(j=0;j<N;j++){
        for(i=0;i<N-j-1;i++){
            if(P[i]<P[i+1]){
                swap1(&A[0][i],&A[0][i+1]);
                swap1(&A[1][i],&A[1][i+1]);
                swap2(&P[i],&P[i+1]);
            }
        }
    }
    printf("\n\n");
    for(i=0;i<2;i++){
        for(j=0;j<N;j++){
            printf("%d  ",A[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    knapsack(V,A,N,size);
    printf("The profit Array::\n");
    for(i=0;i<N;i++){
        printf("%.2f  ",P[i]);
    }
    printf("\n\n");
    printf("The knapsack vector is:\n");
    for(i=0;i<N;i++){
        printf("%.2f  ",V[i]);
        profit=profit+(V[i]*A[0][i]);
    }
    printf("\nThe Profit is :: %.2f\n",profit);
    return 0;
}
