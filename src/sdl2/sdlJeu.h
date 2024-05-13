#ifndef _SDLJEU_H
#define _SDLJEU_H


#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "../core/Car.h"


/*#include <cassert>
#include <time.h>*/



#include "../core/Jeu.h"

//! \brief Pour gérer une image avec SDL2
class Image {

private:

    SDL_Surface * m_surface;
    SDL_Texture * m_texture;
    bool m_hasChanged;

public:
    Image () ;
    ~Image();
    void loadFromFile (const char* filename, SDL_Renderer * renderer);
    void loadFromCurrentSurface (SDL_Renderer * renderer);
    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
    // affichage Aysoy 
     /**
    @brief Affiche la texture redimensionnée
    @param renderer : le renderer
    @param x : position x
    @param y : position y 
   
    */
    void draw_carAysoy(SDL_Renderer *renderer, float x, float y, float v, float a, int w=-1, int h = -1);
    SDL_Texture * getTexture() const;
    void setSurface(SDL_Surface * surf);
};



/**
    La classe gerant le jeu avec un affichage SDL
*/
class SDLSimple {

private :

	Jeu jeu;

    SDL_Window * window;
    SDL_Renderer * renderer;

    TTF_Font * font;
    Image font_im;
    SDL_Color font_color;

    Mix_Chunk * sound;
    bool withSound;

    Image im_damier ;
    Image im_mur;
    Image im_roue;
    Image im_grass ;
    Image im_VoitureJoueur ;
    Image im_pastille;
    Image im_Bot;
    Image im_car; 
    //Image im_vj2nd;
    Image im_haut ;
    Image im_bas ;
    Image im_droite ;
    Image im_gauche ;
    
    Image im_diaghd ;
    Image im_diaghg ;
    Image im_diagbd ;
    Image im_diagbg ;


    bool souris;
    bool touche;
public :

    SDLSimple ();
    ~SDLSimple ();
    void sdlBoucle ();
    void sdlAff ();

};

#endif
