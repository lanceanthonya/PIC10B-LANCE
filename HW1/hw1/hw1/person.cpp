/*
PIC 10B 1A, Homework 1
Purpose: Tic-tac-toe game, Person class cpp file
Author: Lance Anthony Aquino
Date: 04/15/2021
*/

#include "person.h"
#include <string>

Person::Person(const std::string& _name) :
    name(_name),
    score(score_zero) // at initialization, the user's score is set to 0
{}
    
int Person::get_score() const
{
    return score; //simply returns the Person class' score stored at the time of the function call
}

std::string Person::get_name() const
{
    return name;
}

void Person::increment_score()
{
    ++score; // increments the player's current score by 1, to indicate that they have won a round of the tic-tac-toe tournament
}


