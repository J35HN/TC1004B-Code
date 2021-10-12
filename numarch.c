#include <unistd.h>

int main(){
    int fd[2];
    int pid;
    
    pipe(fd);
    pid = fork();

    // dos procesos
    if (pid == 0){ // hijo
        close(STDIN_FILENO);
        dup(fd[0]); // Hacer conexión
        close(fd[1]);
        execlp("wc", "wc", "-l", NULL);
    } else {
        close(STDOUT_FILENO);
        dup(fd[1]);
        close(fd[0]);
        execlp("ls", "ls", NULL);

    }
    return 0;
}