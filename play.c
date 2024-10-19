#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "play.h"

//Used
// void play(){
//     while(!game_over(char** board, const int rows, const int cols, char player_piece, int needed_Amount)){
//         get_Move(char** board, const int rows, const int cols, char blank_char, int row, int col); //changed
//         place_move(char** board, int rows, int col, char blank_char);
//         switch_Turns(int player);
//     }
// }

//Used
bool isValidFormat(const int num_args_needed, const int num_args_read, bool should_be_last_value_on_line){
	bool format_is_correct = num_args_read == num_args_needed;
	if(should_be_last_value_on_line){
	    char should_be_newline = '?';
		scanf("%c", &should_be_newline);
		format_is_correct = format_is_correct && should_be_newline == '\n';
	 }
	return format_is_correct;
}

int get_Move(char** board, const int rows, const int cols, char blank_char){
    int num_args_read;
    int num_args_needed = 1;
    int col;

    do{
        sprintf("Enter a column between 0 and %d to play in: ", rows);
        num_args_read = scanf("%d", &col);
    }while(!(get_Valid_Move(num_args_read, num_args_needed, board, rows, cols, blank_char, col)));


    return col;
}


bool get_Valid_Move(const int num_args_read, const int num_args_needed, char** board, const int rows, const int cols, char blank_char, int col){
    if(!(isValidFormat(num_args_read, num_args_needed, true))){
        return false;
    }
    else if((col > cols) || (col < 0)){
        return false;
    }
    else if(!(check_col_availability(board, rows, col, blank_char))){
        return false;
    }
    else{
        return true;
    }
}

//Use
bool check_col_availability(char** board, int rows, int col, char blank_char){
    for(int i = 0; i < rows - 1; ++i){
        if(board[i][col] == blank_char){
            return true;
        }
    }
    return false;
}


 int place_move(char** board, int rows, int cols, char blank_char, char player_piece){
    for(int i = rows - 1; i >= 0; i--){
        if(board[i][cols] == blank_char){
            board[i][cols] = player_piece;
            return i;
        }
    }
    return 0;
 }

//Used
int switch_Turns(int player){
    if(player == 1){
        return 0;
    }
    else{
        return 1; 
    }
}
