# UAS - Programación Dinámica

Mini projects developed for the Programación Dinámica course at Universidad Autónoma de Sinaloa (UAS).

## Projects

| Project | Language | Description |
|---|---|---|
| [Tic Tac Toe](./tic-tac-toe) | C++ | Console-based two-player Tic Tac Toe with move validation, win detection, and replay option |

## Challenges solved

A few issues that came up while building the Tic Tac Toe project:

- **Char-to-index conversion:** translating the player's input (e.g. `'5'`) into the actual board index (`4`) using `casilla - '0' - 1`, since the player counts from 1 but the array starts at 0.
- **Out-of-range input:** an early version didn't validate that the entered number was between 1 and 9. An invalid number produced an out-of-bounds index, accessing memory outside the array. Fixed by adding `indice < 0 || indice > 8` to the input validation loop.
- **Variable scope:** the `indice` variable was initially declared inside the `do { }` block, making it unreachable from the loop's `while` condition. Fixed by declaring it before the `do` block.

## Author

MAMV
