/*
 PIC 10B Lecture 1, Homework 4
 Purpose: HW4, ComplexVector class cpp file
 Author: Lance Anthony Aquino
 Date: 05/08/2022
*/

#include "ComplexVector.h"
#include "Complex.h"
#include <vector>
#include <iostream>

ComplexVector::ComplexVector():
    compvec(std::vector<Complex>())
{}

ComplexVector::ComplexVector(const std::vector<Complex>& _compvec):
    compvec(_compvec)
{}

void ComplexVector::append (const Complex& complex_num)
{
    compvec.push_back(complex_num); // calls the existing push_back method for the vector
}

size_t ComplexVector::get_size() const
{
    return compvec.size();
}

std::vector<Complex> ComplexVector::get_vector() const
{
    return compvec;
}

Complex ComplexVector::operator[](size_t index) const
{
    return compvec[index];
}

ComplexVector operator+ (const ComplexVector& compvec1, const ComplexVector& compvec2)
{
    size_t final_index = compvec1.get_size() -1;
    ComplexVector new_vec; // a new vector containing the newly calculate complex numbers is generated

    for (size_t current_index = 0; current_index <= final_index; ++ current_index)
    {
        new_vec.append (compvec1[current_index] + compvec2[current_index]); // carries out the overloaded addition operator between the two complex numbers in the two vectors
    }
    return new_vec;
}

ComplexVector operator- (const ComplexVector& compvec1, const ComplexVector& compvec2)
{
    size_t final_index = compvec1.get_size() -1;
    ComplexVector new_vec; // a new vector containing the newly calculate complex numbers is generated
    
    for (size_t current_index = 0; current_index <= final_index; ++ current_index)
    {
        new_vec.append (compvec1[current_index] - compvec2[current_index]); // carries out the overloaded subtraction operator between the two complex numbers in the two vectors
    }
    return new_vec;
}
ComplexVector operator* (const ComplexVector& compvec1, const ComplexVector& compvec2)
{
    size_t final_index = compvec1.get_size() -1;
    ComplexVector new_vec; // a new vector containing the newly calculate complex numbers is generated
    
    for (size_t current_index = 0; current_index <= final_index; ++ current_index)
    {
        new_vec.append (compvec1[current_index] * compvec2[current_index]); // carries out the overloaded multiplication operator between the two complex numbers in the two vectors
    }
    return new_vec;
}
ComplexVector operator/ (const ComplexVector& compvec1, const ComplexVector& compvec2)
{
    size_t final_index = compvec1.get_size() -1;
    ComplexVector new_vec; // a new vector containing the newly calculate complex numbers is generated

    for (size_t current_index = 0; current_index <= final_index; ++ current_index)
    {
        new_vec.append (compvec1[current_index] / compvec2[current_index]); // carries out the overloaded division operator between the two complex numbers in the two vectors
    }
    return new_vec;
}

std::ostream& operator<<(std::ostream& os, const ComplexVector & compvec)
{
    os << "{ ";
    size_t last_index = compvec.get_size() - 1 ;
    for (size_t current_index = 0; current_index<=last_index; ++ current_index)
    {
        os <<compvec[current_index];
        if (current_index == last_index)
        {
            os << " "; // for the last item in the vector, only prints a space instead of another comma
            break;
        }
        os << " , "; // prints commas only between complex numberss
    }
    os << "}";
    return os;
}

ComplexVector compseq(int last_n)
{
    ComplexVector compvec; // creates an empty ComplexVector storing the sequence, that can be printed later
    
    for (int cur_n = 1; cur_n <= last_n ; ++ cur_n) // starts at n=1, ends at n=last_n
    {
        compvec.append(compseq_helper(cur_n)); // calculates and appends the current complex number in the sequence to the end of the vector
    }
    return compvec;
}

Complex compseq_helper(int n)
{
    if (n == 1) // represents the first complex number in the sequence.
    {
        return Complex (1,1); // correspnds to (1+i). This marks the end of the recursion loops
    }

    // Represents the "( (2+3i)n / (7+(5n^2)i ) )" term in the sequence.
    // Note: The reason 1 is subtracted from the n's because at a given f(n), the term above is based on the previous n, or n-1
    
    int previous_n = n-1;
    
    Complex numer = Complex (previous_n * 2,previous_n* 3);
    Complex denom (7,5*pow(previous_n,2));
    Complex comp = numer/denom;
    
    // Represents the multiplication of the above term by the previous f(n), or: f(n) =( (2+3i)(n-1) / (7+(5(n-1)^2)i ) ) * f(n-1)
    // This calls the function again, but with the previous n in the sequence (n-1), until reaching n=1.
    // Once it reaches n=1, all values of the sequence from n=1 to the n at the first function call will be multiplied by each other to get the current number in the complex number sequence
    
    return comp * compseq_helper(--n);
    
}
