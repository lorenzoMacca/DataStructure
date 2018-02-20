#include <iostream>
using namespace std;

#include <pthread.h>
#include <string>
#include <sstream>

#define N 5

void *worker_thread(void *arg)
{
    //printf("This is worker_thread #%ld\n", (long)arg);
    // the part of the string are not printed at the same time
    //cout << "This is worker_thread: " << (long)arg << endl;
    stringstream ss;
    
    ss << "This is worker_thread: " << (long)arg << endl;
    cout << ss.str();
    
    pthread_exit(NULL);
}

/*
 pthread_create needs a:
 - pointer to pthread_t structure.
 - attr
 - start routine void *(*start_routine)(void *)
 - arg A single argument that may be passed to start_routine.
   It must be passed as a void pointer. NULL may be used if no argument is to be passed.
 
 */

int main(){
    
    pthread_t my_thread[N];
    
    
    
    long id;
    for(id = 1; id <= N; id++) {
        int ret =  pthread_create(&my_thread[id], NULL, &worker_thread, (void*)id);
        if(ret != 0) {
            printf("Error: pthread_create() failed\n");
            exit(EXIT_FAILURE);
        }
    }
    
    pthread_exit(NULL);
}
