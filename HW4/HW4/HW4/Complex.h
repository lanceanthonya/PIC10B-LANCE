/*
 PIC 10B Lecture 1, Homework 4
 Purpose: HW4, Complex class header file
 Author: Lance Anthony Aquino
 Date: 05/08/2022
*/

#ifndef __COMPLEX__
#define __COMPLEX__

#include <iostream>
#include <cmath>
#include <iomanip>

/**
 @class Complex a class representing a complex number, in a+bi format, where a is the real component, b is the imaginary component, and i is the imaginary number
 */
class Complex
{
public:
    /**
     Default Constructor for a Complex variable, which sets the values for a and b as 0
     */
    Complex();
    
    /**
     Constructor for a complex number
     
     @tparam t any numeric type that can be reasonably converted to a double number
     @tparam y any numeric type that can be reasonably converted to a double number. Used in cases where t and y are of different types (in case one is an int and the other is a double)

     
     @param _a the real component of the complex number
     @param _b the imaginary component of the complex number (multiplies by i )
     */
    template <typename t, typename y>
    Complex(const t & _a, const y & _b):
        a(static_cast<double>(_a)),
        b(static_cast<double>(_b))
    {}
    
    /**
     Getter function for the real component of the complex number
     
     @return the a component of the complex number
     */
    double get_a() const;
    
    /**
     Getter function for the imaginary component of the complex number
     
     @return the b component of the complex number
     */
    double get_b()const;
    



private:
    double empty = 0; // case for a and b where the default constructor is used

    double a;
    double b;
};

/**
 Operator overloading for the addition or "+" operator
 
 @param compnum1 first number to add
 @param compnum2 second number to add
 
 @return a new Complex object, with the real and imaginary components of the inputs added
 */

Complex operator+ (const Complex& compnum1, const Complex& compnum2);

/**
 Operator overloading for the subtraction or "-" operator
 
 @param compnum1 first number
 @param compnum2 number to be subtracted from the first number
 
 @return a new Complex object, with the real and imaginary components of the inputs subtracted
 */

Complex operator- (const Complex& compnum1, const Complex& compnum2);

/**
 Operator overloading for the multiplication or "*" operator
 
 @param compnum1 first number to be multiplied
 @param compnum2 second number to be multiplied
 
 @return a new Complex object, that is the product of the inputted complex numbers
 */

Complex operator* (const Complex& compnum1, const Complex& compnum2);

/**
 Operator overloading for the division or "/" operator
 
 @param compnum1 division numerator
 @param compnum2 division denomenator
 
 @return a new Complex object, that is the quotient of the inputted complex numbers
 */

Complex operator/ (const Complex& compnum1, const Complex& compnum2);

/**
 Operator overloading for  the "<<" operator
 
 @param output some output stream
 @param compnum a Complex object to print on the output stream buffer, in "a+bi" format
 
 @return writes the formatted version of the Complex object (a+bi) on whatever output target
 */
std::ostream& operator<<(std::ostream& output, const Complex& compnum);

#endif /* __COMPLEX__ */

