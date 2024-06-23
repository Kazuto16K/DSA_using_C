#include <stdlib.h>
#include <stdio.h>

void transpose(int **C,int row,int col){
    int **D,i,j;
    D=(int **)malloc(col*sizeof(int *));
    for(i=0;i<col;i++){
        D[i]=(int *)malloc(row*sizeof(int));
    }
    
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            D[j][i]=C[i][j];
        }
    }
    
    printf("\nThe Transpose is::\n");
    for(i=0;i<col;i++){
        for(j=0;j<row;j++){
            printf("%d   ",D[i][j]);
        }
        printf("\n");
    }
    
}


int main() {
    int **A,**B;
    int row,col,i,k=0,j,z;
    printf("Enter number of rows:");
    scanf("%d",&row);
    printf("Enter number of columns:");
    scanf("%d",&col);
    A=(int **)malloc(row*sizeof(int *));
    for(i=0;i<row;i++){
        A[i]=(int *)malloc(col*sizeof(int));
    }
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("Enter %d%dth Element: ",i+1,j+1);
            scanf("%d",&A[i][j]);
            if(A[i][j]!=0){
                k++;
            }
        }
    }
    
    B=(int **)malloc((k+1)*sizeof(int *));
    for(i=0;i<k+1;i++){
        B[i]=(int *)malloc(3*sizeof(int));
    }
    
    if((row*col)>((k+1)*3)){
        printf("Triplet Form Can be generated!!");
        z=1;
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                if(A[i][j]!=0){
                    B[z][0]=i;
                    B[z][1]=j;
                    B[z][2]=A[i][j];
                    z++;
                }
                
                   
            }
        }
        B[0][0]=row;
        B[0][1]=col;
        B[0][2]=k;
    }
    printf("\nThe Matrix is::\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%d   ",A[i][j]);
        }
        printf("\n");
    }
    printf("The Triplet Matrix is:: \n");
    for(i=0;i<k+1;i++){
        for(j=0;j<3;j++){
            printf("%d   ",B[i][j]);
        }
        printf("\n");
    }
    
    transpose(A,row,col);
    

    return 0;
}
