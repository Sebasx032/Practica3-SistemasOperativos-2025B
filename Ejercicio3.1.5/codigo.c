#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
    int pid;
    pid = fork();

    if (pid > 0) {
        // Proceso padre
        printf("Soy el proceso padre y espero 60 segundos antes de terminar.\n");
        printf("Durante este tiempo, el proceso hijo termina, pero su entrada en la tabla de procesos sigue existiendo (zombie).\n");
        sleep(60); // El padre se queda vivo mientras el hijo ya terminó
    } 
    else if (pid == 0) {
        // Proceso hijo
        printf("Soy el proceso hijo y termino inmediatamente.\n");
        exit(0); // Termina el proceso hijo
    } 
    else {
        // Error al crear el proceso
        perror("Error al crear el proceso");
    }

    return 0;
}
