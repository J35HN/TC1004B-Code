#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void handleSignal(int signal){
    printf("jaja, no me matas\n");
}

int main(){
    signal(2, handleSignal);
    while(1){
        printf("trabajando...\n");
        sleep(1);
    }
    return 0;
}