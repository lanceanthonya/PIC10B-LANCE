/*
 PIC 10B Lecture 1, Homework 4
 Purpose: HW4, main file
 Author: Lance Anthony Aquino
 Date: 05/08/2022
*/

#include <iostream>
#include <vector>
#include "Complex.h"
#include "ComplexVector.h"
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{

    // v1 = { 2 + 4 i, 3 + 5 i, -1 - 3 i , 8 + 10 i }
    // ComplexVector constructed using the regular construtor
    vector<Complex>v1 = {
        Complex(2,4),
        Complex(3,5),
        Complex(-1,-3),
        Complex(8,10)
    };
    ComplexVector cv1(v1);

    // v2 = { -10 + 3.5 i, 4 + 7.3 i, 2 - 8 i, 10 -142 i},
    // ComplexVector default constructed, then the individual values were appended afterwards.
    ComplexVector cv2;
    cv2.append(Complex(-10,3.5));
    cv2.append(Complex(4,7.3));
    cv2.append(Complex(2,-8));
    cv2.append(Complex(10,-142));

    // Rounds the printed output on the conssole for the v1 and v2 to the tenths place and in fixed format (Ex: 100.0 + 20.0)
    cout << fixed<<setprecision(1);
    
    cout << "v1 = ";
    cout << cv1 <<'\n';

    cout << "v2 = ";
    cout << cv2 <<'\n';

    // Mathematical operations between v1 and v2 are calculated and printed
    
    cout << "v1 + v2 = ";
    cout << (cv1+cv2) <<'\n';

    cout << "v1 - v2 = ";
    cout << (cv1-cv2) << '\n';

    cout << "v1 * v2 = ";
    cout << (cv1*cv2)<<'\n';

    cout << "v1 / v2 = ";
    cout << (cv1/cv2)<< '\n';
    
    cout<<"\n\n";
    
    cout<< "Writing Complex Sequence to File";
    
    // Calculating the sequence from the HW4 pdf to the file "ComplexSequence.txt" u
    
    ofstream complex_seq_ofs ("ComplexSequence.txt", ios_base::app );

    if (complex_seq_ofs) // Checks to see if the file stream could successfully be opened.
    {
        complex_seq_ofs<< setprecision(6);
        complex_seq_ofs<<compseq(6);
        cout<< "...Done\n";
    }
    else // Otherwwise, the console prints an error
    {
        cout<< "...Error! File could not be written to\n";
    }
    complex_seq_ofs.close();
    
    return 0;
}
