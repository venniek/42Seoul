FROM debian:buster

RUN apt update
RUN apt -y install php7.3 php-mysqli php-fpm wget

EXPOSE 9000

COPY ./conf/www.cnf /etc/php/7.3/fpm/pool.d
COPY ./tools /var/www

RUN sed -i 's/\/run\/php\/php7.3-fpm.sock/0.0.0.0:9000/g' /etc/php/7.3/fpm/pool.d/www.conf
RUN chmod +x /var/www/wordpress_start.sh

ENTRYPOINT [ "/var/www/wordpress_start.sh" ]
CMD [ "/usr/sbin/php-fpm7.3", "--nodaemonize" ]