#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid;
    int i;
    pid = fork();

    switch(pid) {
        case -1: // Si pid es -1 quiere decir que ha habido un error
            printf("No se ha podido crear el proceso hijo\n");
            break;

        case 0: // Cuando pid es cero quiere decir que es el proceso hijo
            for(i = 1; i <= 10; i++)
                printf("%d Soy el hijo con PID: %d \n", i, getpid());
            break;

        default: // Cuando es distinto de cero es el padre
            for(i = 1; i <= 10; i++)
                printf("%d Soy el padre con PID: %d \n", i, getpid());
            // La función wait detiene el proceso padre y se queda esperando hasta
            // que termine el hijo
            wait(0);
            break;
    }
}
