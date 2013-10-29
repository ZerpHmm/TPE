#ifndef MATH_MATH_HPP
#define MATH_MATH_HPP

namespace math
{
    /**
     *  @brief Compare le signe de deux nombres
     *  @param i
     *  @param j
     *  @return true ssi i et j sont de même signe. 0 est de même signe avec tous les nombres
    **/
        template<typename T>
            bool samesign(T i, T j);
}

#include "Math.tpp"

#endif // MATH_MATH_HPP
