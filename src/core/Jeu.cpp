#include <iostream>
#include "Jeu.h"
#include "VoitureJoueur.h"
#include "VoitureBot.h"
#include "Car.h"
using namespace std;


Jeu::Jeu() : vj(), vbot() ,ter(),car()//, vj2nd()
{
    //Besoin du module Terrain 
	//ter.recupBonus(vj.getX(), vj.getY());
	//ter.toucheObs(vj.getX(), vj.getY());
	//ter.mangePastille(car.getPositionX(),car.getPositionY());
    
}

const Terrain& Jeu::getConstTerrain () const 
{ 
	return ter; 
}   

const VoitureJoueur& Jeu::getConstJoueur() const
{
    return vj;// vj2nd;  

}

const VoitureBot& Jeu::getConstBot() const
{
    return vbot;
}

// constructeur car Aysoy in jeu.cpp
const Voiture& Jeu::getConstCar() const
{
    return car;
}

// Need module VoitureBot 
void Jeu::actionsAutomatiques() 
{
    vbot.bougeAuto(ter);
}

//Besoin du module Terrain
bool Jeu::actionClavier (const char touche) {
	switch(touche) {
		case 'g' :
				vj.gauche(ter);
				break;
		case 'd' :
				vj.droite(ter);
				break;
		case 'b' :
				vj.haut(ter);
				break;
		case 'h' :
				vj.bas(ter);
				break;
		case 'e' :
				car.avancer(ter);
				break;
		case 's' :
				car.tournerGauche(ter);
				break;
		case 'f' :
				car.tournerDroite(ter);
				break;
		case 'x':
				car.reculer(ter);
				break;
		// vj2nd 
		/*
		case 'q' :
				vj2nd.gauche(ter);
				break;
		case 'f' :
				vj2nd.droite(ter);
				break;
		case 'z' :
				vj2nd.haut(ter);
				break;
		case 's' :
				vj2nd.bas(ter);
				break;
		*/
		/*			
		case 'r' :
				vj.avancer(ter);
				break;
		
		case '8' :
				vj.reculer(ter);
				break;
		*/
	}
	
	/*
	if (ter.getXY(vj.getX(),vj.getY())=='.') 
	{
	    ter.recupBonus(vj.getX(),vj.getY());
        return true;
	}
	*/
	return false;
}

void Jeu::testRegression (){
	vbot.testRegressionBot(ter);
	vj.testRegressionJoueur(ter);
}



