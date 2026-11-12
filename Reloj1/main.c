
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include "animacion.h"

// Variables y constantes globales
#define NUM_HILOS 3
int teclaPresionada = 0; // Variable global para almacenar la tecla presionada
bool terminado = false;

// Función que mostrará los segundos transcurridos
DWORD WINAPI mostrarSegundos(LPVOID lpParam) {
  int id = *(int*)lpParam;

  int i = 0;
  for (i = 0; i <= 59; i++) {
    limpiarPantalla();
    moverCursor(30, 10);
    printf("Segundo: %d", i);
    moverCursor(0, 30); // Mover a la parte inferior
    tocarNota(440, 100); // Nota La (A4) durante 100 ms
    Sleep(200);
    if (teclaPresionada == 27) { // 27 es el código ASCII para la tecla ESC
      break; // Salir del bucle si se presiona ESC
    }
  }

  if (i > 59) {
    terminado = true; // Marcar como terminado si se completan los 60 segundos
  }

  return 0;
}

// Función que esperará a que el usuario presione una tecla y luego tocará un sonido
DWORD WINAPI esperarTecla(LPVOID lpParam) {
  int id = *(int*)lpParam;

  while (teclaPresionada != 27) { // 27 es el código ASCII para la tecla ESC
    if (_kbhit()) {
      moverCursor(0, 30); // Mover a la parte inferior
      teclaPresionada = _getch(); // Leer la tecla presionada
      tocarNota(523, 200); // Nota Do (C5) durante 200 ms
    }
    Sleep(100); // Evitar uso excesivo de CPU
    if (terminado) {
      break; // Salir del bucle si se completan los 60 segundos
    }
  }

  return 0;
}

// Función de animación adicional
DWORD WINAPI avanceSegundos(LPVOID lpParam) {
  int id = *(int*)lpParam;

  int i = 0;
  int x = 10; // Posición inicial en x
  for (i = 0; i <= 59; i++) {
    moverCursor(x, 20);
    printf(" %c", 177);
    moverCursor(0, 30); // Mover a la parte inferior
    Sleep(400);
    x++; // Mover a la derecha
    if (teclaPresionada == 27) { // 27 es el código ASCII para la tecla ESC
      break; // Salir del bucle si se presiona ESC
    }
  }

  return 0;
}


int main() {

  HANDLE hilos[NUM_HILOS];
  int ids[NUM_HILOS];

  // Crear múltiples hilos
  ids[0] = 1; // ID de cada hilo
  hilos[0] = CreateThread(NULL, 0, mostrarSegundos, &ids[0], 0, NULL);
  ids[1] = 2; // ID de cada hilo
  hilos[1] = CreateThread(NULL, 0, esperarTecla, &ids[1], 0, NULL);
  ids[2] = 3; // ID de cada hilo
  hilos[2] = CreateThread(NULL, 0, avanceSegundos, &ids[2], 0, NULL);

  // Esperar a que todos los hilos terminen
  WaitForMultipleObjects(NUM_HILOS, hilos, TRUE, INFINITE);

  // Cerrar los handles de los hilos
  for (int i = 0; i < NUM_HILOS; i++) {
    CloseHandle(hilos[i]);
  }

  moverCursor(0, 30); // Mover cursor a la posición final
  return 0;
}
