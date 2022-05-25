/*
 PIC 10B Lecture 1, Homework 4
 Purpose: HW4, Complex class cpp file
 Author: Lance Anthony Aquino
 Date: 05/08/2022
*/

#include "Complex.h"
#include <iostream>
#include <cmath>
#include <iomanip>

Complex::Complex():
    a(empty),
    b(empty)
{}

double Complex::get_a() const
{
    return a;
}


double Complex::get_b()const
{
    return b;
}




Complex operator+ (const Complex& compnum1, const Complex& compnum2)
{
    const double new_a = compnum1.get_a() + compnum2.get_a(); // the new a value is the real components added together
    const double new_b = compnum1.get_b() + compnum2.get_b(); // the new b value is the imaginary components added togethher
    return Complex(new_a,new_b);
}

Complex operator- (const Complex& compnum1, const Complex& compnum2)
{
    const double new_a = compnum1.get_a() - compnum2.get_a(); // the new a value is the real component of the second Complex object subtracted from the real component of the first Complex object
    const double new_b = compnum1.get_b() - compnum2.get_b(); // the new b value is the imaginary component of the second Complex object subtracted from the real component of the first Complex object
    return Complex(new_a,new_b);
}

Complex operator* (const Complex& compnum1, const Complex& compnum2)
{
    // imaginary and real value of compnum1
    double a = compnum1.get_a();
    double b = compnum1.get_b();
    
    // imaginary and real value of compnum2
    double c = compnum2.get_a();
    double d = compnum2.get_b();

    // Calculations for the new real and imaginary values of a new Complex number
    double new_a = (a * c) - (b * d);
    double new_b = (b * c) + (a * d);
    return Complex(new_a,new_b);
}

Complex operator/ (const Complex& compnum1, const Complex& compnum2)
{
    // imaginary and real value of compnum1
    double a = compnum1.get_a();
    double b = compnum1.get_b();
    
    // imaginary and real value of compnum2
    double c = compnum2.get_a();
    double d = compnum2.get_b();
    
    // Calculations for the new real and imaginary values of a new Complex number
    double new_a = ((a*c) + (b*d))/(pow(c,2) + pow(d,2));
    double new_b = ((b*c) - (a*d))/(pow(c,2) + pow(d,2));
    return Complex (new_a,new_b);
}


std::ostream& operator<<(std::ostream& output, const Complex& compnum)
{
    // printing the complex number in a + bi formatt
    
    output<< compnum.get_a(); // "a" component printed as normal
    
    // the sign that preceeds b depends on the sign of b
    if (compnum.get_b()>0) // "+" if it's positive
    {
        output<< " +" << compnum.get_b()<<"i";
    }
    else // "-" is printed if b is negaive
    {
        output<< " -" <<abs(-1 * compnum.get_b()) << "i";
    }
    return output;
}
