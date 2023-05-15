# Les bases de l'administration de systems sous linux

#### 1. Gestion des fichiers et des répertoires

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

#### 2. Gestion des utilisateurs et des groupes

La gestion des utilisateurs et des groupes est également une partie essentielle de l'administration système. Voici quelques commandes importantes :

- `useradd`, `userdel`, `usermod` : Pour ajouter, supprimer et modifier les utilisateurs.
- `passwd` : Pour changer le mot de passe d'un utilisateur.
- `groupadd`, `groupdel`, `groupmod` : Pour ajouter, supprimer et modifier les groupes.
- `gpasswd` : Pour administrer les membres d'un groupe.
- `su`, `sudo` : Pour changer d'utilisateur ou exécuter des commandes en tant qu'un autre utilisateur.

#### 3. Gestion des permissions

Les permissions déterminent qui peut faire quoi avec un fichier ou un répertoire. Voici quelques commandes importantes :

- `chmod` : Change les permissions d'un fichier ou d'un répertoire.
- `chown` : Change le propriétaire d'un fichier ou d'un répertoire.
- `chgrp` : Change le groupe d'un fichier ou d'un répertoire.
- `umask` : Définit les permissions par défaut pour les nouveaux fichiers et répertoires.

#### 4. Utilisation des commandes de base (ls, cd, mv, cp, etc.)

Ces commandes sont fondamentales pour naviguer et manipuler le système de fichiers. Il est important de les comprendre et de savoir les utiliser couramment.

#### 5. Installation et gestion des paquets logiciels

En fonction de la distribution Linux que vous utilisez, vous utiliserez différents outils pour gérer les paquets logiciels. Les plus courants sont `apt` (pour les distributions basées sur Debian comme Ubuntu), `yum` ou `dnf` (pour les distributions basées sur Red Hat comme Fedora), et `pacman` (pour Arch Linux).

Ces outils vous permettent d'installer, de mettre à jour et de supprimer des logiciels, ainsi que de rechercher des informations sur les paquets disponibles.

## Introduction à la virtualisation

#### Comprendre les concepts de base de la virtualisation

La virtualisation est une technologie qui permet de créer des versions virtuelles de ressources physiques, comme des serveurs, des dispositifs de stockage, ou des réseaux. 

Les principales formes de virtualisation comprennent :

- Virtualisation de serveur : Plusieurs systèmes d'exploitation s'exécutent simultanément sur un seul serveur physique. Chacun d'eux fonctionne comme s'il était sur son propre serveur dédié.
- Virtualisation de stockage : Le stockage physique est regroupé en une seule ressource qui peut être gérée de manière centralisée.
- Virtualisation de réseau : Les ressources réseau physiques sont virtualisées pour offrir des services de réseau plus flexibles et évolutifs.

#### Découverte de Docker

Docker est une plateforme open-source qui facilite la création, le déploiement et l'exécution d'applications par l'utilisation de conteneurs. Les conteneurs permettent aux développeurs de regrouper une application avec toutes les parties dont elle a besoin, comme les bibliothèques et autres dépendances, et de les expédier en un seul paquet.

#### Installation et configuration de Docker

L'installation de Docker varie en fonction du système d'exploitation que vous utilisez. Pour Ubuntu, vous pouvez utiliser les commandes suivantes :

bash
sudo apt-get update
sudo apt-get install docker-ce docker-ce-cli containerd.io


Pour vérifier que Docker a été installé correctement, utilisez :

bash
docker --version


#### Création, gestion et utilisation de conteneurs Docker

Voici quelques commandes de base pour travailler avec Docker :

- `docker run` : Crée et démarre un nouveau conteneur Docker.
- `docker ps` : Liste les conteneurs Docker actifs.
- `docker stop` : Arrête un conteneur Docker.
- `docker rm` : Supprime un conteneur Docker.
- `docker images` : Liste les images Docker disponibles.
- `docker pull` : Télécharge une image Docker à partir d'un registre.
- `docker build` : Crée une image Docker à partir d'un Dockerfile.


## Création d'images Docker

#### Comprendre le concept d'image Docker

Une image Docker est un modèle immuable, qui est essentiellement une capture instantanée d'un conteneur. Les images sont créées avec la commande docker build, qui utilise une instruction Dockerfile. Une fois créées, les images peuvent être utilisées pour créer de nouveaux conteneurs Docker.

#### Création d'images Docker avec Dockerfile

Un Dockerfile est un fichier texte qui contient toutes les commandes, dans l'ordre, nécessaires pour construire une image Docker donnée. Par exemple, un Dockerfile pour une application Node.js peut ressembler à ceci :

`Dockerfile`
## Définir une image de base
`FROM node:14`

## Définir le répertoire de travail dans le conteneur Docker
`WORKDIR /usr/src/app`

## Copier package.json et package-lock.json
`COPY package*.json ./`

## Installer les dépendances
`RUN npm install`

## Copier le reste de l'application dans le conteneur Docker
`COPY . .`

## Exposer le port que l'application utilise
`EXPOSE 8080`

## Définir la commande pour exécuter l'application
`CMD [ "node", "app.js" ]`

Pour construire une image à partir de ce Dockerfile, vous utiliseriez la commande docker build :

`bash`
`docker build -t my-nodejs-app .`

#### Gestion des images Docker

Voici quelques commandes de base pour gérer les images Docker :

- docker images : Liste toutes les images Docker sur votre machine.
- docker rmi [image_id] : Supprime une image Docker spécifique.

## Utilisation de Docker Compose

#### Comprendre le concept de Docker Compose

Docker Compose est un outil qui permet de définir et de gérer des applications multi-conteneurs Docker. Il utilise des fichiers YAML pour configurer les services de l'application (conteneurs), les volumes, les réseaux, etc. Docker Compose simplifie le processus de gestion des conteneurs Docker et est particulièrement utile pour le développement, les tests et les environnements de déploiement de stagiaire.

