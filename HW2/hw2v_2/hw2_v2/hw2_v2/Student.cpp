/*
PIC 10B 2A, Homework 2
Purpose: CPP file for Student Class
Author: Lance Anthony Aquino
Date: 04/20/2022
*/

#include "Student.h"
#include <string>

Student::Student() :
    name ("") // sets the name as an empty string by default
{}

Student::Student(const std::string& _name):
    name (_name) // sets the name to the string that was passed as an argument
{}

std::string Student::get_name() const
{
    return name;
}

bool operator==( const Student& stud_1, const Student& stud_2)
{
    return stud_1.get_name() == stud_2.get_name() ? true : false; // compares the name variable stored in both stud_1 and stud_2. Returns true if they are the same string, letter for letter, false otherwise.

}
