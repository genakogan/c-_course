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


class RationalArray {
private:
    int arraySize;
    Rational* array;

public:
    // Constructors
    RationalArray(int size = 0) : arraySize(size), array(new Rational[size]) {}

    RationalArray(const RationalArray& other) : arraySize(other.arraySize), array(new Rational[other.arraySize]) {
        for (int i = 0; i < arraySize; i++) {
            array[i] = other.array[i];
        }
    }

    // Destructor
    ~RationalArray() {
        delete[] array;
    }

    // Operator overloads
    RationalArray operator*(const RationalArray& other) const {
        if (arraySize != other.arraySize) {
            throw invalid_argument("Arrays must be of the same size.");
        }
        RationalArray result(arraySize);
        for (int i = 0; i < arraySize; i++) {
            result.array[i] = array[i] * other.array[i];
        }
        return result;
    }

    RationalArray& operator*=(const RationalArray& other) {
        if (arraySize != other.arraySize) {
            throw invalid_argument("Arrays must be of the same size.");
        }
        for (int i = 0; i < arraySize; i++) {
            array[i] *= other.array[i];
        }
        return *this;
    }

    RationalArray& operator=(const RationalArray& other) {
        if (this != &other) {
            delete[] array;
            arraySize = other.arraySize;
            array = new Rational[arraySize];
            for (int i = 0; i < arraySize; i++) {
                array[i] = other.array[i];
            }
        }
        return *this;
    }

    bool operator==(const RationalArray& other) const {
        if (arraySize != other.arraySize) {
            return false;
        }
        for (int i = 0; i < arraySize; i++) {
            if (array[i] != other.array[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const RationalArray& other) const {
        return !(*this == other);
    }

    // Stream insertion
    friend ostream& operator<<(ostream& out, const RationalArray& arr) {
        for (int i = 0; i < arr.arraySize; i++) {
            out << arr.array[i] << ' ';
        }
        return out;
    }

    // Stream extraction
    friend istream& operator>>(istream& in, RationalArray& arr) {
        for (int i = 0; i < arr.arraySize; i++) {
            in >> arr.array[i];
        }
        return in;
    }

    // Subscript operator
    Rational& operator[](int index) {
        if (index < 0 || index >= arraySize) {
            throw out_of_range("Index out of range.");
        }
        return array[index];
    }

    const Rational& operator[](int index) const {
        if (index < 0 || index >= arraySize) {
            throw out_of_range("Index out of range.");
        }
        return array[index];
    }
};

int main() {
    RationalArray arr1(3);
    RationalArray arr2(3);
    cin >> arr1 >> arr2;
    RationalArray arr3 = arr1 * arr2;
    arr1 *= arr2;
    cout << arr1 << endl;
    cout << (arr1 == arr2) << endl;
    cout << (arr1 != arr2) << endl;
    cout << arr3 << endl;
    cout << arr1[1] << endl;
    arr1[1] = Rational(5, 6);
    cout << arr1[1] << endl;
    return 0;
}
