FROM alpine:3.14

RUN apk update
RUN apk add mariadb mariadb-server
RUN rm -f /var/cache/apk/*

ENTRYPOINT ["mysqld_safe"]