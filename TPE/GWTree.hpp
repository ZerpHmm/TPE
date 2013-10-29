#ifndef GWTREE_HPP
#define GWTREE_HPP

#include <list>
#include "global.hpp"
#include "GWRules.hpp"

class GWEntity;

/**
 *  @brief GWTree
 *
 *      Arbre de Galton-Watson contenant des éléments de type GWEntity
 *      La reproduction de ceux-ci est gouverné par un objet de type GWRules
 *
 *  @see GWEntity
 *  @see GWRules
**/
    class GWTree final
    {
        public:
            GWTree(GWEntity* root);
            ~GWTree();

        /**
         *  @brief Getters
        **/
            void setRules(const GWRules& rules);
            const GWRules& rules() const;
            GWRules& rules();

        /**
         *  @return lastGenID + 1
         *
         *      Parce que cette fonction retourne le nombre total de générations, racine comprise.
         *      Et que gw_root.genID == 0
        **/
            uint generations() const;

        /**
         *  @brief Create a new generation
         *
         *  @post lastGenID is incremented
         */
            void processNextGen();

    private:

        /**
         * @brief Called after processNextGen() to update the list lastGen
         */
            void updateLastGenList();

        private:
            GWEntity *gw_root;
            GWRules gw_rules;
            uint lastGenID; /// Incrémenté de 1 à chaque nouvelle génération

        /**
         * @brief Tableau contenant toutes les GWEntity de la dernière génération.
         *
         *      Evite de devoir rechercher la dernière descendance par <b>gw_root</b>
        **/

            std::list<GWEntity*> lastGen;
    };

#endif // GWTREE_HPP
