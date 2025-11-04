# Ejercicio 3.1.4 - Creación secuencial de múltiples procesos hijos

## Descripción
Este ejercicio muestra cómo crear **varios procesos hijos** de forma **secuencial** utilizando la llamada al sistema **`fork()`**.  
Cada hijo realiza una tarea diferente y el **proceso padre** espera a que cada hijo finalice antes de crear el siguiente, asegurando que **ningún proceso hijo quede huérfano** y que la ejecución se mantenga controlada.

El programa demuestra cómo el padre y los hijos pueden ejecutar diferentes secciones de código y cómo utilizar **`wait()`** para sincronizar su finalización.

## Funcionamiento del código
1. El proceso padre inicia la ejecución e itera desde `i = 1` hasta `NUM_PROC = 3`, creando un hijo en cada iteración mediante **`fork()`**.
2. Dependiendo del valor de retorno de `fork()`:
   - En el **hijo** (`pid == 0`), se llama a la función `hijoHaceAlgo(i)`, donde cada hijo ejecuta una tarea diferente:
     - **Hijo 1:** Cuenta del 1 al 10.  
     - **Hijo 2:** Muestra los números pares hasta 20.  
     - **Hijo 3:** Muestra los múltiplos de 3 hasta 30.  
     Luego el hijo finaliza con `exit(0)` para no continuar el bucle del padre.
   - En el **padre** (`pid > 0`), se ejecuta `wait(NULL)` para esperar a que el hijo actual termine antes de crear el siguiente.
3. Una vez que los tres hijos han terminado, el padre imprime un mensaje indicando que **todos los hijos han finalizado**.
4. El uso de `usleep()` en los hijos permite observar claramente la ejecución de cada uno con un breve retardo entre las impresiones.
