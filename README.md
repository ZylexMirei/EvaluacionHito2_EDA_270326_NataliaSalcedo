Sistema de turnos de estudiantes

Este es un programa en consola hecho en C++ (sin usar STL) que sirve para manejar turnos de atención de estudiantes usando una lista doblemente enlazada.

¿Qué hace el programa?

El sistema permite hacer varias cosas básicas:

Registrar estudiantes con su nombre y código.
Atender al primer estudiante que llegó (tipo cola FIFO).
Mostrar todos los estudiantes que están esperando.
Buscar un estudiante por su nombre y ver en qué posición está.
(Extra) Mostrar la lista al revés usando los punteros de la lista doble.
Estructura usada (y por qué)

Se usó una lista doblemente enlazada hecha manualmente con struct Nodo y struct Cola.

Elegí esta estructura porque:

Un arreglo no sirve mucho aquí porque tiene tamaño fijo y es incómodo para eliminar elementos.
Una lista simple sí funciona, pero no permite recorrer hacia atrás fácilmente.
La lista doble es mejor porque:
Se puede insertar y eliminar rápido (O(1)).
Permite recorrer en ambos sentidos (normal y reverso).

Cada nodo tiene:

nombre[50]
codigo[20]
sig → apunta al siguiente
ant → apunta al anterior (esto permite ir hacia atrás)
Complejidad de las operaciones
Registrar estudiante: O(1)
Porque siempre se agrega al final.
Atender estudiante: O(1)
Porque siempre se elimina el primero.
Buscar por nombre: O(n)
Hay que recorrer la lista hasta encontrarlo.
Mostrar lista: O(n)
Se recorre todo.
Mostrar en reversa: O(n)
Igual, pero empezando desde el final.
Cómo compilar y ejecutar
Requisitos
Tener instalado g++ (o cualquier compilador de C++11)
Compilar
g++ -std=c++11 -o turnos main.cpp
Ejecutar


En Windows:

turnos.exe
Ejemplo de uso
Sistema de turnos (simple)

1. Registrar
2. Atender
3. Mostrar
4. Buscar
5. Mostrar reverso
6. Salir
Opcion: 1

Nombre: Ana Mamani
Codigo: 20231001

Se registro a Ana Mamani (turno #1)
