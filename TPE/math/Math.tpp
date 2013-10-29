#ifndef MATH_MATH_TPP
#define MATH_MATH_TPP

#include "Math.hpp"

//////////////////////
// namespace math
//////////////////////

namespace math
{
    //////////////////////
    // Template functions
    //////////////////////

        /////////////////////////////
        // Inline template functions
        /////////////////////////////

            template<typename T>
                inline bool samesign(T i, T j)
            {
                return i >= 0 ?
                        j >= 0 :
                        j <= 0;
            }
}

#endif // MATH_MATH_TPP
