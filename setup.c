#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "setup.h"

//Used
void display_Board(char** board, const int rows, const int cols){
       printf(" ");
       for(int i = rows; i >= 0; ++i){
            printf("%d\n", i);
            for(int j = 0; j < cols; ++j){
                printf("%c ", board[rows][cols]);
            }
            printf("\n");
       }

       printf("\n");

       for(int i = 0; i < cols; ++i){
            printf("%d ", i);
       }
}

bool game_over(char** board, const int rows, const int cols, char player_piece, int placed_row, int placed_col, int needed_Amount, char blank_char){
    return game_over_win(char** board, char player_piece, int placed_row, int placed_col, int needed_Amount) || game_over_tie(char** board, const int rows, const int cols, char player_piece, int needed_Amount, char blank_char);
}


bool game_over_win(char** board, char player_piece, int placed_row, int placed_col, int needed_Amount){
    if(is_horizontal_win(board, placed_row, placed_col, player_piece, needed_Amount) || is_vertical_win(board, placed_row, placed_col, player_piece, needed_Amount)){
        return true;
    }
    else if(right_diagonal_win(board, placed_row, placed_col, player_piece, needed_Amount) || left_diagonal_win(board, placed_row, placed_col, player_piece, needed_Amount)){
        return true;
    }
    else{
        return false;
    }
}

bool game_over_tie(char** board, const int rows, const int cols, char player_piece, int needed_Amount, char blank_char){
    if(is_tie(board, rows, cols, blank_char)){
        return true;
    }
    else{
        return false;
    }
}


bool is_tie(char** board, const int rows, const int cols, char blank_char){
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            if(board[i][j] != blank_char){
                return false;
            }
        }
    }
    return true;
}


bool is_horizontal_win(char** board, int rows, int cols, char player_piece, int needed_Amount){
    int count = 1;

    int counter = 0;

    while(board[rows][cols - 1 - counter]  == player_piece){
        count++;
        counter++;
        if(count == needed_Amount){
            return true;
        }
    }



    int second_Counter = 0;

    while(board[rows][cols + 1 + second_Counter] == player_piece){
        count++;
        second_Counter++;
        if(count == needed_Amount){
            return true;
        }
    }
    return false;
}


bool is_vertical_win(char** board, int rows, int cols, char player_piece, int needed_Amount){
    int count = 1;
    int counter = 0;

    while(board[rows - 1 - counter][cols] == player_piece){
        count++;
        counter++;
        if(count == needed_Amount){
            return true;
        }
    }
    return false;
}

bool left_diagonal_win(char** board, int rows, int cols, char player_piece, int needed_Amount){
    int count = 1;
    int counter = 0;

    while(board[rows - 1 - counter][cols - 1 - counter] == player_piece){
        count++;
        counter++;
        if(count == needed_Amount){
            return true;
        }
    }

    int second_Counter = 0;

    while(board[rows + 1 + second_Counter][cols + 1 + second_Counter] == player_piece){
        count++;
        counter++;
        if(count == needed_Amount){
            return true;
        }
    }
    return false;
}

bool right_diagonal_win(char** board, int rows, int cols, char player_piece, int needed_Amount){
    int count = 1;
    int counter = 0;

    while(board[rows + 1 + counter][cols - 1 - counter] == player_piece){
        count++;
        counter++;
        if(count == needed_Amount){
            return true;
        }
        if(rows + 1 + counter >= rows){
            break;
        }
        if(cols - 1 - counter <= 0){
            break;
        }
    }

    int second_Counter = 0;

    while(board[rows - 1 - second_Counter][cols + 1 + second_Counter] == player_piece){
        count++;
        second_Counter++;
        if(count == needed_Amount){
            return true;
        }
    }
    return false;
}


//Used
 void clean_board(char** board, const int rows, const int cols, char blank_char){
    for(int i = 0; i < rows; ++i){
        free((*board)[rows]);
    }
    free(*board);
    *board = NULL;
 }




