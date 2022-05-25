/*
 PIC 10B, Homework 3
 Purpose: cpp file for textfile class and other related functions
 Author: Lance Anthony Aquino
 Date: 05/01/2022
*/

#ifndef __TEXTFILE__
#define __TEXTFILE__

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

/**
 @class Textfile just stores the name of a txt file. However, this class contains several members for calculating the number of chars, words, and lines contained in the file
 */
class Textfile{
public:
    
    /**
     Constructor that accepts a string, representing the name of a txt file to be analyzed. 
     
     @param _filename some string that represents the .txt file to be openned
     */
    
    Textfile(const std::string & _filename);
    
    /**
     Calculates the total number of chars in the txt file, including newlines
     
     @return the total number of chars in the txt file denoted by filename
     */
    
    size_t get_num_of_chars() const;
    
    /**
     Calculates the total number of words in the txt file
     
     @return the total number of words in the txt file denoted by filename
     */
    
    size_t get_num_of_words() const;
    
    /**
     Calculates the total number of lines in the txt file
     
     @return the total number of lines in the txt file denoted by filename
     */
    
    size_t get_num_of_lines() const;
    
    /**
     Getter function for the name of the txt file, as stored in filename
     
     @return a string representing the name of a txt file
     */
    std::string get_file_name() const;
    
private:
    
    const std::string filename; // the name of a txt file, including the .txt extension
    
};

/**
 Overloaded operator for '<', which determines if f1 has less lines than f2.
 
 @param f1 the first file to be compared
 @param f2 the second file to be compared
 
 @return true if the txt file for f1 contains less lines than the txt file for f2. Otherwise false
 */

bool operator<(const Textfile& f1, const Textfile& f2 );

/**
 Overloaded operator for '>', which determines if f1 has more lines than f2.
 
 @param f1 the first file to be compared
 @param f2 the second file to be compared
 
 @return true if the txt file for f1 contains more lines than the txt file for f2. Otherwise false
 */

bool operator>(const Textfile& f1, const Textfile& f2 );


/**
 Overloaded operator for '==', which determines if f1 and f2 have the same number of lines
 
 @param f1 the first file to be compared
 @param f2 the second file to be compared
 
 @return true if both files contain the same number of lines, false otherwie
 */
bool operator==(const Textfile& f1, const Textfile& f2 );


#endif /* __TEXTFILE__ */
