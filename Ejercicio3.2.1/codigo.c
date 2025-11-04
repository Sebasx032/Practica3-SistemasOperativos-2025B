#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int ejecutarNuevoProc();

int main() {
    int pid = ejecutarNuevoProc();

    // Espera a que el hijo termine
    wait(0);
    fprintf(stdout, "El proceso hijo con PID %d se ha ejecutado\n", pid);

    return 0;
}

int ejecutarNuevoProc() {
    int pid = fork();

    switch(pid) {
        case -1:
            fprintf(stderr, "No se pudo crear el proceso\n");
            exit(1);

        case 0:
            // Aquí el hijo ejecuta el programa 3.1.1 compilado
            execl("./ejercicio3_1_1", "ejercicio3_1_1", NULL);

            // Si execl falla
            fprintf(stderr, "Error al ejecutar execl\n");
            exit(1);

        default:
            // El padre devuelve el PID del hijo
            return pid;
    }
}
