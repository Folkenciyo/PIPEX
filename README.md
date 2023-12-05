<br/>
<h1 align="center">PIPEX</h1>
<p align="center">
 <img tyle="display: block;-webkit-user-select: none;margin: auto;background-color: hsl(0, 0%, 90%);transition: background-color 300ms;" src="https://i.ibb.co/vYyPWyR/pixlr-image-generator-5735e3c1-8210-4348-b7a7-f671a1cf1a34.png" height=50% width=50%>
</p>

 <p align="center">
    Pipex reproduce el comportamiento del operador de tubería | del shell en C.
    <br/>
    <br/>
  </p>
</p>

## Contenido

* Sobre el proyecto
* Cómo usar
  * Compilación
* Uso
* Autor

## Sobre el proyecto

Pipex es una herramienta que replica el comportamiento del operador de tubería | del shell en el lenguaje C. Diseñado para ejecutarse como ./pipex infile cmd1 cmd2 outfile, simula la funcionalidad de una línea de comando shell como < infile cmd1 | cmd2 > outfile. Este proyecto involucra la aplicación de conceptos fundamentales como pipe(), fork(), dup2() y execve(), desafiando a los desarrolladores a entender y emplear estas funciones para dirigir flujos de entrada y salida entre dos comandos, emulando así el comportamiento de la tubería en un entorno de programación. Pipex representa un desafío que pone a prueba tanto la comprensión de conceptos de bajo nivel como la capacidad para coordinar y manipular procesos, esencial para crear una secuencia efectiva que conecte la salida de un comando con la entrada de otro de manera eficiente y precisa.

### Funcionalidades principales
 * Emulación de tuberías eficiente: Pipex está diseñado para replicar la funcionalidad del operador de tubería | del shell en C, utilizando eficientemente las funciones fundamentales como pipe(), fork(), dup2() y execve(). Esto permite dirigir flujos de datos entre comandos de manera óptima, buscando imitar la operatividad de las tuberías del shell.

 * Manipulación de dos flujos: El programa opera con dos flujos de datos, uno de entrada y otro de salida, gestionando estos flujos mediante operaciones específicas para ejecutar los comandos proporcionados (cmd1 y cmd2) y conectar sus salidas y entradas de manera precisa, tal como lo haría el operador de tuberías en el shell.

 * Minimización de movimientos: El desafío central reside en encontrar la secuencia de operaciones necesarias para minimizar el número de movimientos requeridos para transferir y manipular los datos entre los comandos proporcionados, optimizando así el flujo de información entre ellos.

### Gestión de recursos y optimización

 * Eficiencia en operaciones: Pipex busca optimizar la ejecución de comandos y el flujo de datos entre ellos, utilizando algoritmos y estrategias que minimicen el uso de operaciones para lograr el comportamiento deseado, todo ello manteniendo la coherencia y funcionalidad esperada.
 * Gestión de recursos del sistema: Se prioriza una gestión eficiente de la memoria y los recursos del sistema para asegurar el funcionamiento adecuado de Pipex, evitando fugas de memoria y garantizando un rendimiento óptimo durante la ejecución de los comandos.


## Cómo usar

### Compilación
Ejecuta los siguientes comandos:

* Para compilar
```bash
make
```
* Para eliminar objetos:
```bash
make clean
```
* Para eliminar objetos y archivos binarios (programa):
```bash
make fclean
```
* Para recompilar:
```bash
make re
```
Este comando generará un archivo ejecutable get_next_line, al cual pasarle un archivo de texto para comprobarlo.

## Guía de uso de Pipex

### Instalación
1. Clona el repositorio o descarga los archivos necesarios para el proyecto.
2. Compila el programa utilizando el comando make.
### Ejecución
El ejecutable se llama `pipex´.
### Sintaxis
```bash
./pipex infile cmd1 cmd2 outfile
```
### Ejemplo de uso
```bash
./pipex input.txt grep hello wc output.txt
```
### Resultado
El programa dirigirá la salida de cmd1 como entrada de cmd2, escribiendo el resultado en outfile. Esta secuencia imita el comportamiento del operador de tubería del shell.

### Verificación del ordenamiento
La ejecución del programa pipex deberá hacer lo mismo que el siguiente comando:
```bash
$> < archivo1 comando1 | comando2 > archivo2
```
### Ejemplos
```bash
$> ./pipex infile "ls -l" "wc -l" outfile
```
deberá hacer lo mismo que “<infile ls -l | wc -l >outfile”
```bash
$> ./pipex infile "grep a1" "wc -w" outfile
```
deberá hacer lo mismo que “<infile grep a1 | wc -w >outfile”
   
## Autor

* **Juan Guerrero** - *@juguerre - 42Málaga* - [Juan Guerrero](https://github.com/Folkenciyo/)

### ¿Puedes agregar más funciones a esta biblioteca? ¿Cómo?
* Haz un fork de este repositorio
* Clona tu fork del repositorio
* Contribuye
* Realiza un push
* Crea una solicitud de extracción (pull request) en este repositorio
* ¡Espera a que se fusionen los cambios!
 ¡Sé feliz! :)
---
## 🔗 Links
[![portfolio](https://img.shields.io/badge/portfolio-002?style=for-the-badge&logo=ko-fi&logoColor=white)](https://porfolio-juan-guerrero.vercel.app/)
[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/juanguerrerodeveloper/)
[![twitter](https://img.shields.io/badge/twitter-1DA1F2?style=for-the-badge&logo=twitter&logoColor=white)](https://twitter.com/JuanAGuerreroP1)

