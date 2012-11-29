#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <arpa/inet.h>
int main(int arc, char** argv)
{
   int sockfd = 0;
   struct sockaddr_in servaddr;
   char sendbuf[1024]= "hello world";
   char  recbuf[1024];
   struct in_addr addr;
   int n = 0;
   bzero(&servaddr, sizeof(servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_port = htons(8888);
   inet_aton("127.0.0.1", &servaddr.sin_addr.s_addr);
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if(connect(sockfd, (__CONST_SOCKADDR_ARG)&servaddr, sizeof(servaddr)) == -1)
   {
       printf("connect error!\n");
       return 1;
   }
   
//       write(sockfd, sendbuf, strlen(sendbuf));
       while((n= read(0, sendbuf, sizeof(sendbuf))) > 0 )
       {
           sendbuf[n] = '\0';
           write(1, sendbuf, strlen(sendbuf));
           write(sockfd, sendbuf, strlen(sendbuf));
       }
       return 0;



}

