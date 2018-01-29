mysql> show databases;
mysql> use <db>;
mysql> show tables;

mysql> SELECT * FROM <table>;
mysql> SELECT <name> FROM <table>;
mysql> SELECT  <name>, <name> FROM <table>;

mysql> describe <table>;
mysql> desc <table>;

mysql> SELECT <name>, <name> FROM <table> limit <nb>;
mysql> SELECT <name>, <name> FROM <table> ORDER BY <name> LIMIT <nb>;

mysql> SELECT <name> FROM <table> ORDER BY <name> DESC LIMIT <nb>; (descending order)
mysql> SELECT <name> FROM <table> WHERE <name> != <nb> ORDER BY <name> DESC LIMIT <nb>;
mysql> SELECT <name> FROM <table> WHERE <name> > <nb> AND <name> < <nb> ORDER BY <name> DESC LIMIT <nb>;

mysql> SELECT count(*) FROM <table> ...
mysql> SELECT max(<name>) FROM <table> ...
mysql> SELECT upper(<name>) FROM <table> ... # (check sur internet)

mysql> SELECT titre FROM film INNER JOIN genre ON film.id_genre = genre.id_genre WHERE genre.id_genre = 25;
mysql> SELECT count(*), id_genre FROM film GROUP BY id_genre;

mysql> DELETE FROM genre; # DELETES EVERYTHING
mysql> DELETE FROM genre WHERE id_genre = 29;

mysql> INSERT INTO genre (id_genre, nom) VALUES ("Test");
mysql> UPDATE genre SET nom = "test" WHERE id_genre = 29;

mysql> CREATE TABLE Test (name VARCHAR(255), id INT PRIMARY KEY AUTO_INCREMENT);
mysql> SELECT * FROM Test; # empty
mysql> INSERT INTO Test (name) VALUES ("toto");
