/*
PIC 10B 1A, Homework 1
Purpose: Tic-tac-toe game, Game class cpp file
Author: Lance Anthony Aquino
Date: 04/15/2021
*/

#include "game.h"
#include "person.h"
#include <vector>
#include <iostream>

// Constructor

Game::Game(Person& _player_o, Person& _player_x):
    player_o (&_player_o), // addresssess of _player_o and _player_x in memory, so operator '&' was used
    player_x (&_player_x),
    winner (nullptr), // empty at first. Modified when one of the two players has won
    game_board (std::vector<std::vector<Person*>>(column_size,row)) // creation of the full, empty 3x3 gameboard
{}

//Member functions

char Game::player_char(const Person* player)
{
    // Compares the inputted player pointer to that of the player pointers stored in the Game class. If neither, a blank space is returned, corressponding to nullptr
    if (player == player_o) // checks if the inptted player pointer matches that of player_o
    {
        return 'O';
    }
    else if (player == player_x)  // checks if the inptted player pointer matches that of player_x
    {
        return 'X';
    }
    return ' '; // if the char matches neither, returns false
}

void Game::display()
{
    // prints the game board by row
    // note, the first subscript refers to the horizontal row, the second subscript refers to the vertical column
    // player_char should yield a char based on the pointer stored at the given position in the 3x3 game_board. X is it matches player_x, o if player_o, and a blank space ' ' if nullptr
    std::cout << '\n';
    std::cout << "     1       2      3  \n";
    std::cout << "         |       |     \n";
    std::cout << "1    "<<player_char(game_board[0][0])<<"   |   "<<player_char(game_board[0][1])<<"   |  "<<player_char(game_board[0][2])<<"  \n";
    std::cout << "  _______|_______|_____\n";
    std::cout << "         |       |     \n";
    std::cout << "2    "<<player_char(game_board[1][0])<<"   |   "<<player_char(game_board[1][1])<<"   |  "<<player_char(game_board[1][2])<<"  \n";
    std::cout << "  _______|_______|_____\n";
    std::cout << "         |       |     \n";
    std::cout << "3    "<<player_char(game_board[2][0])<<"   |   "<<player_char(game_board[2][1])<<"   |  "<<player_char(game_board[2][2])<<"  \n";
    std::cout << "         |       |     \n";
    std::cout << '\n';

    
}

bool Game::make_move ( Person& player_making_move, int column_coordinate, int row_coordinate){
    
    size_t min_coordinate = 1; // the minimum coordinate value in either direction is 1
    //First, checks if input corresponds to a valid position
    if (column_coordinate < min_coordinate || column_size < column_coordinate) //  checks to see if the column coordinate is within bounds, which would mean that it's is between 1 and 3 inclusive
    {
        return false;
    }
    if (row_coordinate < min_coordinate || horizontal_size < row_coordinate) //  checks to see if the horizontal coordinate is within bounds,  which would mean that it's is between 1 and 3 inclusive
    {
        return false;
    }
    
    //Converts coordinates into their indeces within the 3x3 matrix (indeces 0 and 2 correspond to the positions 1 and 3)
    size_t column_index = column_coordinate-1;
    size_t row_index = row_coordinate-1;
    if (game_board[row_index][column_index] != nullptr)   // Next, checks if the position to modify is already occupied
    {
        return false;
    }
    else
    {
        game_board[row_index][column_index] = &player_making_move; // modifies game_board pointer so that it now points at the player who made the move
        return true;
    }

}

bool Game::player_has_won_match (Person& player_to_check)
{

    if (horizontal_win(player_to_check) || vertical_win(player_to_check)|| diagonal_win(player_to_check)) // checks to see if the player has met the win condition by having 3 in a row in eitther the horizonttal, vertical, or diagonal directions. They just need one of any of these three win conditions in order to beat the game
    {
        winner = &player_to_check; // sets Person* winner to point at the player_to_check if they meet any of the 3 possible win conditions
        return true;
    }
    else // if the player_to_check fails all win conditions, then this will remain false and winner remains pointing to nullptr.
    {
        return false;
    }
    
    
}

