////
////  tesst.cpp
////  hw2
////
////  Created by Lance Aquino on 4/24/22.
////
//
//#include <iostream>
//#include "Student.h"
//#include <string>
//#include "StudentClub.h"
//
//using namespace std;
//int main()
//{
//    
//    string Pname = "V";//"Victor Presy";//"Michael President";
//    string VPname ="V";// "Victor Presy";
//    string Sname = "V";//"Jimmy Sec";
//    string Tname = "V";//"Tommy Treasurer";
//    
//    Student P, VP, S, T;
//    P = Student(Pname);
//    VP = Student(VPname);
//    S = Student(Sname);
//    T = Student(Tname);
//    
//    vector<Student*> members;
//
//    Student* Pp = &P;
//    
//    Student *VPp = &VP;
//
//    Student* Sp = &S;
//
//    Student* Tp = &T;
//    
//    
//    std::string name;
//    
//    while (name != "Q")
//    {
//        cout << "Input student name. Type \"Q\" to stop: ";
//        getline(cin,name);
//        if (name == "Q")
//        {
//            break;
//        }
//        Student new_member = Student(name);
//        Student* new_member_ptr = &new_member;
//        members.push_back(new_member_ptr);
//    }
//    
//    StudentClub dumbasses = StudentClub(Pp, VPp, Sp, Tp, members);
//    
//    
//    
//    cout<< "There are " << dumbasses.number_members() << " members in the club\n";
//    cout<< "President name/address: "<< dumbasses.get_president()->get_name() << " "<<dumbasses.get_president() << '\n';
//    cout<< "Vice President name/address: "<<dumbasses.get_vice_president()-> get_name() << " " <<dumbasses.get_vice_president() << '\n';
//    cout << "Secretary name/address: "<< dumbasses.get_secretary()->get_name() << " "<< dumbasses.get_secretary()<< '\n';
//    cout << "Treasurer name/address: "<< dumbasses.get_treasurer() -> get_name() << " " << dumbasses.get_treasurer() << '\n';
//
//    
//    return 0;
//}
///*
//
//Code for testing the Student class
//Student stud1;
//string name1 = "Michael";
//string name2 = "Jackson";
//stud1 = Student (name1);
//Student stud2 = Student(name2);
//
//if (stud1 == stud2)
//{
//    cout << "Same name\n";
//}
//else
//{
//    cout<< "Different names\n";
//}
//
//stud1 = stud2; // makes the names the same
//
//if (stud1 == stud2)
//{
//    cout << "Same name\n";
//}
//else
//{
//    cout<< "Different names\n";
//}
//*/
//
