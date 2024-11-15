# Connect N

Overview: This project implements a command-line version of a "Connect-N" game. Players take turns placing their pieces on a grid, aiming to line up a specified number of consecutive pieces in any direction (horizontal, vertical, or diagonal) to win. The game supports customizable board dimensions and win conditions.

Features
 - Customizable Game Board: Specify the number of rows, columns, and consecutive pieces needed to win.
 - Player Piece Selection: Players choose their piece symbols.
 - Win and Tie Detection: The game determines when a player has won or if it ends in a tie.
 - Dynamic Player Turns: Alternates between players, checking the board state after each move.

Getting Started
 - Prerequisites
   - C Compiler (e.g., gcc)
   - Standard libraries included in C (e.g., <stdio.h>, <stdlib.h>, <stdbool.h>)
   - Compilation
     - Place all .c and .h files (source and header files) in the same directory.
     - Compile the program with: gcc -o connectn main.c play.c setup.c
     - Run the program with: ./connectn num_rows num_columns win_condition
   - Arguments:
     - num_rows: Number of rows in the game board.
     - num_columns: Number of columns in the game board.
     - win_condition: Number of consecutive pieces needed to win.

Potential Improvements
 - AI Player: Implement a computer opponent.
 - Dynamic Player Piece Selection: Allow players to pick unique symbols dynamically.
 - Graphical Interface: Create a GUI version of the game.
