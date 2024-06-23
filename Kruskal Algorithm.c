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
edge_list flist;

int n=9;

void swap(struct edge *a,struct edge *b){
	struct edge temp=*a;
	*a=*b;
	*b=temp;
}

int l_partition(int low, int high){
	int pivot=elist.data[high].w;
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

int find(int set[], int vertexno) {
  return (set[vertexno]);
}

void applyUnion(int set[], int c1, int c2) {
  int i;

  for (i = 0; i < n; i++){
    if (set[i] == c2)
      set[i] = c1;
	}
}


void kruskal(int Graph[][9]) {
  int set[MAX], i, j, c1, c2,e=0;
  

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
  
  
  quick(0,e-1);
    int k2=0;
  
  for (i = 0; i < n; i++)
    set[i] = i;

  

  for (i = 0; i < k; i++) {
    c1 = find(set, elist.data[i].u);
    c2 = find(set, elist.data[i].v);

    if (c1 != c2) {
      flist.data[m] = elist.data[i];
      m = m + 1;
      applyUnion(set, c1, c2);
    }
  }
}


void print() {
  int i, weight = 0;

  for (i = 0; i < m; i++) {
    printf("\n%d - %d : %d", flist.data[i].v, flist.data[i].u, flist.data[i].w);
    weight = weight + flist.data[i].w;
  }

  printf("\nWeight of the Spanning tree is: %d", weight);
}

int main() {
  int i, j, total_cost;

  n = 9;
  int Graph[9][9]={0,4,0,0,0,0,0,8,0,
      4,0,8,0,0,0,0,11,0,
      0,8,0,7,0,4,0,0,2,
      0,0,7,0,9,14,0,0,0,
      0,0,0,9,0,10,0,0,0,
      0,0,4,14,10,0,2,0,0,
      0,0,0,0,0,2,0,1,6,
      8,11,0,0,0,0,1,0,7,
      0,0,2,0,0,0,6,7,0};
    
  
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
  kruskal(Graph);
  printf("\nEdges and Their Weights:\n");
  print();
}
