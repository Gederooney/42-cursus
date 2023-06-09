# Projet ft_printf

## Description

Le projet `ft_printf` est une implémentation en C de la fonction `printf` de la bibliothèque standard du C (libc). L'objectif de ce projet était de comprendre en profondeur le fonctionnement des arguments variables en C et d'appliquer ces connaissances en reproduisant une version simplifiée mais robuste de `printf`.

## Fonctionnalités

La fonction `ft_printf` supporte les conversions suivantes :

- `%c` : Affiche un seul caractère.
- `%s` : Affiche une chaîne de caractères (telle que définie par la convention C).
- `%p` : L’argument de pointeur `void *` est affiché en hexadécimal.
- `%d` : Affiche un nombre décimal (base 10).
- `%i` : Affiche un entier en base 10.
- `%u` : Affiche un nombre décimal non signé (base 10).
- `%x` : Affiche un nombre en hexadécimal (base 16) avec des lettres minuscules.
- `%X` : Affiche un nombre en hexadécimal (base 16) avec des lettres majuscules.
- `%%` : Affiche un signe pourcentage.

## Installation

Pour compiler le programme, exécutez la commande `make` dans le répertoire principal du projet.

## Utilisation

Après avoir compilé le programme, vous pouvez l'utiliser comme suit :

```c
ft_printf("Votre format", ...);
