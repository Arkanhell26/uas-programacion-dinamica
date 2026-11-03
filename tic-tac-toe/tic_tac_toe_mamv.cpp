/* MAMV */

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

// Revisa las 8 combinaciones posibles de 3 en línea
// Regresa 'X' u 'O' si alguien ganó, o ' ' (espacio) si nadie ha ganado aún
char revisarGanador(char tablero[]) {
  // 3 filas, 3 columnas, 2 diagonales
  int combinaciones[8][3] = {
      {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // filas
      {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // columnas
      {0, 4, 8}, {2, 4, 6}             // diagonales
  };

  for (int i = 0; i < 8; i++) {
    int a = combinaciones[i][0];
    int b = combinaciones[i][1];
    int c = combinaciones[i][2];

    // Si las 3 posiciones tienen el mismo símbolo (X o O), hay ganador
    if (tablero[a] == tablero[b] && tablero[b] == tablero[c] &&
        (tablero[a] == 'X' || tablero[a] == 'O')) {
      return tablero[a];
    }
  }

  return ' '; // nadie ha ganado todavía
}

int main() {
  char jugarDeNuevo = 'S';

  // Loop externo: permite reiniciar el juego (mejora opcional de la rúbrica)
  while (jugarDeNuevo == 'S' || jugarDeNuevo == 's') {
    char tablero[9];
    char turno = 'X';
    char ganador = ' ';

    // Llena el tablero con los números 1-9
    for (int i = 0; i < 9; i++) {
      tablero[i] = '0' + i + 1;
    }

    // Loop principal: máximo 9 jugadas (se corta antes si hay ganador)
    for (int j = 0; j < 9; j++) {
      mostrarTablero(tablero);

      char casilla;
      int indice;

      // Pide la casilla hasta que sea válida (existe y está libre)
      do {
        cout << "Turno de " << turno << ". Elige una casilla: ";
        cin >> casilla;
        indice = casilla - '0' - 1;
      } while (indice < 0 || indice > 8 || tablero[indice] != casilla);

      tablero[indice] = turno;

      // Revisa si esa jugada generó un ganador
      ganador = revisarGanador(tablero);
      if (ganador != ' ') {
        break; // ya hay ganador, se sale del loop de jugadas
      }

      // Cambia el turno
      if (turno == 'X') {
        turno = 'O';
      } else {
        turno = 'X';
      }
    }

    mostrarTablero(tablero);

    // Resultado final
    if (ganador != ' ') {
      cout << "¡Gano el jugador " << ganador << "!" << '\n';
    } else {
      cout << "Empate, nadie gano." << '\n';
    }

    cout << "¿Jugar de nuevo? (S/N): ";
    cin >> jugarDeNuevo;
    cout << '\n';
  }

  return 0;
}