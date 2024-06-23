#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int size=0,N;

typedef struct vertex{
    int vc;
	int index[MAX];
	int Adj[MAX];
}ver;

typedef struct Adj_list{
	ver data[MAX];
}Alist;

Alist list;

int parent(int i){
    return (i-1)/2;
}

void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

int len(int s){
	int c,i;
	for(i=0;i<MAX;i++){
		if(list.data[s].Adj[i]==0){
			break;
		}
		c++;
	}
	return c;
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

void insert(int **Q,int parent[],int d[],int Visit[]){
	if(size==0){
		Q[0][0]=parent[0];
		Q[1][0]=d[0];
		Q[2][0]=Visit[0];
		Q[3][0]=0;
		size=size+1;
	}
	else{
		Q[0][size]=parent[size];
		Q[1][size]=d[size];
		Q[2][size]=Visit[size];
		Q[3][size]=size;
		shiftup(Q,size);
		size=size+1;
	}
}

int extractMIN(int **Q,int d[],int Visit[]){
    int j;
    for(j=size/2;j>=0;j--)
	   heapify(Q,size,j); 
	
    int i=Q[3][0];
	swap(&Q[0][0],&Q[0][size-1]);
	swap(&Q[1][0],&Q[1][size-1]);
	swap(&Q[2][0],&Q[2][size-1]);
	swap(&Q[3][0],&Q[3][size-1]);
	size=size-1;
	if(Visit[i]==0 && d[i]<=Q[1][size-1]){
		return i;
	}
	
}

void printPATH(int d[],int parent[],int src, int dest){
	if(src==dest){
	    printf("%d",src);
	    return;
	}
	else{
	    printPATH(d,parent,src,parent[dest]);
	    printf(" -> %d",dest);
	}
}

void Dijktras(int s){
	int Parent[MAX],d[MAX],Visit[MAX];
	int i,j,c,v;
	int **Q;
	Q=(int **)malloc(4*sizeof(int *));
	for(i=0;i<4;i++){
	    Q[i]=(int *)malloc(N*sizeof(int));
	}
	for(i=0;i<N;i++){
		Parent[i]=0;
		d[i]=9999;
		Visit[i]=0;
	}
	Parent[s]=-1;
	d[s]=0;
	for(i=0;i<N;i++){
		insert(Q,Parent,d,Visit);
	}
	
	
	for(i=0;i<N;i++){
		int u=extractMIN(Q,d,Visit);
		Visit[u]=1;
		
		
		for(v=0;v<list.data[u].vc;v++){
		    int m=list.data[u].index[v];
			if( Visit[m]==0 && (d[m]>d[u]+list.data[u].Adj[v])){
				d[m]=d[u]+list.data[u].Adj[v];
				Parent[m]=u;
				for(c=0;c<size;c++){
				    if(Q[3][c]==m){
				        Q[0][c]=u;
				        Q[1][c]=d[m];
				        shiftup(Q,c);
				    }
		    	}
				
			}
			
		}
		
	}
	
	for(i=0;i<N;i++){
	
		printPATH(d,Parent,s,i);
		printf("\nPath Length Between Src(%d) to Dest(%d) : %d\n\n",s,i,d[i]);
	}
	
}

int main() {
    int i,j,source;
    N=5;
    int A[5][5]={0,10,0,5,0,
        0,0,1,2,0,
        0,0,0,0,4,
        0,3,9,0,2,
        7,0,6,0,0};
      
    for(i=0;i<N;i++)  {
        list.data[i].vc=0;
        int k=0;
        for(j=0;j<N;j++){
            if(A[i][j]!=0){
                list.data[i].index[k]=j;
                list.data[i].Adj[k]=A[i][j];
                list.data[i].vc++;
                k++;
            }    
        }
    }
    printf("\nAdjacency List\n");
    for(i=0;i<N;i++)  {
        printf("%d -> ",i);
        for(j=0;j<list.data[i].vc;j++){
            printf("%d,",list.data[i].index[j]);
            
        }
        printf("\n");
    }
    printf("\n\n");
    printf("Enter Source: ");
    scanf("%d",&source);
    
    Dijktras(source);
}
    

