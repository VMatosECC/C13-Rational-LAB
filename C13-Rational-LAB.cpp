#include <iostream>
#include <string>
#include <cmath>   // For abs
using namespace std;


class Rational {
private:
    int numerator;
    int denominator;


    void reduce() {
        int common = gcd(numerator, denominator); 
        if (common != 0) { // Avoid division by zero if gcd is 0
            numerator /= common;
            denominator /= common;
        }

        // Ensure denominator is positive - if not, flip signs
        if (denominator < 0) { 
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Naive Version. Greatest Common Divisor (GCD) function 
    // not the best implementation, but it works for now.
    static int gcd(int a, int b) {

        //Brute force solution
        a = abs(a);
        b = abs(b);
        if (a > b) swap(a, b); //do this to make sure that a <= b

        for (int commonDivisor = a; commonDivisor > 1; commonDivisor--) {
            if ((a % commonDivisor == 0) &&
                (b % commonDivisor == 0))
                return commonDivisor;
        }
        return 1;
    }



    // Condensed Constructor
    Rational(int num = 1, int den = 1) {
        numerator = num;
        setDenominator(den);
    }

    // Copy Constructor
    Rational(const Rational& other) : numerator(other.numerator), 
        denominator(other.denominator) {}

    // Setters
    void setNumerator(int num) { numerator = num; reduce(); }

    void setDenominator(int den) {
        if (den == 0) {
            cout << "Error: Denominator cannot be zero. Setting to 1." << endl;
            denominator = 1;
        }
        else {
            denominator = den;
            reduce();
        }
    }

    // Getters
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    // toString()
    string toString() const {
        return to_string(numerator) + "/" + to_string(denominator);
    }


    // Add
    Rational add(const Rational& other) const {
        int newNum = numerator * other.denominator + other.numerator * denominator;
        int newDen = denominator * other.denominator;
        return Rational(newNum, newDen); // Reduce will be called in the constructor
    }

    // Subtract
    Rational subtract(const Rational& other) const {
        int newNum = numerator * other.denominator - other.numerator * denominator;
        int newDen = denominator * other.denominator;
        return Rational(newNum, newDen); // Reduce will be called in the constructor
    }

    // TODO: Multiply, Divide, <, >, ==, !=, <=, >=, ++, --, +=, -=, *=, /=
    
    //// Overload the + operator
    //Rational operator+(const Rational& other) const {
    //    return add(other);
    //}

    // Overload the + operator
    Rational operator+(const Rational& other) const {
        int newNum = this->numerator * other.denominator + other.numerator * this->denominator;
        int newDen = this->denominator * other.denominator;
        return Rational(newNum, newDen); // Reduce will be called in the constructor
    }

    // Overload the - operator
    Rational operator-(const Rational& other) const {
        return subtract(other);
    }

    friend ostream& operator<<(ostream& sout, const Rational& r) {
        sout << r.toString();
        return sout;
    }

    // Prefix ++
    Rational& operator++() { 
        numerator += denominator;
        reduce();
        return *this;
    }

    // Postfix ++
    Rational operator++(int) { 
        Rational temp = *this;
        ++(*this);
        return temp;
    }

    // Prefix --
    Rational& operator--() { 
        numerator -= denominator;
        reduce();
        return *this;
    }

    // Postfix --
    Rational operator--(int) { 
        Rational temp = *this;
        --(*this);
        return temp;
    }

    // Operator less than
    bool operator<(const Rational& other) const {
        return (numerator * other.denominator) < (other.numerator * denominator);
    }

    //Operator == (compare)
    bool operator==(const Rational& other) const {
        return (numerator == other.numerator) && (denominator == other.denominator);
    }

    //Operator +=
    Rational& operator+=(const Rational& other) {
        numerator = numerator * other.denominator + other.numerator * denominator;
        denominator *= other.denominator;
        reduce();
        return *this;
    }

};


int main() {
    Rational r1(3, 4);
    Rational r2;

    cout << "r1: " << r1.toString() << endl; // Output: r1: 3/4
    cout << "r2: " << r2.toString() << endl; // Output: r2: 1/1

    r2.setNumerator(1);
    r2.setDenominator(2);
    cout << "r2: " << r2.toString() << endl; // Output: r2: 1/2


    Rational sum = r1.add(r2);
    cout << "sum: " << sum.toString() << endl;   // Output: sum: 5/4

    Rational diff = r1.subtract(r2);
    cout << "diff: " << diff.toString() << endl; // Output: diff: 1/4

    Rational r3(-2, 3);
    cout << "r3: " << r3.toString() << endl; // Output: r3: -2/3

    Rational r4(40, -60);
    cout << "r4: " << r4.toString() << endl; // Output: r4: -2/3

    Rational r5(r4);
    cout << "r5: " << r5.toString() << endl; // Output: r5: -2/3

    cout << "GCD of 40 and 60: " << Rational::gcd(40, 60) << endl; // Output: 20

    r5.setDenominator(0); // Output: Error: Denominator cannot be zero. Setting to 1.
    cout << "r5: " << r5.toString() << endl; // Output: r5: -2/1

    r4.setDenominator(-10);
    cout << "r4: " << r4.toString() << endl; // Output: r4: 1/5

    //Test operator overloading
    Rational r6 = r1 + r2;
    cout << "r6: " << r6.toString() << endl; // Output: r6: 5/4

    Rational r7 = r1 - r2;
    cout << "r7: " << r7.toString() << endl; // Output: r7: 1/4

    cout << "r1: " << r1 << endl; // Output: r1: 3/4    
    cout << "r2: " << r2 << endl; // Output: r2: 1/2

    //TODO - Add more tests for the remaining operators

    return 0;
}

