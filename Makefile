# Makefile.mk
# Carlos Santos
# CS 270
# Bruce Bolden
# 12/4/19
# make file for serve client HW 4

# make both server and client
all:
	gcc server.c -o s
	gcc client.c -o c
# make just the server
server:
	gcc server.c -o s
# make just the client
client:
	gcc client.c -o c
# run the sever on port 4501
# ./filename port
runs:
	./s 4501
# run the client on port 4501 and with a set hostname
# ./filename hostname port
runc:
	./c Localhost 4501

