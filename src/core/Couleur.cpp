#include <iostream>
#include "Couleur.h"
using namespace std;

Couleur::Couleur()
{
    r = 0;
    g = 0;
    b = 0;
}

unsigned char Couleur:: getRouge()
{
    return r;
}

unsigned char Couleur:: getVert()
{
    return g;
}

unsigned char Couleur:: getBleu()
{
    return b;
}


// TEST 

void Couleur::setRouge(const unsigned int nr) {

    r = nr;
}

void Couleur::setVert(const unsigned int ng) {

    g = ng;
}

void Couleur::setBleu(const unsigned int nb) {
    b = nb;
}




