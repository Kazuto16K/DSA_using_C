
#include <stdio.h>
#include <time.h>
int size = 0,c=0, total=0;
void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}
int parent(int i){
    return (i-1)/2;
}

void heapify(int array[], int size, int i) {	
  
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size&& c++ && array[l] > array[largest])
      largest = l;
    if (r < size && c++ && array[r] > array[largest])
      largest = r;

    if (largest != i) {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
  
}
void shiftup(int array[],int i){
    while(i>0 && c++ && array[parent(i)]<array[i]){
        swap(&array[parent(i)],&array[i]);
        i=parent(i);
    }
}

void insert(int array[], int newNum) {
  if (size == 0) {
    array[0] = newNum;
    size += 1;
  } 
  else {
    array[size] = newNum;
    shiftup(array,size);
    size += 1;
  
  }
}


void extractMAX(int array[]) {
  swap(&array[0], &array[size - 1]);
  size -= 1;
  int i;
  heapify(array, size, 0);

}


void printArray(int array[], int size) {
  printf("\n");
  int i;	
  for (i = 0; i < size; i++)
    printf("%d ", array[i]);
  printf("\n");
}
void heapsort(int array[],int k){
	int i;
  	for( i=0;i<1000;i++){
      	insert(array, (rand()%1000));
  	}
  	while(size!=0){
    	extractMAX(array);
  	}
  	//printArray(array,10);
  	printf("\nNo of comparisons in Case %d : %d\n",k,c);
  	total=total+c;
  	c=0;
}


int main(){
  int array[1000];
  srand(time(NULL));
  
  
  int i;
  for(i=0;i<5;i++){
  	heapsort(array,i+1);
  	
  }
  printf("\n\nAverage number of Comparisons: %.2f",total/5.0);
}

  

  

