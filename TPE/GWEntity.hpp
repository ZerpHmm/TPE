#ifndef GWENTITY_HPP
#define GWENTITY_HPP

#include "global.hpp"

class GWRules;

/**
 *  @class GWEntity
 *
 *      Element d'un arbre de Galton-Watson
 *
 *  @see GWTree
**/
    class GWEntity
    {
        public:
            GWEntity(); /// @brief generation = 0
            ~GWEntity(); /// @brief Destructor

        /**
         * @brief getGenID
         * @return 
         */
            uint getGenID() const; /// @return genID

        /**
         *  @return gw_children
        **/
            const std::vector<GWEntity*>& children() const;
            std::vector<GWEntity*>& children();

        /**
         *  @return gw_children.size()
        **/

            uint nbchildren() const;

        /**
         * @param i Initialise le generation ID
         *
         *      Appelé par GWRules::processNextGen
         *
         *  @see GWRules::processNextGen
         */
            void setGenID(uint i);

        /**
         *  @brief Rempli gw_children
         *
         *      Appelé par GWTree::processNextGen
         *
         *      Si gw_children n'était pas vide (cette fonction aurait donc déjà été appelée),
         *      gw_children est vidé avant le processus
         *
         *  @param generation   ID de la génération
         *  @param GWRules      Règles de probabilité de reproduction
         *  @return nbchildren()
         *
         *  @see GWTree::processNextGen
         *  @see GWRules
        **/
            uint processReproduction(const GWRules&);

            void killChildren();

        private:
            uint genID;
            std::vector<GWEntity*> gw_children; /// Deleted in destructor
    };

#endif // GWENTITY_HPP