bool Game::horizontal_win (Person& player_to_check)
{
    
    bool has_won = false;
    for (auto current_row : game_board) // iterates through each "row" (so starts with game_board[0], ends with game_board[2]
    {
        bool row_only_points_to_inputted_player = true; // initially set to true. Becomes false for a given row if it ever encounters a pointer other than the inputted player's
        for (Person* current_position : current_row) // iterates through each position within a given horizontal row
        {
            if (current_position != &player_to_check) //checks to see if the given position points to the player to check
            {
                row_only_points_to_inputted_player = false; // changes this to false if the row ever points to nullptr or the other player
                break;
            }
            
        }
        if (row_only_points_to_inputted_player == true) // if at the end of the check, the all pointers within the horizontal row ponted to the inputted player, then they have met the win condition in the horizontal direction
        {
            winner = &player_to_check;
            has_won = true; // ends the loop since the player has met the win condition at least once.
            break;
        }
    }
    return has_won;
}

bool Game::vertical_win (Person& player_to_check)
{
    bool has_won = false;
    size_t max_row_index = horizontal_size - 1; // refers to the final row index. The last row in our case is game_board[2], or the last vector in game_board
    size_t max_column_index = column_size - 1; // refers to the last column index. In our case, that will be x = 3. In practice, row 1, column 3 will refer to game_board[0][2], or the last element within the vector game_board[0]
    for (size_t current_column = 0; current_column<=max_column_index; ++ current_column) // iterates through each column of the 3x3 grid
    {
        bool column_only_points_to_inputted_player = true;
        for (size_t current_row = 0; current_row <=max_row_index; ++current_row) // iterates through each row in a column (goes downward in the 3x3 gameboard)
        {
            if (game_board[current_row][current_column]!= &player_to_check) // checks to if any pointers within a given vertical column in game_board differ from that of the player to check
            {
                column_only_points_to_inputted_player = false; // immediately breaks the loop iterating through a given column if a pointer that isn't the inputted player's is detected in the current column
                break;
            }
            
        }
        if (column_only_points_to_inputted_player == true) // if an entire column is iterated through and no pointers other than the inputted player's were found, then they have met the win condition in the vertical direction
        {
            has_won = true;
            break;
        }
    }
    return has_won;
}

bool Game::diagonal_win (Person& player_to_check)
{
    bool has_won = false;
    size_t max_row_index = horizontal_size - 1; // refers to the final row index. The last row in our case is game_board[2], or the last vector in game_board. Note both diagonal checks start from the first horizontal row and end at the last horizontal row
    size_t max_column_index = column_size - 1; // refers to the last column index.
    
    // Note, the possible diagonal positions to check are:
    // left to right: (1,1),(2,2),(3,3), such that it makes a "line" that would look like: '\'
    bool left_right_diagonal_only_points_to_player = true;
    for (size_t current_left_right_diagonal = 0; current_left_right_diagonal<= max_row_index; ++ current_left_right_diagonal)
    {
        if (game_board[current_left_right_diagonal][current_left_right_diagonal]!= &player_to_check) // checks to if any pointers within the left-to-right diagonal line in game_board differ from that of the player to check
        {
            left_right_diagonal_only_points_to_player = false; // immediately breaks the loop iterating through a given column if a pointer that isn't the inputted player's is detected in the diagonal
            break;
        }
    }
    if (left_right_diagonal_only_points_to_player == true) // should always stay true if there were never any positions that pointed to anything besidess that of the inputted player
    {
        has_won = true;
        return has_won;
    }
    
    // right to left: (1,3),(2,2), (3,1), such that it makes a "line" that would look like: '/'
    bool right_left_diagonal_only_points_to_player = true;
    //iterates through the indeces of any position on the 3x3 board that would make a diagonal line from right to left
    for (size_t current_row = 0, current_column = max_column_index ; current_row<=max_row_index; ++current_row, -- current_column) //note that this starts at the rightmost position, so we start at the first row (row 1), at the last column (column 3)
    {
        if(game_board[current_row][current_column]!= &player_to_check) //checks to if any pointers within the right-to-left diagonal line in game_board differ from that of the player to check
        {
            right_left_diagonal_only_points_to_player = false; // immediately sets this win condition to false and breaks the loop if it finds a pointer that differs from that of the player being checked
            break;
        }
    }
    if (right_left_diagonal_only_points_to_player == true) //should always stay true if there were never any positions that pointed to anything besidess that of the inputted player
    {
        has_won = true;
        return has_won;
    }
    
    return has_won; // if there is no win in either diagonal, then has_won remains false and the inputted player has not won in either of  the diagonal directions
}

Person* Game::get_winner() const
{
    return winner; // returns a pointer to the winner of the match
}

