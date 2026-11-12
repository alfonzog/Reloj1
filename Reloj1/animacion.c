#include <stdio.h>
#include <windows.h>

// Función para mover el cursor a una posición específica
void moverCursor(int x, int y) {
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Función para limpiar la pantalla
void limpiarPantalla() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD written;
  DWORD cells;
  COORD home = { 0, 0 };

  if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
    cells = csbi.dwSize.X * csbi.dwSize.Y;
    FillConsoleOutputCharacter(hConsole, ' ', cells, home, &written);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cells, home, &written);
    SetConsoleCursorPosition(hConsole, home);
  }
}

// Función para cambiar color de texto y fondo
/*
* 0 = Negro	8 = Gris oscuro
* 1 = Azul	9 = Azul claro
* 2 = Verde	10 = Verde claro
* 3 = Aqua	11 = Aqua claro
* 4 = Rojo	12 = Rojo claro
* 5 = Púrpura	13 = Púrpura claro
* 6 = Amarillo	14 = Amarillo claro
* 7 = Blanco	15 = Blanco brillante
*/
void cambiarColor(int textoColor, int fondoColor) {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, (fondoColor << 4) | textoColor);
}

// Función para tocar una nota
/*
C4 - Do  261 Hz
D4 - Re  294 Hz
E4 - Mi  329 Hz
F4 - Fa  349 Hz
G4 - Sol 392 Hz
A4 - La  440 Hz
B4 - Si  493 Hz
C5 - Do (octava superior) 523 Hz
*/
void tocarNota(int frecuencia, int duracion) {
  Beep(frecuencia, duracion);
  Sleep(50); // Pausa breve entre notas para que suene mejor
}