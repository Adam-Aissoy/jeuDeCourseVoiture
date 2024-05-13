/**
@brief Module gérant la voiture de l'ordinateur
@file VoitureBot.h
@date 2023/03/07
*/

#ifndef _VOITUREBOT_H
#define _VOITUREBOT_H

#include "Terrain.h"
#include "Couleur.h"
#include "VoitureJoueur.h"

/*!
* \brief Module gérant la voiture controllé par l'ordinateur
*
* Ce module créer une voiture controllée par l'ordinateur, elle possède les même carractéristiques qu'une voiture du joueur.
*
*
*
*/
class VoitureBot {

private :

	int VBot_x;
    int VBot_y;
	Couleur CBot;
	float VitBot;
    unsigned char etat; //valeur entre 3 et 0 compris, si 0 la voiture est morte sinon etat est son nombre de vie restante, si etat == 4 
    					//la voiture est invulnérable
	unsigned char  compteur_deplacement ;
	unsigned char score ;

public:
	
   	 /**
	@brief Constructeur de la classe VoitureBot, initialise la vitesse à 20 et la position de la voiture en [4,1], sur la ligne de depart
	*/
    VoitureBot();
	
	/**
	@brief Assesseur de la classe VoitureBot, récuềre la valeur x de la voiture bot
	*/
    int getX () const;

	/**
	@brief Assesseur de la classe VoitureBot, récuềre la valeur y de la voiture bot
	*/
    int getY () const;
	
	 /**
	@brief Déplace la voiture de l'ordinateur à gauche
	*/
    void gauche (const Terrain & t);
    
    	 /**
	@brief Déplace la voiture de l'ordinateur à droite
	*/	
    void droite (const Terrain & t);
    
     	/**
	@brief Déplace la voiture de l'ordinateur à haut
	*/
    void haut (const Terrain & t);
    
    	 /**
	@brief Déplace la voiture de l'ordinateur à bas
	*/
    void bas (const Terrain & t);

	/**
	*\brief procedure qui convertit les coordonnées en pixel de la voiture en case
	*
	* Cette procédure est nécessaire pour vérifier si la voiture peut avancer dans les fonctions de déplacement, elle créer des entiers i et j qui sont la case ou est placé la voiture 
	*/
	void pixelCase (int &i , int &j);

    	/**
	@brief Déplace la voiture automatiquement
	*
	*Pour cela la voiture calcule sa distance avec chaque mur et avance vers la direction ou il y a le plus d'espace. Pour cela on utilise les fonctions loin_de et loin_de_hors 
	*Pour suivre la route on definit des zones, dans chaque zone on a des diretions interdites pour que la voiture ne parte pas a contre sens.
	*/
    void bougeAuto (const Terrain & t);
	
	/**
	@brief Déplace la voiture automatiquement en fonction des murs
	*
	* Déplace la voiture en fonctions des murs, cette procédure est uilisée dans bougeAuto 
	*/
 	void bougeMur (const Terrain & t);

	/**
	@brief Déplace la voiture aléatoirement sans prendre en compte les murs
	*
	* Déplace la voiture dans une des 4 directions aléatoirement, cette procédure permet de changer un peu le trajet du bot pour pimenter la course
	*/
	void bougeAleatoire (const Terrain & t);
 	 /*!
	* \brief Nécessaire pour le déplacement automatique de la voiture bot 
	*
	* Cette fonction permet de calculer à quelle distance des murs est la voiturebot et renvoie le mur le plus loin
	*
	* 1 : Mur Nord, 2 : Mur Est, 3 : Mur Sud, 4 : Mur Ouest
	*/
    int loin_de(const Terrain & t);
    
	 	 /*!
	* \brief Nécessaire pour le déplacement automatique de la voiture bot 
	*
	* Cette fonction permet de calculer à quelle distance des murs est la voiturebot et renvoie le mur le plus loin, en excluant le mur du haut(Nord).
	*
	*/
    int loin_de_hors_N(const Terrain & t);


	 	 /*!
	* \brief Nécessaire pour le déplacement automatique de la voiture bot 
	*
	* Cette fonction permet de calculer à quelle distance des murs est la voiturebot et renvoie le mur le plus loin, en excluant le mur de droite(Est).
	*
	*/
    int loin_de_hors_E(const Terrain & t);

	 	 /*!
	* \brief Nécessaire pour le déplacement automatique de la voiture bot 
	*
	* Cette fonction permet de calculer à quelle distance des murs est la voiturebot et renvoie le mur le plus loin, en excluant le mur du bas(Sud).
	*
	*/
    int loin_de_hors_S(const Terrain & t);

	 	 /*!
	* \brief Nécessaire pour le déplacement automatique de la voiture bot 
	*
	* Cette fonction permet de calculer à quelle distance des murs est la voiturebot et renvoie le mur le plus loin, en excluant le mur de gauche(Ouest).
	*
	*/
    int loin_de_hors_W(const Terrain & t);

	 	 /*!
	* \brief Nécessaire pour le déplacement automatique de la voiture bot 
	*
	* Cette fonction permet de calculer à quelle distance des murs est la voiturebot et renvoie le mur le plus loin, en excluant le mur du haut(Nord) et le mur de droite(Est).
	*
	*/
	int loin_de_hors_N_E(const Terrain & t);

