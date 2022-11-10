#!/bin/bash

if [ ! -f /etc/ssl/certs/nginx.crt ]; then
echo "nginx: setting up ssl... ";
openssl req -x509 -nodes -days 365 -newkey rsa:4096 -keyout /etc/ssl/private/nginx.key -out /etc/ssl/certs/nginx.crt -subj "/C=KR/ST=Seoul/L=Seoul/O=wordpress/CN=naykim.42.fr";
echo "nginx: ssl is set up!";
fi

exec "$@"