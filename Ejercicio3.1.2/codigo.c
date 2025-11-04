#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int pid;

int main() {
    pid = fork();

    switch (pid) {
        case -1:
            printf("\nNo he podido crear el proceso hijo");
            break;

        case 0:
            printf("\nSoy el hijo, mi PID es %d y mi PPID es %d", getpid(), getppid());
            wait(0);
            break;

        default:
            printf("\nSoy el padre, mi PID es %d y el PID de mi hijo es %d", getpid(), pid);
    }

    printf("\nFinal de ejecución de %d \n", getpid());
    exit(0);
}
