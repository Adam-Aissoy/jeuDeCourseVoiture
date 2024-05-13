#include "VoitureBot.h"

#include <stdlib.h>
#include <iostream> 
#include <stdlib.h> // pour srand() et rand()
#include <time.h> // pour time()
#include <unistd.h>// pour sleep

#define TAILLE_SPRITE 32

using namespace std ;


VoitureBot :: VoitureBot () : VitBot(20) {
VBot_x = 4*TAILLE_SPRITE;
VBot_y = 1*TAILLE_SPRITE;

etat = 3;
compteur_deplacement = 0 ;

score = 0 ;
}

void VoitureBot::gauche(const Terrain & t)
{
    int i, j;
    pixelCase(i,j);

    if(t.estPositionPersoValide(i -1, j)){
    VBot_x = VBot_x - VitBot;
	}
}

void VoitureBot::droite (const Terrain & t)
{
    int i, j;
    pixelCase(i,j);

    if(t.estPositionPersoValide(i + 1, j)){
    VBot_x = VBot_x + VitBot;
	}
}

void VoitureBot::bas (const Terrain & t)
{
    int i, j;
    pixelCase(i,j);

    if(t.estPositionPersoValide(i , j + 1)){
    VBot_y = VBot_y + VitBot;
	}  
}

void VoitureBot::haut (const Terrain & t)
{
    int i, j;
    pixelCase(i,j);

    if(t.estPositionPersoValide(i, j)){
    VBot_y = VBot_y - VitBot;;
	}
}

void VoitureBot::pixelCase (int &i , int &j)
{
    i = (VBot_x + 1) / TAILLE_SPRITE;
    j = (VBot_y + 1) / TAILLE_SPRITE;
}


void VoitureBot :: ReplacerVoitureBot(const Terrain & t){
	//(à rajouter)
}

void VoitureBot :: RespawnVoitureBot(const Terrain & t){
	VitBot = 0;
	etat = 4;//la voiture est invulnérable
	ReplacerVoitureBot(t)  ;
	
	//attendre 3 seconde avant que le bot puisse bouger(a rajouter)
	
	etat = 3; // la voiture n'est plus invulnérable
	VitBot = 10;	
}


void VoitureBot :: CrashVoitureBot(const Terrain & t){
	if(t.estPositionPersoValide(VBot_x, VBot_y)==false){
		if(etat == 4){
		cout <<"voiture bot invulnérable";
		}
		else{		
			if(etat>0 && etat <4){
				VitBot = VitBot * 0.8 ;
				etat -- ;
			}
			else {
				RespawnVoitureBot(t);
			}
		}
	}
}

int VoitureBot :: maximum4element(unsigned const int a, unsigned const int b, unsigned const int c, unsigned const int d){
	unsigned int max ;
	if(a>=b){
	max = a ;
	}
	else{
		max = b ;
	}
	
	if(c>=max){
	max = c ;
	}
	
	if(d>=max){
	max = d ;
	}
	
	return max ;
}

int VoitureBot :: maximum3element(unsigned const int a, unsigned const int b, unsigned const int c){
	unsigned int max ;
	if(a>=b){
	max = a ;
	}
	else{
		max = b ;
	}
	
	if(c>=max){
	max = c ;
	}
	
	return max ;
}

int VoitureBot :: maximum2element(unsigned const int a, unsigned const int b){
	unsigned int max ;
	if(a>=b){
	max = a ;
	}
	else{
		max = b ;
	}
	
	return max ;
}


int VoitureBot :: loin_de(const Terrain & t){
	int N = 0 ;
	int E = 0 ;
	int W = 0 ;
	int S = 0 ;
	
	int loin = 0;
	
	while(t.estPositionPersoValide(VBot_x/TAILLE_SPRITE,VBot_y/TAILLE_SPRITE - N)){
	N++;
	}
	
	while(t.estPositionPersoValide(VBot_x/TAILLE_SPRITE,VBot_y/TAILLE_SPRITE + S)){
	S++;
	}
	
	while(t.estPositionPersoValide(VBot_x/TAILLE_SPRITE + E, VBot_y/TAILLE_SPRITE)){
	E++;
	}
	
	while(t.estPositionPersoValide(VBot_x/TAILLE_SPRITE - W, VBot_y/TAILLE_SPRITE)){
	W++;
	}
	
	loin = maximum4element(N,S,E,W);
	
	if(loin == N){
		return 1 ; //Nord 
		
		}else {
			if(loin == E){
				return 2 ; //Est 
	
				}else {
					if(loin == S){
						return 3 ; //Sud
						
						}else {					
							if(loin == W){
								return 4 ; // Ouest
								}else{
									return 0; //erreur
								}
								
						}
				}
		}
}

