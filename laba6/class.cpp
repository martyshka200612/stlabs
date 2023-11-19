#include <iostream>
#include <stdexcept>

#include "class.h"

using namespace std;

ProperFraction::ProperFraction(int numerator, int denominator) : num(numerator), denom(denominator){
    if (denom == 0) {
        throw invalid_argument("Denominator cannot be zero.");
    }
    simplify();
}

void ProperFraction::simplify() {
// Упрощение дроби, если это возможно
    int gcd_1 = gcd(num, denom);
    num /= gcd_1;
    denom /= gcd_1;
    if ((num < 0 && denom > 0) || (num > 0 && denom < 0)) {
        num = -1*abs(num);
        denom = abs(denom);
    } else {
        num= abs(num);
        denom = abs(denom);
    }
}



ProperFraction::ProperFraction (const ProperFraction& fraction) : num(fraction.num), denom(fraction.denom) {}



ProperFraction ProperFraction::operator+ (const ProperFraction& fraction) {
    int newNumerator = num * fraction.denom+ fraction.num * denom;
    int newDenominator = denom * fraction.denom;
    ProperFraction result(newNumerator, newDenominator);
    result.simplify();
    return result;
}


ProperFraction ProperFraction::operator* (const ProperFraction& fraction) {
    int newNumerator = num * fraction.num;
    int newDenominator = denom * fraction.denom;
    ProperFraction result(newNumerator, newDenominator);
    result.simplify();
    return result;
}


ProperFraction ProperFraction::operator/ (const ProperFraction& fraction) {
    int newNumerator = num * fraction.denom;
    int newDenominator = denom * fraction.num;
    ProperFraction result(newNumerator, newDenominator);
    result.simplify();
    return result;
}

void ProperFraction::print() {
    cout << num << "/" << denom;
}
ProperFraction ProperFraction::takecopy(const ProperFraction& copy) {
    num = copy.num;
    denom = copy.denom;
}

int ProperFraction::gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

