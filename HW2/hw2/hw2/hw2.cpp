/*
PIC 10B 2A, Homework 2
Purpose: Program that records the officers and members of a club, while also taking into account members who hold multiple positions. This is the main file
Author: Lance Anthony Aquino
Date: 04/20/2022
*/


#include "Student.h"
#include "StudentClub.h"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    
    string current_officer_to_add; // string variable that will receive the input of the officer
    
    // creation of 4 Student classes that store the four main officer positions
    cout<< "President: ";
    getline (cin, current_officer_to_add);
    Student pres = Student (current_officer_to_add);
    
    cout << "\nVice President: ";
    getline(cin, current_officer_to_add);
    Student v_pres = Student(current_officer_to_add);
    
    cout << "\nSecretary: ";
    getline (cin, current_officer_to_add);
    Student sec = Student (current_officer_to_add);
    
    cout<< "\nTreasurer: ";
    getline (cin,current_officer_to_add);
    Student treas = Student (current_officer_to_add);
    
    vector<Student*> members;
    std::string name;
    
    // continues to accept Student classes of new members, until "Q" is hit
    while (name != "Q")
    {
        cout << "\nNew Member (Q to quit): ";
        getline(cin,name);
        if (name == "Q") // breaks the input loop before a new input for a member can be added
        {
            break;
        }
        Student new_member = Student(name);
        //Student* new_member_ptr = &new_member;
        members.push_back(&new_member);
    }
    
    //StudentClub student_club = StudentClub(pres_ptr, v_pres_ptr , sec_ptr, treas_ptr, members);
    StudentClub student_club = StudentClub(&pres,&v_pres,&sec,&treas, members);

    
    size_t listing_width = 16; // setw uses this number, so that all officer positions align
    
    cout<< "MATHLETES (" << " "<<student_club.number_members() << " total members)\n";
    cout <<  setfill(' ')<<setw(listing_width) << "President: ";
    cout<< student_club.get_president() -> get_name()<<'\n';
    cout <<  setfill(' ')<<setw(listing_width) << "Vice President: ";
    cout <<student_club.get_vice_president() -> get_name()<<'\n';
    cout <<  setfill(' ')<<setw(listing_width) << "Secretary: ";
    cout <<student_club.get_secretary() -> get_name()<<'\n';
    cout <<  setfill(' ')<<setw(listing_width) << "Treasurer: ";
    cout<< student_club.get_treasurer() -> get_name()<<'\n';
    

    return 0;
    
}
