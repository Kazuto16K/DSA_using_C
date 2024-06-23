#include <stdio.h>
#include <string.h>
#include <pthread.h>

// Global variable:
int i = 2;

void* foo(void* p){
  // Print value received as argument:
  printf("Process ID:%d\n",getpid());
  printf("Thread Id: %d\n",pthread_self());

  // Return reference to global variable:
  pthread_exit(&i);
}

int main(void){
  // Declare variable for thread's ID:
  pthread_t id1,id2;

  int j = 1;
  pthread_create(&id1, NULL, foo, &j);
  pthread_create(&id2, NULL, foo, &j);
    
  int* ptr;

  pthread_join(id1, (void**)&ptr);
  pthread_join(id2, (void**)&ptr);
  printf("Value recevied by parent from child: ");
  printf("%i\n", *ptr);
}