	 	 /*!
	* \brief Nécessaire pour le déplacement automatique de la voiture bot 
	*
	* Cette fonction permet de calculer à quelle distance des murs est la voiturebot et renvoie le mur le plus loin, en excluant le mur du bas(Sud) et le mur de gauche(Ouest).
	*
	*/
	int loin_de_hors_S_W(const Terrain & t);

	/*!
	* \brief Nécessaire pour le déplacement automatique de la voiture bot 
	*
	* Cette fonction permet de calculer à quelle distance des murs est la voiturebot et renvoie le mur le plus loin, en excluant le mur du bas(Sud) et le mur de droit(Est).
	*
	*/
	int loin_de_hors_S_E(const Terrain & t);

	/*!
	* \brief Nécessaire pour le déplacement automatique de la voiture bot 
	*
	* Cette fonction permet de calculer à quelle distance des murs est la voiturebot et renvoie le mur le plus loin, en excluant le mur du haut(Nord) et le mur de gauche(Ouest).
	*
	*/
	int loin_de_hors_N_W(const Terrain & t);


    	 /*!
	* \brief Nécessaire pour le déplacement automatique de la voiture bot 
	* Cette fonction renvoie le plus grand élement entre 4 nombres, elle est utilisée pour comparer les distances des 4 murs avec la fonctions loin_de.
	*/
    int maximum4element(unsigned const int a, unsigned const int b, unsigned const int c, unsigned const int d);

    	 /*!
	* \brief Nécessaire pour le déplacement automatique de la voiture bot 
	*
	* Cette fonction renvoie le plus grand élement entre 3 nombres, elle est utilisée pour comparer les distances des 3 murs avec les fonctions loin_de_hors.
	*/
	int maximum3element(unsigned const int a, unsigned const int b, unsigned const int c);

	/*!
	* \brief Nécessaire pour le déplacement automatique de la voiture bot 
	*
	* Cette fonction renvoie le plus grand élement entre 2 nombres, elle est utilisée pour comparer les distances des 2 murs avec les fonctions loin_de_hors.
	*/
	int maximum2element(unsigned const int a, unsigned const int b);

	/*!
	* \brief Nécessaire pour le déplacement automatique de la voiture bot 
	*
	* Cette fonction renvoie un nombre entre 1 et 8 qui correspond à une ou plusieurs directions interdites pour la voiture bot. Ce qui empeche la voiture bot d'aller dans le mauvais sens du circuit.
	*<br> A savoir :<br>  
					 1 : haut interdit <br> 
					 2 : droite interdit <br> 
					 3 : bas interdit <br> 
					 4 : gauche interdit <br> 
					 5 : droite haut interdit <br> 
					 6 : bas gauche interdit <br> 
					 7 : gauche haut interdit <br> 
					 8 : gauche bas interdit
	*/
	int direction_interdite();

   	 /**
	@brief Déplace la voiture vers un Bonus
	*
	* Cette prodécure n'est pas utilisée car nous n'avons pas pu mettre en place le système de bonus 
	*/
    void bougeBonus (const Terrain & t);
	

	 /*!
	* \brief Replace la voiture de l'ordinateur au centre du circuit
	*
	* Cette procédure permet de replacer la voiture de l'ordinateur au bon endroit après un crash. <br>
	*Cette prodécure n'est pas utilisée car nous n'avons pas pu mettre en place le système de crash
	*/
    void ReplacerVoitureBot(const Terrain & t);
    
    
        	 /*!
	* \brief Re-initialise les valeurs par défaut de la voiture de l'ordinateur après un crash
	*
	* Cette procédure permet de faire réapparaitre la voiture bot après un crash, elle redonne sa vitesse initiale à la voiture(20 unité de vitesse) et son nombre de vie initial(3 vies).<br>
	*Cette prodécure n'est pas utilisée car nous n'avons pas pu mettre en place le système de crash
	*/
    void RespawnVoitureBot(const Terrain & t);
	
	       /*!
     *  \brief Vérifie si la voiture de l'ordinateur se crash
     *
     * Procédure qui permet de vérifier si la voiture à percuté un obstacle, elle utilisera la fonction "PositionValide" à l'avenir. <br>  
     * Si la voiture percute un obstacle elle perd 1 vie et sa vitesse baisse de 20%(cette diminution se cumule après plusieurs crash).<br>
	 * Cette prodécure n'est pas utilisée car nous n'avons pas pu mettre en place le système de crash
     *  
     */
    void CrashVoitureBot(const Terrain & t);

	 /*!
     *  \brief Vérifie le score de la voiture de l'ordinateur
     *
	 * Cette procédure vérifie si la voiture a fait un tour de terrain, si oui elle augmente son score de 1.
	 * <br> Nous n'avons pas eu le temps de terminer cette procédure pour le moment
	 */	
	void verifscore();

     /*!
     *
     * Effectue une série de tests vérifiant que le module fonctionne et
     * que les données membres sont conformes
     *  
     */
    void testRegressionBot (const Terrain &t);
};



/**
@brief Récupère la position en x de la voiture controlé par l'ordinateur
*/
inline int VoitureBot::getX () const { return VBot_x; }

/**
@brief Récupère la position en y de la voiture controlé par l'ordinateur
*/
inline int VoitureBot::getY () const { return VBot_y; }


#endif

//vérifier si la voiture peut avancer dans les fonctions de déplacement, elle créer des entiers i et j qui sont la case ou est placé la voiture 