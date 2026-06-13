# Noughts and Crosses (Tic-Tac-Toe)

A simple two-player implementation of the classic game **Noughts and Crosses** (Tic-Tac-Toe), written in pure C and played in the terminal.

![Language](https://img.shields.io/badge/language-C-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

## Features

- Classic 3×3 Tic-Tac-Toe on a coordinate-labelled board.
- Two-player hot-seat play — Player 1 is `X`, Player 2 is `O`.
- Win detection across rows, columns, and both diagonals.
- Draw detection when the board fills with no winner.
- No external dependencies — just the C standard library.

## Build

You'll need a C compiler such as `gcc`. From the project directory:

```sh
gcc main.c -o tictactoe
```

`main.c` includes `main.h`, so keep both files together.

## Run

```sh
./tictactoe
```

## How to Play

The board uses a 3×3 grid with rows and columns indexed `0`–`2`:

```
Current Game Board:

   0 1 2
0
1
2
```

1. Player 1 (`X`) is prompted first.
2. Enter the **row number** (`0`, `1`, or `2`) and press `Enter`.
3. Enter the **column number** (`0`, `1`, or `2`) and press `Enter`.
4. The updated board is displayed and play passes to Player 2 (`O`).
5. Players alternate until someone lines up three marks horizontally, vertically, or diagonally, or the board fills for a draw.

The result is announced and the program exits.

> **Note:** Entering a coordinate outside `0`–`2`, or choosing a cell that is already taken, ends the game immediately rather than re-prompting.

## Project Structure

| File | Description |
|------|-------------|
| `main.c` | Game logic — board display, move handling, win/draw checks, and the main loop. |
| `main.h` | Function declarations. |
| `Testing/` | A small standalone function test. |

## License

Released under the [MIT License](LICENSE).
