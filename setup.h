#ifndef SETUP_H
#define SETUP_H
    #include <stdbool.h>

    void display_Board(char** board, const int rows, const int cols);
    bool game_over(char** board, const int rows, const int cols, char player_piece, int placed_row, int placed_col, int needed_Amount, char blank_char);
    bool game_over_win(char** board, char player_piece, int placed_row, int placed_col, int needed_Amount);
    bool game_over_tie(char** board, const int rows, const int cols, char player_piece, int needed_Amount, char blank_char);
    bool is_tie(char** board, const int rows, const int cols, char blank_char);
    bool is_horizontal_win(char** board, int rows, int cols, char player_piece, int needed_Amount);
    bool is_vertical_win(char** board, int rows, int cols, char player_piece, int needed_Amount);
    bool left_diagonal_win(char** board, int rows, int cols, char player_piece, int needed_Amount);
    bool right_diagonal_win(char** board, int rows, int cols, char player_piece, int needed_Amount);
    void clean_board(char** board, const int rows, const int cols, char blank_char);


#endif