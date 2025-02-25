#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;


class RationalXXX
{
//private:
//    int num;    //carries the sign
//    int den;    //non-zero, always positive!
//
//    int mygcd(int a, int b) {
//
//        //Brute force solution
//        a = abs(a);
//        b = abs(b);
//        if (a > b) swap(a, b); //do this to make sure that a <= b
//
//        for (int commonDivisor = a; commonDivisor > 1; commonDivisor--) {
//            if ((a % commonDivisor == 0) && 
//                (b % commonDivisor == 0))
//                return commonDivisor;
//        }
//        return 1;
//    }
//
//    void reduce() {
//        if (den < 0)
//        {
//            num = -num;
//            den = -den;
//        }
//        
//        int commonDivisor = mygcd(num, den);
//        num /= commonDivisor;
//        den /= commonDivisor;
//    }
//
//public:
//    void setNum(int n) { num = n; reduce(); }
//    void setDen(int d) { den = d; reduce(); }
//
//    Rational(int n = 1, int d = 1) {
//        //Naive version - should throw exception
//        if (d == 0) { cout << "Error Zero-div\n"; return; }
//
//        num = n;
//        den = d;
//        reduce();
//    }
//
//    Rational(Rational& other) {
//        num = other.num;
//        den = other.den;
//    }
//
//    string toString() {
//        stringstream sout;
//        sout << this << " Rational [num: " << num << ", den: " << den << "]";
//        return sout.str();
//    }
//
//    Rational operator+ (Rational& other) {
//        num = num * other.den + other.num * den;
//        den = den * other.den;
//        reduce();
//        return *this;
//    }
};

