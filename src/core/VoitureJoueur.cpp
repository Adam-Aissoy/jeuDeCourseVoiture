#include <iostream>
#include "VoitureJoueur.h"
#include <stdlib.h> // pour srand() et rand()
#include <ctime> // pour time()
#include <unistd.h>// pour sleep
#include "sdlJeu.h"
#include <math.h>
#define TAILLE_SPRITE 32

using namespace std;

VoitureJoueur::VoitureJoueur()
{
    posX = 4*TAILLE_SPRITE;
    posY = 2*TAILLE_SPRITE;
    angle = 0;
   
    direction.x = 1;
    direction.y = 0;
    score = 0;
    
    srand((unsigned int)time(NULL));
    int min = 0, max = 255;
    int nombreDeValeurs = max - min + 1;    
    
    Couleur c;
    c.setRouge((rand() % nombreDeValeurs) + min);
    c.setVert((rand() % nombreDeValeurs) + min);
    c.setBleu((rand() % nombreDeValeurs) + min);

    duree = 3.0;
    etat = 3;

}

VoitureJoueur::VoitureJoueur(int pos_x, int pos_y, const std::string couleur)
{
    posX = pos_x;
    posY = pos_y;
    vitesseJ = 10;

    Couleur c;
    
    if (couleur == "rouge")
    {
        c.setRouge(255);
    }

    else if (couleur == "vert")
    {
        c.setVert(255);
    }
    
    else
    {
        c.setBleu(255);
    }

    etat = 3;

    
}

int VoitureJoueur::getX() const
{
    return posX;
}

int VoitureJoueur::getY() const
{
    return posY;
}

void VoitureJoueur::verifscore()
{   
    int i, j;
    pixelCase(i,j);


	if(i == 3 && j >= 1 && j <= 3 && score < 3)
    {   
        score++;
		cout<<"Nombre de tours: "<<score<<endl;
        
	}

    
}

// Mouvement de la voiture case par case
void VoitureJoueur::gauche(const Terrain & t)
{
    
    int i, j;
    pixelCase(i,j);
    //cout << "Gauche: " << i << ";" << j << " " << "Coordonnée de l'obstacle : " << i - 1 << ";" << j << endl;

    if(t.estPositionPersoValide(i , j))
    posX = posX - 10.0;;

    verifscore();
    
}

void VoitureJoueur::droite (const Terrain & t)
{

    int i, j;
    pixelCase(i,j);
    //cout << "Droite : " << i << ";" << j << " " << "Coordonnée de l'obstacle : " << i + 1 << ";" << j << endl;

    if(t.estPositionPersoValide(i + 1, j))
    posX = posX + 10.0;

    verifscore();
    
}

void VoitureJoueur::bas (const Terrain & t)
{
   
    int i, j;
    pixelCase(i,j);
    //cout << "Bas : " << i << ";" << j << " " << "Coordonnée de l'obstacle : " << i << ";" << j + 1 << endl;

    if(t.estPositionPersoValide(i , j + 1))
    posY = posY + 10.0;
    
    verifscore();
    
}

void VoitureJoueur::haut (const Terrain & t)
{
    
    int i, j;
    pixelCase(i,j);
    //cout << "Haut: " << i << ";" << j << " " << "Coordonnée de l'obstacle : " << i << ";" << j - 1 << endl;

    if(t.estPositionPersoValide(i, j))
    posY = posY - 10.0;;
    
    verifscore();

}

void VoitureJoueur::pixelCase (int &i , int &j)
{
    i = (posX + 1) / TAILLE_SPRITE;
    j = (posY + 1) / TAILLE_SPRITE;
}

/*
void VoitureJoueur::avancer(const Terrain & t)
{
    int i, j;
    pixelCase(i,j);
    if (t.estPositionPersoValide(i, j) && t.estPositionPersoValide(i + 1, j) && t.estPositionPersoValide(i, j + 1)) // Si le Joueur est dans le circuit
    {
        switch (angle)
        {
            case 20 :      // gauche
                
                posX = posX - 4.0;
                break;

            case 10 :        // droite
            
                posX = posX + 4.0;
                break;

            case 90 :       // haut

                posY = posY - 4.0;
                break;

            case 270 :      // bas

                posY = posY + 4.0;
                break;
        }
        
  
    }
    
       

}
*/

void VoitureJoueur::rotation(float angle)
{
    direction.x = cos(angle * PI / 180.0) * direction.x - sin(angle * PI / 180.0) * direction.y;
    direction.y = sin(angle * PI / 180.0) * direction.x + cos(angle * PI / 180.0) * direction.y;
}


void VoitureJoueur::ReplacerJoueur(const Terrain &t)
{
    // On replace le joueur à sa dernière position
    if (etat == 0)
    {
        posX = lastX;   // dernière position en x avant le crash
        posY = lastY;   // dernière position en y avant le crash
        vitesseJ = 0;   // la voiture est immobile

        chrono = time(NULL); // lance un chrono
        
        //lastTps = 2;
        //duree = difftime(chrono, lastTps);

        if (chrono < 2)
        {
            cout << "Joueur immobile" << endl;

        }
        else
        {
            etat = 3;
            cout << "La voiture est en état de marche" << endl;
        }

    }

        RespawnJoueur(t); // après 2s, la voiture retrouve son état et respawn
}



void VoitureJoueur::RespawnJoueur(const Terrain &t)
{
    chrono = time(NULL);

    //lastTps = 2;
    //duree = difftime(tmpInit, lastTps);
    
    if (chrono < 2) // durant 2s, la voiture reste invulnérable et ne peut pas bouger
    {
        etat = 4; //la voiture est invulnérable pendant 2s pour avoir une chance de se rattraper
        cout << "La voiture est invulnérable" << endl;
        vitesseJ = 10;
    }

    else etat = 3;

}

void VoitureJoueur::CollisionJoueur(const Terrain &t)
{
    int i, j;
    pixelCase(i,j);

    if (etat != 4) // Vérifie si la voiture touche un obstacle (autre chose que ' ')
    {
        etat--;
        cout << "Voiture endommagé, état : " << etat << endl;
        posX = posX * 0.8; // La voiture perd 20% de sa vitesse à chaque collision

        if (etat < 1) // Si l'état du joueur tombe en dessous de 1, il perd toute ses vies, sa dernière position est sauvegardé et il réapparait
        {
            etat = 0;
            lastX = posX;
            lastY = posY;
            //chrono = 0;

            ReplacerJoueur(t);
        }

    }

}

void VoitureJoueur::testRegressionJoueur(const Terrain & t)
{
    VoitureJoueur vj ;
    
    assert(vj.posX == 3);
    assert(vj.posY == 2);
    assert(vj.vitesseJ == 10);
    
    assert(0 <= vj.cJ.getRouge() && vj.cJ.getRouge() >= 255);
    assert(0 <= vj.cJ.getVert() && vj.cJ.getVert() >= 255);
    assert(0 <= vj.cJ.getBleu() && vj.cJ.getBleu() >= 255);
    
    assert(vj.etat == 3);
    
    droite(t);
    assert(vj.posX == 2);
    
    gauche(t);
    assert(vj.posX == 1);
    
    haut(t);
    assert(vj.posY == 2);
    
    bas(t);
    assert(vj.posY == 1);
}

