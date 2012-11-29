DIR=$(shell pwd)
BIN_DIR=$(DIR)/bin
LIB_DIR=$(DIR)/lib
SRC_DIR=$(DIR)/src/server
INCLUDE_DIR=$(DIR)/include
PROG=$(BIN_DIR)/tcpserver01

INCLUDE=-I$(INCLUDE_DIR)

CC=gcc
CFLAGS=-Wall -W -g

$(PROG): tcpserver01.o str_echo.o
	$(CC) tcpserver01.o str_echo.o  -o $(PROG) 
tcpserver01.o: $(INCLUDE_DIR)/unp.h 
	$(CC)  $(INCLUDE) -c src/server/tcpserver01.c
str_echo.o: $(DIR)/src/lib/str_echo.c
	$(CC) $(INCLUDE) -c $(DIR)/src/lib/str_echo.c
