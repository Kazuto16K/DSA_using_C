#include<stdio.h>
#include<stdlib.h>
int size=0;
int parent(int i){
    return (i-1)/2;
}

void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

void heapify(int **Q, int size, int i) {	
  
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && Q[1][l] < Q[1][smallest])
      smallest = l;
    if (r < size && Q[1][r] < Q[1][smallest])
      smallest = r;

    if (smallest != i) { 
    	
      swap(&Q[0][i], &Q[0][smallest]);	
      swap(&Q[1][i], &Q[1][smallest]);
      swap(&Q[2][i], &Q[2][smallest]);
      swap(&Q[3][i], &Q[3][smallest]);
      heapify(Q, size, smallest);
    }
  
}

void shiftup(int **Q,int i){
    while(i>0 && Q[1][parent(i)]>Q[1][i]){
    	swap(&Q[0][parent(i)],&Q[0][i]);
        swap(&Q[1][parent(i)],&Q[1][i]);
        swap(&Q[2][parent(i)],&Q[2][i]);
		swap(&Q[3][parent(i)],&Q[3][i]);        
        i=parent(i);
    }
}

void insert(int **Q,int *parent,int *Key,int *Visit){
	if(size==0){
		Q[0][0]=parent[0];
		Q[1][0]=Key[0];
		Q[2][0]=Visit[0];
		Q[3][0]=0;
		size=size+1;
	}
	else{
		Q[0][size]=parent[size];
		Q[1][size]=Key[size];
		Q[2][size]=Visit[size];
		Q[3][size]=size;
		size=size+1;
	}
}

int extractMIN(int **Q,int *Key,int *Visit,int N){
    int j;
    //for(j=size/2;j>=0;j--)
	//   heapify(Q,size,j); 
	
    int i=Q[3][0];
	swap(&Q[0][0],&Q[0][size-1]);
	swap(&Q[1][0],&Q[1][size-1]);
	swap(&Q[2][0],&Q[2][size-1]);
	swap(&Q[3][0],&Q[3][size-1]);
	size=size-1;
	heapify(Q,size,0);
	if(Visit[i]==0 && Key[i]<=Q[1][size]){
		return i;
	}
	
}

void printMST(int *parent,int A[][9],int N){
	printf("Edge\tWeight\n");
	int i,weight=0;
	for(i=1;i<N;i++){
		printf("%d-%d \t %d\n",parent[i],i,A[i][parent[i]]);
		weight=weight+A[i][parent[i]];
	}
	printf("\nWeight of the Graph: %d",weight);
}

void Prim(int A[][9],int N){
	int *parent;
	int *Key;
	int *Visit,i,j,c;
	int **Q;
	parent=(int *)malloc(N*sizeof(int));
	Key=(int *)malloc(N*sizeof(int));
	Visit=(int *)malloc(N*sizeof(int));
	Q=(int **)malloc(4*sizeof(int *));
	for(i=0;i<4;i++){
	    Q[i]=(int *)malloc(N*sizeof(int));
	}
	for(i=0;i<N;i++){
		parent[i]=0;
		Key[i]=9999;
		Visit[i]=0;
	}
	parent[0]=-1;
	Key[0]=0;
	for(i=0;i<N;i++){
		insert(Q,parent,Key,Visit);
	}
	
	for(i=0;i<N;i++){
		int u=extractMIN(Q,Key,Visit,N);
		printf("Extracted Key: %d\n",u);
		Visit[u]=1;
		for(j=0;j<N;j++){
			if(A[u][j]!=0 && Visit[j]==0 && A[u][j]<Key[j]){
				parent[j]=u;
				Key[j]=A[u][j];
				for(c=0;c<size;c++){
				    if(Q[3][c]==j){
				        Q[0][c]=u;
				        Q[1][c]=A[u][j];
				        shiftup(Q,c);
				    }
				}
			}
		}
	}
	printMST(parent,A,N);
}

int main() {
    int N=9,i,j,total_weight=0;
    int A[9][9]={0,4,0,0,0,0,0,8,0,
      4,0,8,0,0,0,0,11,0,
      0,8,0,7,0,4,0,0,2,
      0,0,7,0,9,14,0,0,0,
      0,0,0,9,0,10,0,0,0,
      0,0,4,14,10,0,2,0,0,
      0,0,0,0,0,2,0,1,6,
      8,11,0,0,0,0,1,0,7,
      0,0,2,0,0,0,6,7,0};
    Prim(A,N);
}
    

