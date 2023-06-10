# Projet Minitalk

Le but de ce projet est de créer un programme d'échange de données utilisant les signaux UNIX.

## Description

Le programme consiste en un serveur et un client. Le serveur doit être lancé en premier et affiche son PID. Le client prend en entrée le PID du serveur et une chaîne de caractères à transmettre. Le serveur reçoit cette chaîne et l'affiche. La communication entre les deux se fait uniquement par des signaux UNIX.

## Comment utiliser

1. Compilez les sources à l'aide du Makefile : `make all`
2. Lancez le serveur : `./server`
3. Dans une autre fenêtre de terminal, lancez le client avec le PID du serveur et une chaîne de caractères : `./client [PID] [string]`

## Règles de codage

- Écrit en langage C conformément à la Norme.
- Toute mémoire allouée sur le heap doit être correctement libérée.
- Le programme ne doit pas s'arrêter de manière inattendue.
- Un Makefile a été fourni pour compiler les sources avec les flags -Wall, -Wextra et -Werror.

## Bonus

Les bonus sont évalués si et seulement si la partie obligatoire est complète et sans défaut. Les bonus comprennent :
- Confirmation de la réception de chaque message par le serveur en envoyant un signal au client.
- Support des caractères Unicode.

