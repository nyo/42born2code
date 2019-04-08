#!/bin/sh
CRON_FILE="/var/spool/cron/crontabs/root"
MD5SUM=$(cat /home/anyo/.crontab_md5 2>&-)
NEWSUM=$(md5sum $CRON_FILE | cut -d ' ' -f 1)
if [ "$MD5SUM" != "$NEWSUM" ]
then
	md5sum $CRON_FILE | cut -d ' ' -f 1 > /home/anyo/.crontab_md5
	mail -s "[!] $CRON_FILE has been modified!" root < $CRON_FILE >/dev/null 2>&-
	# mail NOT sent to root because of Debian 9 security rules (sent to 'anyo' instead)
fi
exit $?
