# ACA Sprint

## Table des matières

- [À propos](#à-propos)
- [Dépendances requises](#dépendances-requises)
- [Compilation et exécution](#compilation-et-exécution)
- [Pour générer la documentation de code](#Pour-générer-la-documentation-de-code)
- [Les commandes](#les-commandes)
- [Contenu de l'archive](#contenu-de-l'archive)
- [Étudiants](#étudiants)

## À propos

ACA_Sprint est un jeu de voiture de course multi-joueurs local. Trois voitures au
maximum s’affrontent sur le circuit dont deux sont contrôlées par des joueurs et le
troisième par l’ordinateur. Les deux joueurs utilisent les touches du clavier pour
pouvoir diriger leur voiture (accélérer et freiner). Une partie se joue en trois tours, le
joueur remporte la course en finissant devant toutes les autres voitures.
Au fil de la course, des objets bonus ou des obstacles handicapant peuvent
apparaître sur le circuit pour rendre le jeu plus dynamique : un boost, une flaque de
boue etc. Si une voiture tape contre un mur, ou une voiture, selon sa vitesse elle
peut exploser, il faudra alors attendre quelque seconde avant que celle-ci
réapparaisse et puisse continuer la course.

- Le jeu sera développé en C/C++
- Les librairies utilisées seront SDL2
- Le code sera géré et archivé sur GitLab
- La documentation du code sera produite sur Doxygen
- L’équipe de développement utilisera les outils de début et profiling : gdb et
valgrind
- Durée de développement : prêt dans 2 mois pour le dépôt du projet sur
TOMUSS

## Dépendances requises

- Système d'exploitation: **Linux** (makefile).
- Libraire graphique pour l'**affichage**: [SDL2](https://www.libsdl.org/download-2.0.php)

## Compilation et exécution

Dans le dossier `ACA_Sprint`, il faut ouvrir un terminal est exéctuer la commande `make` (compilation).
Puis il suffit d'executer la commande `bin/Course_sdl` pour lancer le jeu en mode graphique (exécution).
On peut également le lancer en mode texte avec `bin/Course_txt`.

## Pour générer la documentation de code 

Dépendance : doxygen http://www.stack.nl/~dimitri/doxygen/ <br>
`cd doc` <br>
`doxygen image.doxy` <br>
Puis ouvrir doc/html/index.html avec firefox

## Les commandes

#### Joueur 1

<kbd>↑</kbd> Déplacer la voiture vers le haut <br>
<kbd>←</kbd> Déplacer la voiture vers la gauche <br>
<kbd>↓</kbd> Déplacer la voiture vers le bas <br>
<kbd>→</kbd> Déplacer la voiture vers la droite 

## Contenu de l'archive

- Le dossier `bin` qui contient **les éxecutables**.
- Le dossier `data` qui contient **les données audio, image**.
- Le dossier `doc` qui contient **la doc**.
- Le dossier `obj` qui contient **les fichiers objets**.
- Le dossier `src` qui contient **les sources**.

## Étudiants

- P2110686 ADAM Oumar Adam
- P2100546 DINH Son-Christophe
- P2006219 YVARS Arthur
