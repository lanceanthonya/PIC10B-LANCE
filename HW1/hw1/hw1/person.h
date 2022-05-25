/*
PIC 10B 1A, Homework 1
Purpose: Tic-tac-toe game, Person class header file
Author: Lance Anthony Aquino
Date: 04/15/2021
*/

#include <string>

#ifndef __PERSON__
#define __PERSON__

/**
 @class Person stores the name of a given player, as well as their running score throughout the tournament
 */
class Person {
public:
    
    /**
     Constructor: Accepts an std::string for the user's name and generates a Person class storing their name and score throughout the tic-tac-toe tournament. Sets their score as 0 at initialization.
     
     @param _name name of the player
     */
    Person(const std::string& _name);
    
    
    /**
     Getter function returning the player's score
     
     @return the player's score at a given point in the game
     */
    int get_score() const;
    
    /**
     Getter function that returns the name of the player
     
     @return the player's name, inputted during construction of the Person classs
     */
    std::string get_name() const;
    

    /**
     Increments the user's score. Only should be called at the end of a round when a give player wins
     */
    void increment_score();
    
    
    
private:
    const std::string name;
    const int score_zero = 0;
    int score; // number of games the user has won. Starts at 0
    
};
             
#endif /* __PERSON__ */
