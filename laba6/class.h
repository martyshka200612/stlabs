#pragma once
#include <iostream>
using namespace std;

class ProperFraction {
private:
    int num;
    int denom;

    int gcd(int i, int j);

    void simplify();

public:
    ProperFraction(int numerator, int denominator);
    ProperFraction(const ProperFraction& fraction);


    ProperFraction operator+ (const ProperFraction& fraction);

    ProperFraction operator* (const ProperFraction& fraction);

    ProperFraction operator/ (const ProperFraction& fraction);

    ProperFraction takecopy (const ProperFraction& fraction);

    int getNumerator(){
        return num;
    }

    int getDenominator(){
        return denom;
    }

    void print();
};
