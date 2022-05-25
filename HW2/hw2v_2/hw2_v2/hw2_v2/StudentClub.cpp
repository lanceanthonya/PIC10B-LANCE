/*
PIC 10B 2A, Homework 2
Purpose: CPP file for StudentClub Class
Author: Lance Anthony Aquino
Date: 04/20/2022
*/

#include "StudentClub.h"

StudentClub::StudentClub(Student*& p, Student*& v, Student*& s, Student*& t, std::vector<Student*> &m):
    president(p),
    vice_president (v),
    secretary(s),
    treasurer(t),
    members_of_club(m)
{
    // First, checks if any officers stored in president, vice_president, secretary, or treasurer refer to the same student, meaning their Student class have the same name
    //same_officer_check();

    // Secondly, adds the officers to the members vector if they aren't in it already. Skips duplicates.
    add_officers_to_members();
    
}

Student* StudentClub::get_president() const
{
    return president;
}


Student* StudentClub::get_vice_president() const
{
    return vice_president;
}


Student* StudentClub::get_secretary() const
{
    return secretary;
}


Student* StudentClub::get_treasurer() const
{
    return treasurer;
}


std::vector<Student*> StudentClub::get_members() const
{
    return members_of_club;
}


void StudentClub::add_member(Student* s)
{
    members_of_club.push_back(s);
}


size_t StudentClub::number_members() const
{
    return members_of_club.size();
}



void StudentClub::same_officer_check()
{
    std::vector<Student*> officers_of_club = {president, vice_president, secretary, treasurer}; // will store an array of all officers in the club positions, in this order. The number
    
    const size_t num_officers = officers_of_club.size(); // the number of officers is always const
    
    for (size_t cur_officer_1 = 0; cur_officer_1 < num_officers ; ++ cur_officer_1) // iterates through each officer for the main loop
    {
        for (size_t cur_officer_2 = 0; cur_officer_2 < num_officers ; ++ cur_officer_2) // as a secondary loop, loops through each officer again in order to compare to the officer n the first loop
        {

            if (*officers_of_club[cur_officer_1] == *officers_of_club[cur_officer_2]) // if two officers refer to two different Student classes that have the same name, it sets the pointer to the officer in the first loop equal to the pointer to the officer in the second loop
            {
                delete officers_of_club[cur_officer_1];
                officers_of_club[cur_officer_1] = officers_of_club[cur_officer_2];
            }
        }
    }
    
    
    // The vector officers_of_club retains the same order, since it's editted in place. Student pointers to the same
    president = officers_of_club[0];
    vice_president = officers_of_club[1];
    secretary = officers_of_club[2];
    treasurer = officers_of_club[3];
}

void StudentClub::add_officers_to_members(){
    
    std::vector<Student*> officers_of_club = {president, vice_president, secretary, treasurer}; // stores a temporary array of all the officers in the club
    
    for (Student* Current_Officer : officers_of_club) // iterates through all the officers of the club to see if they are already listed as members
    {
        bool officer_alredy_listed = false;
        for (Student* Current_Member : members_of_club) // iterates through each member of the club
        {
            if ((*Current_Officer) == (*Current_Member)) // if the officer is found in the members list, their name iss not added and it skips them
            {
                officer_alredy_listed = true;
                break;
            }
        }
        if (officer_alredy_listed == false)
        {
            members_of_club.push_back(Current_Officer);
        }
        
        
    }
}

StudentClub::~StudentClub()
{
    for (Student* student_ptr : members_of_club)
    {
        delete student_ptr;
    }
}
