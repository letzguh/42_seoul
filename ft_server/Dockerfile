FROM debian:buster

RUN apt-get update
RUN apt-get install -y \
	nginx \
	openssl \
	vim \
	php7.3-fpm \
	mariadb-server \
	php-mysql \
	php-mbstring \
	wget

COPY ./srcs/run.sh ./
COPY ./srcs/default ./
COPY ./srcs/config.inc.php ./
COPY ./srcs/wp-config.php ./

EXPOSE 80 443

CMD bash run.sh
