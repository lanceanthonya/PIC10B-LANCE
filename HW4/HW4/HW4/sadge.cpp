////
////  sadge.cpp
////  HW4
////
////  Created by Lance Aquino on 5/8/22.
////
//
//#include <iostream>
//#include <vector>
//#include "Complex.h"
//#include "ComplexVector.h"
//#include <iomanip>
//#include <fstream>
//
//using namespace std;
//
//int main()
//{
///**
////Test code for the Complex code
//    Complex c1 = Complex (5,5);
//    Complex c2 = Complex (5,5);
//    
//    cout << setprecision(1);
//    
//    cout<<(c1-c2) <<'\n';
//    
//    cout<<(c1+c2)<<'\n';
//   
//    cout<< (c1*c2)<<'\n';
//   
//    cout<< (c1/c2)<<'\n';
//*/
//     
//    // v1 = { 2 + 4 i, 3 + 5 i, -1 - 3 i , 8 + 10 i }
//    vector<Complex>v1 = {
//        Complex(2,4),
//        Complex(3,5),
//        Complex(-1,-3),
//        Complex(8,10)
//    };
//    ComplexVector cv1(v1);
//
//    // v2 = { -10 + 3.5 i, 4 + 7.3 i, 2 - 8 i, 10 -142 i},
//    ComplexVector cv2;
//    cv2.append(Complex(-10,3.5));
//    cv2.append(Complex(4,7.3));
//    cv2.append(Complex(2,-8));
//    cv2.append(Complex(10,-142));
//
//    cout<< "First 6 numbers of compseq:";
//    cout<<compseq(6);
//    cout<< "\n\n";
//    
//    
//    cout << fixed<< setprecision(1);
//    
//    cout << "v1 = ";
//    cout << cv1 <<'\n';
//
//    cout << "v2 = ";
//    cout << cv2 <<'\n';
//
//    cout << "v1 + v2 = ";
//    cout << (cv1+cv2) <<'\n';
//
//    cout << "v1 - v2 = ";
//    cout << (cv1-cv2) << '\n';
//
//    cout << "v1 * v2 = ";
//    cout << (cv1*cv2)<<'\n';
//
//    cout << "v1 / v2 = ";
//    cout << (cv1/cv2)<< '\n';
//    cout << setprecision(6);
//
//  
//    return 0;
//}
