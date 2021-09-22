// program to create threads
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h> //API to implement thread in C

void* routine1(){
    printf("Test from thread1\n");
    sleep(3);
    /* 
    sleep function is used to cause delay between operations to ensure 
    the threads are working properly
    */
    printf("Thread1 completed\n");

}

void* routine2(){
    printf("Test from thread2 \n");
    sleep(2);
    printf("Thread2 completed\n");
}

int main (int argc, char* argv[]){
    pthread_t t1, t2;   // variable of structure pthread_t are created 

    pthread_create(&t1, NULL, &routine1, NULL);     // thread intialization  
    /*  Parameter 1: pointer to the pthread_t variable
        Parameter 2: attributes regarding customisation with threads
        parameter 3: function to execute
        Parameter 4: argument to be passed to the function
    */
    pthread_create(&t2, NULL, &routine2, NULL);
    pthread_join(t1, NULL);     // waits for the thread to terminate
    pthread_join(t2, NULL);
    return 0;
}