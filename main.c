#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "play.h"
#include "setup.h"


//Declarations
// void play_game(int rows, int cols, char blank_char);
// void setup();
// void announce_results(int player_num);
char** build_board(int row_dimension, int col_dimension, char blank_char);
// char* players_pick_pieces(int num_players);
// char player_pick_piece(int player_num);
// bool is_valid_piece(char piece);

// //Used
// void play_game(){
//     setup(int rows, int cols, char blank_char);
//     play(char** board, const int rows, const int cols, char blank_char, int needed_Amount);
//     announce_results(int player_num);
// }

// //Used
// void setup(int rows, int cols, char blank_char){
//     build_board(int rows, int cols, char blank_char);
//     players_pick_pieces(int num_players);
//     choice_first_player();
// }

//Used
char** build_board(int row_dimension, int col_dimension, char blank_char){
    char** board = (char**)calloc(row_dimension, sizeof(char*));
    for(int i = 0; i < row_dimension; ++i){
        board[i] = (char*)calloc(col_dimension, sizeof(char));
        for(int j = 0; j < col_dimension; ++j){
            board[i][j] = blank_char;
        }
    }
    return board;
}

//Used
// void announce_results(int player_num){
//     if(won(player_num)){
//         printf("Player %d Won!", player_num);
//     }
//     else{
//         printf("Tie game!");
//     }
// }

//Used

// //Used
// char* players_pick_pieces(int num_players){
//     char* pieces = (char*)calloc(num_players, sizeof(char));
//     for(int i = 0; i < num_players; ++i){
//         pieces[i] = player_pick_piece();
//     }
//     return pieces;
// }

// //Used
// char player_pick_piece(int player_num){
//     char piece;
//     char prompt[50];
//     sprintf(prompt, "Player %d please enter your piece: ", player_num);
//     do{
//         piece = getValidChar(prompt);
//     }while(!is_valid_piece(piece));
//     return piece;
// }

// //Used
// bool is_valid_piece(char piece){
//     if(piece == ' '){
//         return false;
//     }
//     else if(!(is_one_of(piece, players_pick_pieces()))){
//         return false;
//     }
//     else{
//         return true;
//     }
// }

// bool is_one_of(char piece1, char* players_pieces, int rows, int cols){
//     for(int i = 0; i < rows; ++i){
//         if(players_pieces[i] == piece1){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
// }



int main(int argc, char* argv[]){
    char symbol = '*';

    if(argc < 4){
        printf("Not enough arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }   
    else if(argc > 4){
        printf("Too many arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }

    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);
    int needed_Amount = atoi(argv[3]);

    char** board = build_board(rows, cols, symbol);

    char player_pieces[50] = "XO";

    int player_turn = 0;

    int placed_col = 0;
    int placed_row = 0;

    while(!(game_over(board, rows, cols, needed_Amount, placed_row, placed_col, player_turn, symbol))){
        display_Board(board, rows, cols);
        placed_col = get_Move(board, rows, cols, symbol);
        placed_row = place_move(board, rows, placed_col, symbol, player_pieces[player_turn]);
        player_turn = switch_Turns(player_turn);
    }

    if(game_over_win(board, player_pieces[player_turn], placed_row, placed_col, needed_Amount)){
        printf("Player %d Won!", player_turn);
    }
    else{
        printf("Tie game!");
    }
    clean_board(board, rows, cols, symbol);

    return 0;
}