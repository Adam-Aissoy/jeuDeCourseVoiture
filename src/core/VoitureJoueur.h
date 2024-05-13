/**
@brief Module gérant la voiture du joueur
@file VoitureJoueur.h
@date 2023/03/07
*/

#ifndef _VOITUREJ_
#define _VOITUREJ_

#include "Couleur.h"
#include "Terrain.h"
#include <string>
#include <ctime> // pour time()

const double PI = 3.1415926; 


/*!
* \brief Module gérant la voiture controllé par le joueur
*
* Ce module créer une voiture controllée par le joueur. <br> 
* Elle possède une position x et y (posX posY), 
*
*
*
*/
class VoitureJoueur {

    private:


        struct Vec2
        {
            double x;
            double y;
            
        };

        Couleur cJ;
        // UTILISER CLASS VEC OU COMPLEXE
        // Pour que la voiture tourne sur lui même
        // Utiliser vecteur vitesse pour la direction de la voiture
        // Faire en sorte que la voiture tourne sur lui même et pas en orbite autour de l'origine

        double posX, posY; // position de la voiture sur l'écran
        double lastX, lastY; // dernière position de la voiture
        int angle;
        float vitesseJ; // vitesse de la voiture du Joueur
        time_t chrono; // temps initiale 
        time_t lastTps;
        Vec2 direction;
        double duree; // temps écoulé depuis le debut du chrono
        unsigned char etat; //valeur entre 3 et 0 compris, si 0 la voiture est morte 
        //sinon etat est son nombre de vie restante, si etat == 4, la voiture est invulnérable
        unsigned int score ;
    				

    public:

        VoitureJoueur();
        VoitureJoueur(int pos_x, int pos_y, const std::string couleur);

        void avancer(const Terrain & t); // avancer <=> accélérer
        void reculer(const Terrain & t); // reculer <=> freiner

        	 /**
	        @brief Déplace la voiture du joueur à gauche
	        */
        void gauche(const Terrain & t);
                	 /**
	        @brief Déplace la voiture du joueur à droite
	        */
        void droite(const Terrain & t);
                	 /**
	        @brief Déplace la voiture du joueur vers le haut
	        */
        void haut(const Terrain & t);
                	 /**
	        @brief Déplace la voiture du joueur vers le bas
	        */
        void bas(const Terrain & t);

            /**
            @brief Récupère la position en x de la voiture du joueur
            */
        int getX () const;
        
             /**
            @brief Récupère la position en y de la voiture du joueur
            */        
        int getY ()const;
            	
                /**
        	*\brief procedure qui convertit les coordonnées en pixel de la voiture en case
         	*
	        * Cette procédure est nécessaire pour vérifier si la voiture peut avancer dans les fonctions de déplacement, elle créer des entiers i et j qui sont la case ou est placé la voiture 
	        */
        void pixelCase (int &i, int &j);

         /**
        	*\brief procedure fait une rotation de la voiture 
         	*
	        * Cette procédure change la direction de la voiture du joueur en utilisant un angle donnée dans les paramètres 
	        */
        void rotation (float angle);

        	 /*!
	* \brief Replace la voiture du Joueur au centre du circuit
	*
	* Cette procédure permet de replacer la voiture du joueur au bon endroit après un crash. <br>
	*Cette prodécure n'est pas utilisée car nous n'avons pas pu mettre en place le système de crash
	*/
        void ReplacerJoueur(const Terrain &t);

        /**
        	*\brief procedure qui vérifie les collisions du Joueur
         	*
	        * Cette procédure est nécessaire pour vérifier les collisons du joueur et l'empecher de traverser les murs
	        */
        void CollisionJoueur(const Terrain &t);

        /**
        	*\brief fonctions qui vérifie les collisions du Joueur
         	*
	        * Cette procédure est nécessaire pour vérifier les collisons du joueur et l'empecher de traverser les murs, elle renvoie un booléen qui renvoie true si il y a une collision
	        */
        bool CollisionVoiture(const Terrain &t);
        

                	 /*!
	* \brief Re-initialise les valeurs par défaut de la voiture du joueur après un crash
	*
	* Cette procédure permet de faire réapparaitre la voiture bot après un crash, elle redonne sa vitesse initiale à la voiture(20 unité de vitesse) et son nombre de vie initial(3 vies).<br>
	*Cette prodécure n'est pas utilisée car nous n'avons pas pu mettre en place le système de crash
	*/
        void RespawnJoueur(const Terrain &t);


             /*!
     *
     * Effectue une série de tests vérifiant que le module fonctionne et
     * que les données membres sont conformes
     *  
     */
        void testRegressionJoueur(const Terrain & t);
        	
             /*!
     *  \brief Vérifie le score de la voiture du joueur
     *
	 * Cette procédure vérifie si la voiture a fait un tour de terrain, si oui elle augmente son score de 1.  Cette procédure est appelé à chaque déplacement du joueur
	 * <br> Nous n'avons pas eu le temps de terminer cette procédure pour le moment
	 */	
        void verifscore();



};

#endif