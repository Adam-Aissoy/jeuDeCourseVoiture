#include <cassert>
#include <time.h>
#include "sdlJeu.h"
#include <stdlib.h>

#include <iostream>
using namespace std;

const int TAILLE_SPRITE = 32;

float temps () {
    return float(SDL_GetTicks()) / CLOCKS_PER_SEC;  // conversion des ms en secondes en divisant par 1000
}

// ============= CLASS IMAGE =============== //

Image::Image () : m_surface(nullptr), m_texture(nullptr), m_hasChanged(false) {
}

Image::~Image()
{
    SDL_FreeSurface(m_surface);
    SDL_DestroyTexture(m_texture);

    m_surface = nullptr;
    m_texture = nullptr;
    m_hasChanged = false;
}

void Image::loadFromFile (const char* filename, SDL_Renderer * renderer) {
    m_surface = IMG_Load(filename);
    if (m_surface == nullptr) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        m_surface = IMG_Load(nfn.c_str());
        if (m_surface == nullptr) {
            nfn = string("../") + nfn;
            m_surface = IMG_Load(nfn.c_str());
        }
    }
    if (m_surface == nullptr) {
        cout<<"Error: cannot load "<< filename <<endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(m_surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(m_surface);
    m_surface = surfaceCorrectPixelFormat;

    m_texture = SDL_CreateTextureFromSurface(renderer,surfaceCorrectPixelFormat);
    if (m_texture == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::loadFromCurrentSurface (SDL_Renderer * renderer) {
    m_texture = SDL_CreateTextureFromSurface(renderer,m_surface);
    if (m_texture == nullptr) {
        cout << "Error: problem to create the texture from surface " << endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?m_surface->w:w;
    r.h = (h<0)?m_surface->h:h;

    if (m_hasChanged) {
        ok = SDL_UpdateTexture(m_texture,nullptr,m_surface->pixels,m_surface->pitch);
        assert(ok == 0);
        m_hasChanged = false;
    }

    ok = SDL_RenderCopy(renderer,m_texture,nullptr,&r);
    assert(ok == 0);
}
// car Aysoy
void Image::draw_carAysoy(SDL_Renderer *renderer, float positionx, float positiony, float vitesse_voiture , float angle_voiture, int w, int h)
{
    int ok;
    SDL_Rect dest;
    dest.x = static_cast<int>(positionx);
    dest.y = static_cast<int>(positiony);
    dest.w = (w<0)?m_surface->w:w;
    dest.h = (h<0)?m_surface->h:h;

   if (m_hasChanged) {
        ok = SDL_UpdateTexture(m_texture,nullptr,m_surface->pixels,m_surface->pitch);
        assert(ok == 0);
        m_hasChanged = false;
    }

    ok = SDL_RenderCopy(renderer,m_texture,nullptr,&dest);
    assert(ok == 0);

  
}

SDL_Texture * Image::getTexture() const {return m_texture;}

void Image::setSurface(SDL_Surface * surf) {m_surface = surf;}










// ============= CLASS SDLJEU =============== //

SDLSimple::SDLSimple () : jeu() {
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
        cout << "No sound !!!" << endl;
        //SDL_Quit();exit(1);
        withSound = false;
    }
    else withSound = true;

	int dimx, dimy;
	dimx = jeu.getConstTerrain().getDimX();
	dimy = jeu.getConstTerrain().getDimY();
	dimx = dimx * TAILLE_SPRITE;
	dimy = dimy * TAILLE_SPRITE;

    // Creation de la fenetre
    window = SDL_CreateWindow("Course", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    // IMAGES
    im_VoitureJoueur.loadFromFile("data/car.png",renderer);
    im_mur.loadFromFile("data/mur.jpg",renderer);
    im_roue.loadFromFile("data/up.png",renderer);
    im_grass.loadFromFile("data/grass.png",renderer);
    im_pastille.loadFromFile("data/dirt.png",renderer);
    im_Bot.loadFromFile("data/car.png",renderer);
     // images car Adam Aysoy 
    im_car.loadFromFile("data/car.png",renderer);
    //im_vj2nd.loadFromFile("data/car.png",renderer);

    im_damier.loadFromFile("data/damier.png",renderer);

    im_haut.loadFromFile("data/murs/haut.png",renderer);
    im_droite.loadFromFile("data/murs/droite.png",renderer);
    im_gauche.loadFromFile("data/murs/gauche.png",renderer);
    im_bas.loadFromFile("data/murs/bas.png",renderer);

    im_diaghd.loadFromFile("data/murs/diaghd.png",renderer);
    im_diaghg.loadFromFile("data/murs/diaghg.png",renderer);
    im_diagbd.loadFromFile("data/murs/diagbd.png",renderer);
    im_diagbg.loadFromFile("data/murs/diagbg.png",renderer);

    // FONTS
    font = TTF_OpenFont("data/DejaVuSansCondensed.ttf",50);
    if (font == nullptr)
        font = TTF_OpenFont("../data/DejaVuSansCondensed.ttf",50);
    if (font == nullptr) {
            cout << "Failed to load DejaVuSansCondensed.ttf! SDL_TTF Error: " << TTF_GetError() << endl; 
            SDL_Quit(); 
            exit(1);
	}
	font_color.r = 50;font_color.g = 50;font_color.b = 255;
	font_im.setSurface(TTF_RenderText_Solid(font,"Course",font_color));
	font_im.loadFromCurrentSurface(renderer);

    // SONS
    if (withSound)
    {
        sound = Mix_LoadWAV("data/son.wav");
        if (sound == nullptr) 
            sound = Mix_LoadWAV("../data/son.wav");
        if (sound == nullptr) {
                cout << "Failed to load son.wav! SDL_mixer Error: " << Mix_GetError() << endl; 
                SDL_Quit();
                exit(1);
        }
    }
}

SDLSimple::~SDLSimple () {
    if (withSound) Mix_Quit();
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void SDLSimple::sdlAff () {
	//Remplir l'écran de blanc
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);

	int x,y;
	const Terrain& ter = jeu.getConstTerrain();
	const VoitureJoueur& Vj = jeu.getConstJoueur();
	const VoitureBot& Bot = jeu.getConstBot();
    const Voiture& Car = jeu.getConstCar();
    // const VoitureJoueur& vj2nd = jeu.getConstJoueur();

    // Afficher les sprites des murs et des pastilles
	for (x=0;x<ter.getDimX();++x)
		for (y=0;y<ter.getDimY();++y)
			if (ter.getXY(x,y)=='#'){
				im_mur.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
			}else{
                if (ter.getXY(x,y)=='.'){
				    im_pastille.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
                }
                else{
                if(ter.getXY(x,y)== '0'){
                    im_roue.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
                }
                else{
                if(ter.getXY(x,y)== 'G'){
                    im_grass.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
                }
                else{
                if(ter.getXY(x,y)== 'A'){
                    im_haut.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
                }else{
                if(ter.getXY(x,y)== 'B'){
                    im_bas.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
                }else{
                if(ter.getXY(x,y)== 'C'){
                    im_gauche.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
                }else{
                if(ter.getXY(x,y)== 'D'){
                    im_droite.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
                }else{
                if(ter.getXY(x,y)== 'E'){
                    im_diaghd.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
                }else{
                if(ter.getXY(x,y)== 'F'){
                    im_diaghg.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
                }else{
                if(ter.getXY(x,y)== 'I'){
                    im_diagbd.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
                }else{
                if(ter.getXY(x,y)== 'H'){
                    im_diagbg.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
                }else{
                if(ter.getXY(x,y)== '@'){
                    im_damier.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
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
                
                
                }}}

	// Afficher le sprite de voiture joueur
	im_VoitureJoueur.draw(renderer,Vj.getX(),Vj.getY(),TAILLE_SPRITE,TAILLE_SPRITE);
   // im_vj2nd.draw(renderer,vj2nd.getX(),vj2nd.getY(),TAILLE_SPRITE,TAILLE_SPRITE);

	// Afficher le sprite du Bot
	im_Bot.draw(renderer,Bot.getX(),Bot.getY(),TAILLE_SPRITE,TAILLE_SPRITE);
     // Afficher car Aysoy
	im_car.draw_carAysoy(renderer,Car.getPositionX(), Car.getPositionY(),Car.getAngle(),Car.getVitesse(),TAILLE_SPRITE,TAILLE_SPRITE);
    // Ecrire un titre par dessus
    SDL_Rect positionTitre;
    positionTitre.x = 270;positionTitre.y = 49;positionTitre.w = 100;positionTitre.h = 30;
    SDL_RenderCopy(renderer,font_im.getTexture(),nullptr,&positionTitre);

}

void SDLSimple::sdlBoucle () {
    SDL_Event events;
	bool quit = false;
    // Aysoy bool 

    bool avancerAppuyee = false;
    bool reculerAppuyee = false;
    bool gaucheAppuyee = false;
    bool droiteAppuyee = false;
    

    Uint32 t = SDL_GetTicks(), nt;

	// tant que ce n'est pas la fin ...
	while (!quit) {

        nt = SDL_GetTicks();
        if (nt-t>500) {
            jeu.actionsAutomatiques();
            t = nt;
        }

		// tant qu'il y a des évenements à traiter (cette boucle n'est pas bloquante)
		while (SDL_PollEvent(&events)) {
			if (events.type == SDL_QUIT) quit = true;           // Si l'utilisateur a clique sur la croix de fermeture
			else if (events.type == SDL_KEYDOWN) {              // Si une touche est enfoncee
                bool mangePastille = false;
				switch (events.key.keysym.scancode) {
				case SDL_SCANCODE_UP:
					mangePastille = jeu.actionClavier('b');    // car Y inverse b
					break;
				case SDL_SCANCODE_DOWN:
					mangePastille = jeu.actionClavier('h');     // car Y inverse h
					break;
				case SDL_SCANCODE_LEFT:
					mangePastille = jeu.actionClavier('g'); // g 
					break;
				case SDL_SCANCODE_RIGHT:
					mangePastille = jeu.actionClavier('d'); // d 
                    break;
                // touche car Aysoy 
                // premier version ça marche pas 
                // all test 

                
                case SDL_SCANCODE_S:
                    jeu.actionClavier( 's' );
					break;
                case SDL_SCANCODE_D:
                    jeu.actionClavier( 'x' );
					break;
                case SDL_SCANCODE_F:
                    jeu.actionClavier( 'f' );
					break;
                case SDL_SCANCODE_E:
                    jeu.actionClavier( 'e' );
					break;

                    
                // Aysoy bouton appuyer ensemles


               

              /*
                    
                            case SDL_SCANCODE_D:
                                reculerAppuyee = true;
                                switch (events.key.keysym.sym) {
                            
                                    case SDLK_s:
                                        gaucheAppuyee = true;
                                        break;
                                    case SDLK_f:
                                        droiteAppuyee = true;
                                        break;
                                }
                                break;
                            case SDL_SCANCODE_E:
                                switch (events.key.keysym.sym) {
                                    case SDLK_e:
                                        avancerAppuyee = false;
                                        break;
                                    case SDLK_d:
                                        reculerAppuyee = false;
                                        break;
                                    case SDLK_s:
                                        gaucheAppuyee = false;
                                        break;
                                    case SDLK_f:
                                        droiteAppuyee = false;
                                        break;
                                }
                                break;
                        
                    

              
            */
                // end Aysoy*
                // second version Aysoy 

            

        
                // end second version Aysoy
                case SDL_SCANCODE_ESCAPE:
                case SDL_SCANCODE_Q:
                    quit = true;
                    break;
				default: break;
				}
				if ((withSound) && (mangePastille))
                    Mix_PlayChannel(-1,sound,0);

                }

                            
		}
        // ici normalement 
        // faire avancer ou reculer la voiture
        /*
                    if (avancerAppuyee && !reculerAppuyee) {
                        jeu.actionClavier( 'e' );
                    } else if (reculerAppuyee && !avancerAppuyee) {
                        jeu.actionClavier( 'x' );
                    }

                    // faire tourner la voiture
                    if (gaucheAppuyee && !droiteAppuyee) {
                        jeu.actionClavier( 's' );
                    } else if (droiteAppuyee && !gaucheAppuyee) {
                        jeu.actionClavier( 'f' );
                    }
        */
		// on affiche le jeu sur le buffer cach�
		sdlAff();

		// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
	}
    //ici Adam Aysoy
}