int VoitureBot :: loin_de_hors_N(const Terrain & t){
	int E = 0 ;
	int W = 0 ;
	int S = 0 ;
	
	int loin = 0;
	
	while(t.estPositionPersoValide(VBot_x/TAILLE_SPRITE,VBot_y/TAILLE_SPRITE + S)){
	S++;
	}
	
	while(t.estPositionPersoValide(VBot_x/TAILLE_SPRITE + E, VBot_y/TAILLE_SPRITE)){
	E++;
	}
	
	while(t.estPositionPersoValide(VBot_x/TAILLE_SPRITE - W, VBot_y/TAILLE_SPRITE)){
	W++;
	}
	
	loin = maximum3element(S,E,W);

			if(loin == E){
				return 2 ; //Est 
	
				}else {
					if(loin == S){
						return 3 ; //Sud
						
						}else {					
							if(loin == W){
								return 4 ; // Ouest
								}else{
									return 0; //erreur
							}
								
					}
			}
}

int VoitureBot :: loin_de_hors_S(const Terrain & t){
	int N = 0 ;
	int E = 0 ;
	int W = 0 ;
	
	int loin = 0;
	
	while(t.estPositionPersoValide(VBot_x/TAILLE_SPRITE,VBot_y/TAILLE_SPRITE - N)){
	N++;
	}
	
	while(t.estPositionPersoValide(VBot_x/TAILLE_SPRITE + E, VBot_y/TAILLE_SPRITE)){
	E++;
	}
	
	while(t.estPositionPersoValide(VBot_x/TAILLE_SPRITE - W, VBot_y/TAILLE_SPRITE)){
	W++;
	}
	
	loin = maximum3element(N,E,W);
	
	if(loin == N){
		return 1 ; //Nord 
		
		}else {
			if(loin == E){
				return 2 ; //Est 
	
				}else {				
							if(loin == W){
								return 4 ; // Ouest
								}else{
									return 0; //erreur
							}
								
				}
		}
}

int VoitureBot :: loin_de_hors_E(const Terrain & t){
	int N = 0 ;
	int W = 0 ;
	int S = 0 ;
	
	int loin = 0;
	
	while(t.estPositionPersoValide(VBot_x/TAILLE_SPRITE,VBot_y/TAILLE_SPRITE - N)){
	N++;
	}
	
	while(t.estPositionPersoValide(VBot_x/TAILLE_SPRITE,VBot_y/TAILLE_SPRITE + S)){
	S++;
	}
	
	while(t.estPositionPersoValide(VBot_x/TAILLE_SPRITE - W, VBot_y/TAILLE_SPRITE)){
	W++;
	}
	
	loin = maximum3element(N,S,W);
	
	if(loin == N){
		return 1 ; //Nord 
		
		}else {
					if(loin == S){
						return 3 ; //Sud
						
						}else {					
							if(loin == W){
								return 4 ; // Ouest
								}else{
									return 0; //erreur
							}
								
					}
		}
}

int VoitureBot :: loin_de_hors_W(const Terrain & t){
	int N = 0 ;
	int E = 0 ;
	int S = 0 ;
	
	int loin = 0;
	
	while(t.estPositionPersoValide(VBot_x/TAILLE_SPRITE,VBot_y/TAILLE_SPRITE - N)){
	N++;
	}
	
	while(t.estPositionPersoValide(VBot_x/TAILLE_SPRITE,VBot_y/TAILLE_SPRITE + S)){
	S++;
	}
	
	while(t.estPositionPersoValide(VBot_x/TAILLE_SPRITE + E, VBot_y/TAILLE_SPRITE)){
	E++;
	}
	
	loin = maximum3element(N,S,E);
	
	if(loin == N){

		return 1 ; //Nord 
		
		}else {
			if(loin == E){
				return 2 ; //Est 
	
				}else {
					if(loin == S){
						return 3 ; //Sud
						
						}else {					
									return 0; //erreur
						}
								
				}
		}
}

int VoitureBot :: loin_de_hors_N_E(const Terrain & t){
	int W = 0 ;
	int S = 0 ;
	
	int loin = 0;
	
	while(t.estPositionPersoValide(VBot_x/TAILLE_SPRITE,VBot_y/TAILLE_SPRITE + S)){
	S++;
	}
	
	while(t.estPositionPersoValide(VBot_x/TAILLE_SPRITE - W, VBot_y/TAILLE_SPRITE)){
	W++;
	}
	
	loin = maximum2element(S,W);
		
	if(loin == S){
		return 3 ; //Sud
						
		}else {					
			if(loin == W){
				return 4 ; // Ouest
					}else{
						return 0; //erreur
					}
								
		}
}

