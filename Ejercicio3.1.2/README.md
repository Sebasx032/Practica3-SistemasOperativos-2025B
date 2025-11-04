# Ejercicio 3.1.2 - Modificación de proceso hijo para registrar valores en un archivo

## Descripción
Este ejercicio muestra cómo crear un **proceso hijo** usando `fork()` y cómo hacer que **el padre y el hijo cooperen** para cumplir una tarea:  
- El **padre** incrementa una variable 10 veces en pasos de 10.  
- El **hijo** registra cada valor de esa variable en un archivo de texto.

El objetivo principal es **practicar la creación de procesos y la coordinación entre padre e hijo**, mostrando el PID de cada proceso y asegurando que la ejecución del hijo se realiza correctamente antes de que el padre finalice.

## Funcionamiento del código
1. Se llama a `fork()` para crear un proceso hijo:
   - En el **hijo** (`pid == 0`):
     - Recibe los valores generados por el padre y los registra en un archivo llamado `valores.txt`.
     - Al terminar, imprime un mensaje indicando que los valores fueron guardados.
   - En el **padre** (`pid > 0`):
     - Incrementa la variable en pasos de 10 y envía los valores al hijo.
     - Espera a que el hijo termine con `wait()`.
     - Imprime un mensaje indicando que el hijo ha finalizado.
2. La comunicación de los valores del padre al hijo se realiza mediante una **pipe**, que es un canal de datos unidireccional que permite que un proceso escriba y otro lea. Esto asegura que el hijo reciba exactamente los valores actualizados y pueda registrarlos en el archivo.
3. Si ocurre algún error al crear el proceso o la pipe, se imprime un mensaje de error y el programa termina.
