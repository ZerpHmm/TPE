#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <cstdlib>
#include <iostream>
#include <QtGlobal>
#include <QDebug>

/**
 *  @brief Macros
**/
    #define ASSERT(cond)                Q_ASSERT(cond)
    #define FATAL()                     Q_ASSERT_X(false, "fatal error", "No description...")
    #define FATALX(what)                Q_ASSERT_X(false, "fatal error", what)

/**
 *  @brief Contracts: preconditions & postconditions
**/
    #define C_PRE(cond)                 Q_ASSERT_X(cond, "precondition", #cond)
    #define C_POST(cond)                Q_ASSERT_X(cond, "postcondition", #cond)
    #define C_PREX(cond, what)          Q_ASSERT_X(cond, "precondition " #cond, what)
    #define C_POSTX(cond, what)         Q_ASSERT_X(cond, "postcondition " #cond, what)

//////////////////////

    double drand(); /// @return Random double in [0 ; 1[

    template<typename T, typename... B> void debug(const T&, const B&...); /// @brief Sortie standard sans passer par std::cout
    void debug();

/**
 *  @namespace tpe
 *  @see Example.cpp
**/
    namespace tpe
    {
        void example1();
    }

//////////////////////
// Inline functions
//////////////////////

    inline double drand() {
        return qrand() / static_cast<double>(RAND_MAX);
    }

    inline void debug() {
        std::cout << std::endl;
    }

//////////////////////
// Template functions
//////////////////////

    template<typename T, typename... B>
        void debug(const T &t, const B&... b)
    {
        std::cout << t;
        debug(b...);
    }

#endif // GLOBAL_HPP
