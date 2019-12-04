# Makefile.mk
# Name: Carlos Santos
# CS 270
# Instructor: Bruce Bolden
# 12/4/19
# make file for serve client HW 4
# To run this code open up to terminals of your choice.
# In on terminal run "make" and then "make runs" to start the server. In the other terminal run "make runc" to start the client.

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
# run the sever on port 4502
# ./filename port
runs:
	./s 4502
# run the client on port 4502 and with a set hostname
# ./filename hostname port
runc:
	./c Localhost 4502

