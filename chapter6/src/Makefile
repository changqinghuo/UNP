TARGET: tcpserver client
tcpserver: tcpserver.o 
	gcc -o tcpserver tcpserver.o 
tcpserver.o: unp.h

client: client.o strcli.o
	gcc -o client client.o strcli.o
client.o: unp.h
strcli.o: unp.h
