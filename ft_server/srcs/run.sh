#!/bin/bash

# authorization
chmod 777 /run.sh
chown -R www-data:www-data /var/www/
chmod 755 /var/www/

# ssl
openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

# nginx
cp -rp ./default /etc/nginx/sites-available/

# phpmyadmin
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/
cp -rp ./config.inc.php /var/www/html/phpmyadmin/ 

# mysql
service mysql start
echo "CREATE DATABASE IF NOT EXISTS wordpress;" | mysql -u root --skip-password
echo "CREATE USER IF NOT EXISTS 'sohelee'@'localhost' IDENTIFIED BY '1234';" \
	| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'sohelee'@'localhost' WITH GRANT OPTION;" \
	| mysql -u root --skip-password
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password

# wordpress
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ var/www/html/
chown -R www-data:www-data /var/www/html/wordpress
cp -rp ./wp-config.php /var/www/html/wordpress/

service nginx start
service mysql restart
service php7.3-fpm start

bash
