#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid = fork();

    if (pid < 0) {
        perror("Error al crear el proceso hijo");
        exit(1);
    }

    if (pid == 0) {
        // Código del hijo
        printf("Soy el hijo con PID %d y voy a listar los procesos del sistema\n", getpid());
        system("ps -ef");  // Ejecuta el comando de listar procesos
        exit(0);           // Termina el hijo
    } else {
        // Código del padre
        wait(NULL);  // Espera a que el hijo termine
        printf("El proceso hijo ha terminado\n");
    }

    return 0;
}
