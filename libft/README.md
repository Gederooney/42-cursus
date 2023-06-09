# Libft

"Libft" est un projet qui vise à créer une bibliothèque de fonctions utilitaires qui seront utilisées tout au long du cursus de l'école 42. L'objectif principal est de renforcer les compétences de base en programmation C, notamment en termes de gestion de la mémoire et de la manipulation de chaînes de caractères.

## Contenu

1. Recodage de fonctions de la bibliothèque standard de C (`libc`), avec le préfixe `ft_` ajouté au nom.
2. Implémentation de fonctions supplémentaires qui peuvent être utiles pour la manipulation de chaînes de caractères.
3. Une section bonus où l'on implémente des fonctions pour manipuler des structures de données de type liste chaînée.

## Fonctions

La bibliothèque `libft` contient de nombreuses fonctions, notamment:

### Partie 1: Fonctions Libc

- Manipulation de caractères : `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- Manipulation de chaînes de caractères : `ft_strlen`, `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_strlcpy`, `ft_strlcat`, `ft_toupper`, `ft_tolower`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_memchr`, `ft_memcmp`, `ft_strnstr`, `ft_atoi`, `ft_calloc`, `ft_strdup`

### Partie 2: Fonctions supplémentaires

- Manipulation de chaînes de caractères : `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`
- Manipulation de fichiers : `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
- Manipulation de listes : `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`

## Installation

1. Cloner le dépôt : `git clone https://github.com/user/libft.git`
2. Aller dans le répertoire : `cd libft`
3. Compiler : `make`

Cela va créer une bibliothèque `libft.a`. Vous pouvez l'utiliser dans vos projets en incluant le header (`#include "libft.h"`) et en compilant avec la bibliothèque (par exemple `gcc -L. -lft mon_fichier.c`).

