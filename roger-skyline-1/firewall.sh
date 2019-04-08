#!/bin/sh

# flush previous rules, delete chains, reset counters
sudo iptables --flush
sudo iptables --delete-chain

# drop everything, but established connections
sudo iptables --policy INPUT   DROP
sudo iptables --policy FORWARD DROP
sudo iptables --policy OUTPUT  DROP
sudo iptables --append INPUT  --match conntrack --ctstate ESTABLISHED --jump ACCEPT
sudo iptables --append OUTPUT --match conntrack --ctstate ESTABLISHED --jump ACCEPT

# drop spoofing packets
# sudo iptables --append INPUT -s 10.0.0.0/8 --jump DROP
# sudo iptables --append INPUT -s 169.254.0.0/16 --jump DROP
# sudo iptables --append INPUT -s 172.16.0.0/12 --jump DROP
# sudo iptables --append INPUT -s 127.0.0.0/8 --jump DROP
# sudo iptables --append INPUT -s 192.168.0.0/24 --jump DROP
# sudo iptables --append INPUT -s 224.0.0.0/4 --jump DROP
# sudo iptables --append INPUT -d 224.0.0.0/4 --jump DROP
# sudo iptables --append INPUT -s 240.0.0.0/5 --jump DROP
# sudo iptables --append INPUT -d 240.0.0.0/5 --jump DROP
# sudo iptables --append INPUT -s 0.0.0.0/8 --jump DROP
# sudo iptables --append INPUT -d 0.0.0.0/8 --jump DROP
# sudo iptables --append INPUT -d 239.255.255.0/24 --jump DROP
# sudo iptables --append INPUT -d 255.255.255.255 --jump DROP

# dropping all invalid packets
sudo iptables --append INPUT   --match state --state INVALID --jump DROP
sudo iptables --append FORWARD --match state --state INVALID --jump DROP
sudo iptables --append OUTPUT  --match state --state INVALID --jump DROP

# anyone who tried to portscan us is locked out for an entire day.
# iptables --append INPUT   --match recent --name portscan --rcheck --seconds 86400 --jump DROP
# iptables --append FORWARD --match recent --name portscan --rcheck --seconds 86400 --jump DROP
# once the day has passed, remove them from the portscan list
# iptables --append INPUT   --match recent --name portscan --remove
# iptables --append FORWARD --match recent --name portscan --remove
#
# iptables -A INPUT -p tcp -m tcp --dport 139 -m recent --name portscan --set -j DROP
# iptables -A FORWARD -p tcp -m tcp --dport 139 -m recent --name portscan --set -j DROP

# these rules add scanners to the portscan list, and log the attempt.
# iptables --append INPUT   --protocol tcp --match tcp --dport 139 --match recent --name portscan --set --jump LOG --log-prefix "Portscan:"
# iptables --append INPUT   --protocol tcp --match tcp --dport 139 --match recent --name portscan --set --jump DROP
# iptables --append FORWARD --protocol tcp --match tcp --dport 139 --match recent --name portscan --set --jump LOG --log-prefix "Portscan:"
# iptables --append FORWARD --protocol tcp --match tcp --dport 139 --match recent --name portscan --set --jump DROP

# anyone who connects to 10 ports (same or differents) in less than 30 seconds is blocked
sudo iptables --append INPUT   --in-interface enp0s3 --match state --state NEW --match recent --name portscan --set
sudo iptables --append FORWARD --in-interface enp0s3 --match state --state NEW --match recent --name portscan --set
sudo iptables --append INPUT   --in-interface enp0s3 --match state --state NEW --match recent --name portscan --update --seconds 300 --hitcount 10 --jump DROP
sudo iptables --append FORWARD --in-interface enp0s3 --match state --state NEW --match recent --name portscan --update --seconds 300 --hitcount 10 --jump DROP

# allow local loopback
sudo iptables --append INPUT  --in-interface lo --jump ACCEPT
sudo iptables --append OUTPUT --out-interface lo --jump ACCEPT
# allow icmp (ping)
sudo iptables --append INPUT  --protocol icmp --jump ACCEPT
sudo iptables --append OUTPUT --protocol icmp --jump ACCEPT
# allow dns resolution
sudo iptables --append INPUT  --protocol udp --dport 53 --jump ACCEPT
sudo iptables --append OUTPUT --protocol udp --dport 53 --jump ACCEPT
sudo iptables --append INPUT  --protocol tcp --dport 53 --jump ACCEPT
sudo iptables --append OUTPUT --protocol tcp --dport 53 --jump ACCEPT
# allow ssh
sudo iptables --append INPUT  --protocol tcp --dport 9393 --jump ACCEPT
sudo iptables --append OUTPUT --protocol tcp --dport 9393 --jump ACCEPT
# allow http (web)
sudo iptables --append INPUT  --protocol tcp --dport 80 --jump ACCEPT
sudo iptables --append OUTPUT --protocol tcp --dport 80 --jump ACCEPT
# allow https (ssl)
sudo iptables --append INPUT  --protocol tcp --dport 443 --jump ACCEPT
sudo iptables --append OUTPUT --protocol tcp --dport 443 --jump ACCEPT
# allow smtp (mails)
# sudo iptables --append OUTPUT --protocol tcp --dport 25 --jump ACCEPT
# verify
sudo iptables -S
exit $?
