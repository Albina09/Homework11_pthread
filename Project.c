#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <stdlib.h>

int a = 0; 

void* sum_a(void *args){
    int tmp;
    
    for(int i = 0; i < 1000000; i++){
        tmp = a;
        tmp++;
        a = tmp;
    }
    printf("a = %d\n", a);
}

int main(){
    pthread_t thread[5];
    int s;
    
    for(int i = 0; i <= 5; i++){
        
        if(pthread_create(&thread[i], NULL, sum_a, NULL) == -1){
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    for(int i = 0; i <= 5; i++){
        
        if(pthread_join(thread[i], NULL) == -1){
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }
    
    exit(EXIT_SUCCESS);
}
