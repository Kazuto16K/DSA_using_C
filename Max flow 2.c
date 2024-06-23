#include <stdio.h>
#define MAX_NODES 100


int n;
int capacity[MAX_NODES][MAX_NODES];
int flow[MAX_NODES][MAX_NODES];
int color[MAX_NODES];
int pred[MAX_NODES];
int residual[MAX_NODES][MAX_NODES];

int min(int x, int y) {
  if(x<y){
      return x;
  }
  return y;
}

int head, tail;
int q[MAX_NODES + 2];

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

// Using BFS as a searching algorithm
int bfs(int start, int target) {
  int u, v;
  for (u = 0; u < n; u++) {
    color[u] = 0;
  }
  head = tail = 0;
  enqueue(start);
  pred[start] = -1;
  while (head != tail) {
    u = dequeue();
    for (v = 0; v < n; v++) {
      if (color[v] == 0 && capacity[u][v] - flow[u][v] > 0) {
        enqueue(v);
        pred[v] = u;
      }
    }
  }
  return color[target] == 2;
}

// Applying fordfulkerson algorithm
int fordFulkerson(int source, int sink) {
  int i, j, u;
  int max_flow = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      flow[i][j] = 0;
    }
  }

  // Updating the residual values of edges
  while (bfs(source, sink)) {
    int increment = 99;
    for (u = n - 1; pred[u] >= 0; u = pred[u]) {
      increment = min(increment, capacity[pred[u]][u] - flow[pred[u]][u]);
    }
    for (u = n - 1; pred[u] >= 0; u = pred[u]) {
      flow[pred[u]][u] += increment;
      //flow[u][pred[u]] -= increment;
      residual[u][pred[u]] = flow[pred[u]][u];
      residual[pred[u]][u]=capacity[pred[u]][u]-flow[pred[u]][u];
    }
    // Adding the path flows
    max_flow += increment;
  }
  return max_flow;
}

void dfs(int s, int visited[])
{
    visited[s] = 1;
    int i;
    for ( i = 0; i < n; i++)
       if (residual[s][i] && visited[i]==0)
           dfs(i, visited);
}
 

void min_cut(int s){
   int visited[MAX_NODES],i,j;
   for(i=0;i<10;i++){
       visited[i]=0;
   }
   dfs(s,visited);
   for(i=0;i<n;i++){
       for(j=0;j<n;j++){
           if(visited[i]==1 && visited[j]==1 && residual[i][j]){
               printf("%d - %d",i,j);
               printf("\n");
           }
           
       }
       printf("\n");
   }
}

int main() {
    n = 6;
    int i,j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      capacity[i][j] = 0;
      residual[i][j] = 0;
    }
  }
  
  //e = 7;

  capacity[0][1] = 10;
  capacity[0][2] = 10;
  capacity[1][2] = 2;
  capacity[1][3] = 4;
  capacity[1][4] = 8;
  capacity[2][4] = 9;
  capacity[3][5] = 10;
  capacity[4][3] = 6;
  capacity[4][5] = 10;
  
  residual[0][1] = 10;
  residual[0][2] = 10;
  residual[1][2] = 2;
  residual[1][3] = 4;
  residual[1][4] = 8;
  residual[2][4] = 9;
  residual[3][5] = 10;
  residual[4][3] = 6;
  residual[4][5] = 10;

  int s = 0, t = 5;
  printf("Max Flow: %d\n\n", fordFulkerson(s, t));
  
  min_cut(0);
  printf("\nFlow:\n");
  for(i=0;i<n;i++){
  	for(j=0;j<n;j++){
  		printf("%d ",flow[i][j]);
	  }
	  printf("\n");
  }
  
  printf("\nCapacity:\n");
  for(i=0;i<n;i++){
  	for(j=0;j<n;j++){
  		printf("%d ",capacity[i][j]);
	  }
	  printf("\n");
  }
  
  printf("\nResidual:\n");
  for(i=0;i<n;i++){
  	for(j=0;j<n;j++){
  		printf("%d ",residual[i][j]);
	  }
	  printf("\n");
  }
}
