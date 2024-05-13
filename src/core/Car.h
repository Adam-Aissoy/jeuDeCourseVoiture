/**
@brief Module gérant le Jeu
@file Car.h
@date 2023/03/07
*/

#ifndef _CAR_H
#define _CAR_H
#include "VoitureJoueur.h"
#include "VoitureBot.h"
#include "Terrain.h"


class Voiture {
public:
    // Constructeur
    Voiture();        
    // Contucteur avec parametres
    Voiture(float x, float y, float v, float a); 
   ~Voiture();         // Destructeur

    // accesseurs et mutateurs pour les membres de données
    float getPositionX() const;
    void setPositionX(float x);
    float getPositionY() const;
    void setPositionY(float y);
    float getVitesse() const;
    void setVitesse(float v);
    float getAngle() const;
    void setAngle(float a);
    // Fonction pour avancer
    void avancer(const Terrain & terrain); 
    // Fonction pour reculer   
    void reculer(const Terrain & terrain);   
    // la voiture à gauche  
    void tournerGauche(const Terrain & terrain); 
    // la voiture à droite
    void tournerDroite(const Terrain & terrain); 
    // rotation
    void rotation_voiture(float angle);
    // Fonction pour vérifier si la voiture est en collision avec un obstacle
    //bool collision(const Terrain & terrain);


private:
    // Attributs privés de la classe Voiture
    float position_x;
    float position_y;
    float vitesse;
    float angle;
};

#endif // VOITURE_H
