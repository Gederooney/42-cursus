# Configuring MariaDB on Linux

MariaDB is a popular open-source relational database management system, which is a fork of MySQL. Here's a guide on how to install and configure it on a Linux machine.

## Step 1: Install MariaDB

On Ubuntu, you can install MariaDB using the apt package manager:

```bash
sudo apt update
sudo apt install mariadb-server
```

## Step 2: Secure MariaDB

After installing, it's recommended to run the security script that comes with MariaDB:

```bash
sudo mysql_secure_installation
```

This script will help you to set a root password, remove anonymous users, disable remote root login, and remove the test database.

## Step 3: Test the Installation

You can check if MariaDB is running with:

```bash
systemctl status mariadb
```

You should see an output indicating that the MariaDB service is running.

## Step 4: Accessing MariaDB

You can log in to MariaDB with the following command:

```bash
mysql -u root -p
```

You will be prompted to enter the root password that you configured during the secure installation.

In the MariaDB prompt, you can create a new database, create a user, and grant privileges to the user. Here's an example:

```sql
CREATE DATABASE mydb;
CREATE USER 'myuser'@'localhost' IDENTIFIED BY 'mypassword';
GRANT ALL PRIVILEGES ON mydb.* TO 'myuser'@'localhost';
FLUSH PRIVILEGES;
```

Replace 'mydb', 'myuser', and 'mypassword' with your database name, username, and password, respectively.

