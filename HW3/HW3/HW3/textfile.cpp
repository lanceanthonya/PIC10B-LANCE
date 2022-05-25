/*
 PIC 10B, Homework 3
 Purpose: header file for textfile class and other related functions
 Author: Lance Anthony Aquino
 Date: 05/01/2022
*/

#include "textfile.h"
#include <string>
#include <fstream>
#include <iostream>

Textfile::Textfile(const std::string & _filename): 
    filename (_filename)
{}

size_t Textfile::get_num_of_chars() const
{
    std::ifstream inputfilestream (filename);
    char current_char;
    size_t num_chars = 0;
    if (inputfilestream){ // inputfilestream returns a boolean of true if it can be accessed
        while (inputfilestream.get(current_char)) // continues to increment the character count for as long as chars can still be extracted from the file stream
        {
           
            ++ num_chars;
            
        }
        inputfilestream.close();
    }

    // if the input file stream fails (i.e. the file doesn't exist or can't be opened for some reason), this returns 0 immediately
    
    return num_chars;
}

size_t Textfile::get_num_of_words() const
{
    std::ifstream inputfilestream (filename);
    std::string current_word;
    size_t num_words = 0;
    if (inputfilestream) // inputfilestream returns a boolean of true if it can be accessed
    {
        while (inputfilestream >> current_word) // increments the word count as long as the file stream keeps supplying words
        {
            ++num_words;
        }
        inputfilestream.close();

    }
    
    // if the input file stream fails (i.e. the file doesn't exist or can't be opened for some reason), this returns 0 immediately
    
    return num_words;
}

size_t Textfile::get_num_of_lines() const
{
    std::ifstream inputfilestream (filename);
    std::string current_line;
    size_t num_lines = 0;
    if (inputfilestream) // inputfilestream returns a boolean of true if it can be accessed
    {
        while ( std::getline(inputfilestream,current_line)) // increments the lines count as long as the filestream keeps supplying lines
        {
            ++num_lines;
        }
        inputfilestream.close();

    }
    
    // if the input file stream fails (i.e. the file doesn't exist or can't be opened for some reason), this returns 0 immediately
    
    return num_lines;
}

std::string Textfile::get_file_name() const
{
    return filename; 
}

bool operator<(const Textfile& f1, const Textfile& f2 )
{
    if (f1.get_num_of_lines() <  f2.get_num_of_lines())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator>(const Textfile& f1, const Textfile& f2 )
{
    if (f1.get_num_of_lines() >  f2.get_num_of_lines())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator==(const Textfile& f1, const Textfile& f2 )
{
    if (f1.get_num_of_lines() ==  f2.get_num_of_lines())
    {
        return true;
    }
    else
    {
        return false;
    }
}

