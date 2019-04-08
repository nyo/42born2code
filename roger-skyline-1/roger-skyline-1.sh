#!/bin/bash

#
# ssh access:
# $ VBoxManage modifyvm roger-skyline-1 --natpf1 "ssh,tcp,,4242,,9393"
# $ VBoxManage modifyvm roger-skyline-1 --natpf1 "http,tcp,,1337,,80"
# $ VBoxManage modifyvm roger-skyline-1 --natpf1 "ssl,tcp,,4343,,443"
# $ VBoxManage showvminfo roger-skyline-1 | grep "Rule"
# $ ssh -p 4242 anyo@localhost
#

# ---------
# Partie VM
# ---------

# Vous devez installer une Virtual Machine (VM) avec l’OS Linux de votre choix...
echo "cat /etc/debian_version"
echo "sudo uname -v"
# ...dans l’hyperviseur de votre choix (VMWare Fusion, VirtualBox...).
# Celle ci devra avoir :
# - Une taille de disque de 8 Go.
echo "sudo fdisk -l"
# - Avoir au moins une partition de 4.2 Go.
echo "sudo df -h"
# - Elle devra également être à jour ainsi que l’ensemble des packages installés pour
# répondre aux demandes de ce sujet.
echo "apt-get -y update && apt-get -y upgrade && apt-get -y dist-upgrade"
echo "apt-get -y autoremove && apt-get -y autoclean"
echo "apt-get -y install sudo vim iptables fail2ban dos2unix curl mailutils dnsutils git net-tools"

# -------------------------
# Partie Réseau et Sécurité
# -------------------------

# Concernant le réseau sur la VM, voici les étapes à réaliser :
# - Vous devez créer un utilisateur non root pour vous connecter et travailler.
echo "adduser anyo --gecos ',,,' --disabled-password --force-badname"
echo "echo 'anyo:<pass>' | chpasswd"

# - Utilisez sudo pour pouvoir, depuis cet utilisateur, effectuer les operations demandant des droits speciaux.
echo "adduser anyo sudo"

# - Nous ne voulons pas que vous utilisiez le service DHCP de votre machine. A vous
# donc de la configurer afin qu’elle ait une IP fixe et un Netmask en /30.

# default (ip a):
#	inet	10.0.2.15/24
#	brd		10.0.2.255

# edit:
#	/etc/network/interfaces
# default:
#	allow-hotplug enp0s3
#	iface enp0s3 inet dhcp
# new:
#	auto enp0s3
#	allow-hotplug enp0s3
#	iface enp0s3 inet static
#		address 10.0.2.1
#		netmask 255.255.255.252
#		gateway 10.0.2.2

# edit:
#	/etc/resolv.conf
# add:
#	nameserver 1.1.1.1"
#	nameserver 8.8.8.8"
echo "sudo chattr +i /etc/resolv.conf"
# echo "sudo chattr -i /etc/resolv.conf"
echo "sudo service networking restart"

# - Vous devez changer le port par defaut du service SSH par celui de votre choix.
# L’accès SSH DOIT se faire avec des publickeys. L’utilisateur root ne doit pas pouvoir se connecter en SSH.
echo "sudo sed -i 's/#Port 22/Port 9393/g' /etc/ssh/sshd_config"
echo "sudo sed -i 's/ssh\t\t22/ssh\t\t9393/g' /etc/services"
echo "sudo sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin no/g' /etc/ssh/sshd_config"
echo "sudo service ssh restart"
# (client side)
echo "ssh-keygen" # set passphrase
echo "ssh-copy-id -p 4242 anyo@localhost" # enter password once, and set to go

# - Vous devez mettre en place des règles de pare-feu (firewall) sur le serveur avec
# uniquement les services utilisés accessible en dehors de la VM.
echo "sudo sh firewall.sh"
echo "sudo sh flush.sh"

# - Vous devez mettre en place une protection contre les DOS (Denial Of Service
# Attack) sur les ports ouverts de votre VM.
echo "sudo cp /etc/fail2ban/jail.conf /etc/fail2ban/jail.local"
echo "sudo service fail2ban restart"
# already configured for allowed ports by default

# - Vous devez mettre en place une protection contre les scans sur les ports ouverts de votre VM
echo "sudo sh firewall.sh" # see firewall
# https://www.ossramblings.com/using_iptables_rate_limiting_to_prevent_portscans

# - Arretez les services dont vous n’avez pas besoin pour ce projet.
echo "sudo service --status-all"
echo "sudo service <service_name> stop"

# - Réalisez un script qui met à jour l’ensemble des sources de package, puis de vos
# packages et qui log l’ensemble dans un fichier nommé /var/log/update_script.log.
# Créez une tache plannifiée pour ce script une fois par semaine à 4h00 du matin et
# à chaque reboot de la machine.
echo "sudo sh update.sh"
echo "sudo crontab -e"
echo "0 4 * * 1 /bin/sh /home/anyo/update.sh >/dev/null 2>&1"

# - Réalisez un script qui permet de surveiller les modifications du fichier /etc/crontab
# et envoie un mail à root si celui-ci a été modifié. Créez une tache plannifiée pour
# script tous les jours à minuit.

# You're missing the point.... root isn't supposed to receive emails! To have root receive emails would compromise your servers security in more ways than one. It's a massive security breach waiting to happen. As I said in my response above, either forward FROM root to another email (debian8@pengsir.hfi for example) OR use the proper way of receiving mail for which I linked the guide. NEVER receive email as root itself!
# https://www.digitalocean.com/community/questions/can-t-root-receive-any-email-with-postfix

echo "sudo sh bigbro.sh"
echo "sudo crontab -e"
echo "0 0 * * * /bin/sh /home/anyo/bigbro.sh >/dev/null 2>&1"

# - Vous devez mettre en place du SSL auto-signé sur l’ensemble de vos services.
# https://www.digitalocean.com/community/tutorials/how-to-create-a-ssl-certificate-on-apache-for-debian-8
echo "voir ssl.sh"

# ----------
# Partie Web
# ----------

# Vous devez mettre en place un serveur web qui DOIT être disponible sur l’IP de la
# VM ou un host (init.login.fr par exemple). Concernant les packages de votre serveur Web,
# vous avez le choix entre Nginx et Apache.
# Vous devez mettre en place une "application" web parmis les choix suivants :
#	- une page de login
#	- un site vitrine
#	- un site qui nous vend du rêve
# L’application web PEUT être codée avec le langage et les technos que vous voulez
# tant qu’elle reste compatible avec les éxigences de ce sujet.
echo "sudo apt-get install mariadb-client mariadb-server php7.0 php7.0-mysql apache2 libapache2-mod-php7.0 phpmyadmin"
# sudo mysql -u root -p
# GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY 'gayadmin' WITH GRANT OPTION;
# FLUSH PRIVILEGES;
# SELECT user, host FROM mysql.user;
# SET PASSWORD FOR 'root'@'localhost' = PASSWORD('gayadmin');
# sudo vim /etc/mysql/mariadb.conf.d/50-server.cnf
# comment out "bind-address"
# sudo a2enmod php7.0
# sudo service apache2 restart 

# ------------------
# Partie Déploiement
# ------------------

# Proposez une solution fonctionnelle d’automatisation de deploiement.
echo "!!! TO DO !!!"
