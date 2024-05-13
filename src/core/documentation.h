/**
@brief Premiere page de la documentation doxygen
@file documentation.h
@date 2023/03/07
*/

/** \mainpage ACA_SPRINT

 
\section intro Principe du Jeu :

ACA_Sprint est un jeu de voiture de course local en 2d vu de dessus. Deux voitures au
maximum s’affrontent sur le circuit dont une est contrôlées par le joueurs et la
deuxième par l’ordinateur. Le joueur utilise les touches du clavier pour
pouvoir diriger sa voiture. Une partie se joue en trois tours, le
joueur remporte la course en finissant devant toutes les autres voitures. <br>

\section amelio Améliorations futures :
Au fil de la course, des objets bonus ou des obstacles handicapant peuvent
apparaître sur le circuit pour rendre le jeu plus dynamique : un boost, une flaque de
boue etc. Si une voiture tape contre un mur, ou une voiture, selon sa vitesse elle
peut exploser, il faudra alors attendre quelque seconde avant que celle-ci
réapparaisse et puisse continuer la course. <br>

Code écrit en C++ <br>
Se compile avec g++ 

\section compil Pour compiler :
Tester sous Linux (Ubuntu).

Dépendances :
 - SDL2 : http://www.libsdl.org/

$ make ou ouvrir le projet avec CodeBlocks puis F9
<br>

\section doc Pour générer la documentation de code :
 Dépendance : doxygen http://www.stack.nl/~dimitri/doxygen/ <br>
 $ cd doc <br>
 $ doxygen doxyfile <br>
 Puis ouvrir doc/html/index.html avec firefox

\section regle Règles du Jeu :

Chaque voiture controllé par l'ordinateur ou le joueur possède 3 vie au début de la course.<br>
Un choc à lieu quand la voiture touche un mur, un autre joueur ou une voiture controllé par l'ordinateur.
Lors d'un choc la voiture perd une vie et voit sa vitesse réduite. <br>
Lorsque la vie d'un voiture atteint 0, elle "meurt" et réapparait au même endroit avec quelqes secondes sans pouvoir bougé tout en etant invulnérable.
la voiture réapparait avec sa vitesse initiale au début de la course et ses 3 vies.

\section voiture Voiture :
Une voiture est définie par une position, un état, un score, et une vitesse.
Une voiture peut se déplacer de haut en bas et de gauche à droite avec les
touches directionnelles du clavier (<kbd>↑</kbd> <kbd>←</kbd> <kbd>↓</kbd> <kbd>→</kbd>).<br>
Deux autre touches serviront à avancer et à ralentir (accélération/freinage) à l'avenir.
Deux voitures au maximum s’affrontent sur le circuit dont une est contrôlée par
un joueurs et le deuxième par l’ordinateur.
*/

