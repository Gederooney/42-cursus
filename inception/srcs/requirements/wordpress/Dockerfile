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
