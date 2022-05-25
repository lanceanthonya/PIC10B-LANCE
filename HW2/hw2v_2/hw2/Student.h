/*
PIC 10B 2A, Homework 2
Purpose: Header file for Student Class
Author: Lance Anthony Aquino
Date: 04/20/2022
*/

#ifndef __STUDENT__
#define __STUDENT__
#include <string>

/**
 @class Student refers to a student that can be a regular member of the club or an officer. Just stores an std::string for the student's name and can be default constructed.
 */
class Student
{
public:
    /**
     Default Constructor that creates a Student object with an empty string stored as the name
     */
    Student();
    
    /**
     Constructor for a student object at stores an inputted name for the Student class
     
     @param _name inputed name for the Student class
     */
    Student(const std::string& _name);

    /**
     Getter function for the Student class' name
     
     @return name variable stored in the student object
     */
    std::string get_name() const;
    
private:
    std::string name;

};

/**
 Overload for the operator '==', which checks if the two Student classess have the same std::string name value
 
 @param stud_1 the first student object
 @param stud_2 the second student object
 
 @return true if the names stored match
 */
bool operator==( const Student& stud_1, const Student& stud_2);

#endif /* __STUDENT__ */
