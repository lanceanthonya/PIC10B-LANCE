/*
PIC 10B, Homework 4
Purpose: Complex Numbers
Author: Isabel Valencia
Date: 05.16.2022
*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include "complex.h"
#include "complexVector.h"

using namespace std;

ComplexVector::ComplexVector () {
    
}

ComplexVector::ComplexVector (int n) {
    this->n = n;
    obj = (Complex * )malloc(n*sizeof(Complex));
    
}

ComplexVector::ComplexVector (int n, double real[], double imaginary[]) {
    this->n = n;
    obj = (Complex *)malloc(n*sizeof(Complex));
    
    for (int i = 0; i < n; i++) {
        obj[i] = Complex(real[i], imaginary[i]);
        
    }
}

void ComplexVector::set (int i, Complex &v) {
    obj[i] = v;
}

int ComplexVector::len() {
    return n;
    
}


void ComplexVector::printSeq (ComplexVector &vec, Complex first, int n) {
    if (n > 6)
        return;
    
    vec.obj[n-1] = first;
    
    Complex obj1 = Complex (2*n, 3*n);
    Complex obj2 = Complex (7, 5*n*n);
    Complex obj1byobj2 = obj1/obj2;
    Complex next = obj1byobj2*first;
    
    printSeq(vec, next, n+1);
    
}

