/* Miguel Angel Moreno Vázquez
   Cuenta: 25134140 */

#include <iostream>
using namespace std;

// Muestra el tablero en pantalla, dividido en 3 filas de 3 casillas
void mostrarTablero(char tablero[]) {
  cout << tablero[0] << '|' << tablero[1] << '|' << tablero[2] << '\n';
  cout << "-----" << '\n';
  cout << tablero[3] << '|' << tablero[4] << '|' << tablero[5] << '\n';
  cout << "-----" << '\n';
  cout << tablero[6] << '|' << tablero[7] << '|' << tablero[8] << '\n';
  cout << '\n';
}

int main() {
  char tablero[9];

  for (int i = 0; i < 9; i++) {
    tablero[i] = '0' + i + 1;
  }

  mostrarTablero(tablero);

  return 0;
}