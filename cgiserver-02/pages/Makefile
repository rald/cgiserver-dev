CC = gcc
FLAGS = -Wall
CGIBIN = .

all:
	$(CC) $(FLAGS) -lcgi gbook.c -o $(CGIBIN)/gbook.cgi -I $(HOME)/libcgi/include -L $(HOME)/libcgi/lib

	@echo 
	@echo Example compiled. Now copy *.cgi and *.htm files 
	@echo to your webserver cgi-bin directory.
	@echo To test, call gbook.cgi application
	@echo 

