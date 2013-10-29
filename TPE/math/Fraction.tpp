#ifndef MATH_FRACTION_TPP
#define MATH_FRACTION_TPP

#include "Fraction.hpp" // For highlight
#include <cmath>

//////////////////////
// class Fraction
//////////////////////

    //////////////////////
    // Inline methods
    //////////////////////

    inline int Fraction::num()  const {
        return numerator;
    }

    inline int Fraction::den() const {
        return denominator;
    }

    inline double Fraction::toDouble() const {
        return static_cast<double>(numerator) / static_cast<double>(denominator);
    }

    inline bool Fraction::isNeg() const {
        return num() < 0;
    }

    inline int Fraction::cross1(const Fraction &f1, const Fraction &f2) {
        return f1.numerator * f2.denominator;
    }

    inline int Fraction::cross2(const Fraction &f1, const Fraction &f2) {
        return f1.denominator * f2.numerator;
    }

    //////////////////////
    // Template methods
    //////////////////////

    template<typename T>
        T Fraction::pgcd(T i, T j)
    {
        return j ? Fraction::pgcd(j, i % j) : i;
    }

#endif // MATH_FRACTION_TPP
