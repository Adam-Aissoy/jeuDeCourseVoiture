/**
@brief Module gérant l'affichage en mode texte
@file winTxt.h
@date 2023/03/07
*/

#ifndef WINTXT_H
#define WINTXT_H

/*!
* \brief Module gérant l'affichage en mode texte 
*
* Créer une fenêtre texte avec un tableau 2D de caractères
*
*/
class WinTXT
{
private:

    int dimx;       //!< \brief largeur
    int dimy;       //!< \brief heuteur
    char* win;      //!< \brief stocke le contenu de la fen�tre dans un tableau 1D mais on y accede en 2D

public:

    WinTXT (int dx, int dy);
    void clear (char c=' ');
    void print (int x, int y, char c);
    void print (int x, int y, char* c);
    void draw (int x=0, int y=0);
    void pause();
    char getCh();

};

void termClear ();

#endif
