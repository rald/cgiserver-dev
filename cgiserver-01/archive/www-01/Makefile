guestbook.cgi: guestbook.c
	gcc guestbook.c -o guestbook.cgi -lcgic -lsqlite3 -I $(HOME)/cgic -L $(HOME)/cgic -I $(HOME)/sqlite3 -L $(HOME)/sqlite3
	chmod 755 guestbook.cgi

clean:
	rm guestbook.cgi
