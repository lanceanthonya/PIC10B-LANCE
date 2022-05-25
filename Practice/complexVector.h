/*
PIC 10B, Homework 4
Purpose: Complex Numbers
Author: Isabel Valencia
Date: 05.16.2022
*/

#ifndef complexVector_h
#define complexVector_h


using namespace std;

class ComplexVector {

public:
    int n;
    
    ComplexVector ();
    
    Complex *obj;
    
    ComplexVector (int n);
    
    ComplexVector (int n, double real[], double imaginary[]);
    
    void set (int i, Complex &v);

    int len();
    
    ComplexVector operator + (ComplexVector const& vec) {
        ComplexVector res = ComplexVector(n);
        
        for (int i = 0; i < n; i++) {
            res.obj[i] = this->obj[i] + vec.obj[i];
            
        }
        
        return res;
        
    }
    
    ComplexVector operator - (ComplexVector const& vec) {
        ComplexVector res = ComplexVector(n);
        
        for (int i = 0; i < n; i++) {
            res.obj[i] = this->obj[i] - vec.obj[i];
            
        }
        
        return res;
        
    }
    
    
    ComplexVector operator * (ComplexVector const& vec) {
        ComplexVector res = ComplexVector(n);
        
        for (int i = 0; i < n; i++) {
            res.obj[i] = this->obj[i] * vec.obj[i];
            
        }
        
        return res;
        
    }
    
    
    ComplexVector operator / (ComplexVector const& vec) {
        ComplexVector res = ComplexVector(n);
        
        for (int i = 0; i < n; i++) {
            res.obj[i] = (this->obj[i])/(vec.obj[i]);
            
        }
        
        return res;
        
    }
    
    
    friend ofstream& operator <<(ofstream &out, const ComplexVector &vec) {
        out << "{";
        
        for (int i = 0; i < vec.n; i++) {
            out << vec.obj[i].real;
            
            if (vec.obj[i].imaginary < 0) {
                out << " - ";
                out << abs(-1*vec.obj[i].imaginary);
                
            }
            
            else {
                out << " + ";
                out << abs(vec.obj[i].imaginary);
                
            }
            
            if (i == vec.n-1)
                out << "i ";
            else
                out << "i, ";
                
        }
        
        out << "}" << endl;
        return out;
        
    }
    
    friend ostream& operator << (ostream &out, const ComplexVector& vec) {
        char str[40];
        out << "{ ";
        
        for (int i = 0; i < vec.n; i++) {
            sprintf(str, "%.1f", vec.obj[i].real);
            out << str;
            
            if (vec.obj[i].imaginary < 0)
                out << " - ";
            
            else
                out << " + ";
            
            sprintf(str, "%.1f", vec.obj[i].imaginary);
            out << str;
            
            if (i == vec.n-1)
                out << "i ";
            
            else
                out << "i, ";
            
        }
        
        out << "}" << endl;
        return out;
        
    }
       
    void printSeq (ComplexVector &vec, Complex first, int n);
    
};



#endif /* complexVector_h */