int VoitureBot :: loin_de_hors_S_W(const Terrain & t){
	int E = 0 ;
	int N = 0 ;
	
	int loin = 0;
	
	while(t.estPositionPersoValide(VBot_x/TAILLE_SPRITE,VBot_y/TAILLE_SPRITE - N)){
	N++;
	}
	
	while(t.estPositionPersoValide(VBot_x/TAILLE_SPRITE + E, VBot_y/TAILLE_SPRITE)){
	E++;
	}
	loin = maximum2element(N,E);
		
	if(loin == N){
		return 1 ; //Nord
						
		}else {					
			if(loin == E){
				return 2 ; // Est
					}else{
						return 0; //erreur
					}
								
		}
}

int VoitureBot :: loin_de_hors_S_E(const Terrain & t){
	int W = 0 ;
	int N = 0 ;
	
	int loin = 0;
	
	while(t.estPositionPersoValide(VBot_x/TAILLE_SPRITE,VBot_y/TAILLE_SPRITE - N)){
	N++;
	}
	
	while(t.estPositionPersoValide(VBot_x/TAILLE_SPRITE - W, VBot_y/TAILLE_SPRITE)){
	W++;
	}
	loin = maximum2element(N,W);
		
	if(loin == N){
		return 1 ; //Nord
						
		}else {					
			if(loin == W){
				return 4 ; // Ouest
					}else{
						return 0; //erreur
					}
								
		}
}

int VoitureBot :: loin_de_hors_N_W(const Terrain & t){
	int E = 0 ;
	int S = 0 ;
	
	int loin = 0;
	
	while(t.estPositionPersoValide(VBot_x/TAILLE_SPRITE,VBot_y/TAILLE_SPRITE + S)){
	S++;
	}
	
	while(t.estPositionPersoValide(VBot_x/TAILLE_SPRITE + E, VBot_y/TAILLE_SPRITE)){
	E++;
	}
	loin = maximum2element(E,S);
		
	if(loin == S){
		return 3 ; //Sud
						
		}else {					
			if(loin == E){
				return 2 ; // Est
					}else{
						return 0; //erreur
					}
								
		}
}

int VoitureBot :: direction_interdite(){

	/* 
	
	TERRAIN N*1
	Directions interdites qui empeche le bot de retourner en arrière 
	
	if(VBot_x >= 1 && VBot_x <= 8 && VBot_y >= 1 && VBot_y <= 4){
	return 6 ;
	}

	if(VBot_x >= 1 && VBot_x <= 8 && VBot_y >= 5 && VBot_y <= 12){
	return 3 ;
	}

	if(VBot_x >= 9 && VBot_x <= 18 && VBot_y == 1){
	return 4;
	}

	if(VBot_x >= 11 && VBot_x <= 18 && VBot_y >= 2 && VBot_y <= 8){
	return 1 ;
	}

	if(VBot_x >= 11 && VBot_x <= 18 && VBot_y >= 9 && VBot_y <= 13){
	return 5 ;
	}

	if(VBot_x >= 1 && VBot_x <= 10 && VBot_y == 13 ){
	return 2 ;
	}

	else{
		return 0; // erreur
	}*/

		if(VBot_x >= 1 && VBot_x <= 6*TAILLE_SPRITE && VBot_y >= 1 && VBot_y <= 3*TAILLE_SPRITE){
		//interdit bas gauche
		return 6 ;
		}

		if(VBot_x >= 6*TAILLE_SPRITE +1 && VBot_x <= 15*TAILLE_SPRITE && VBot_y >= 1 && VBot_y <= 7*TAILLE_SPRITE){
		//interdit gauche
		return 4 ;
		}

		if(VBot_x >= 15*TAILLE_SPRITE +1 && VBot_x <= 20*TAILLE_SPRITE && VBot_y >= 1 && VBot_y <= 6*TAILLE_SPRITE){
		//interdit gauche haut
		return 7 ;
		}

		if(VBot_x >= 17*TAILLE_SPRITE +1 && VBot_x <= 20*TAILLE_SPRITE && VBot_y >= 6*TAILLE_SPRITE +1 && VBot_y <= 7*TAILLE_SPRITE){
		//interdit haut
		return 1 ;
		}

		if(VBot_x >= 11*TAILLE_SPRITE +1 && VBot_x <= 20*TAILLE_SPRITE && VBot_y >= 7*TAILLE_SPRITE +1 && VBot_y <= 16*TAILLE_SPRITE){
		//interdit 	droite haut
		return 5 ;
		}
		if(VBot_x >= 1 && VBot_x <= 11*TAILLE_SPRITE && VBot_y >= 10*TAILLE_SPRITE +1 && VBot_y <= 16*TAILLE_SPRITE){
		//interdit 	droite bas
		return 8 ;
		}

		if(VBot_x >= 1 && VBot_x <= 8*TAILLE_SPRITE && VBot_y >= 9*TAILLE_SPRITE + 1 && VBot_y <= 10*TAILLE_SPRITE){
		//interdit bas gauche
		return 6 ;
		}

		if(VBot_x >= 1 && VBot_x <= 10*TAILLE_SPRITE && VBot_y >= 7*TAILLE_SPRITE+1 && VBot_y <= 9*TAILLE_SPRITE){
		//interdit bas gauche
		return 8 ;
		}

		if(VBot_x >= 1 && VBot_x <= 6*TAILLE_SPRITE && VBot_y >= 3*TAILLE_SPRITE +1 && VBot_y <= 7*TAILLE_SPRITE){
		//interdit bas droite
		return 8 ;
		}

		else{
			return 0;
		}

}

