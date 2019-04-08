#!/bin/sh
# flush previous rules, delete chains, reset counters
sudo iptables --flush
sudo iptables --delete-chain
sudo iptables --policy INPUT   ACCEPT
sudo iptables --policy FORWARD ACCEPT
sudo iptables --policy OUTPUT  ACCEPT
# verify
sudo iptables -S
exit $?
