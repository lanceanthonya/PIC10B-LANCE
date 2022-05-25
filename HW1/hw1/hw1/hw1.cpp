/*
PIC 10B 1A, Homework 1
Purpose: Tic-tac-toe game, main routine file
Author: Lance Anthony Aquino
Date: 04/15/2021
*/

#include "person.h"
#include "game.h"
#include <iostream>
#include <string>

using namespace std;
int main()
{
    // Asks for the number of games to play
    int num_games;
    do
    {
        if (cin.fail()) // if the previous attempt to input a valid input failed, clears the cin buffer
        {
            cin.clear();
            cin.ignore(256, '\n');
        }
        cout << "Number of games: ";
        cin >> num_games;
    }
    while (cin.fail()); // runs until user inputs a valid input that does not cause cin to fail. In this case, they need to input an int
    
    // Ask for player names
    cin.clear();
    cin.ignore(256, '\n');  // ignores whitespace from the previous input
    string player_x_name, player_o_name;
    cout << "Player 1 name = ";
    getline (cin, player_x_name);
    cout << "Player 2 name = ";
    getline (cin, player_o_name);
    
    // Creates two person classes. One for each player involved in the game. The player's score in the tournament is a member value that can be accessed later
    Person player_x = Person(player_x_name);
    Person player_o = Person(player_o_name);
    
    // Start of game routine. Print out words "Tic Tac Toe" and the markers each user will use
    cout << "     Tic Tac Toe\n";
    cout << "  "<< player_x.get_name() << " (X) - "<< player_o.get_name() << " (O)\n";
    
    // Main tournament routine. Loops until the number of games played == the number of games to play set at the start
    for (size_t current_game = 1; current_game <= num_games; ++current_game) // iterates through rounds until the number of games played equals num_games. Starts with game # 1, or current_game = 1
    {
        
        const size_t max_num_moves = 9; // the max possible number of moves is 9, since there are 9 total spaces on the 3x3 grid. If the number of moves has reached 9 and there is no winner yet, then it's a stalemate. No winner for a round
        
        
        // Routine for one round. Loops until the maximum number of moves has been made. If by the end of the round, no one has won, this round ends in a draw
        
        Game round = Game (player_o, player_x); // resets the game board by creating a new Game object.
        
        round.display(); // shows the initial, empty 3x3 game board so that the first player can make their move
        
        Person* player_whose_turn_it_is = nullptr; // pointer that points to whoever's turn in is to make a move during the round
        
        for (size_t num_moves_made = 1; num_moves_made<=max_num_moves; ++ num_moves_made)
        {
            int row_coordinate = 0 , column_coordinate = 0; // coordinates for user input
            if (num_moves_made%2!= 0) // player_x always makes the first move. Therefore, they always make a move if the current number of moves made is odd
            {
                player_whose_turn_it_is = &player_x; //makes it so that player_x will be prompted to make a move
            }
            else //player_o makes a move on any other turn, which will be on an even-numbered turn
            {
                player_whose_turn_it_is = &player_o;
            }
            
            do // do while loop that keeps asking user for input until they finally input valid coordinates for the game
            {
                
                if (cin.fail()) // if the previous attempt to input a valid input failed, clears the cin buffer so that the user can try to input coordinates again
                {
                    cin.clear();
                    cin.ignore(256, '\n');
                }
                else if (!cin.fail()) // if the previous attempt to input a valid input was alright, prompts the user for input
                {
                    cout << player_whose_turn_it_is->get_name()<< " ("<< round.player_char(player_whose_turn_it_is)<< ") Mark Location: ";
                    cin >> column_coordinate >> row_coordinate;
                }
            }
            while (cin.fail() || !round.make_move(*player_whose_turn_it_is, column_coordinate, row_coordinate)); // checks to see if the move was valid by checking to seee if the buffer failed, which would indicate that the wrong number of chars, non-ints, or a string was inputted. Then runs tthe make_move() function, which checks to see if the chars inputted are valid coordinates. The function returns false if the move was invalid. If the input was valid, then the move is made and the board dissplay is shown
            
            round.display(); // displays the game board, after it has been modified by the user inputted mark
            if (round.player_has_won_match(*player_whose_turn_it_is))// checks if the current player pointed at by player_ptr has met any win conditions
            {
                break;
            }
        }
        if (round.get_winner() == nullptr) // special case where no winner has been set
        {
            cout << "No one wins this round\n";
            cout << player_x.get_name() << " : " << player_x.get_score() <<'\n';
            cout << player_o.get_name() << " : " << player_o.get_score()<< '\n';
        }
        else // case where there is a definitive winner
        {
            Person* winner_ptr = round.get_winner(); // pointer to the winner of the game
            std::string winner_name = winner_ptr -> get_name(); // dereferences the winner pointer and calls the get_name() method on that value
            cout <<  winner_name << " wins this round\n";
            winner_ptr -> increment_score(); // increments the score of the winner of the round
            
            // Prints the running score for both players once the round is over
            cout << player_x.get_name() << " : " << player_x.get_score() <<'\n';
            cout << player_o.get_name() << " : " << player_o.get_score()<< '\n';
        }

        
    }
    
    // Post-tournament routine. Tells us who won based on the scores stored for each Person
    
    int player_x_score = player_x.get_score();
    int player_o_score = player_o.get_score();
    
    if (player_x_score < player_o_score) // player o scored higher than player x
    {
        cout<< "Congratulations " << player_o.get_name()<< " . You Won!";
    }
    else if (player_x_score > player_o_score) // player x scored higher than player o
    {
        cout<< "Congratulations " << player_x.get_name()<< " . You Won!";
    }
    else // Last case is if their final scores are equal, where the tournament ends in a tie
    {
        cout << "No one wins. Tournament ends in a tie!";
    }
    
    return 0;
    
}
