#include <stdio.h>
#define MAX 100


int n;
int capacity[MAX][MAX];
int flow[MAX][MAX];
int color[MAX];
int parent[MAX];
int residual[MAX][MAX];

int min(int x, int y) {
  if(x<y){
      return x;
  }
  return y;
}

int head, tail;
int q[MAX];

void enqueue(int x) {
  q[tail] = x;
  tail++;
  color[x] = 1;
}

int dequeue() {
  int x = q[head];
  head++;
  color[x] = 2;
  return x;
}


int bfs(int start, int target) {
  int u, v;
  for (u = 0; u < n; u++) {
    color[u] = 0;
  }
  head = tail = 0;
  enqueue(start);
  parent[start] = -1;
  while (head != tail) {
    u = dequeue();
    for (v = 0; v < n; v++) {
      if (color[v] == 0 && capacity[u][v] - flow[u][v] > 0) {
        enqueue(v);
        parent[v] = u;
      }
    }
  }
  return color[target] == 2;
}


int fordFulkerson(int source, int sink) {
  int i, j, u;
  int max_flow = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      flow[i][j] = 0;
    }
  }

  while (bfs(source, sink)) {
    int inc = 99;
    for (u = n - 1; parent[u] >= 0; u = parent[u]) {
      inc = min(inc, capacity[parent[u]][u] - flow[parent[u]][u]);
    }
    for (u = n - 1; parent[u] >= 0; u = parent[u]) {
      flow[parent[u]][u] += inc;
      residual[u][parent[u]] = flow[parent[u]][u];
      residual[parent[u]][u]=capacity[parent[u]][u]-flow[parent[u]][u];
    }
    max_flow += inc;
  }
  return max_flow;
}

void dfs(int s, int visited[])
{
    visited[s] = 1;
    int i;
    for ( i = 0; i < n; i++){
       if (residual[s][i] && visited[i]==0)
           dfs(i, visited);
    }       
}
 
int present(int cut[],int v) {
    int i;
    for(i=0;i<n;i++){
        if(cut[i]==v)
            return 1;
    }
    return 0;
}

void min_cut(int s){
   int visited[MAX],i,j,cut[10],k=1;
   for(i=0;i<10;i++){
       visited[i]=0;
   }
   dfs(s,visited);
   cut[0]=s;
   for(i=0;i<n;i++){
       for(j=0;j<n;j++){
           if(visited[i]==1 && visited[j]==1 && residual[i][j]){
               if(!present(cut,j)){
                   cut[k]=j;
                   k++;
               }     
           }
           
       }
   }
   for(i=0;i<k;i++){
       printf("%d ",cut[i]);
   }
}

int main() {
    n = 4;
    int i,j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      capacity[i][j] = 0;
      residual[i][j] = 0;
    }
  }
  
  capacity[0][1] = 20;
  capacity[0][2] = 10;
  capacity[1][2] = 30;
  capacity[1][3] = 10;
  capacity[2][3] = 20;
  
  residual[0][1] = 20;
  residual[0][2] = 10;
  residual[1][2] = 30;
  residual[1][3] = 10;
  residual[2][3] = 20;


  int s = 0, t = 3;
  printf("Max Flow: %d\n\n", fordFulkerson(s, t));
  printf("MIN cut vertex: ");
  min_cut(0);
  printf("\nResidual:\n");
  for(i=0;i<n;i++){
  	for(j=0;j<n;j++){
  		printf("%d ",residual[i][j]);
	  }
	  printf("\n");
  }
}
