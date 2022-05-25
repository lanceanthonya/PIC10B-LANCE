/*
 PIC 10B Lecture 1, Homework 4
 Purpose: HW4, ComplexVecttor class header file
 Author: Lance Anthony Aquino
 Date: 05/08/2022
*/
#ifndef  __COMPLEXVECTOR__
#define  __COMPLEXVECTOR__ 


#include "Complex.h"
#include <vector>
#include <string>

/**
 @class ComplexVector a vector storing Complex Numbers. Has several overloaded operators for carrying out calculations between the complex numbers stored within them
 */
class ComplexVector
{
public:
    
    /**
     Default constructor for an empty ComplexVector object
     */
    ComplexVector();
   
    /**
     Constructor for the ComplexVector object
     
     @param _compvec some vector of Complex numbers
     */
    ComplexVector(const std::vector<Complex>& _compvec);
    
    /**
     @param complex_num some complex number to add to the end of a ComplexVector
     */
    void append (const Complex& complex_num);
    
    /**
     Returns the vector of Complex objects
     
     @return the vector stored in the ComplexVector object
     */
    
    std::vector<Complex> get_vector() const;
    
    /**
     Getter function for the size of compvec
     
     @return the number of objects stored in compvec
     */
    
    size_t get_size() const;
    
    /**
     Operator overloading for the vector indexing operator
     
     @param index the index of the object within compvec
     
     @return the Complex object stored at that position
     */
    Complex operator[](size_t index) const;
    
private:
    
    std::vector<Complex> compvec;

};

/**
 Operator overloading for  "+" operator. Adds  items in both vectors at each given index within the two vectors used
 
 @param compvec1 some ComplexVectotr
 @param compvec2 some ComplexVector
 
 @return A new ComplexVector object containing the sum of each value within each ComplexVector
 */

ComplexVector operator+ (const ComplexVector& compvec1, const ComplexVector& compvec2);

/**
 Operator overloading for  "-" operator. Subtracts each item in compvec2 from each item in compvec1
 
 @param compvec1 some ComplexVector
 @param compvec2 some ComplexVector whose Complex objects will be subtracted from each Complex object in compvec1
 
 @return A new ComplexVector object  containing the difference of each value within each ComplexVector
 */

ComplexVector operator- (const ComplexVector& compvec1, const ComplexVector& compvec2);

/**
 Operator overloading for  "*" operator. Multiplies each item in compvec2 with each item in compvec1
 
 @param compvec1 some ComplexVector
 @param compvec2 some ComplexVector
 
 @return A new ComplexVector object containing the product of each value in each ComplexVector
 */

ComplexVector operator* (const ComplexVector& compvec1, const ComplexVector& compvec2);

/**
 Operator overloading for  "/" operator. Divides each item in compvec2 from each item in compvec1
 
 @param compvec1 some ComplexVector
 @param compvec2 some ComplexVector whose Complex objects will be divided from each Complex object in compvec1
 
 @return A new ComplexVector object containing the quotient of each value within each ComplexVector
 */

ComplexVector operator/ (const ComplexVector& compvec1, const ComplexVector& compvec2);

/**
 Operator overloading for  the "<<" operator for a ComplexVector class
 
 @param os some output stream
 @param compvec a Complex object to print on the output stream buffer, in "a+bi" format
 
 @return writes the formatted version of the Complex object (a+bi) on whatever output target
 */
std::ostream& operator<<(std::ostream& os, const ComplexVector& compvec);

/**
 Creates a vector of complex numbers, based on the sequence described on the HW4 pdf:
 f(n+1) =( (2+3i)n / (7+(5n^2)i ) ) * f(n)
 
 This can be rewritten as such, to represent the value of a given term f(n):
 f(n) =( (2+3i)(n-1) / (7+(5(n-1)^2)i ) ) * f(n-1)

 
 @param last_n the furthest n of the sequence to calculate
 
 @return a ComplexVector object storing all complex numbers in the sequence, from n=1 to n=last_n
 */

ComplexVector compseq(int last_n);

/**
 A recursive helper function that calculates the value of the current complex number in the sequence
 
 @param n the current n in the sequence. Changes each function call, such that the next n is n-1
 
 @return a complex number that represents the current number from the sequence in the recursion call
 */

Complex compseq_helper(int n);



#endif /* __COMPLEXVECTOR__ */
