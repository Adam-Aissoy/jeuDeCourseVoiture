/* Aysoy */ 
#include <cmath>
#include "Car.h"
#include "Terrain.h"
#define TAILLE_SPRITE 32


Voiture::Voiture() {
    position_x = 4.0f*TAILLE_SPRITE;
    position_y = 2.0f*TAILLE_SPRITE;
    vitesse=1.0f;
    angle = 0.0f;
}

// Constructeur avec paramètres
Voiture::Voiture(float x, float y, float v, float a) {
    position_x = x; 
    position_y = y;
    vitesse = v;
    angle = a;
}

Voiture::~Voiture() {
    // rien à faire dans le destructeur pour le moment
}

// here Aysoy 
// Accesseurs et mutateurs pour les membres de données
float Voiture::getPositionX() const {
    return position_x;
}

void Voiture::setPositionX(float x) {
    position_x = x;
}

float Voiture::getPositionY() const {
    return position_y;
}

void Voiture::setPositionY(float y) {
    position_y = y;
}

float Voiture::getVitesse() const {
    return vitesse;
}

void Voiture::setVitesse(float v) {
    vitesse = v;
}

float Voiture::getAngle() const {
    return angle;
}

void Voiture::setAngle(float a) {
    angle = a;
}

// Méthodes pour faire avancer ou reculer la voiture

void Voiture::avancer(const Terrain & terrain) {
    position_x += vitesse * cos(angle);
    position_y += vitesse * sin(angle);

    // vérifier si la voiture est sortie de la piste
    if (terrain.estPositionPersoValide(position_x, position_y)) {
        // corriger la position de la voiture
        position_x -= vitesse * cos(angle);
        position_y -= vitesse * sin(angle);
    }
}


void Voiture::reculer(const Terrain & terrain) {
    position_x -= vitesse * cos(angle);
    position_y -= vitesse * sin(angle);

    // vérifier si la voiture est sortie de la piste
    if (terrain.estPositionPersoValide(position_x, position_y)) {
        // corriger la position de la voiture
        position_x += vitesse * cos(angle);
        position_y += vitesse * sin(angle);
    }
}

// Méthodes pour faire tourner la voiture à gauche ou à droite
void Voiture::tournerGauche(const Terrain & terrain) {
    angle -= 0.1f;  // changer l'angle de 0.1 radians vers la gauche

    // vérifier si la voiture est sortie de la piste
    if (terrain.estPositionPersoValide(position_x, position_y)) {
        // corriger l'angle de la voiture
        angle += 0.1f;
    }
}

void Voiture::tournerDroite(const Terrain & terrain) {
    angle += 0.1f;  // changer l'angle de 0.1 radians vers la droite

    // vérifier si la voiture est sortie de la piste
    if (terrain.estPositionPersoValide(position_x, position_y)) {
        // corriger l'angle de la voiture
        angle -= 0.1f;
    }
}
// rotation
void Voiture::rotation_voiture(float angle) {
    this->angle += angle; // Ajout de l'angle à l'angle existant
}
// collision Aysoy

/*
bool Voiture::collision(const Terrain &terrain) {
    // Vérifier si la voiture est en collision avec le bord gauche du terrain
    if (position_x - LARGEUR_VOITURE / 2 < 0) {
        return true;
    }

    // Vérifier si la voiture est en collision avec le bord droit du terrain
    if (position_x + LARGEUR_VOITURE / 2 > terrain.getLargeur()) {
        return true;
    }

    // Vérifier si la voiture est en collision avec le bord supérieur du terrain
    if (position_y - HAUTEUR_VOITURE / 2 < 0) {
        return true;
    }

    // Vérifier si la voiture est en collision avec le bord inférieur du terrain
    if (position_y + HAUTEUR_VOITURE / 2 > terrain.getHauteur()) {
        return true;
    }

    // Vérifier si la voiture est en collision avec un obstacle du terrain
    for (const Obstacle &obstacle : terrain.getObstacles()) {
        if (position_x + LARGEUR_VOITURE / 2 > obstacle.getPositionX() - obstacle.getLargeur() / 2 &&
            position_x - LARGEUR_VOITURE / 2 < obstacle.getPositionX() + obstacle.getLargeur() / 2 &&
            position_y + HAUTEUR_VOITURE / 2 > obstacle.getPositionY() - obstacle.getHauteur() / 2 &&
            position_y - HAUTEUR_VOITURE / 2 < obstacle.getPositionY() + obstacle.getHauteur() / 2) {
            return true;
        }
    }

    // Si la voiture n'est en collision avec aucun obstacle, retourner false
    return false;
}

*/
