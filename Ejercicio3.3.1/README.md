# Ejercicio 3.3.1 - Uso de `system()` para listar procesos del sistema

## Descripción
Este ejercicio muestra cómo crear un **proceso hijo** usando `fork()` y cómo ejecutar un comando del sistema desde ese hijo utilizando la función `system()`.  

El objetivo es:
- Crear un hijo que ejecute el comando `ps -ef` para listar todos los procesos del sistema.
- Hacer que el padre espere a que el hijo termine antes de continuar.

## Funcionamiento del código
1. Se llama a `fork()` para crear un proceso hijo:
   - En el **hijo** (`pid == 0`):
     - Imprime un mensaje indicando su PID.
     - Ejecuta `system("ps -ef")` para listar los procesos del sistema.
     - Termina la ejecución con `exit(0)`.
   - En el **padre** (`pid > 0`):
     - Espera a que el hijo termine con `wait(NULL)`.
     - Imprime un mensaje indicando que el hijo ha finalizado.

2. Si ocurre un error al crear el proceso hijo, se imprime un mensaje de error y el programa termina.
