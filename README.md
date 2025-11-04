# Práctica 3 - Sistemas Operativos 2025B

Bienvenido al repositorio **Practica3-SistemasOperativos-2025B**, donde se desarrollan ejercicios prácticos relacionados con la creación y gestión de procesos en sistemas tipo UNIX utilizando llamadas al sistema como `fork()`, `execl()`, `wait()`, `system()` y comunicación entre procesos.

Este repositorio está organizado por ejercicios de la práctica 3, mostrando cómo interactúan procesos padre e hijo, cómo se sincronizan, y cómo se ejecutan programas externos o comandos del sistema.

---

## Contenido de la práctica

### 3.1 Creación y gestión de procesos con `fork()`

- **[Ejercicio 3.1.1 - Creación de procesos con fork()](./codigo/README.md)**  
  Introduce la llamada al sistema `fork()`. Se crean procesos hijos que imprimen sus PIDs y el PID del padre. Permite observar la ejecución concurrente de padre e hijo.

- **[Ejercicio 3.1.2 - Modificación de proceso hijo para registrar valores](./ejercicio3_1_2/README.md)**  
  Demuestra la cooperación entre padre e hijo: el padre incrementa una variable, mientras el hijo registra cada valor en un archivo de texto. Se emplea `fork()` y comunicación mediante **pipes**.

- **[Ejercicio 3.1.3 - Evitar procesos huérfanos](./ejercicio3_1_3/README.md)**  
  Crea un proceso hijo asegurando que no quede huérfano. El padre espera a que el hijo termine usando `wait()`, y se imprimen PIDs de padre e hijo.

- **[Ejercicio 3.1.4 - Creación secuencial de múltiples hijos](./ejercicio3_1_4/README.md)**  
  Muestra cómo crear varios hijos secuencialmente, cada uno realizando tareas distintas, asegurando que el padre espera a que cada hijo termine antes de crear el siguiente.

- **[Ejercicio 3.1.5 - Creación de un proceso zombie](./ejercicio3_1_5/README.md)**  
  Ilustra cómo un hijo puede convertirse en **zombie** si el padre no llama a `wait()` tras su finalización. Se puede observar el estado Z usando herramientas como `top`.

### 3.2 Ejecución de programas externos

- **[Ejercicio 3.2.1 - Creación y ejecución de un proceso hijo con execl()](./ejercicio3_2_1/README.md)**  
  El hijo ejecuta un programa externo (`ejercicio3_1_1`) mediante `execl()`. El padre espera a que el hijo finalice antes de continuar.

### 3.3 Uso de comandos del sistema

- **[Ejercicio 3.3.1 - Uso de system() para listar procesos](./ejercicio3_3_1/README.md)**  
  Crea un hijo que ejecuta `ps -ef` mediante `system()`, mientras el padre espera su finalización. Permite observar los procesos activos del sistema.

---

## Requisitos

- Sistema operativo tipo UNIX/Linux.  
- Compilador de C (gcc).  
- Permisos para ejecutar comandos del sistema (`system()`).

---

## Instrucciones de compilación

Para compilar cada ejercicio, navegar a la carpeta correspondiente y ejecutar:

```bash
gcc nombre_ejercicio.c -o nombre_ejercicio

Para ejecutar:

./nombre_ejercicio
