//
// Created by Genady Kogan on 04/08/2024.
//
#include <iostream>
using namespace std;

class Rational {
private:
    int numerator;
    int denominator;

    // Function to calculate GCD
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Function to reduce the fraction
    void reduce() {
        int gcdValue = gcd(numerator, denominator);
        numerator /= gcdValue;
        denominator /= gcdValue;
    }

public:
    // Constructors
    Rational(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (denominator == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        reduce();
    }

    // Operator overloads
    Rational operator*(const Rational& other) const {
        return Rational(numerator * other.numerator, denominator * other.denominator);
    }

    Rational& operator*=(const Rational& other) {
        numerator *= other.numerator;
        denominator *= other.denominator;
        reduce();
        return *this;
    }

    Rational& operator=(const Rational& other) {
        numerator = other.numerator;
        denominator = other.denominator;
        return *this;
    }

    bool operator==(const Rational& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Rational& other) const {
        return !(*this == other);
    }

    // Prefix increment
    Rational& operator++() {
        numerator += denominator;
        return *this;
    }

    // Postfix increment
    Rational operator++(int) {
        Rational temp(*this);
        numerator += denominator;
        return temp;
    }

    // Stream insertion
    friend ostream& operator<<(ostream& out, const Rational& r) {
        out << r.numerator << '/' << r.denominator;
        return out;
    }

    // Stream extraction
    friend istream& operator>>(istream& in, Rational& r) {
        char slash;
        in >> r.numerator >> slash >> r.denominator;
        if (r.denominator == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        r.reduce();
        return in;
    }
};

int main() {
    Rational r1(1, 2);
    Rational r2(3, 4);
    Rational r3 = r1 * r2;
    r1 *= r2;
    cout << r1 << endl;
    cout << (r1 == r2) << endl;
    cout << (r1 != r2) << endl;
    cin >> r1;
    cout << r1 << endl;
    cout << ++r1 << endl;
    cout << r1++ << endl;
    cout << r1 << endl;
    return 0;
}
