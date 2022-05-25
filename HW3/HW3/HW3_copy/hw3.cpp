/*
 PIC 10B, Homework 3
 Purpose: Main routine file for the assignment
 Author: Lance Anthony Aquino
 Date: 05/01/2022
*/


#include "textfile.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
int main()
{
    // User input the names of the files to be analyzed, including the .txt extension for each file name
    std::string file_1_name, file_2_name;
    cout<< "Enter the name of file 1: ";
    getline (cin,file_1_name);
    cout<< "Enter the name of file 2: ";
    getline (cin,file_2_name);
    
    // Generates Textfle objects for the file names inputted, in order to access the methods for calculating the numbers of chars, words, and lines in either file
    Textfile file1 = Textfile (file_1_name);
    Textfile file2 = Textfile (file_2_name);
    
    ofstream properties_ofs ("properties.txt",  std::ios_base::app ); // creates a new txt file named "properties.txt and generates an output file stream to it in order write down info about the properties and comparisons of the properties between file1 and file2
    
    // Writes down the properties of file1 and file2, including their names, the number of chars, and the number of words stored in each
    properties_ofs << "File Name: "<< file1.get_file_name() << '\n';
    properties_ofs << "Number of characters: "<< file1.get_num_of_chars() << '\n';
    properties_ofs << "Number of words: "<< file1.get_num_of_words() << "\n\n";

    properties_ofs << "File Name: "<< file2.get_file_name() << '\n';
    properties_ofs << "Number of characters: "<< file2.get_num_of_chars() << '\n';
    properties_ofs << "Number of words: "<< file2.get_num_of_words() << "\n\n";

    // compares the number of lines stored in file1 and file2
    if (file1 == file2) // if both files have the same number of lines
    {
        properties_ofs << "The file named \""<< file1.get_file_name() << "\" has the same number of lines as the file named \""<< file2.get_file_name()<<"\".";
    }
    else if(file1 < file2) // if file1 has lest lines than file2
    {
        properties_ofs << "The file named \""<< file1.get_file_name() << "\" has less lines than the file named \""<< file2.get_file_name()<<"\".";
    }
    else // if file1 has more lines than file2
    {
        properties_ofs << "The file named \""<< file1.get_file_name() << "\" has more lines than the file named \""<< file2.get_file_name()<<"\".";
    }
    
    return 0;
}
