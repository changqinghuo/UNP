TARGET:client tcpserver 
client: client.o strcli.o 
	gcc -o  client  client.o strcli.o 
client.o: unp.h
strcli.o: strcli.c unp.h
	gcc -c strcli.c 
tcpserver: tcpserver.o  
	gcc -o tcpserver tcpserver.o  
tcpserver.o: unp.h

