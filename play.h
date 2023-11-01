#ifndef PLAY_H
#define PLAY_H
    #include <stdbool.h>

    // void play();
    int get_Move(char** board, const int rows, const int cols, char blank_char);
    bool get_Valid_Move(const int num_args_read, const int num_args_needed, char** board, const int rows, const int cols, char blank_char, int col);
    bool check_col_availability(char** board, int rows, int col, char blank_char);
    int place_move(char** board, int rows, int cols, char blank_char, char player_piece);
    int switch_Turns(int player);

#endif