/*
PIC 10B 1A, Homework 1
Purpose: Tic-tac-toe game, Game class header file
Author: Lance Anthony Aquino
Date: 04/15/2021
*/

#include "person.h"
#include <string>
#include <vector>

#ifndef __GAME__
#define __GAME__


/**
 @class Game stores information about the 2 players of one round of the tic-tac-toe game. Also stores the status of the tic tac toe game, including what moves have already been made along with the state of the 3x3 game board. Contains a member function for printing the board as well
 */
class Game{
public:
    
    /**
     Constructor: accepts the two Person values, by reference. These Person values are then used to create a game board at construction
     
     @param _player_o Person class refering to the player who is assigned the "O" markers in the tic-tac-toe game
     @param _player_x Person class refering to the player who is assigned the "X" markers in the tic-tac-toe game
     */
    
    Game(Person& _player_o, Person& _player_x);
        
    /**
     Prints the formatted 3x3 game board, as it is at the time of function call
     */
    
    void display();
    
    
    /**
     Given a pointer to a Person class that either matches player_o or player_x, checks if the inputted point matches either and returns a char based on this
     
     @param player the Person class to check
     
     @return a char of either 'O' or 'X', dependent on if the inputted player is player_o or player_x
     */
    
    char player_char(const Person* player);
    
    /**
     Modifies the 3x3 game board, given the user inputted x and y coordinates
          
     @param player_making_move refers to the current Person class making a move. Should alternate with each turn
     @param column_coordinate posittion within a given horizontal row on the board (1-3) that the player wishes to put their mark on
     @param row_coordinate  vertical possition  on the board (1-3) that the player wishes to put their mark on
     
     @return true if the move was valid, false if the move was invalid.
     */
    
    bool make_move ( Person& player_making_move, /*char*/  int column_coordinate, /*char*/  int row_coordinate);
    
    /**
     Checks if the inputted player has won, by aligning their respective mark 3 times in a row on the board, whether tthat is horizontal, vertical, or diagonal. The function is broken down into three functions within it to check for each win condition situation
     
     @param player_to_check the Person class for whom we will check if they have met any win condition on the 3x3 board
     
     @return true if that player has won, else false
     */
    
    bool player_has_won_match (Person& player_to_check);
    
    /**
     Checks if the inputted player has won in the horiizontal direction
     
     @param player_to_check Person class for whom we check for having a victory in the horizontal direction
     
     @return true if the Person has won the game by having three in a row horizontally, false otherwise
     */
    
    bool horizontal_win (Person& player_to_check);

    /**
     Checks if the inputted player has won in the horiizontal direction
     
     @param player_to_check Person class for whom we check for having a victory in the vertical direction
     
     @return true if the Person has won the game by having three in a row vertically, false otherwise
     */
    
    bool vertical_win (Person& player_to_check);
    
    /**
     Checks if the inputted player has won in the diiagonal direction
     
     @param player_to_check Person class for whom we check for having a victory in the diagonal direction
     
     @return true if the Person has won the game by having three in a row diagonally, false otherwise
     */
    
    bool diagonal_win (Person& player_to_check);
    
    /**
     Returns a pointer to the winner of the round
     
     @return a pointer to the winner of the mattch
     */
    
    Person* get_winner() const;

    
private:
    
    Person* player_o; // Pointer for the Person class refering to the player who is assigned the "O" markers in the tic-tac-toe game
    Person* player_x; // Pointer for the Person class refering to the player who is assigned the "X" markers in the tic-tac-toe game
    Person* winner; // Points to the winner. Only set to a Person address if one of the players have met the win condition
    
    const size_t horizontal_size= 3; // length of the game board (total number of horizontal slots)
    const size_t column_size = 3; // width of the game board (number of slots within a horizontal row)
    
    // vector used for creating the 2D vector used for representing and formatting the game board
    std::vector<Person*> row = std::vector<Person*>(horizontal_size,nullptr); // represents one empty horizontal row
    
    // will serve as a 3x3 "grid", with each positon corresponding to a pointer to a Person, which will either be player_o or player_x if they have made a move. If no moves have been made on a position, it is a nullptr by default
    std::vector<std::vector < Person* > > game_board;
    
};

#endif /* __GAME__ */
