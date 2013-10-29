#ifndef MATH_FRACTION_HPP
#define MATH_FRACTION_HPP

#include <iostream>
#include "global.hpp"

class Fraction;

/**
 *  @brief Extern operators
**/
    std::ostream& operator<<(std::ostream&, const Fraction&);
    Fraction operator+(const Fraction&, const Fraction&);
    Fraction operator*(const Fraction&, const Fraction&);

    bool operator==(const Fraction&, const Fraction&);
    bool operator!=(const Fraction&, const Fraction&);
    bool operator<(const Fraction&, const Fraction&);
    bool operator>(const Fraction&, const Fraction&);
    bool operator<=(const Fraction&, const Fraction&);
    bool operator>=(const Fraction&, const Fraction&);

/**
 *  @class Fraction
**/
    class Fraction final
    {
        typedef int Type;

        public:
            Fraction();         /// @brief Fraction = 0/1
            Fraction(Type num);  /// @brief Fraction = num/1

        /**
         *  @brief Fraction = num/den
         *  @param num
         *  @param den
         *  @pre den != 0
        **/
            Fraction(Type num, Type den);
            ~Fraction(); /// @brief Destructor

            QString toString() const; /// @return "num/den" si den != 1 ; sinon "num"
            double toDouble() const;  /// @return num/den

        /**
         *  @brief Getters
        **/
            int num() const; /// @brief Get the numerator
            int den() const; /// @brief Get the denominator

            void setNum(Type i); /// @brief Set the numerator
            void setDen(Type i); /// @brief Set the denominator

            bool isNeg() const; /// @return true if the fraction is negative


        /**
         *  @brief Operators
        **/
            Fraction& operator+=(const Fraction&);
            Fraction& operator*=(const Fraction&);

        /**
         *  @brief Plus grand commun diviseur
         *  @param i
         *  @param j
        **/
            template<typename T>
                static T pgcd(T i, T j);

        /**
         *  @brief Used by the comparaison operators
        **/
            static int cross1(const Fraction &f1, const Fraction &f2); /// @return f1.numerator * f2.denominator
            static int cross2(const Fraction &f1, const Fraction &f2); /// @return f1.denominator * f2.numerator

        private:

        /**
         *  @brief Rend la fraction irréductible et rend le dénominateur positif
         *         Toute fonction non-const de cette classe doit appeler ensuite cette méthode
         *  @see Fraction::pgcd
        **/
            void simplify();

        private:
            Type numerator;   /// @brief Numerator
            Type denominator; /// @brief Denominator > 0
    };

#include "Fraction.tpp"

#endif // MATH_FRACTION_HPP
