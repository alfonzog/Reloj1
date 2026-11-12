
// Función para mover el cursor a una posición específica
void moverCursor(int x, int y);

// Función para limpiar la pantalla
void limpiarPantalla();

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
void cambiarColor(int textoColor, int fondoColor);

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
void tocarNota(int frecuencia, int duracion);