void VoitureBot :: bougeMur (const Terrain & t){
	if(direction_interdite() == 1){  // INTERDIT D'ALLER EN HAUT
		
		//cout<<"interdit HAUT ,";

		if(loin_de_hors_N(t)==2){
		/*
			DEBUG
			cout<<"droite";
			cout<<loin_de_hors_N(t);
			*/
			droite(t);
		}

		if(loin_de_hors_N(t)==3){
			/*
			DEBUG
			cout<<"bas";
			cout<<loin_de_hors_N(t);
			*/
			bas(t);	
		}
	
		if(loin_de_hors_N(t)==4){
			/*
			DEBUG
			cout<<"gauche";
			cout<<loin_de_hors_N(t);
			*/
			gauche(t);
		}

		
		}else {
			if(direction_interdite() == 2){ //INTERDIT D'ALLER A DROITE
				
				//cout<<"interdit DROITE ,";

				if(loin_de_hors_E(t)==1){
					/*
					DEBUG
					cout<<"haut";
					cout<<loin_de_hors_E(t);
					*/
					haut(t);
				}

				if(loin_de_hors_E(t)==3){
					/*
					DEBUG
					cout<<"bas";
					cout<<loin_de_hors_E(t);
					*/
					bas(t);	
				}

				if(loin_de_hors_E(t)==4){
					/*
					DEBUG
					cout<<"gauche";
					cout<<loin_de_hors_E(t);
					*/
					gauche(t);
				}
	
				}else {
					if(direction_interdite() == 3){ // INTERDIT D'ALLER EN BAS
						
						//cout<<"interdit BAS ,";
						if(loin_de_hors_S(t)==1){
							/*
							DEBUG
							cout<<"haut";
							cout<<loin_de_hors_S(t);
							*/
							haut(t);
						}

						if(loin_de_hors_S(t)==2){
							/*
							DEBUG
							cout<<"droite";
							cout<<loin_de_hors_S(t);
							*/
							droite(t);	
						}

						if(loin_de_hors_S(t)==4){
							/*
							DEBUG
							cout<<"gauche";
							cout<<loin_de_hors_S(t);
							*/
							gauche(t);
						}
						
						}else {					
							if(direction_interdite() == 4){ // INTERDIT D'ALLER A GAUCHE
								
								//cout<<"interdit GAUCHE ,";	

								if(loin_de_hors_W(t)==1){
									/*
									DEBUG
									cout<<"haut";
									cout<<loin_de_hors_W(t);
									*/
									haut(t);
								}

								if(loin_de_hors_W(t)==2){
									/*
									DEBUG
									cout<<"droite";
									cout<<loin_de_hors_W(t);
									*/
									droite(t);	
								}

								if(loin_de_hors_W(t)==3){
									/*
									DEBUG
									cout<<"bas";
									cout<<loin_de_hors_W(t);
									*/
									bas(t);
								}

								}else {					
							if(direction_interdite() == 5){ // INTERDIT D'ALLER DROITE ET EN HAUT
								
									if(loin_de_hors_N_E(t)==3){
									/*
									DEBUG
									cout<<"bas";
									cout<<loin_de_hors_N_E(t);
									*/
									bas(t);	
								}

								if(loin_de_hors_N_E(t)==4){
									/*
									DEBUG
									cout<<"gauche";
									cout<<loin_de_hors_N_E(t);
									*/
									gauche(t);
								}							

							}else {					
							if(direction_interdite() == 7){ // INTERDIT D'ALLER GAUCHE ET EN HAUT
								
									if(loin_de_hors_N_W(t)==3){
									/*
									DEBUG
									cout<<"bas";
									cout<<loin_de_hors_N_E(t);
									*/
									bas(t);	
								}

								if(loin_de_hors_N_W(t)==2){
									/*
									DEBUG
									cout<<"gauche";
									cout<<loin_de_hors_N_E(t);
									*/
									droite(t);
								}							

							}else {					
							if(direction_interdite() == 8){ // INTERDIT D'ALLER DROITE ET EN BAS
								if(loin_de_hors_S_E(t)==1){
									
									/*
									DEBUG
									cout<<"bas";
									cout<<loin_de_hors_N_E(t);
									*/
									haut(t);	
								}

								if(loin_de_hors_S_E(t)==4){
									
									/*
									DEBUG
									cout<<"gauche";
									cout<<loin_de_hors_N_E(t);
									*/
									gauche(t);
								}							

							}else {					
							if(direction_interdite() == 6){ // INTERDIT D'ALLER GAUCHE ET EN BAS
									
									if(loin_de_hors_S_W(t)==1){
									/*
									DEBUG
									cout<<"haut";
									cout<<loin_de_hors_S_W(t);
									*/
									haut(t);	
								}

								if(loin_de_hors_S_W(t)==2){
									/*
									DEBUG
									cout<<"droite";
									cout<<loin_de_hors_S_W(t);
									*/
									droite(t);
								}
						
								}else{
									if(loin_de(t)==2){
										/*
										DEBUG
										cout<<"droite";
										cout<<loin_de(t);
										*/
										droite(t);
									}
	
									if(loin_de(t)==3){
									/*
										DEBUG
										cout<<"droite";
										cout<<loin_de(t);
										*/
										bas(t);	
									}
	
									if(loin_de(t)==4){
										/*
										DEBUG
										cout<<"droite";
										cout<<loin_de(t);
										*/
										gauche(t);
									}

									if(loin_de(t)==1){
										/*
										DEBUG
										cout<<"droite";
										cout<<loin_de(t);
										*/
										haut(t);
									}
								}	
							}
						}
					}
				}
			}
		}
	}
}


