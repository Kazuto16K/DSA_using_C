#include <stdio.h>

#define MAX 20
int k=0,m=0;
typedef struct edge {
  int u, v, w;
} edge;


typedef struct edge_list {
  edge data[MAX];
  //int n;
} edge_list;

edge_list elist;

int Graph[9][9]={0,4,0,0,0,0,0,8,0,
      4,0,8,0,0,0,0,11,0,
      0,8,0,7,0,4,0,0,2,
      0,0,7,0,9,14,0,0,0,
      0,0,0,9,0,10,0,0,0,
      0,0,4,14,10,0,2,0,0,
      0,0,0,0,0,2,0,1,6,
      8,11,0,0,0,0,1,0,7,
      0,0,2,0,0,0,6,7,0};
int n=9;
edge_list spanlist;

//void kruskalAlgo();
//int find(int belongs[], int vertexno);
void applyUnion(int belongs[], int c1, int c2);
//void print();

void swap(struct edge *a,struct edge *b){
	struct edge temp=*a;
	*a=*b;
	*b=temp;
}

int l_partition(int low, int high){
	int pivot=elist.data[high].w;
	//printf("elist.data[high].w : %d\n",elist.data[high].w);
	int i=low-1;
	int j;
	for(j=low;j<high;j++){
		if(elist.data[j].w<=pivot){
			i++;
			swap(&elist.data[i],&elist.data[j]);
		}
	}
	
	swap(&elist.data[i+1],&elist.data[high]);
	return i+1;
}

void quick(int low,int high){
	if(low<high){
		int q=l_partition(low,high);
		quick(low,q-1);
		quick(q+1,high);
	}
}

// Applying Krushkal Algo
void kruskalAlgo() {
  int belongs[MAX], i, j, cno1, cno2,e=0;
  

  for (i = 0; i < n; i++){
    for (j = 0; j < i; j++) {
      if (Graph[i][j] != 0) {
        elist.data[k].u = i;
        elist.data[k].v = j;
        elist.data[k].w = Graph[i][j];
        k++;
        e++;
      }
    }
  }
  printf("\nNo of edges: %d\n",e);
  /*int k2=0;
  for(i=0;i<8;i++){
      printf("%d ",elist.data[k2].u);
      printf("%d ",elist.data[k2].v);
      printf("%d ",elist.data[k2].w);
      printf("\n");
      k2++;
  }*/
    //sort();
  quick(0,e-1);
    int k2=0;
  for(i=0;i<e;i++){
      printf("%d ",elist.data[k2].u);
      printf("%d ",elist.data[k2].v);
      printf("%d ",elist.data[k2].w);
      printf("\n");
      k2++;
  }
  for (i = 0; i < n; i++)
    belongs[i] = i;

  //m = 0;

  for (i = 0; i < k; i++) {
    cno1 = find(belongs, elist.data[i].u);
    cno2 = find(belongs, elist.data[i].v);

    if (cno1 != cno2) {
      spanlist.data[m] = elist.data[i];
      m = m + 1;
      applyUnion(belongs, cno1, cno2);
    }
  }
}

int find(int belongs[], int vertexno) {
  return (belongs[vertexno]);
}

void applyUnion(int belongs[], int c1, int c2) {
  int i;

  for (i = 0; i < n; i++){
    if (belongs[i] == c2)
      belongs[i] = c1;
	}
}

// Sorting algo
void sort() {
  int i, j;
  edge temp;

  for (i = 1; i < k; i++)
    for (j = 0; j < k - 1; j++)
      if (elist.data[j].w > elist.data[j + 1].w) {
        temp = elist.data[j];
        elist.data[j] = elist.data[j + 1];
        elist.data[j + 1] = temp;
      }
}

// Printing the result
void print() {
  int i, cost = 0;

  for (i = 0; i < m; i++) {
    printf("\n%d - %d : %d", spanlist.data[i].v, spanlist.data[i].u, spanlist.data[i].w);
    cost = cost + spanlist.data[i].w;
  }

  printf("\nSpanning tree cost: %d", cost);
}

int main() {
  int i, j, total_cost;

  n = 9;
    
  
    printf("\nAdjaceny List:\n");
    for(i=0;i<n;i++){
        printf("%d -> \t",i);
        for(j=0;j<n;j++){
            if(Graph[i][j]!=0){
                printf("%d, ",j);
            }
            
        }
        printf("\n");
    }
    /*printf("\nAdjacency matrix!\n\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",Graph[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");*/
  kruskalAlgo();
  print();
}
