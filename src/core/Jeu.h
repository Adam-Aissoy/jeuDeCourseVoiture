/**
@brief Module gérant le Jeu
@file Jeu.h
@date 2023/03/07
*/

#ifndef _JEU_H
#define _JEU_H
#include "VoitureJoueur.h"
#include "VoitureBot.h"
#include "Terrain.h"
#include "Car.h"


/*!
* \brief Module gérant le Jeu
*
* Ce module met en place tout le jeu et met en commun les autres modules
*
*
*
*/
class Jeu {

    private:

        VoitureJoueur vj;
        //VoitureJoueur vj2nd;
        VoitureBot vbot;
		Terrain ter;
        Voiture car;

    public:

        Jeu();
        
        /**
	@brief Accesseur :
	*
	* Necessaire pour l'affichage, recupere le terrain 
	*/
        const Terrain& getConstTerrain () const;
        
        /**
	@brief Accesseur :
	*
	* Necessaire pour l'affichage, recupere la voiture du Joueur 
	*/
        const VoitureJoueur& getConstJoueur() const;
        
        /**
	@brief Accesseur :
	*
	*Necessaire pour l'affichage, recupere la voiture de l'ordinateur
	*/
        const VoitureBot& getConstBot() const;     


        	  /**
	@brief constructeur Car Aysoy
	*
	* Fonction construct car Aysoy
	*/        
        const Voiture& getConstCar() const ;       
        
        /**
	@brief Gere les actions automatiques
	*
	* Fonction qui permet de gerer les actions automatiques non controlle par le Joueur avec des touches (Deplacement de l'ordinateur, apparition de bonus, ...)
	*/        
        void actionsAutomatiques();
        
        /**
	*
	* Fonction qui verifie si une action clavier a eu lieu , renvoie un booleen 
	*/       
        bool actionClavier(const char touche); 
        

		     /*!
     *
     * Effectue une série de tests vérifiant que le module fonctionne et
     * que les données membres sont conformes
     *  
     */
        void testRegression();

};




#endif
