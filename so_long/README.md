# So Long, Et merci pour le poisson!

## Présentation du projet

"So Long" est un jeu 2D simple conçu pour pratiquer l'utilisation de textures, de sprites et quelques éléments de base de gameplay. Le but du jeu est de contrôler un dauphin qui s'échappe de la planète Terre après avoir mangé du poisson.

## Fonctionnalités clés

- Utilisation de la bibliothèque graphique MiniLibX.
- Gestion de fenêtre et gestion des événements.
- Choix de couleurs et de textures.
- Affichage d'une image dans une fenêtre.
- Gestion des mouvements du personnage à l'aide des touches W, A, S, D.
- Collecte d'items sur la carte avant de pouvoir s'échapper.
- Affichage du compte total de mouvements dans le shell après chaque mouvement.
- Vérification de l'existence d'un chemin valide dans la carte.
- Gestion des erreurs de configuration de la carte.

## Configuration de la carte

La carte est construite en utilisant trois éléments :

- Les murs
- Les items à collecter
- L'espace vide

Les caractères utilisés pour représenter ces éléments sont les suivants :

- 0 pour un emplacement vide,
- 1 pour un mur,
- C pour un item à collecter (C pour collectible),
- E pour une sortie (E pour exit),
- P pour la position de départ du personnage.

## Partie bonus

En plus des fonctionnalités de base, des fonctionnalités supplémentaires ont été ajoutées pour la partie bonus :

- Possibilité pour le joueur de perdre si son personnage est touché par une patrouille ennemie.
- Ajout d'animations de sprites.
- Affichage du compte total de mouvements directement à l'écran dans la fenêtre, plutôt que dans le shell.

## Conclusion

Ce projet a permis de me familiariser avec la programmation graphique et de mettre en pratique des concepts clés tels que la gestion des événements, la manipulation de textures et la création de gameplay basique.
