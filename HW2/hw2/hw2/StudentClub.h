/*
PIC 10B 2A, Homework 2
Purpose: Header file for StudentClub Class
Author: Lance Anthony Aquino
Date: 04/20/2022
*/

#ifndef __STUDENTCLUB__
#define __STUDENTCLUB__

#include "Student.h"
#include <vector>

class StudentClub{
public:
    
    /**
     Constructor for a StudentClub class
     
     @param p President of the club
     @param v Vice president of the club
     @param t Treasurer of the club
     @param m Vector storing all the members of the club. Doesn't include the officers, but if it does, they are accounted for
     */
    StudentClub(Student* p, Student* v, Student* s, Student* t, std::vector<Student*> &m);
    
    /**
     Getter function for the president
     
     @return pointer to the pressident of StudentClub
     */
    
    Student* get_president() const;
    
    /**
     Getter function for the vice president
    
    @return pointer to the vice president of StudentClub
     */
    
    Student* get_vice_president() const;
    
    /**
     Getter function for the secretary
    
     @return pointer to the  secre&tary of StudentClub
     */
    Student* get_secretary() const;
    
    /**
     Getter function for the treasurer
    
    @return pointer to the  treasurer of StudentClub
     */
    Student* get_treasurer() const;
    
    /**
     Getter function for the member vector
    
    @return a vector storing pointerss to all studentss in the club
     */
    std::vector<Student*> get_members() const;
    
    /**
     Adds a new member to the StudentClub class,
     
     @param s a pointer to a student object
     */
    void add_member(Student* s);
    
    /**
     Returns the number of members stored in 
     */
    size_t number_members() const;
private:
    
    
    Student* president = nullptr;
    Student* vice_president = nullptr;
    Student* secretary = nullptr;
    Student* treasurer = nullptr;
    std::vector<Student*> members_of_club;
   
    
    /**
     Iterates through the list of pointers to all the officers in the club. If two Student names are the same, then they're set to the same addresss if they weren't already. Then changes the values of president, vice_president, secretary, and treasurer based on this since the array should retain the same order as seen above
     */
    void same_officer_check();
    
    /**
     Iterates through the list of officers and the list of members. If the officer's name is not found in the current list of all pointers for the members of the club, then their pointer is added. If the name is found in the existing list of members, then their name is not added to the roster.
     */
    void add_officers_to_members();
    

    
};

#endif /* __STUDENTCLUB__ */


