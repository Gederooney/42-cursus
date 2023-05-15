# Basics of Linux System Administration

## 1. Gestion des fichiers et des répertoires

La gestion des fichiers et des répertoires est une compétence fondamentale en administration système Linux. Voici quelques commandes importantes :

- `ls` : Liste les fichiers et les répertoires.
- `cd` : Change le répertoire courant.
- `pwd` : Affiche le répertoire courant.
- `touch` : Crée un nouveau fichier vide.
- `mkdir` : Crée un nouveau répertoire.
- `rm` : Supprime les fichiers et répertoires.
- `cp` : Copie les fichiers et répertoires.
- `mv` : Déplace ou renomme les fichiers et répertoires.
- `find` : Recherche des fichiers et des répertoires.
- `cat`, `less`, `more`, `head`, `tail` : Affiche le contenu des fichiers.

## 2. Gestion des utilisateurs et des groupes

La gestion des utilisateurs et des groupes est également une partie essentielle de l'administration système. Voici quelques commandes importantes :

- `useradd`, `userdel`, `usermod` : Pour ajouter, supprimer et modifier les utilisateurs.
- `passwd` : Pour changer le mot de passe d'un utilisateur.
- `groupadd`, `groupdel`, `groupmod` : Pour ajouter, supprimer et modifier les groupes.
- `gpasswd` : Pour administrer les membres d'un groupe.
- `su`, `sudo` : Pour changer d'utilisateur ou exécuter des commandes en tant qu'un autre utilisateur.

## 3. Gestion des permissions

Les permissions déterminent qui peut faire quoi avec un fichier ou un répertoire. Voici quelques commandes importantes :

- `chmod` : Change les permissions d'un fichier ou d'un répertoire.
- `chown` : Change le propriétaire d'un fichier ou d'un répertoire.
- `chgrp` : Change le groupe d'un fichier ou d'un répertoire.
- `umask` : Définit les permissions par défaut pour les nouveaux fichiers et répertoires.

## 4. Utilisation des commandes de base (ls, cd, mv, cp, etc.)

Ces commandes sont fondamentales pour naviguer et manipuler le système de fichiers. Il est important de les comprendre et de savoir les utiliser couramment.

## 5. Installation et gestion des paquets logiciels

En fonction de la distribution Linux que vous utilisez, vous utiliserez différents outils pour gérer les paquets logiciels. Les plus courants sont `apt` (pour les distributions basées sur Debian comme Ubuntu), `yum` ou `dnf` (pour les distributions basées sur Red Hat comme Fedora), et `pacman` (pour Arch Linux).

Ces outils vous permettent d'installer, de mettre à jour et de supprimer des logiciels, ainsi que de rechercher des informations sur les paquets disponibles.
