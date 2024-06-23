// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Graph{
    char vertex;
    char parent;
    char Adj[10];
    int weight[10];
    int visited;
    int key;
};

int size = 0;
void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}
int parent(int i){
    return (i-1)/2;
}

void swap2(struct Graph *A, struct Graph *B){
    struct Graph temp = *A;
    *A = *B;
    *B = temp;
}

void heapify(struct Graph S[], int size, int i) {	
  
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && S[l].key < S[smallest].key)
      smallest = l;
    if (r < size && S[r].key < S[smallest].key)
      smallest = r;

    if (smallest != i) {
      swap2(&S[i], &S[smallest]);
      heapify(S, size, smallest);
    }
  
}
void shiftup(struct Graph S[],int i){
    while(i>0 && S[parent(i)].key>S[i].key){
        swap2(&S[parent(i)],&S[i]);
        i=parent(i);
    }
}

void insert(struct Graph S[] , char c) {
  if (size == 0) {
    S[0].vertex = c;
    size += 1;
  } 
  else {
    S[size].vertex = c;
    shiftup(S,size);
    size += 1;
  
  }
}


char extractMIN(struct Graph S[]) {
  swap2(&S[0], &S[size - 1]);
  size -= 1;
  heapify(S, size, 0);
  return S[size].vertex;

}



//void heapsort(int array[],int k){
//	int i;
  	//for( i=0;i<N;i++){
    //  	insert(array, (rand()%1000));
  	//}
//  	while(size!=0){
//    	extractMAX(array);
//  	}
//}

int inde(struct Graph S[],int i,int k){
	char c=S[i].Adj[k];
	for(i=0;i<10;i++){
		if(c==S[i].vertex){
			return i;
		}
	}
	
}

int count(struct Graph S[],int i){
	int j,c=0;
	//for(i=0;i<N;i++){
		for(j=0;j<10;j++){
			int k=S[i].Adj[j];
			if(k!=0){
				c++;
			}
			else
				break;
		}
		
	//}
	return c;
}

void Prim(struct Graph S[],int N, char B[]){
    int i,k,j,c;
    for(i=0;i<N;i++){
        S[i].vertex=B[i];
        S[i].parent='z';
        S[i].key=999;
        S[i].visited=0;
    }
    S[0].key=0;
    //struct Graph S1[N];
    for(i=0;i<N;i++){
    	insert(S,B[i]);
	}
    
    i=0;
    //j=N;
    /*for(i=0;i<N;i++){
        printf("%c ",S[i].vertex);
    }
    printf("\nExtract Min: %c\n",extractMIN(S));
    printf("\nExtract Min: %c\n",extractMIN(S));
    printf("\nExtract Min: %c\n",extractMIN(S));
    printf("\nExtract Min: %c\n",extractMIN(S));*/
    while(size>=0 && i<N){
        S[i].visited=1;
        S[i].vertex=extractMIN(S);
        
        //c=count(S,i);
        for(k=0;k<10;k++){
            if(S[i].weight[k]!=0){
            	int m=inde(S,i,k);
                if(S[m].visited==0 || S[m].weight[k]<S[m].key ){
                	S[m].parent=S[i].vertex;
                	S[m].key=S[m].weight[k];
                	S[m].visited=1;
    			}
            }		
			//printf("Index: %d\n",m);
        }
        //printf("Vertex : %c\n",S[i].vertex);
        //j=j-1;
        i=i+1;
    }
    
}

int main() {
    int **A,N,i,j,total_weight=0;
    char *B;
    printf("Enter Number of Vertices: ");
    scanf("%d",&N);
    struct Graph S[N];
    B=(char *)malloc(N*sizeof(char));
    A=(int **)malloc(N*sizeof(int *));
    for(i=0;i<N;i++){
        A[i]=(int *)malloc(N*sizeof(int));
    }
    for(i=0;i<N;i++){
        B[i]=97+i;
    }
    printf("-----Enter the Adjacency matrix-----\n\n");
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("Enter edge length of %c%c: ",B[i],B[j]);
            scanf("%d",&A[i][j]);
        }
    }
    for(i=0;i<N;i++){
        for(j=0;j<10;j++){
            S[i].weight[j]=0;
        }
    }
    //S[0].weight[0]=0;
    for(i=0;i<N;i++){
    	//S[i].vertex=B[i];
    	for(j=0;j<N;j++){
    		if(A[i][j]!=0){
    			//S[i].vertex=B[i];
    			S[i].Adj[j]=B[j];
    			S[i].weight[j]=A[i][j];
			}
		}
	}
	
	
	printf("\n\nPrinting The Adjacency Matrix:\n\n");
	for(i=0;i<N;i++){
	    for(j=0;j<N;j++){
	        printf("%d ",A[i][j]);
	    }
	    printf("\n");
	}
	/*printf("\nWeights:\n");
	
	for(i=0;i<N;i++){
	    for(j=0;j<5;j++){
	        printf("%d ",S[i].weight[j]);
	    }
	    printf("\n");
	}*/
	
	
	Prim(S,N,B);
	for(i=0;i<N;i++){
	    //printf("Vertex: %c\n",S[i].vertex);
	    //printf("Parent: %c\n",S[i].parent);
	    /*printf("Adjacent Vertex are: ");
	    for(j=0;j<count(S,i);j++){
	        printf("%c ",S[i].Adj[j]);
	    }*/
	    printf("\nKey of Vertex %c : %d \n\n",S[i].vertex,S[i].key);
	}
	for(i=0;i<N;i++){
		total_weight=total_weight+S[i].key;
	}
	printf("Total Weight of tree: %d",total_weight);
    return 0;
}
