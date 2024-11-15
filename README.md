# Connect N

This project is a C implementation of the classic Connect-N game, where players take turns placing their pieces on a grid. The objective is to be the first to get a specified number of consecutive pieces in a row, column, or diagonal.

How to Run
To compile and run the game, you need to have a C compiler (e.g., gcc). After compiling, you can run the game by providing command-line arguments for the board size and winning condition.

Compilation
bash
Copy code
gcc -o connectn main.c
Execution
The program requires three arguments:

num_rows: Number of rows on the game board.
num_columns: Number of columns on the game board.
number_of_pieces_in_a_row_needed_to_win: The number of consecutive pieces required to win.
bash
Copy code
./connectn num_rows num_columns number_of_pieces_in_a_row_needed_to_win
Example:

bash
Copy code
./connectn 6 7 4
Game Mechanics
Game Setup:

The board is initialized with empty spaces using the build_board function.
Players are assigned pieces (e.g., X and O) and take turns placing their pieces.
Gameplay Loop:

Players select a column to drop their piece.
The game checks if the current move leads to a win or tie.
The game ends when a player wins or the board is filled without a winner.
Win/Tie Conditions:

The game detects a win by checking rows, columns, and diagonals using functions such as is_horizontal_win, is_vertical_win, and diagonal checks.
A tie is declared if all cells are filled with no winning sequence.
Memory Management:

Memory for the game board is allocated dynamically and freed after the game to avoid memory leaks.
Key Files and Functions
main.c: Contains the main logic of the game, including setting up the board, player moves, and determining the game outcome.
build_board: Creates the game board based on input dimensions.
display_Board: Displays the current state of the board to the player.
get_Move and place_move: Handle player inputs and update the board.
switch_Turns: Alternates between players.
game_over, game_over_win, game_over_tie: Check for winning or tie conditions.
clean_board: Frees memory allocated for the board.
Example Output
plaintext
Copy code
Enter a column between 0 and 6 to play in: 3
Player X placed a piece in column 3
...
Player X Won!
Additional Notes
Ensure that each player selects a valid column that is not already full.
The game will prompt again if an invalid column is entered.
Future Improvements
AI Player: Add an option to play against a basic AI.
Graphical Interface: Convert the game to a graphical version using a library such as SDL for a better user experience.
