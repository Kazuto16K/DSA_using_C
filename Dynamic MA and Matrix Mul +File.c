#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int r1,c1,i,j,k,r2,c2;
	int **A,**B,**R;
	FILE *fp,*fr;
	fp=fopen("gen.txt","w+");
	fr=fopen("res.txt","w+");
	printf("Enter Row of Mat 1: ");
	scanf("%d",&r1);
	printf("Enter Col of Mat 1: ");
	scanf("%d",&c1);
	printf("Enter Row of Mat 2: ");
	scanf("%d",&r2);
	printf("Enter Col of Mat 2: ");
	scanf("%d",&c2);
	
	if(c1!=r2){
		printf("Matrix Multipliction not possible!!");
	}
	else{
		srand(time(NULL));
		//For Matrix 1 into TXT FILE
		for(i=0;i<r1;i++){
			for(j=0;j<c1;j++){
				
				fprintf(fp,"%d ",rand()%10);
			}
			fprintf(fp,"\n");
		}
		fprintf(fp,"\n");
		for(i=0;i<r1;i++){
			for(j=0;j<c1;j++){
				
				fprintf(fp,"%d ",rand()%10);
			}
			fprintf(fp,"\n");
		}
		rewind(fp);
		A=(int **)malloc(r1*sizeof(int *));
		for(i=0;i<r1;i++){
			A[i]=(int *)malloc(c1*sizeof(int));
		}
		B=(int **)malloc(r2*sizeof(int *));
		for(i=0;i<r2;i++){
			B[i]=(int *)malloc(c2*sizeof(int));
		}
		R=(int **)malloc(r1*sizeof(int *));
		for(i=0;i<r1;i++){
			R[i]=(int *)malloc(c2*sizeof(int));
		}
		//ENTERING VALUES OF MATRIX 1
		for(i=0;i<r1;i++){
			for(j=0;j<c1;j++){
				fscanf(fp,"%d",&A[i][j]);
			}
		}
		//ENTERING VALUES OF MATRIX 2
		for(i=0;i<r2;i++){
			for(j=0;j<c2;j++){
				fscanf(fp,"%d",&B[i][j]);
			}
		}
		//GENERATING MULTIPLED MATRIX
		for(i=0;i<r1;i++){
			for(j=0;j<c2;j++){
				R[i][j]=0;
				for(k=0;k<c1;k++){
					R[i][j]+=A[i][k]*B[k][j];
				}
			}
		}
		//PRINTING MATRIX 1
		printf("\n\n");
		printf("*****Printing Matrix 1*****\n");
		for(i=0;i<r1;i++){
			for(j=0;j<c1;j++){
				printf("%d   ",A[i][j]);
			}
			printf("\n");
		}
		//PRINTING MATRIX 2
		printf("\n\n");
		printf("*****Printing Matrix 2*****\n");
		for(i=0;i<r2;i++){
			for(j=0;j<c2;j++){
				printf("%d   ",B[i][j]);
			}
			printf("\n");
		}
		//PRINTING RESULTANT MATRIX 
		printf("\n\n");
		printf("*****Printing Resultant Matrix*****\n");
		for(i=0;i<r1;i++){
			for(j=0;j<c2;j++){
				printf("%d   ",R[i][j]);
			}
			printf("\n");
		}
		//ENTERING MATRIX INTO TXT FILE
		printf("\n\n");
		for(i=0;i<r1;i++){
			for(j=0;j<c1;j++){
				fprintf(fr,"%d",R[i][j]);
			}
			fprintf(fr,"\n");
		}
		fclose(fp);
		fclose(fr);
	}
}
