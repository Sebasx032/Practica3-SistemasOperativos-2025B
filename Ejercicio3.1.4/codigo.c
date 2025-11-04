#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUM_PROC 3

void hijoHasAlgo(int numero);

int main() {
    int i, pid;

    for (i = 1; i <= NUM_PROC; i++) {
        pid = fork();

        switch (pid) {
            case -1:
                fprintf(stderr, "Error al crear el proceso\n");
                break;

            case 0:
                hijoHasAlgo(i);
                break;

            default:
                printf("Ejecutando el padre\n");
                wait(0);
                printf("Mi hijo %d ha terminado. \n", i);
                exit(0);
        }
    }
}

void hijoHasAlgo(int numero) {
    int i, MAX = 10;

    printf("Ejecutando el hijo %d: \n", numero);

    for (i = 1; i <= MAX; i++)
        printf("%d\t", i);

    printf("\n");
}
