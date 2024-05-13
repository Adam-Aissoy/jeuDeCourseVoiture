#ifndef _COULEUR_
#define _COULEUR_

/**
@brief Module gérant les couleurs des voitures en utilisant 3 composants(R,G,B)
@file Couleur.h
@date 2023/03/07
*/

/**
@brief Module gérant les couleurs des voitures en utilisant 3 composants(R,G,B)
*/
class Couleur {

    private:

        unsigned char r,g,b; // entier dans [0, 255]

    public:
    
    /**
    @brief Constructeur de la classe Couleur, initialise r,g,b a la valeur 0
    */
        Couleur();
        
       /*!
     *  \brief Accesseur :
     *
     * récupère la composante rouge du pixel
     *  
     *  
     */
        unsigned char getRouge();


       /*!
     *  \brief Accesseur :
     *
     * récupère la composante verte du pixel
     *  
     *  
     */
        unsigned char getVert();

       /*!
     *  \brief Accesseur :
     *
     * récupère la composante bleu du pixel
     *  
     *  
     */
        unsigned char getBleu();


       /*!
     *  \brief Mutateur :
     *
     * modifie la composante rouge du pixel
     *  
     *@param nr : valeur rouge a modifier
     */
        void setRouge(const unsigned int nr);

       /*!
     *  \brief Mutateur :
     *
     * modifie la composante verte du pixel
     *
     *@param ng : valeur verte a modifier  
     */
        void setVert(const unsigned int nv);

       /*!
     *  \brief Mutateur :
     *
     * modifie la composante bleu du pixel
     *@param nb : valeur bleu a modifier
     *  
     */
        void setBleu(const unsigned int nb);

};



#endif