void VoitureBot :: bougeAleatoire (const Terrain & t){
	
	srand(time(NULL));
	
	int n = 0;
	n = rand()%4 + 1;
	
	switch (n) {

		case 1 :
			haut(t);
			break;

		case 2 :
			droite(t);
			break;

		case 3 :
			bas(t);
			break;

		case 4 :
			gauche(t);
			break;

		default: 
			cout<<"erreur"<<endl<<flush;
			break;
	}
}

void VoitureBot :: verifscore(){
	if(VBot_x==4 && VBot_y >= 1 && VBot_y <= 3){
		score ++;
		cout<<"score Bot :"<<score<<"fin"<<endl<<flush;
		cout<<"etat Bot :"<<etat<<"fin"<<endl<<flush;
	}
}

void VoitureBot :: bougeAuto (const Terrain & t){
	bougeMur(t);
	compteur_deplacement ++ ;

	if(compteur_deplacement == 4){
	bougeAleatoire(t);
	compteur_deplacement = 0 ;
	}
	verifscore();
}

void VoitureBot :: testRegressionBot(const Terrain &t){
	
	// Initialisation d'une voiture bot grace au constructeur par défaut 
	
	VoitureBot vb ;
	
	assert(vb.VBot_x == 1);
	assert(vb.VBot_y == 1);
	assert(vb.VitBot == 10);
	
	assert(etat == 3);
	
	
	//on verifie les fonctions de deplacement 
	
	droite(t);
	assert(vb.VBot_x == 2);
	
	gauche(t);
	assert(vb.VBot_x == 1);
	
	haut(t);
	assert(vb.VBot_y == 0);
	
	bas(t);
	assert(vb.VBot_y == 1);

	//on verifier les fonctions maximum 

	int z = 0 ;
	int a = 1 ;
	int b = 2 ;
	int c = 3 ;
	int d = 4 ;

	assert(maximum4element(a,b,c,d) == d && d == 4);
	assert(maximum3element(a,b,c) == c && c ==3);
	assert(maximum2element(a,b) == b && b== 2);

	assert(maximum4element(z,z,z,z) == z && z == 0);
	assert(maximum3element(z,z,z) == z && z == 0);
	assert(maximum2element(z,z) == z && z == 0);

}
