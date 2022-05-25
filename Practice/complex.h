/*
PIC 10B, Homework 4
Purpose: Complex Numbers
Author: Isabel Valencia
Date: 05.16.2022
*/

#ifndef complex_h
#define complex_h

class Complex {
    
public:
    double real, imaginary;
    
    Complex ();
    
    Complex (double real, double imaginary);
    
    Complex operator + (Complex const &obj) {
        return Complex(real-obj.real, imaginary-obj.imaginary);
    }
    
    Complex operator - (Complex const &obj) {
        return Complex(real-obj.real, imaginary-obj.imaginary);
    }
    
    Complex operator * (double n) {
        return Complex(real*n, imaginary*n);
    }
    
    Complex operator * (Complex const &obj) {
        double ac = real*obj.real;
        double bd = imaginary*obj.imaginary;
        double bc = imaginary*obj.real;
        double ad = real*obj.imaginary;
        return Complex((ac-bd),(bc+ad));
        
    }
    
    Complex operator / (Complex const &obj) {
        double ac = real*obj.real;
        double bd = imaginary*obj.imaginary;
        double bc = imaginary*obj.real;
        double ad = real*obj.imaginary;
        double denominator = (obj.real*obj.real) + (obj.imaginary*obj.imaginary);
        return Complex((ac-bd)/denominator,(bc+ad)/denominator);
        
    }
    
};





#endif /* complex_h */