#### Création de fichiers docker-compose.yml

Un fichier docker-compose.yml permet de définir comment Docker doit gérer votre application. Voici un exemple de fichier docker-compose.yml pour une application web simple qui utilise une base de données :

```yaml
version: '3'
services:
  web:
    build: .
    ports:
     - "5000:5000"
    volumes:
     - .:/code
    depends_on:
     - db
  db:
    image: postgres
```

Dans cet exemple, nous avons deux services : 'web' et 'db'. Le service 'web' est construit à partir du Dockerfile dans le répertoire courant, mappé au port 5000 et dépend du service 'db'. Le service 'db' utilise simplement l'image Docker 'postgres'.

#### Gestion de plusieurs conteneurs avec Docker Compose

Docker Compose rend la gestion de plusieurs conteneurs simple. Vous pouvez utiliser quelques commandes simples pour démarrer, arrêter et voir l'état de tous les conteneurs définis dans votre fichier docker-compose.yml :

- `docker-compose up` : Crée et démarre les conteneurs
- `docker-compose down` : Arrête et supprime les conteneurs, les réseaux, les images et les volumes
- `docker-compose ps` : Liste tous les conteneurs en cours d'exécution

## Introduction à NGINX

### Installation et configuration de NGINX

Pour installer NGINX sur Ubuntu, vous pouvez utiliser le gestionnaire de paquets apt:

```bash
sudo apt update
sudo apt install nginx
```

Après l'installation, le service NGINX devrait démarrer automatiquement. Vous pouvez vérifier son état avec la commande suivante :

```bash
systemctl status nginx
```

### Utilisation de NGINX comme serveur Web et reverse proxy

NGINX peut servir des fichiers statiques directement, agissant comme un serveur Web. Par exemple, si vous avez un fichier index.html dans le répertoire /var/www/html, vous pouvez le servir avec NGINX.

NGINX peut également agir comme un reverse proxy. Cela signifie qu'il peut prendre des requêtes entrantes et les transmettre à d'autres serveurs, puis renvoyer les réponses de ces serveurs aux clients.

### Configuration de NGINX pour utiliser TLSv1.2 ou TLSv1.3

Pour configurer NGINX pour utiliser TLSv1.2 ou TLSv1.3, vous devez modifier le fichier de configuration de NGINX. Vous pouvez spécifier les protocoles que vous voulez utiliser avec la directive ssl_protocols dans le bloc server de votre fichier de configuration. Par exemple :

```nginx
server {
    listen 443 ssl;
    ssl_protocols TLSv1.2 TLSv1.3;

    # autres configurations...
}
```

Assurez-vous d'avoir un certificat SSL et une clé privée installés pour pouvoir utiliser HTTPS.

## Installation et configuration de WordPress

### Télécharger WordPress

1. Rendez-vous sur le [site officiel de WordPress](https://wordpress.org/download/) pour télécharger la dernière version de WordPress.
2. Décompressez le fichier que vous avez téléchargé.

    ```bash
    tar -xvf latest.tar.gz
    ```

### Transférer les fichiers sur votre serveur Web

1. Vous pouvez utiliser `scp` ou `rsync` pour transférer les fichiers sur votre serveur.

    ```bash
    scp -r wordpress/ user@your_server:/path/to/your/website
    ```

### Créer une base de données MySQL pour WordPress

1. Connectez-vous à MySQL.

    ```bash
    mysql -u root -p
    ```

2. Créez une base de données pour WordPress.

    ```sql
    CREATE DATABASE wordpress;
    ```

### Lancer le script d'installation

1. Accédez à votre site Web dans un navigateur Web pour lancer le script d'installation.

## Utilisation de WordPress avec PHP-FPM

### Assurez-vous que PHP et PHP-FPM sont installés et configurés

1. Pour installer PHP et PHP-FPM, vous pouvez utiliser `apt` sur Ubuntu.

    ```bash
    sudo apt-get install php-fpm
    ```

2. Vérifiez que PHP-FPM fonctionne.

    ```bash
    systemctl status php-fpm
    ```

### Modifiez la configuration de votre serveur web pour utiliser PHP-FPM

1. Pour NGINX, modifiez votre fichier de configuration de site (/etc/nginx/sites-available/your-site) pour inclure le bloc suivant.

    ```nginx
    location ~ \.php$ {
        include snippets/fastcgi-php.conf;
        fastcgi_pass unix:/var/run/php/php7.2-fpm.sock;
    }
    ```

2. Vérifiez que la configuration de NGINX est correcte et rechargez le service.

    ```bash
    sudo nginx -t
    sudo systemctl reload nginx
    ```

### Vérifiez que WordPress fonctionne correctement avec PHP-FPM

1. Accédez à votre site WordPress dans un navigateur pour vérifier que tout fonctionne correctement.

## Introduction à MariaDB

### Installation de MariaDB

1. Vous pouvez installer MariaDB avec `apt` sur Ubuntu.

    ```bash
    sudo apt-get install mariadb-server
    ```

2. Vérifiez que MariaDB est en cours d'exécution.

    ```bash
    systemctl status mariadb
    ```

### Configuration de MariaDB

1. Exécutez le script de sécurisation de l'installation.

    ```bash
    sudo mysql_secure_installation
    ```

2. Suivez les instructions à l'écran pour définir un mot de passe root, supprimer les utilisateurs anonymes, désactiver la connexion root à distance et supprimer la base de données de test.

### Utilisation de MariaDB

1. Connectez-vous à MariaDB.

    ```bash
    mysql -u root -p
    ```

2. Créez des bases de données et des utilisateurs comme vous le feriez avec MySQL.
