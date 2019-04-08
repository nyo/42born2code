# Vous devez mettre en place du SSL auto-signé sur l’ensemble de vos services.
# installing openssl
echo "sudo apt-get install openssl"
# creating self signed key and cert
echo "sudo openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt"
