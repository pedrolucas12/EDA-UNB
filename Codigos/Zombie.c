#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>

int counter = 0;
pid_t p;
void sinal();

int main (){
    signal(SIGUSR1,sinal);
    signal(SIGUSR2,sinal);
    
    while(1){
        pause();
    }
    
    return 0;
}

void sinal(){
    if(counter==0){
    	counter++;
        p = fork ();
        if (p==0){
            exit(0);
        }
    }else if(counter==1){
    	counter++;
        waitpid(-1, NULL, WNOHANG);
    }else{
        exit(0);
    }
}