With these steps, you have a basic MariaDB setup on your Linux machine. For more advanced configurations, please refer to the [MariaDB documentation](https://mariadb.com/kb/en/).

# Building a Custom MariaDB Docker Image on Alpine Linux

Building a Docker image on Alpine Linux is a great way to keep the size of your images down. Here's a guide on how to build a custom MariaDB Docker image based on Alpine Linux.

## Step 1: Create a Dockerfile

First, create a new directory for your Docker project and navigate into it:

```bash
mkdir mariadb && cd mariadb
```

Then, create a new file in this directory named `Dockerfile`:

```bash
touch Dockerfile
```

## Step 2: Define the Base Image

Open the Dockerfile in a text editor, and start by defining the base image. We'll use Alpine for this example:

```Dockerfile
FROM alpine:3.14
```

## Step 3: Install MariaDB

Next, add the commands to update the package lists and install MariaDB:

```Dockerfile
RUN apk update && apk add mariadb mariadb-client && rm -f /var/cache/apk/*
```

## Step 4: Set the Entrypoint

Finally, add an ENTRYPOINT instruction that starts the MariaDB server:

```Dockerfile
ENTRYPOINT ["mysqld_safe"]
```

Your final Dockerfile should look like this:

```Dockerfile
FROM alpine:3.14

RUN apk update && apk add mariadb mariadb-client && rm -f /var/cache/apk/*

ENTRYPOINT ["mysqld_safe"]
```

## Step 5: Build the Docker Image

You can now build the Docker image with the following command:

```bash
docker build -t my-mariadb .
```

Replace 'my-mariadb' with your desired image name.

Now, you have a Docker image with MariaDB installed. You can run a container from this image, but remember that the MariaDB server in the container won't have a root password set, and it won't be secured as it would be if you ran the `mysql_secure_installation` script. For a production setup, you would need to add more instructions to your Dockerfile to configure MariaDB securely.


# Configuring WordPress with PHP-FPM on Linux

WordPress is the world's most popular content management system (CMS), and PHP-FPM (FastCGI Process Manager) is a robust and high-performance way to serve PHP applications like WordPress. This guide will show you how to install and configure WordPress with PHP-FPM on a Linux machine.

## Step 1: Install PHP-FPM and Necessary PHP Extensions

On Ubuntu, you can install PHP-FPM and the necessary PHP extensions for WordPress with the following commands:

```bash
sudo apt update
sudo apt install php-fpm php-mysql php-curl php-gd php-intl php-mbstring php-soap php-xml php-xmlrpc php-zip
```

## Step 2: Download WordPress

Next, download the latest version of WordPress from the official WordPress website:

```bash
wget https://wordpress.org/latest.tar.gz
```

Then, extract the downloaded file and move the WordPress files to the web root directory:

```bash
tar xzf latest.tar.gz
sudo mv wordpress /var/www/html/
```

## Step 3: Configure WordPress

Now, navigate to the WordPress directory and copy the sample configuration file to create a new configuration file:

```bash
cd /var/www/html/wordpress
cp wp-config-sample.php wp-config.php
```

Then, open the new configuration file in a text editor and fill in your database details:

```bash
nano wp-config.php
```

Find the section that contains the dummy database details and replace them with your actual database name, username, and password.

## Step 4: Configure PHP-FPM

PHP-FPM uses a pool configuration file for each website. By default, there is a pool configuration file named www.conf. You can copy this file to create a new pool configuration file for your WordPress site:

```bash
sudo cp /etc/php/7.4/fpm/pool.d/www.conf /etc/php/7.4/fpm/pool.d/your-site.conf
```

Open the new pool configuration file in a text editor and make the necessary changes for your site. The exact changes will depend on your site's requirements, but you may need to adjust settings such as the user and group, the listen directive, and the pm directive.

Finally, restart PHP-FPM to apply your changes:

```bash
sudo service php7.4-fpm restart
```

That's it! You have installed and configured WordPress with PHP-FPM on your Linux machine.

# Building a Custom WordPress + PHP-FPM Docker Image on Alpine Linux

Building a Docker image on Alpine Linux is a great way to keep the size of your images down. Here's a guide on how to build a custom WordPress with PHP-FPM Docker image based on Alpine Linux.

## Step 1: Create a Dockerfile

First, create a new directory for your Docker project and navigate into it:

```bash
mkdir wordpress-docker && cd wordpress-docker
```

Then, create a new file in this directory named `Dockerfile`:

```bash
touch Dockerfile
```

## Step 2: Define the Base Image

Open the Dockerfile in a text editor, and start by defining the base image. We'll use Alpine for this example:

```Dockerfile
FROM alpine:3.14
```

## Step 3: Install PHP-FPM and Necessary PHP Extensions

Next, add the commands to update the package lists and install PHP-FPM and the necessary PHP extensions for WordPress:

```Dockerfile
RUN apk update && \
    apk add php7 php7-fpm php7-mysqli php7-json php7-openssl php7-curl \
    php7-zlib php7-xml php7-phar php7-intl php7-dom php7-xmlreader php7-ctype \
    php7-mbstring php7-gd nginx wget && \
    rm -f /var/cache/apk/*
```

## Step 4: Download and Configure WordPress

Add the commands to download the latest version of WordPress and configure it:

```Dockerfile
RUN wget https://wordpress.org/latest.tar.gz && \
    tar -xzf latest.tar.gz && \
    mv wordpress /var/www/html/ && \
    rm latest.tar.gz
```

## Step 5: Set the Entrypoint

Finally, add an ENTRYPOINT instruction that starts PHP-FPM:

```Dockerfile
ENTRYPOINT ["php-fpm7", "-F"]
```

Your final Dockerfile should look like this:

```Dockerfile
FROM alpine:3.14

RUN apk update && \
    apk add php7 php7-fpm php7-mysqli php7-json php7-openssl php7-curl \
    php7-zlib php7-xml php7-phar php7-intl php7-dom php7-xmlreader php7-ctype \
    php7-mbstring php7-gd nginx wget && \
    rm -f /var/cache/apk/*

RUN wget https://wordpress.org/latest.tar.gz && \
    tar -xzf latest.tar.gz && \
    mv wordpress /var/www/html/ && \
    rm latest.tar.gz

ENTRYPOINT ["php-fpm7", "-F"]
```

## Step 6: Build the Docker Image

You can now build the Docker image with the following command:

```bash
docker build -t my-wordpress .
```

Replace 'my-wordpress' with your desired image name.

# Docker Compose Guide for WordPress and MariaDB with Networks and .env file

1. In your project root directory, create a new file named `.env` and add your environment variables:

```
MYSQL_ROOT_PASSWORD=root-password
MYSQL_DATABASE=wordpress
MYSQL_USER=wordpress
MYSQL_PASSWORD=secret
WORDPRESS_DB_HOST=mariadb
WORDPRESS_DB_USER=wordpress
WORDPRESS_DB_PASSWORD=secret
WORDPRESS_DB_NAME=wordpress
```

2. Replace `root-password` and `secret` with your desired MariaDB root password and WordPress database password respectively.

3. Create a new file named `docker-compose.yml` in your project root directory.

4. Open the file in a text editor, and add the following content:

```yaml
version: '3.8'

services:
  mariadb:
    build: ./path-to-your-mariadb-dockerfile
    volumes:
      - mariadb_data:/var/lib/mysql
    environment:
      MYSQL_ROOT_PASSWORD: ${MYSQL_ROOT_PASSWORD}
      MYSQL_DATABASE: ${MYSQL_DATABASE}
      MYSQL_USER: ${MYSQL_USER}
      MYSQL_PASSWORD: ${MYSQL_PASSWORD}
    networks:
      - wp_network
  wordpress:
    depends_on:
      - mariadb
    build: ./path-to-your-wordpress-dockerfile
    volumes:
      - wordpress_data:/var/www/html
    environment:
      WORDPRESS_DB_HOST: ${WORDPRESS_DB_HOST}
      WORDPRESS_DB_USER: ${WORDPRESS_DB_USER}
      WORDPRESS_DB_PASSWORD: ${WORDPRESS_DB_PASSWORD}
      WORDPRESS_DB_NAME: ${WORDPRESS_DB_NAME}
    networks:
      - wp_network
  nginx:
    build: ./path-to-your-nginx-dockerfile
    ports:
      - "80:80"
    depends_on:
      - wordpress
    networks:
      - wp_network

networks:
  wp_network:
    driver: bridge
    ipam: default

volumes:
  mariadb_data:
    driver: local
  wordpress_data:
    driver: local
```

5. Replace `./path-to-your-mariadb-dockerfile` and `./path-to-your-wordpress-dockerfile` with the paths to the directories containing your Dockerfiles for MariaDB and WordPress respectively.

6. To start all your services, open a terminal in your project root directory (the directory containing your `docker-compose.yml` file), and run the following command:

```bash
docker-compose up -d
```

7. To stop your services, use the following command:

```bash
docker-compose down
```

Your data in the `mariadb_data` volume will persist across container restarts and removals. The `wp_network` allows your containers to communicate with each other.

# Dockerfile for Nginx

## Step 1: Specify the base image

We'll start by specifying our base image. Alpine Linux is a lightweight Linux distribution so it's a good choice for a base image.

```Dockerfile
FROM alpine:3.14
```

## Step 2: Install Nginx

Next, we'll update the package list in our base image and install Nginx.

```Dockerfile
RUN apk update && apk add nginx
```

## Step 3: Remove the default Nginx configuration file

We'll remove the default configuration file provided by Nginx. We're going to replace it with our own configuration file in the next step.

```Dockerfile
RUN rm /etc/nginx/conf.d/default.conf
```

## Step 4: Copy your Nginx configuration file into the Docker image

Next, we'll copy our Nginx configuration file from our local machine into the Docker image. This configuration file will tell Nginx how to handle incoming requests.

```Dockerfile
COPY nginx.conf /etc/nginx/conf.d/
```

## Step 5: Expose the port Nginx is reachable on

Finally, we'll tell Docker that Nginx inside our container will be listening on port 80. This doesn't actually publish the port to the host machine -- it just documents that the container is designed to serve traffic on this port.

```Dockerfile
EXPOSE 80
```

## Step 6: Specify the command to run Nginx

The last thing we need to do is tell Docker what command to run when the container starts up. In this case, we want to run Nginx.

```Dockerfile
CMD ["nginx", "-g", "daemon off;"]
```

And that's it! We now have a Dockerfile that will build an Nginx image based on Alpine Linux.

Below is the complete Dockerfile for creating a custom Nginx image based on Alpine Linux.

```Dockerfile
# Step 1: Specify the base image
FROM alpine:3.14

# Step 2: Install Nginx
RUN apk update && apk add nginx

# Step 3: Remove the default Nginx configuration file
RUN rm /etc/nginx/conf.d/default.conf

# Step 4: Copy your Nginx configuration file into the Docker image
COPY nginx.conf /etc/nginx/conf.d/

# Step 5: Expose the port Nginx is reachable on
EXPOSE 80

# Step 6: Specify the command to run Nginx
CMD ["nginx", "-g", "daemon off;"]
```
