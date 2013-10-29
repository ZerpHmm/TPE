#include "Fraction.hpp"
#include "Math.hpp"

using namespace std;

//////////////////////
// Extern operators
//////////////////////

    ostream& operator<<(ostream &flux, const Fraction &f)
    {
        flux << f.toString().toStdString();
        return flux;
    }

    Fraction operator+(const Fraction &f1, const Fraction  &f2)
    {
        Fraction result(f1);
        result += f2;
        return result;
    }

    Fraction operator*(const Fraction &f1, const Fraction  &f2)
    {
        Fraction result(f1);
        result *= f2;
        return result;
    }

#define COMPARAISON_OPERATOR(op) \
    bool operator op(const Fraction &f1, const Fraction &f2) { return Fraction::cross1(f1, f2) op Fraction::cross2(f1, f2);}

    COMPARAISON_OPERATOR(==)
    COMPARAISON_OPERATOR(!=)
    COMPARAISON_OPERATOR(>)
    COMPARAISON_OPERATOR(<)
    COMPARAISON_OPERATOR(>=)
    COMPARAISON_OPERATOR(<=)

#undef COMPARAISON_OPERATOR

//////////////////////
// class Fraction
//////////////////////

    Fraction::Fraction() :
        Fraction(0)
    {
    }

    Fraction::Fraction(Type i) :
        Fraction(i, 1)
    {
    }

    Fraction::Fraction(Type i, Type j) :
        numerator(i),
        denominator(j)
    {
        C_PRE(j != 0);
        simplify();
    }

    Fraction::~Fraction() {
        // Nothing to do
    }

    //////////////////////
    // Operators
    //////////////////////

    Fraction& Fraction::operator+=(const Fraction &other)
    {
        numerator = (numerator * other.denominator) + (denominator * other.numerator);
        denominator *= other.denominator;

        simplify();
        return *this;
    }

    Fraction& Fraction::operator*=(const Fraction &other)
    {
        numerator *= other.numerator;
        denominator *= other.denominator;

        simplify();
        return *this;
    }

    //////////////////////
    // Getters
    //////////////////////

    void Fraction::setDen(Type i) {
        C_PRE(i != 0);
        denominator = i;
    }

    void Fraction::setNum(Type i)
    {
        numerator = i;
    }

    //////////////////////
    /// toString
    //////////////////////

    QString Fraction::toString() const
    {
        QString str;
        str.append(QString::number(numerator));

        if(denominator != 1)
        {
            str.append("/").append(QString::number(denominator));
        }

        return str;
    }

    //////////////////////
    /// simplify
    //////////////////////

    void Fraction::simplify()
    {
        const Type i = Fraction::pgcd(num(), den());
        numerator /= i;
        denominator /= i;

        if(math::samesign(num(), den()))
        {
            numerator = std::abs(num());
            denominator = std::abs(den());
        }
        else
        {
            numerator = -(std::abs(num()));
            denominator = std::abs(den());
        }
    }
