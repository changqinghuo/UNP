#ifndef UNP_H
#define UNP_H

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <arpa/inet.h>

#define SERV_PORT (8888)
#define BUFSIZE  (1024)
void str_cli(FILE* fp, int sockfd);
void str_echo(int sockfd);
#define max(a,b) ((a)>(b) ? (a):(b))




#endif
