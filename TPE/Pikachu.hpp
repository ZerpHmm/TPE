#ifndef PIKACHU_HPP
#define PIKACHU_HPP

#include <vector>
#include "global.hpp"

class PikachuGenerator;

/**
 *  @brief Pikachu
**/
    class Pikachu final
    {
        public:
            Pikachu(const PikachuGenerator&, const Pikachu* const parent = 0);
            ~Pikachu();

            void reproduceMe();

        private:
            const Pikachu* const parent;
            std::vector<Pikachu*> children; /// Deleted in constructor

            const PikachuGenerator* generator;
    };

#endif // PIKACHU_HPP
