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
    
    string pres_str, vp_str, sec_str, treas_str; // string variable that will receive the input of the officer
    
    // creation of 4 Student classes that store the four main officer positions
    cout<< "President: ";
    getline (cin, pres_str);
    
    cout << "\nVice President: ";
    getline(cin, vp_str);
    
    cout << "\nSecretary: ";
    getline (cin, sec_str);
    
    cout<< "\nTreasurer: ";
    getline (cin,treas_str);
    
    const size_t num_officers = 4;
    
    string officer_list[num_officers] = {pres_str, vp_str, sec_str, treas_str};
    vector<Student*> officer_ptr_list (num_officers,nullptr);
    for (size_t first_current_officer_indx = 0; first_current_officer_indx<num_officers;++first_current_officer_indx)
    {
        bool name_already_there = false;
        for (size_t second_current_officer_index = 0; second_current_officer_index < num_officers; ++ second_current_officer_index)
        {
            if (officer_ptr_list[second_current_officer_index] == nullptr || *officer_ptr_list[first_current_officer_indx] == *officer_ptr_list[ second_current_officer_index])
            {
                name_already_there = true;
                officer_ptr_list[second_current_officer_index] = officer_ptr_list[second_current_officer_index];
                break;
                
            }
    
        }
        if (name_already_there == false)
        {
            officer_ptr_list[first_current_officer_indx] = new Student(officer_list[first_current_officer_indx]);
        }
    }
    
    
    
    // continues to accept Student classes of new members, until "Q" is hit
    
    vector<Student*> members;
    string name;
    
    while (name != "Q")
    {
        cout << "\nNew Member (Q to quit): ";
        getline(cin,name);
        if (name == "Q") // breaks the input loop before a new input for a member can be added
        {
            break;
        }
        Student* new_member = new Student(name);
        members.push_back(new_member);
    }
    
    //StudentClub student_club = StudentClub(pres_ptr, v_pres_ptr , sec_ptr, treas_ptr, members);
    
    StudentClub student_club = StudentClub(officer_ptr_list[0], officer_ptr_list[1], officer_ptr_list[2], officer_ptr_list[3], members);


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
    

    //student_club.~StudentClub(); // ask about this
    
    return 0;
    
}
