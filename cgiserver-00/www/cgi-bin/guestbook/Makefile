index.cgi: index.c
	gcc index.c -o index.cgi -lcgic -lsqlite3 -ldl -lpthread -I $(HOME)/cgic -L $(HOME)/cgic -I $(HOME)/sqlite3 -L $(HOME)/sqlite3
	chmod 755 index.cgi

clean:
	rm index.cgi
