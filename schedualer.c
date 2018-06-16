#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void * test(){
  printf("asdasd");
  pthread_exit(NULL);
}
void f(void *func, int n){
  pthread_t thrd;
  void *t;
  sleep(n);
  pthread_create(&thrd,NULL,func,NULL);
  pthread_join(thrd,&t);
  printf((char *)t);
}

int main(){
  f(test,5);
  

}
