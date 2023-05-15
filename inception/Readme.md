# Inception 42 Toutes mes notes

1. [Introduction à Docker et Docker Compose](#introduction-a-docker-et-docker-compose)
2. [Création de la Machine Virtuelle](#creation-de-la-machine-virtuelle)
3. [Comprendre et Utiliser NGINX](#comprendre-et-utiliser-nginx)
   1. [Installation de NGINX](#installation-de-nginx)
   2. [Configuration de NGINX](#configuration-de-nginx)
   3. [Sécurisation de NGINX avec TLS](#securisation-de-nginx-avec-tls)
4. [Comprendre et Utiliser WordPress, php-fpm et MariaDB](#comprendre-et-utiliser-wordpress-php-fpm-et-mariadb)
   1. [Installation et Configuration de WordPress et php-fpm](#installation-et-configuration-de-wordpress-et-php-fpm)
   2. [Installation et Configuration de MariaDB](#installation-et-configuration-de-mariadb)
5. [Gestion des Volumes Docker](#gestion-des-volumes-docker)
   1. [Création de Volumes](#creation-de-volumes)
   2. [Gestion des Données avec les Volumes](#gestion-des-donnees-avec-les-volumes)
6. [Création d'un Makefile](#creation-dun-makefile)
7. [Sécurité](#securite)
8. [Partie Bonus](#partie-bonus)
   1. [Ajout de Services Supplémentaires](#ajout-de-services-supplementaires)
   2. [Test des Services](#test-des-services)

## 1. Introduction à Docker et Docker Compose

### 1.1 Qu'est-ce que Docker ?

Docker est une plateforme open source qui permet de faciliter le déploiement, l'exécution et la gestion d'applications dans des environnements isolés appelés conteneurs. Les conteneurs Docker sont légers et portables car ils n'ont pas besoin d'un système d'exploitation complet pour fonctionner. Ils sont isolés du reste du système et entre eux, mais peuvent communiquer entre eux et avec l'extérieur.

### 1.2 Pourquoi utiliser Docker ?

Docker offre de nombreux avantages :

1. **Isolation** : chaque conteneur fonctionne de manière indépendante, ce qui permet d'éviter les conflits entre les différentes applications et leurs dépendances.
2. **Portabilité** : un conteneur Docker peut être exécuté sur n'importe quelle machine qui a Docker installé, indépendamment du système d'exploitation et de la configuration matérielle.
3. **Efficacité** : les conteneurs Docker sont légers et démarrés rapidement, ce qui permet de maximiser l'utilisation des ressources de votre machine.
4. **Intégration et déploiement continus** : Docker s'intègre bien avec des outils populaires de CI/CD (Intégration Continue / Déploiement Continu), ce qui permet de mettre en place des pipelines de déploiement automatisés.

### 1.3 Qu'est-ce que Docker Compose ?

Docker Compose est un outil qui permet de définir et de gérer des applications multi-conteneurs avec Docker. Avec Docker Compose, vous pouvez définir vos services, leurs configurations et leurs dépendances dans un fichier YAML, puis démarrer tous les services avec une seule commande. Docker Compose est particulièrement utile dans les environnements de développement et de test, ainsi que dans les déploiements CI/CD.

### 1.4 Pourquoi utiliser Docker Compose ?

Voici quelques raisons d'utiliser Docker Compose :

1. **Simplicité** : avec Docker Compose, vous pouvez définir et exécuter des applications multi-conteneurs avec une seule commande.
2. **Automatisation** : Docker Compose permet d'automatiser la configuration de vos services, ce qui élimine la nécessité de démarrer et de configurer manuellement chaque conteneur.
3. **Reproductibilité** : comme la configuration de votre application est définie dans un fichier, vous pouvez facilement reproduire votre environnement sur d'autres machines.
