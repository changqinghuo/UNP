#ifndef UNP_H
#define UNP_H

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <arpa/inet.h>

const int SERV_PORT = 8888;
const int BUFSIZE = 1024;
void str_cli(FILE* fp, int sockfd);
void str_echo(int sockfd);





#endif
